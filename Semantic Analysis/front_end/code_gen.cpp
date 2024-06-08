#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <numeric>
#include <map>
#include <fstream>
#include "AST.hpp"
#include "symbol_table.hpp"
#include "assemble.hpp"
#include "compile_state.hpp"

extern Assemble rodata, data, bss, text;
extern SymbolTable const_eval_symbol_table;
extern std::vector<std::string> param_regs;
SymbolTable symbol_table;
CompileState compile_state;

void CompUnitAST::code_gen() {
    if (!external_defs.empty()) {
        for (auto &external_def : external_defs) {
            external_def->code_gen();
        }
    }
    // 就是 比如main函数里引用了个global var d 结果d其实在main后才定义 你这样就导致他对了
    if (!decls.empty()) {
        for (auto &decl : decls) {
            decl->code_gen();
        }
    }
    if (!func_defs.empty()) {
        for (auto &func_def : func_defs) {
            func_def->code_gen();
        }
    }
}

void ExternalDefAST::code_gen() {
    return ;
}

void DeclAST::code_gen() {
    if (std::holds_alternative<ConstDeclAST*>(decl)) {
        std::get<ConstDeclAST*>(decl)->code_gen();
    } else {
        std::get<VarDeclAST*>(decl)->code_gen();
    }
}

void ConstDeclAST::code_gen() {
    if (!const_defs.empty()) {
        for (auto &const_def : const_defs) {
            const_def->code_gen();
        }
    }
}

void ConstDefAST::code_gen() {
    if (symbol_table.get_level() == 1) {
        // 全局变量
        rodata.append(".globl\t%s\n", ident.c_str());
        rodata.append(".align\t4\n");
        rodata.append(".type\t%s, @object\n", ident.c_str());
        if(dim.empty()) {
            rodata.append(".size\t%s, 4\n", ident.c_str());
            rodata.append("%s:\n", ident.c_str());
            rodata.append("\t.long\t%d\n", dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value);
            symbol_table.insert(ident, new Symbol(SymbolType::CONST_INT, 0, 0, dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value));
        } else {
            int size = 1;
            for (auto &dim_size : dim) {
                size *= dynamic_cast<NumExpAST*>(dim_size)->value;
            }
            rodata.append(".size\t%s, %d\n", ident.c_str(), size);
            rodata.append("%s:\n", ident.c_str());
            std::vector<int> dims;
            std::vector<int> values;
            for (auto &dim_size : dim) {
                dims.push_back(dynamic_cast<NumExpAST*>(dim_size)->value);
            }
            for (auto &const_init_val : (std::get<ConstInitValListAST*>(const_init_val->value))->const_init_vals) {
                auto val = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value;
                rodata.append("\t.long\t%d\n", val);
                values.emplace_back(val);
            }
            symbol_table.insert(ident, new Symbol(SymbolType::CONST_INT, 0, 1, dims, values));
        }
    } else {
        /* TODO */
        // 局部变量
        // std::cout << "ConstDefAST::code_gen() in level 2+" << std::endl;
        // if (std::holds_alternative<ConstInitValListAST*>(const_init_val->value))
        if (!dim.empty()) {
            //局部变量数组
            rodata.append(".align\t4\n");
            int level = symbol_table.get_level();
            rodata.append(".type\t%s.%d, @object\n", ident.c_str(), level-1);
            int size = 1;
            for (auto &dim_size : dim) {
                size *= dynamic_cast<NumExpAST*>(dim_size)->value;
            }
            rodata.append(".size\t%s.%d, %d\n", ident.c_str(), level-1, size);
            rodata.append("%s.%d:\n", ident.c_str(), level-1);
            std::vector<int> dims;
            std::vector<int> values;
            for (auto &dim_size : dim) {
                dims.push_back(dynamic_cast<NumExpAST*>(dim_size)->value);
            }
            for (auto &const_init_val : (std::get<ConstInitValListAST*>(const_init_val->value))->const_init_vals) {
                auto val = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value;
                rodata.append("\t.long\t%d\n", val);
                values.push_back(val);
            }
            symbol_table.insert(ident, new Symbol(SymbolType::CONST_ARRAY, 0, 1, dims, values));
        } else {
            // 局部普通变量
            // text.append();
            compile_state.update_offset(-4);
            text.append("\tmovl\t$%d, %d(%%rbp)\n", dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value, compile_state.get_offset());
            symbol_table.insert(ident, new Symbol(SymbolType::CONST_INT, compile_state.get_offset(), 0, dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value));
        }
    }
    // rodata.append("%s:\n", ident.c_str());
    // if(dim.empty()) {
    //     rodata.append("\t\t.long\t%d\n", dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value);
    //     symbol_table.insert(ident, new Symbol(SymbolType::CONST_INT, 0, 0, dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value));
    // } else {
    //     std::vector<int> values;
    //     for (auto &const_init_val : (std::get<ConstInitValListAST*>(const_init_val->value))->const_init_vals) {
    //         auto val = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value;
    //         rodata.append("\t\t.long\t%d\n", val);
    //         values.push_back(val);
    //     }
    //     symbol_table.insert(ident, new Symbol(SymbolType::CONST_INT, 0, 1, values));
    // }
}

void VarDeclAST::code_gen() {
    if (!var_defs.empty()) {
        for (auto &var_def : var_defs) {
            var_def->code_gen();
        }
    }
}

void VarDefAST::code_gen() {
    if (symbol_table.get_level() == 1) {
        // 全局变量
        data.append(".globl\t%s\n", ident.c_str());
        data.append(".align\t4\n");
        data.append(".type\t%s, @object\n", ident.c_str());
        if (dim.empty()) {
            data.append(".size\t%s, 4\n", ident.c_str());
            data.append("%s:\n", ident.c_str());
            data.append("\t.long\t%d\n", dynamic_cast<NumExpAST*>(std::get<ExpAST*>(init_val->value))->value);
            symbol_table.insert(ident, new Symbol(SymbolType::INTCONST, 0, 0, dynamic_cast<NumExpAST*>(std::get<ExpAST*>(init_val->value))->value));
        } else {
            int size = 1;
            std::vector<int> dims;
            std::vector<int> values;
            for (auto &dim_size : dim) {
                size *= dynamic_cast<NumExpAST*>(dim_size)->value;
                dims.push_back(dynamic_cast<NumExpAST*>(dim_size)->value);
            }
            if (init_val == nullptr) {
                data.append(".size\t%s, %d\n", ident.c_str(), size);
                data.append("%s:\n", ident.c_str());
                for (int i = 0; i < size; i++) {
                    data.append("\t.long\t0\n");
                    values.emplace_back(0);
                }
                symbol_table.insert(ident, new Symbol(SymbolType::INT_ARRAY, 0, 1, dims, values));
            } else {
                data.append(".size\t%s, %d\n", ident.c_str(), size);
                data.append("%s:\n", ident.c_str());
                std::vector<int> dims;
                std::vector<int> values;
                for (auto &dim_size : dim) {
                    dims.push_back(dynamic_cast<NumExpAST*>(dim_size)->value);
                }
                for (auto &const_init_val : (std::get<InitValListAST*>(init_val->value))->init_vals) {
                    auto val = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value))->value;
                    data.append("\t.long\t%d\n", val);
                    values.push_back(val);
                }
                symbol_table.insert(ident, new Symbol(SymbolType::INT_ARRAY, 0, 1, dims, values));
            }
        }
    } else {
        // std::cout << __LINE__ << std::endl;
        if (dim.empty()) {
            compile_state.update_offset(-4);
            if (dynamic_cast<NumExpAST*>(std::get<ExpAST*>(init_val->value))) {
                text.append("\tmovl\t$%d, %d(%%rbp)\n",
                            dynamic_cast<NumExpAST *>(std::get<ExpAST *>(init_val->value))->value,
                            compile_state.get_offset());
                symbol_table.insert(ident, new Symbol(SymbolType::INTCONST, compile_state.get_offset(), 0,
                                                      dynamic_cast<NumExpAST *>(std::get<ExpAST *>(
                                                              init_val->value))->value));
            } else if (dynamic_cast<VarExpAST*>(std::get<ExpAST*>(init_val->value))) {
                dynamic_cast<VarExpAST*>(std::get<ExpAST*>(init_val->value))->code_gen();
                text.append("\tmovl\t%%r10d, %d(%%rbp)\n", compile_state.get_offset());
                symbol_table.insert(ident, new Symbol(SymbolType::INTCONST, compile_state.get_offset(), 0, 0));
            } else if (dynamic_cast<BinaryExpAST*>(std::get<ExpAST*>(init_val->value))) {
                dynamic_cast<BinaryExpAST*>(std::get<ExpAST*>(init_val->value))->code_gen();
                text.append("\tmovl\t%%r10d, %d(%%rbp)\n", compile_state.get_offset());
                symbol_table.insert(ident, new Symbol(SymbolType::INTCONST, compile_state.get_offset(), 0, 0));
            } else if (dynamic_cast<UnaryExpAST*>(std::get<ExpAST*>(init_val->value))) {
                dynamic_cast<UnaryExpAST*>(std::get<ExpAST*>(init_val->value))->code_gen();
                text.append("\tmovl\t%%r10d, %d(%%rbp)\n", compile_state.get_offset());
                symbol_table.insert(ident, new Symbol(SymbolType::INTCONST, compile_state.get_offset(), 0, 0));
            } else if (dynamic_cast<FuncCallAST*>(std::get<ExpAST*>(init_val->value))) {
                dynamic_cast<FuncCallAST*>(std::get<ExpAST*>(init_val->value))->code_gen();
                text.append("\tmovl\t%%eax, %d(%%rbp)\n", compile_state.get_offset());
                symbol_table.insert(ident, new Symbol(SymbolType::INTCONST, compile_state.get_offset(), 0, 0));
            }
        } else {
            int size = 1;
            std::vector<int> dims;
            std::vector<int> values;
            // 局部变量数组
            // std::cout << __LINE__ << std::endl;
            for (auto &dim_size : dim) {
//                compile_state.update_offset(-4 * (dynamic_cast<NumExpAST*>(dim_size)->value));
                size *= dynamic_cast<NumExpAST*>(dim_size)->value;
                dims.push_back(dynamic_cast<NumExpAST*>(dim_size)->value);
            }
            compile_state.update_offset(-4 * size);
            // std::cout << __LINE__ << std::endl;
            if (init_val == nullptr) {
                // std::cout << __LINE__ << std::endl;
                for (int i = 0; i < size; i++) {
                    text.append("\tmovl\t$0, %d(%%rbp)\n", compile_state.get_offset() + i * 4);
                    values.emplace_back(0);
                }
                // std::cout << __LINE__ << std::endl;
                symbol_table.insert(ident, new Symbol(SymbolType::INT_ARRAY, compile_state.get_offset(), 1, dims, values));
            } else {
                // std::cout << __LINE__ << std::endl;
                for (int i = 0; i < size; i++) {
                    text.append("\tmovl\t$%d, %d(%%rbp)\n", dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<InitValListAST*>(init_val->value)->init_vals[i]->value))->value, compile_state.get_offset() + i * 4);
                    values.emplace_back(dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<InitValListAST*>(init_val->value)->init_vals[i]->value))->value);
                }
                symbol_table.insert(ident, new Symbol(SymbolType::INT_ARRAY, compile_state.get_offset(), 1, dims, values));
            }
            // for (int i = 0; i < std::get<InitValListAST*>(init_val->value)->init_vals.size(); i++) {
            //     text.append("\tmovl\t$%d, %d(%%rbp)\n", dynamic_cast<NumExpAST*>(std::get<ExpAST*>(std::get<InitValListAST*>(init_val->value)->init_vals[i]->value))->value, compile_state.get_offset() + i * 4);
            // }
        }
    }
}

void FuncDefAST::code_gen() {
    /* TODO */
    /* 还没想好怎么写 */
    symbol_table.push_scope();
    symbol_table.insert(ident, new Symbol(SymbolType::FUNCTION, return_type));
    text.append(".globl\t%s\n", ident.c_str());
    text.append(".type\t%s, @function\n", ident.c_str());
    text.append("%s:\n", ident.c_str());
    text.append("\tpushq\t%%rbp\n");
    text.append("\tmovq\t%%rsp, %%rbp\n");
    block->code_gen();
    symbol_table.pop_scope();
}

void BlockAST::code_gen() {
    for (auto &block_item : block_items) {
        block_item->code_gen();
    }
}

void BlockItemAST::code_gen() {
    if (std::holds_alternative<DeclAST*>(block_item)) {
        std::get<DeclAST*>(block_item)->code_gen();
    } else {
        std::get<StmtAST*>(block_item)->code_gen();
    }
}

void NullStmtAST::code_gen() {
    /* 何もしない */
}

void AssignStmtAST::code_gen() {

}

void ExpStmtAST::code_gen() {

}

void BlockStmtAST::code_gen() {

}

void IfStmtAST::code_gen() {

}

void WhileStmtAST::code_gen() {

}

void BreakStmtAST::code_gen() {

}

void ContinueStmtAST::code_gen() {

}

void ReturnStmtAST::code_gen() {
    if (exp == nullptr) {
        text.append("\tleave\n");
        text.append("\tret\n");
    } else {
        // std::cout << "in ret stmt" << std::endl;
        if (dynamic_cast<NumExpAST*>(exp)) {
            text.append("\tmovl\t$%d, %%eax\n", dynamic_cast<NumExpAST*>(exp)->value);
        } else if (dynamic_cast<VarExpAST*>(exp)){
            if (dynamic_cast<VarExpAST*>(exp)->dim.empty()) {
                Symbol *var = symbol_table.try_lookup(dynamic_cast<VarExpAST*>(exp)->ident);
                if (var->type == SymbolType::CONST_INT) {
                    text.append("\tmovl\t$%d, %%eax\n", symbol_table.lookup(dynamic_cast<VarExpAST*>(exp)->ident)->const_value);
                } else if (symbol_table.try_lookup(dynamic_cast<VarExpAST*>(exp)->ident)->type == SymbolType::INTCONST){
                    if (var->level == 1) {
                        text.append("\tmovl\t%s(%%rip), %%eax\n", dynamic_cast<VarExpAST*>(exp)->ident.c_str());
                    } else {
                        text.append("\tmovl\t%d(%%rbp), %%eax\n", var->offset);
                    }
                    // text.append("\tmovl\t%s(%%rip), %%eax\n", dynamic_cast<VarExpAST*>(exp)->ident.c_str());
                    // text.append("\tmovl\t%d(%%rbp), %%eax\n", symbol_table.lookup(dynamic_cast<VarExpAST*>(exp)->ident)->offset);
                }
            } else {
                int bias = 0;
                Symbol *array = symbol_table.try_lookup(dynamic_cast<VarExpAST*>(exp)->ident);
                int dim_size = dynamic_cast<VarExpAST*>(exp)->dim.size();
                for (int i = 1; i <= dim_size; i++) {
                    if (i != dim_size) {
                        bias += dynamic_cast<NumExpAST*>(dynamic_cast<VarExpAST*>(exp)->dim[i-1])->value * std::reduce(array->dims.begin() + i, array->dims.end(), 1, std::multiplies<int>());
                    } else {
                        bias += dynamic_cast<NumExpAST*>(dynamic_cast<VarExpAST*>(exp)->dim[i-1])->value;
                    }
                }
                std::cout << bias << std::endl;
                if (array->type == SymbolType::CONST_ARRAY) {
                    text.append("\tmovl\t$%d, %%eax\n", symbol_table.lookup(dynamic_cast<VarExpAST*>(exp)->ident)->const_array_values[bias-1]);
                } else if (array->type == SymbolType::INT_ARRAY) {
                    /* TODO */
                    if (array->level == 1) {
                        text.append("\tmovl\t%s+%d(%%rip), %%eax\n", dynamic_cast<VarExpAST*>(exp)->ident.c_str(), bias * 4);
                    } else {
                        text.append("\tmovl\t%d(%%rbp), %%eax\n", symbol_table.lookup(dynamic_cast<VarExpAST*>(exp)->ident)->offset + bias * 4);
                    }
                }
            }
        } else if (dynamic_cast<BinaryExpAST*>(exp)) {
            dynamic_cast<BinaryExpAST*>(exp)->code_gen();
        } else if (dynamic_cast<UnaryExpAST*>(exp)) {
            dynamic_cast<UnaryExpAST*>(exp)->code_gen();
        } else if (dynamic_cast<FuncCallAST*>(exp)) {
            dynamic_cast<FuncCallAST*>(exp)->code_gen();
        }
        text.append("\tleave\n");
        text.append("\tret\n");
    }
}

void UnaryExpAST::code_gen() {
    // if (dynamic_cast<NumExpAST*>(value)) {
    //     if (op == "-") {
    //         text.append("\tmovl\t$%d, %%eax\n", -dynamic_cast<NumExpAST*>(value)->value);
    //     } else if (op == "!") {
    //         text.append("\tmovl\t$%d, %%eax\n", !dynamic_cast<NumExpAST*>(value)->value);
    //     } else {
    //         text.append("\tmovl\t$%d, %%eax\n", dynamic_cast<NumExpAST*>(value)->value);
    //     }
    // } else if (dynamic_cast<VarExpAST*>(value)) {
        
    // } else if (dynamic_cast<BinaryExpAST*>(value)) {
    //     dynamic_cast<BinaryExpAST*>(value)->code_gen();
    // } else if (dynamic_cast<UnaryExpAST*>(value)) {
    //     dynamic_cast<UnaryExpAST*>(value)->code_gen();
    // } else if (dynamic_cast<FuncCallAST*>(value)) {
    //     dynamic_cast<FuncCallAST*>(value)->code_gen();
    // }
    if (op == "+") {
        value->code_gen();
    } else if (op == "-") {
        if (dynamic_cast<NumExpAST*>(value) || dynamic_cast<VarExpAST*>(value)) {
            value->code_gen();
            text.append("\tnegl\t%%r10d\n");
            offset = text.save_register("%r10d", compile_state);
        } else if (dynamic_cast<BinaryExpAST*>(value)) {
            value->code_gen();
            text.append("\tmovl\t%d(%%rbp), %%r10d\n", value->offset);
            text.append("\tnegl\t%%r10d\n");
            offset = text.save_register("%r10d", compile_state);
        } else if (dynamic_cast<FuncCallAST*>(value)){
            value->code_gen();
            text.append("\tmovl\t%%eax, %%r10d\n");
            text.append("\tnegl\t%%r10d\n");
            offset = text.save_register("%r10d", compile_state);
        }
    } else if (op == "!") {
        value->code_gen();
        text.append("\tcmpl\t$0, %%r10d\n");
        text.append("\tsete\t%%r10b\n");
        text.append("\tmovzbl\t%%r10b, %%r10d\n");
    }
}

void FuncCallAST::code_gen() {
    if (ident == "printf") {
        rodata.append(".section\t.rodata\n");
        if (!compile_state.get_format_string_status(format_output)) {
            compile_state.insert_format_string(format_output);
            rodata.append("\t.format_string%d\t%s", compile_state.get_format_string_count(format_output), format_output.c_str());
        }
        text.append("\tleaq\t.format_string%d(%%rip), %s\n", compile_state.get_format_string_count(format_output), param_regs[0].c_str());
        for (int i = 0; i < r_args.size(); i++) {
            /* TODO */

        }
        text.append("\tcall\tprintf\n");
    } else if (ident == "scanf") {
        rodata.append(".section\t.rodata\n");
        if (!compile_state.get_format_string_status(format_output)) {
            compile_state.insert_format_string(format_output);
            rodata.append("\t.format_string%d\t%s", compile_state.get_format_string_count(format_output), format_output.c_str());
        }
        text.append("\tleaq\t.format_string%d(%%rip), %s\n", compile_state.get_format_string_count(format_output), param_regs[0].c_str());  
        for (int i = 0; i < r_args.size(); i++) {
            /* TODO */
        }
        text.append("\tcall\tscanf\n");
    } else {
        for (int i = 0; i < r_args.size(); i++) {
            /* TODO */

        }
        text.append("\tcall\t%s\n", ident.c_str());
    }

}

void BinaryExpAST::code_gen() {
    if (op == "+") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\taddl\t%%r9d, %%r8d\n");
        offset = text.save_register("%r8d", compile_state);
        // text.append("\tmovl\t%%r8d, %%eax\n");
    } else if (op == "-") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tsubl\t%%r9d, %%r8d\n");
        offset = text.save_register("%r8d", compile_state);
        // text.append("\tmovl\t%%r8d, %%eax\n");
    } else if (op == "*") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\timull\t%%r9d, %%r8d\n");
        offset = text.save_register("%r8d", compile_state);
        // text.append("\tmovl\t%%r8d, %%eax\n");
    } else if (op == "/") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%eax\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcltd\n");
        text.append("\tidivl\t%%r9d\n"); 
        offset = text.save_register("%eax", compile_state);
        // text.append("\tmovl\t%%eax, %%eax\n");
    } else if (op == "%") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%eax\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcltd\n");
        text.append("\tidivl\t%%r9d\n");
        offset = text.save_register("%edx", compile_state);
        // text.append("\tmovl\t%%edx, %%eax\n");
    } else if (op == "<") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcmpl\t%%r9d, %%r8d\n");
        /* TODO */
        text.append("\tjl\t.L\n");
        true_list.emplace_back(text.get_line());
        text.append("\tjmp\t.L\n");
        false_list.emplace_back(text.get_line());
    } else if (op == ">") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcmpl\t%%r9d, %%r8d\n");
        text.append("\tjg\t.L\n");
        true_list.emplace_back(text.get_line());
        text.append("\tjmp\t.L\n");
        false_list.emplace_back(text.get_line());
        /* TODO */
    } else if (op == "<=") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcmpl\t%%r9d, %%r8d\n");
        text.append("\tjle\t.L\n");
        true_list.emplace_back(text.get_line());
        text.append("\tjmp\t.L\n");
        false_list.emplace_back(text.get_line());
        /* TODO */
    } else if (op == ">=") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcmpl\t%%r9d, %%r8d\n");
        text.append("\tjge\t.L\n");
        true_list.emplace_back(text.get_line());
        text.append("\tjmp\t.L\n");
        false_list.emplace_back(text.get_line());
        /* TODO */
    } else if (op == "==") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcmpl\t%%r9d, %%r8d\n");
        text.append("\tje\t.L\n");
        true_list.emplace_back(text.get_line());
        text.append("\tjmp\t.L\n");
        false_list.emplace_back(text.get_line());
        /* TODO */
    } else if (op == "!=") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r9d\n");
        text.append("\tcmpl\t%%r9d, %%r8d\n");
        text.append("\tjne\t.L\n");
        true_list.emplace_back(text.get_line());
        text.append("\tjmp\t.L\n");
        false_list.emplace_back(text.get_line());
        /* TODO */
    } else if (op == "&&") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        text.append("\ttestl\t%%r8d, %%r8d\n");
        text.append("\tjz\t.L");
        false_list.emplace_back(text.get_line());
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        text.append("\ttestl\t%%r8d, %%r8d\n");
        text.append("\tjz\t.L");
        false_list.emplace_back(text.get_line());
        true_list.emplace_back(text.get_line());
        // text.append("\tjz\t.L%d\n", compile_state.get_label_count());
    } else if (op == "||") {
        lhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        text.append("\ttestl\t%%r8d, %%r8d\n");
        text.append("\tjnz\t.L");
        true_list.emplace_back(text.get_line());
        rhs->code_gen();
        text.append("\tmovl\t%%r10d, %%r8d\n");
        text.append("\ttestl\t%%r8d, %%r8d\n");
        text.append("\tjnz\t.L");
        true_list.emplace_back(text.get_line());
        false_list.emplace_back(text.get_line());
    }
}

void NumExpAST::code_gen() {
    text.append("\tmovl\t$%d, %%r10d\n", value);
}

void VarExpAST::code_gen() {
    if (dim.empty()) {
        Symbol *var = symbol_table.try_lookup(ident);
        if (var->type == SymbolType::CONST_INT) {
            text.append("\tmovl\t$%d, %%r10d\n", var->const_value);
        } else if (var->type == SymbolType::INTCONST) {
            if (var->level == 1) {
                text.append("\tmovl\t%s(%%rip), %%r10d\n", ident.c_str());
            } else {
                text.append("\tmovl\t%d(%%rbp), %%r10d\n", var->offset);
            }
        }
    } else {
        // 有问题 VarExpAST的维度是表达式，不一定是字面值常量
        Symbol *array = symbol_table.try_lookup(ident);
        int dim_size = dim.size();
        text.append("\tmovl\t$0, %%r11d\n");
        for (int i = 1; i <= dim_size; i++) {
            if (i != dim_size) {
                dim[i-1]->code_gen();
                text.append("\timull\t$%d, %%r11d\n", std::reduce(array->dims.begin() + i, array->dims.end(), 1, std::multiplies<int>()));
                text.append("\taddl\t%%r10d, %%r11d\n");
            } else {
                dim[i-1]->code_gen();
                text.append("\taddl\t%%r10d, %%r11d\n");
            }
        }
        if (array->type == SymbolType::CONST_ARRAY) {
            text.append("\tleaq\t%s(%rip), %%rsi\n", ident.c_str());
            text.append("\tshll\t$2, %%r11d\n");
//            text.append("\tcltq\n");
            text.append("\taddq\t%%rsi, %%r11\n");
            text.append("\tmovl\t(%%rsi), %%r10d\n");
        } else {
            if (array->level == 1) {
                text.append("\tleaq\t%s(%%rip), %%rsi", ident.c_str());
                text.append("\tshll\t$2, %%r11d\n");
//                text.append("\tcltq\n");
                text.append("\taddq\t%%rsi, %%r11\\n");
                text.append("\tmovl\t(%%rsi), %%r10d\n");
            } else {
                text.append("\tleaq\t%d(%%rbp), %%rsi\n", array->offset);
                text.append("\tshll\t$2, %%r11d\n");
//                text.append("\tcltq\n");
                text.append("\taddq\t%%rsi, %%r11\n");
                text.append("\tmovl\t(%%rsi), %%r10d\n");
            }
        }
//        int bias = 0;
//        Symbol *array = symbol_table.try_lookup(ident);
//        int dim_size = dim.size();
//        for (int i = 1; i <= dim_size; i++) {
//            if (i != dim_size) {
//                bias += dynamic_cast<NumExpAST*>(dim[i-1])->value * std::reduce(array->dims.begin() + i, array->dims.end(), 1, std::multiplies<int>());
//            } else {
//                bias += dynamic_cast<NumExpAST*>(dim[i-1])->value;
//            }
//        }
//        if (array->type == SymbolType::CONST_ARRAY) {
//            text.append("\tmovl\t$%d, %%r10d\n", symbol_table.lookup(ident)->const_array_values[bias-1]);
//        } else if (array->type == SymbolType::INT_ARRAY) {
//            if (array->level == 1) {
//                text.append("\tmovl\t%s+%d(%%rip), %%r10d\n", ident.c_str(), bias * 4);
//            } else {
//                text.append("\tmovl\t%d(%%rbp), %%r10d\n", symbol_table.lookup(ident)->offset + bias * 4);
//            }
//        }
    }
}