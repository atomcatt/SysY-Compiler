#include "AST.hpp"
#include "const_eval_helper.hpp"
#include "symbol_table.hpp"
#include <typeinfo>
#include <variant>
#include <type_traits>
#include <numeric>

using namespace ConstEvalHelper;

SymbolTable const_eval_symbol_table;

void CompUnitAST::const_eval(BaseAST *&root) {
    std::cout << "CompUnitAST::const_eval() start" << std::endl;
    for (DeclAST* decl : decls) {
        const_eval_helper(decl);
    }
    for (FuncDefAST* func_def : func_defs) {
        const_eval_helper(func_def);
    }
}

void DeclAST::const_eval(BaseAST *&root) {
    std::cout << "DeclAST::const_eval() start" << std::endl;
    if (std::holds_alternative<ConstDeclAST*>(decl)) {
        const_eval_helper(std::get<ConstDeclAST*>(decl));
    } else {
        const_eval_helper(std::get<VarDeclAST*>(decl));
    }
}

void ConstDeclAST::const_eval(BaseAST *&root) {
    std::cout << "ConstDeclAST::const_eval() start" << std::endl;
    for (ConstDefAST* const_def : const_defs) {
        for (ExpAST*& exp : const_def->dim) {
            const_eval_helper(exp);
            std::cout << "dim is " << dynamic_cast<NumExpAST*>(exp)->value << std::endl;

            array_dim_check(exp);
            // for (auto &dim : const_def->dim) {
            //     auto num_exp = dynamic_cast<NumExpAST*>(dim);
            //     std::cout << "num_exp->value: " << num_exp->value << std::endl;
            // }
        }
        if (!const_def->const_init_val) {
            throw std::runtime_error("constant variable must be initialized");
        }
        std::cout << "const_def->ident: " << const_def->ident << std::endl;
        for (auto dim : const_def->dim) {
            std::cout << "const_def->dim: " << static_cast<NumExpAST*>(dim)->value << std::endl;
        }
        fix_nested_array(const_def->const_init_val, const_def->dim);
        const_eval_helper(const_def->const_init_val);
        const_initializer_assert(const_def->const_init_val);
        if (const_def->dim.empty()) {
            auto num_exp = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_def->const_init_val->value));
            const_eval_symbol_table.insert(const_def->ident, new Symbol(SymbolType::CONST_INT, 0, 0, num_exp->value));
        } else {
            std::vector<int> const_array_values;
            auto const_init_val_list = std::get<ConstInitValListAST*>(const_def->const_init_val->value);
            for (ConstInitValAST* const_init_val : const_init_val_list->const_init_vals) {
                if (std::holds_alternative<ExpAST*>(const_init_val->value)) {
                    // const std::type_info &type = typeid(const_init_val->value);
                    // std::cout << type.name() << std::endl;
                    auto num_exp = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value));
                    const_array_values.push_back(num_exp->value);
                } else {
                    const std::type_info &type = typeid(const_init_val->value);
                    std::cout << type.name() << std::endl;  
                    auto const_init_val_list = std::get<ConstInitValListAST*>(const_init_val->value);
                    for (ConstInitValAST* const_init_val : const_init_val_list->const_init_vals) {
                        if(std::holds_alternative<ExpAST*>(const_init_val->value)) { std::cout << "ExpAST*" << std::endl;}
                        else { std::cout << "ConstInitValListAST*" << std::endl;}
                        auto num_exp = dynamic_cast<NumExpAST*>(std::get<ExpAST*>(const_init_val->value));
                        std::cout << "num_exp->value: " << num_exp->value << std::endl;
                        const_array_values.push_back(num_exp->value);
                    }
                }
            }
            const_eval_symbol_table.insert(const_def->ident, new Symbol(SymbolType::CONST_ARRAY, 0, 1, const_array_values));
        }
    }
}

void VarDeclAST::const_eval(BaseAST *&root) {
    std::cout << "VarDeclAST::const_eval() start" << std::endl;
    for (VarDefAST* var_def : var_defs) {
        for (ExpAST*& exp : var_def->dim) {
            const_eval_helper(exp);
            array_dim_check(exp);
        }
        if (!var_def->init_val) {
            continue;
        }
        fix_nested_array(var_def->init_val, var_def->dim);
        const_eval_helper(var_def->init_val);
        initializer_type_fix(var_def->init_val);
    }
}

void ConstInitValAST::const_eval(BaseAST *&root) {
    std::cout << "ConstInitValAST::const_eval() start" << std::endl;
    if (std::holds_alternative<ExpAST*>(value)) {
        const_eval_helper(std::get<ExpAST*>(value));
    } else {
        const_eval_helper(std::get<ConstInitValListAST*>(value));
    }
}

void ConstInitValListAST::const_eval(BaseAST *&root) {
    std::cout << "ConstInitValListAST::const_eval() start" << std::endl;
    for (ConstInitValAST* const_init_val : const_init_vals) {
        const_eval_helper(const_init_val);
    }
}

void InitValAST::const_eval(BaseAST *&root) {
    std::cout << "InitValAST::const_eval() start" << std::endl;
    if (std::holds_alternative<ExpAST*>(value)) {
        const_eval_helper(std::get<ExpAST*>(value));
    } else {
        const_eval_helper(std::get<InitValListAST*>(value));
    }
}

void InitValListAST::const_eval(BaseAST *&root) {
    std::cout << "InitValListAST::const_eval() start" << std::endl;
    for (InitValAST* init_val : init_vals) {
        const_eval_helper(init_val);
    }
}

void FuncFParamAST::const_eval(BaseAST *&root) {
    std::cout << "FuncFParamAST::const_eval() start" << std::endl;
    for (ExpAST *&exp : dim) {
        if (!exp) {
            continue;
        }
        const_eval_helper(exp);
        array_dim_check(exp);
    }
}

void BlockAST::const_eval(BaseAST *&root) {
    std::cout << "BlockAST::const_eval() start" << std::endl;
    for (BlockItemAST *&block_item : block_items) {
        const_eval_helper(block_item);
    }
}

void BlockItemAST::const_eval(BaseAST *&root) {
    std::cout << "BlockItemAST::const_eval() start" << std::endl;
    if (std::holds_alternative<DeclAST*>(block_item)) {
        const_eval_helper(std::get<DeclAST*>(block_item));
    } else {
        const_eval_helper(std::get<StmtAST*>(block_item));
    }
}

void FuncDefAST::const_eval(BaseAST *&root) {
    std::cout << "FuncDefAST::const_eval() start" << std::endl;
    const_eval_symbol_table.push_scope();
    for (FuncFParamAST *&f_arg : f_args) {
        const_eval_helper(f_arg);
    }
    const_eval_helper(block);
    const_eval_symbol_table.pop_scope();
}

void NullStmtAST::const_eval(BaseAST *&root) {
    std::cout << "NullStmtAST::const_eval() start" << std::endl;
    // なにも出来ません　TAT
}

void AssignStmtAST::const_eval(BaseAST *&root) {
    std::cout << "AssignStmtAST::const_eval() start" << std::endl;
    // なにも出来なかった　TAT
}

void ExpStmtAST::const_eval(BaseAST *&root) {
    std::cout << "ExpStmtAST::const_eval() start" << std::endl;
    // なにも出来ない　TAT
}

void BlockStmtAST::const_eval(BaseAST *&root) {
    std::cout << "BlockStmtAST::const_eval() start" << std::endl;
    const_eval_symbol_table.push_scope();
    for (BlockItemAST *&block_item : block_items) {
        const_eval_helper(block_item);
    }
    const_eval_symbol_table.pop_scope();
}

void IfStmtAST::const_eval(BaseAST *&root) {
    std::cout << "IfStmtAST::const_eval() start" << std::endl;
    const_eval_helper(then_stmt);
    if(else_stmt) {
        const_eval_helper(else_stmt);
    }
}

void WhileStmtAST::const_eval(BaseAST *&root) {
    std::cout << "WhileStmtAST::const_eval() start" << std::endl;
    const_eval_helper(stmt);
}

void BreakStmtAST::const_eval(BaseAST *&root) {
    std::cout << "BreakStmtAST::const_eval() start" << std::endl;
    // なにも出来ない　TAT
}

void ContinueStmtAST::const_eval(BaseAST *&root) {
    std::cout << "ContinueStmtAST::const_eval() start" << std::endl;
    // なにも出来ない　TAT
}

void ReturnStmtAST::const_eval(BaseAST *&root) {
    std::cout << "ReturnStmtAST::const_eval() start" << std::endl;
    // なにも出来ない　TAT
}

void UnaryExpAST::const_eval(BaseAST *&root) {
    std::cout << "UnaryExpAST::const_eval() start" << std::endl;
    const_eval_helper(value);
    if(op == std::string("+")) {
        root = value;
        return ;
    }
    if(op == std::string("-")) {
        auto num_exp = dynamic_cast<NumExpAST*>(value);
        if(!num_exp) {
            return ;
        }
        root = new NumExpAST(-(num_exp->value));
    }
}

void FuncCallAST::const_eval(BaseAST *&root) {
    std::cout << "FuncCallAST::const_eval() start" << std::endl;
    // なにも出来ない　TAT
}

void BinaryExpAST::const_eval(BaseAST *&root) {
    std::cout << "BinaryExpAST::const_eval() start" << std::endl;
    const_eval_helper(lhs);
    const_eval_helper(rhs);
    auto lhs_num_exp = dynamic_cast<NumExpAST*>(lhs);
    auto rhs_num_exp = dynamic_cast<NumExpAST*>(rhs);
    // std::cout << "lhs_num_exp value is " << lhs_num_exp->value << " and " << "rhs_num_exp value is " << rhs_num_exp->value << std::endl;
    if (!lhs_num_exp || !rhs_num_exp) {
        return ;
    }
    if (op == std::string("+")) {
        root = new NumExpAST(lhs_num_exp->value + rhs_num_exp->value);
        std::cout << "root value is " << dynamic_cast<NumExpAST*>(root)->value << std::endl;
        return ;
    } else if (op == std::string("-")) {
        root = new NumExpAST(lhs_num_exp->value - rhs_num_exp->value);
        return ;
    } else if (op == std::string("*")) {
        root = new NumExpAST(lhs_num_exp->value * rhs_num_exp->value);
        return ;
    } else if (op == std::string("/")) {
        root = new NumExpAST(lhs_num_exp->value / rhs_num_exp->value);
        return ;
    } else if (op == std::string("%")) {
        root = new NumExpAST(lhs_num_exp->value % rhs_num_exp->value);
        return ;
    } else if (op == std::string("==")) {
        root = new NumExpAST(lhs_num_exp->value == rhs_num_exp->value);
        return ;
    } else if (op == std::string("!=")) {
        root = new NumExpAST(lhs_num_exp->value != rhs_num_exp->value);
        return ;
    } else if (op == std::string("<")) {
        root = new NumExpAST(lhs_num_exp->value < rhs_num_exp->value);
        return ;
    } else if (op == std::string("<=")) {
        root = new NumExpAST(lhs_num_exp->value <= rhs_num_exp->value);
        return ;
    } else if (op == std::string(">")) {
        root = new NumExpAST(lhs_num_exp->value > rhs_num_exp->value);
        return ;
    } else if (op == std::string(">=")) {
        root = new NumExpAST(lhs_num_exp->value >= rhs_num_exp->value);
        return ;
    } else if (op == std::string("&&")) {
        root = new NumExpAST(lhs_num_exp->value && rhs_num_exp->value);
        return ;
    } else if (op == std::string("||")) {
        root = new NumExpAST(lhs_num_exp->value || rhs_num_exp->value);
        return ;
    } else {
        throw std::runtime_error("Unknown binary operator");
    }
}

void NumExpAST::const_eval(BaseAST *&) {
    std::cout << "NumExpAST::const_eval() start" << std::endl;
    // なにも出来ない　TAT
}

void VarExpAST::const_eval(BaseAST *&root) {
    std::cout << "VarExpAST::const_eval() start" << std::endl;
    auto symbol = const_eval_symbol_table.try_lookup(ident);
    // std::cout << "ident: " << ident << ": " << symbol->const_value << std::endl;
    if (!symbol) {
        // std::cout << "symbol is null" << std::endl;
        return ;
    }
    auto value = symbol->const_value;
    // std::cout << "value: " << value << std::endl;
    // std::cout << "root: "<< root << std::endl;
    root = new NumExpAST(value);
}