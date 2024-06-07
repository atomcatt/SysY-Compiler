#include "const_eval_helper.hpp"
#include "AST.hpp"
#include <stdexcept>
#include <variant>
#include <numeric>
#include <iostream>

using namespace ConstEvalHelper;

//检查常量初始化列表是否是字面值
void ConstEvalHelper::const_initializer_assert(std::variant<ConstInitValAST*, InitValAST*> node) {
    if (std::holds_alternative<ConstInitValAST*>(node)){
        if (std::holds_alternative<ExpAST*>(std::get<ConstInitValAST*>(node)->value)) {
            if (!dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<ConstInitValAST*>(node)->value)))
            {
                throw std::runtime_error("unexpected non-constant initializer");
            }
        }else if (std::holds_alternative<ConstInitValListAST*>(std::get<ConstInitValAST*>(node)->value)){
            auto init_val_list = std::get<ConstInitValListAST*>(std::get<ConstInitValAST*>(node)->value);
            for (auto init_val : init_val_list->const_init_vals) {
                const_initializer_assert(init_val);
            }
        } else {

        }
    } else {
        if (std::holds_alternative<ExpAST*>(std::get<InitValAST*>(node)->value)) {
            if (!dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<InitValAST*>(node)->value)))
            {
                throw std::runtime_error("unexpected non-constant initializer");
            }
        }else if (std::holds_alternative<InitValListAST*>(std::get<InitValAST*>(node)->value)) {
            auto init_val_list = std::get<InitValListAST*>(std::get<InitValAST*>(node)->value);
            for (auto init_val : init_val_list->init_vals) {
                const_initializer_assert(init_val);
            }
        }else {

        }
    
    }
}

//初始化列表初值类型修复，只处理字面值常量，不处理运行时类型转换
void ConstEvalHelper::initializer_type_fix(std::variant<ConstInitValAST*, InitValAST*> node) {
    if (std::holds_alternative<ConstInitValAST*>(node)){
        if (std::holds_alternative<ExpAST*>(std::get<ConstInitValAST*>(node)->value)) {
            auto num_exp = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<ConstInitValAST*>(node)->value));
            if (!num_exp) {
                return ;
            }
        } else if (std::holds_alternative<ConstInitValListAST*>(std::get<ConstInitValAST*>(node)->value)){
            auto initializer_list = std::get<ConstInitValListAST*>(std::get<ConstInitValAST*>(node)->value);
            for (ConstInitValAST* value : initializer_list->const_init_vals) {
                initializer_type_fix(value);
            }
        } else {

        }
    } else {
        if (std::holds_alternative<ExpAST*>(std::get<InitValAST*>(node)->value)) {
            auto num_exp = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<InitValAST*>(node)->value));
            if (!num_exp) {
                return ;
            }
        } else if (std::holds_alternative<InitValListAST*>(std::get<InitValAST*>(node)->value)) {
            auto initializer_list = std::get<InitValListAST*>(std::get<InitValAST*>(node)->value);
            for (InitValAST* value : initializer_list->init_vals) {
                initializer_type_fix(value);
            }
        } else {

        }
    }
}
//检查数组维度是否是非负整数
void ConstEvalHelper::array_dim_check(ExpAST* dim) {
    // std::cout << "array_dim_check" << std::endl;
    auto num_exp = dynamic_cast<NumExpAST*>(dim);
    // std::cout << "num_exp" << std::endl;
    if (!num_exp) {
        throw std::runtime_error("unexpected non-constant array size");
    }
    if (num_exp->value < 0) {
        throw std::runtime_error("array size must be non-negative");
    }
}
//数组展开与填充
void ConstEvalHelper::array_flatten(std::variant<ConstInitValAST*, InitValAST*> init_val, std::deque<int> dim_sizes) {
    std::cout << "array_flatten" << std::endl;
    if (std::holds_alternative<ConstInitValAST*>(init_val)){
        std::cout << "array_flatten of ConstInitValAST" << std::endl;
        if (std::holds_alternative<ExpAST*>(std::get<ConstInitValAST*>(init_val)->value)) {
            std::cout << "array_flatten in ConstInitValAST of ExpAST" << std::endl;
            return ;
        }
        if (dim_sizes.empty()) {
            throw std::runtime_error("nested initializer list is too deep");
        }
        std::vector<ConstInitValAST*> values;
        int full_size = std::reduce(dim_sizes.begin(), dim_sizes.end(), 1, std::multiplies<>());
        // int full_size = dim_sizes.back();
        /* 添加的对空列表初始化 */
        if (std::holds_alternative<std::monostate>(std::get<ConstInitValAST*>(init_val)->value)) {
            std::cout << "array_flatten in ConstInitValAST of monostate" << std::endl;
            // int full_size = std::reduce(dim_sizes.begin(), dim_sizes.end(), 1, std::multiplies<>());
            std::cout << "full_size in monostate = " << full_size << std::endl;
            std::vector<ConstInitValAST*> values;
            for (size_t i = 0; i < full_size; i++) {
                auto ptr = new ConstInitValAST();
                ptr->value = new NumExpAST(0);
                values.emplace_back(ptr);
            }
            auto ptr = new ConstInitValListAST();
            std::get<ConstInitValAST*>(init_val)->value = ptr;
            std::get<ConstInitValListAST*>(std::get<ConstInitValAST*>(init_val)->value)->const_init_vals = values;
            return ;
        }
        /* 结束后添加的 */
        if (std::holds_alternative<ConstInitValListAST*>(std::get<ConstInitValAST*>(init_val)->value)) {
            std::cout << "array_flatten in ConstInitValAST of ExpAST" << std::endl;
            std::cout << "full_size = " << full_size << std::endl;
            auto initializer_list = std::get<ConstInitValListAST*>(std::get<ConstInitValAST*>(init_val)->value);
            dim_sizes.pop_front();
            // dim_sizes.pop_back();
            int flag = 0;
            std::deque<int> dim_sizes_copy = dim_sizes;
            for (ConstInitValAST* flatten_value : initializer_list->const_init_vals) {
                std::cout << "recusive array_flatten" << std::endl;
                if(flag == 0 && std::holds_alternative<ExpAST*>(flatten_value->value)) {
                    flag = 1;
                }
                if (flag == 1 && (std::holds_alternative<ConstInitValListAST*>(flatten_value->value)||(std::holds_alternative<std::monostate>(flatten_value->value)))) {
                    std::deque<int> temp;
                    temp.emplace_back(dim_sizes.back());
                    dim_sizes = temp;
                }
                array_flatten(flatten_value, dim_sizes);
                dim_sizes = dim_sizes_copy;
                if (std::holds_alternative<ExpAST*>(flatten_value->value)) {
                    values.emplace_back(flatten_value);
                } else {
                    auto flatten_list = std::get<ConstInitValListAST*>(flatten_value->value);
                    values.insert(values.end(), flatten_list->const_init_vals.begin(), flatten_list->const_init_vals.end());
                }
                if (values.size() >= full_size) {
                    break;
                }
            }
            std::cout << "values.size() in ConstInitValList = " << values.size() << "\n" << "full_size in ConstInitValList = " << full_size << std::endl;
            if (values.size() > full_size) {
                throw std::runtime_error("initializer overflow");
            }
            for (size_t i = values.size(); i < full_size; i++) {
                std::cout << "fxxk in ConstInitValList" << std::endl;
                auto ptr = new ConstInitValAST();
                ptr->value = new NumExpAST(0);
                values.emplace_back(ptr);
            }
            initializer_list->const_init_vals = values;
        }
    } else if (std::holds_alternative<InitValAST*>(init_val)) {
        if (std::holds_alternative<ExpAST*>(std::get<InitValAST*>(init_val)->value)) {
            std::cout << "array_flatten in InitValAST of ExpAST" << std::endl;
            return ;
        }
        if (dim_sizes.empty()) {
            throw std::runtime_error("nested initializer list is too deep");
        }
        std::vector<InitValAST*> values;
        int full_size = std::reduce(dim_sizes.begin(), dim_sizes.end(), 1, std::multiplies<>());
        // int full_size = dim_sizes.front();
        // int full_size = dim_sizes.back();
        if (std::holds_alternative<std::monostate>(std::get<InitValAST*>(init_val)->value)) {
            std::cout << "array_flatten in InitValAST of monostate" << std::endl;
            // int full_size = std::reduce(dim_sizes.begin(), dim_sizes.end(), 1, std::multiplies<>());
            std::vector<InitValAST*> values;
            for (size_t i = 0; i < full_size; i++) {
                auto ptr = new InitValAST();
                ptr->value = new NumExpAST(0);
                values.emplace_back(ptr);
            }
            auto ptr = new InitValListAST();
            std::get<InitValAST*>(init_val)->value = ptr;
            std::get<InitValListAST*>(std::get<InitValAST*>(init_val)->value)->init_vals = values;
            return ;
        }
        if (std::holds_alternative<InitValListAST*>(std::get<InitValAST*>(init_val)->value)) {
            std::cout << "array_flatten in InitValAST of InitValListAST" << std::endl;
            auto initializer_list = std::get<InitValListAST*>(std::get<InitValAST*>(init_val)->value);
            std::cout << "dim_sizes.pop_front() = " << dim_sizes.front() << std::endl;
            dim_sizes.pop_front();
            // dim_sizes.pop_back();
            int flag = 0;
            std::deque<int> dim_sizes_copy = dim_sizes;
            for (InitValAST* flatten_value : initializer_list->init_vals) {
                std::cout << "recusive array_flatten" << std::endl;
                // dim_sizes.pop_front();
                if(flag == 0 && std::holds_alternative<ExpAST*>(flatten_value->value)) {
                    flag = 1;
                }
                if (flag == 1 && (std::holds_alternative<InitValListAST*>(flatten_value->value)||(std::holds_alternative<std::monostate>(flatten_value->value)))) {
                    std::deque<int> temp;
                    temp.emplace_back(dim_sizes.back());
                    dim_sizes = temp;
                }
                array_flatten(flatten_value, dim_sizes);
                dim_sizes = dim_sizes_copy;
                if (std::holds_alternative<ExpAST*>(flatten_value->value)) {
                    values.emplace_back(flatten_value);
                } else {
                    auto flatten_list = std::get<InitValListAST*>(flatten_value->value);
                    values.insert(values.end(), flatten_list->init_vals.begin(), flatten_list->init_vals.end());
                }
                if (values.size() >= full_size) {
                    break;
                }
            }
            std::cout << "values.size() in InitValList = " << values.size() << "\n" << "full_size in InitValList = " << full_size << std::endl;
            if (values.size() > full_size) {
                throw std::runtime_error("initializer overflow");
            }
            for (size_t i = values.size(); i < full_size; i++) {
                std::cout << "fxxk" << std::endl;
                auto ptr = new InitValAST();
                ptr->value = new NumExpAST(0);
                values.emplace_back(ptr);
            }
            initializer_list->init_vals = values;
        }
    } else {
        std::cout << "array_flatten of monostate" << std::endl;
        // int full_size = std::reduce(dim_sizes.begin(), dim_sizes.end(), 1, std::multiplies<>());
        // std::vector<ConstInitValAST*> values;
        // for (size_t i = 0; i < full_size; i++) {
        //     auto ptr = new ConstInitValAST();
        //     ptr->value = new NumExpAST(0);
        //     values.emplace_back(ptr);
        // }
        // auto ptr = new ConstInitValListAST();
        // std::get<ConstInitValAST*>(init_val)->value = ptr;
        // std::get<ConstInitValListAST*>(std::get<ConstInitValAST*>(init_val)->value)->const_init_vals = values;
    }
}
//数组格式化
void ConstEvalHelper::array_format(std::variant<ConstInitValAST*, InitValAST*> init_val, std::deque<int> dim_sizes) {
    if (dim_sizes.size() <= 1) {
        return ;
    }
    int curr_size = dim_sizes.front();
    int full_size = std::reduce(dim_sizes.begin(), dim_sizes.end(), 1, std::multiplies<>());
    int step = full_size / curr_size;
    if (std::holds_alternative<ConstInitValAST*>(init_val)){
        auto initializer_list = std::get<ConstInitValListAST*>(std::get<ConstInitValAST*>(init_val)->value);
        std::vector<ConstInitValAST*> values;
        dim_sizes.pop_front();
        for (int i = 0; i < full_size; i+= step) {
            auto new_value = new ConstInitValAST();
            auto new_list = new ConstInitValListAST();
            new_list->const_init_vals = std::vector<ConstInitValAST*>(initializer_list->const_init_vals.begin() + i, initializer_list->const_init_vals.begin() + i + step);
            new_value->value = new_list;
            array_format(new_value, dim_sizes);
            values.emplace_back(new_value);
        }
        initializer_list->const_init_vals = values;
    } else if (std::holds_alternative<InitValAST*>(init_val)) {
        auto initializer_list = std::get<InitValListAST*>(std::get<InitValAST*>(init_val)->value);
        std::vector<InitValAST*> values;
        dim_sizes.pop_front();
        for (int i = 0; i < full_size; i+= step) {
            auto new_value = new InitValAST();
            auto new_list = new InitValListAST();
            new_list->init_vals = std::vector<InitValAST*>(initializer_list->init_vals.begin() + i, initializer_list->init_vals.begin() + i + step);
            new_value->value = new_list;
            array_format(new_value, dim_sizes);
            values.emplace_back(new_value);
        }
        initializer_list->init_vals = values;
    }else {

    }
}
//调用flatten和format，完成数组的展开和拆分，实现数组规整化及补0操作
void ConstEvalHelper::fix_nested_array(std::variant<ConstInitValAST*, InitValAST*> init_val, const std::vector<ExpAST*> &dim) {
    std::deque<int> dim_sizes;
    for (ExpAST* dim_exp : dim) {
        // auto num_exp = dynamic_cast<NumExpAST*>(dim_exp);
        // 使用dynamic_cast进行类型转换会在遇到非直接字面量的维度时会转换失败，所以这里用了static_cast
        NumExpAST* num_exp = static_cast<NumExpAST*>(dim_exp);
        if(num_exp == nullptr) { std::cout << "num_exp is nullptr" << std::endl;}
        dim_sizes.emplace_back(num_exp->value);
        std::cout << "dim_sizes " << num_exp->value << std::endl;
    }
    array_flatten(init_val, dim_sizes);
    std::cout << "array_flatten done" << std::endl;
    // array_format(init_val, dim_sizes);
    std::cout << "array_format done" << std::endl;
}