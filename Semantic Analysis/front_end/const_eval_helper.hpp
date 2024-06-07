#pragma once
#include "AST.hpp"
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iostream>

namespace ConstEvalHelper {
    template <typename Ty>
    typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
    const_eval_helper(Ty *&p) {
        BaseAST *base = p;
        // std::cout << __LINE__ << std::endl;
        // std::cout << base << std::endl;
        base->const_eval(base);
        // std::cout << __LINE__ << std::endl;
        p = dynamic_cast<Ty *>(base);
        // std::cout << __LINE__ << std::endl;
        if (!p) {
            throw std::runtime_error("Failed to cast to derived type");
        }
    }

    // 检查常量初始化列表是否是字面值
    void const_initializer_assert(std::variant<ConstInitValAST*, InitValAST*>node);
    // 初始化列表初值类型修复，只处理字面值常量，不处理运行时类型转换
    void initializer_type_fix(std::variant<ConstInitValAST*, InitValAST*>node);
    // 检查数组维度是否是非负整数
    void array_dim_check(ExpAST *dim);
    // 数组展开与填充
    void array_flatten(std::variant<ConstInitValAST*, InitValAST*>init_val, std::deque<int> dim_sizes);
    // 数组格式化
    void array_format(std::variant<ConstInitValAST*, InitValAST*>init_val, std::deque<int> dim_sizes);
    // 调用flatten和format，完成数组的展开和拆分，实现数组规整化及补0操作
    void fix_nested_array(std::variant<ConstInitValAST*, InitValAST*>init_val, const std::vector<ExpAST *> &dim);
} // namespace ConstEvalHelper