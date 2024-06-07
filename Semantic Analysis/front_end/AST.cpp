#include "AST.hpp"
#include <iostream>

void show_ast(BaseAST *ast, int depth) {
  std::string indent(depth * 4, ' '); // 缩进

  // 根据AST节点类型进行相应的处理
  if (dynamic_cast<CompUnitAST *>(ast)) {
    auto node = dynamic_cast<CompUnitAST *>(ast);
    std::cout << indent << "CompUnitAST" << std::endl;
    for (auto external_def : node->external_defs) {
      show_ast(external_def, depth + 1);
    }
    for (auto decl : node->decls) {
      show_ast(decl, depth + 1);
    }
    for (auto func_def : node->func_defs) {
      show_ast(func_def, depth + 1);
    }

  } else if (dynamic_cast<ExternalDefAST *>(ast)) {
    auto node = dynamic_cast<ExternalDefAST *>(ast);
    std::cout << indent << "ExternalDefAST: " << node->value << std::endl;

  } else if (dynamic_cast<DeclAST *>(ast)) {
    auto node = dynamic_cast<DeclAST *>(ast);
    std::cout << indent << "DeclAST" << std::endl;
    if (std::holds_alternative<ConstDeclAST *>(node->decl)) {
      show_ast(std::get<ConstDeclAST *>(node->decl), depth + 1);
    } else {
      show_ast(std::get<VarDeclAST *>(node->decl), depth + 1);
    }

  } else if (dynamic_cast<ConstDeclAST *>(ast)) {
    auto node = dynamic_cast<ConstDeclAST *>(ast);
    std::cout << indent << "ConstDeclAST" << std::endl;
    for (auto const_def : node->const_defs) {
      show_ast(const_def, depth + 1);
    }

  } else if (dynamic_cast<ConstDefAST *>(ast)) {
    auto node = dynamic_cast<ConstDefAST *>(ast);
    std::cout << indent << "ConstDefAST: " << node->ident << std::endl;
    for (auto exp : node->dim) {
      show_ast(exp, depth + 1);
    }
    if (node->const_init_val) {
      show_ast(node->const_init_val, depth + 1);
    }

  } else if (dynamic_cast<ConstInitValAST *>(ast)) {
    auto node = dynamic_cast<ConstInitValAST *>(ast);
    std::cout << indent << "ConstInitValAST" << std::endl;
    if (std::holds_alternative<ExpAST *>(node->value)) {
      show_ast(dynamic_cast<NumExpAST*>(std::get<ExpAST *>(node->value)), depth + 1);
    } else if (std::holds_alternative<ConstInitValListAST *>(node->value)){
        for (auto const_init_val_list : std::get<ConstInitValListAST *>(node->value)->const_init_vals) {
            show_ast(const_init_val_list, depth + 1);
        }
    } else {
        std::cout << indent + std::string(4, ' ') << "ConstInitValAST" << std::endl;
        std::cout << indent + std::string(8, ' ') << "{}" << std::endl;
    }

  } else if (dynamic_cast<ConstInitValListAST *>(ast)) {
    auto node = dynamic_cast<ConstInitValListAST *>(ast);
    std::cout << indent << "ConstInitValListAST" << std::endl;
    for (auto const_init_val : node->const_init_vals) {
      show_ast(const_init_val, depth + 1);
    }

  } else if (dynamic_cast<VarDeclAST *>(ast)) {
    auto node = dynamic_cast<VarDeclAST *>(ast);
    std::cout << indent << "VarDeclAST" << std::endl;
    for (auto var_def : node->var_defs) {
      show_ast(var_def, depth + 1);
    }

  } else if (dynamic_cast<VarDefAST *>(ast)) {
    auto node = dynamic_cast<VarDefAST *>(ast);
    std::cout << indent << "VarDefAST: " << node->ident << std::endl;
    for (auto exp : node->dim) {
      show_ast(exp, depth + 1);
    }
    if (node->init_val) {
      show_ast(node->init_val, depth + 1);
    }

  } else if (dynamic_cast<InitValAST *>(ast)) {
    auto node = dynamic_cast<InitValAST *>(ast);
    std::cout << indent << "InitValAST" << std::endl;
    if (std::holds_alternative<ExpAST *>(node->value)) {
      show_ast(std::get<ExpAST *>(node->value), depth + 1);
    } else if (std::holds_alternative<InitValListAST *>(node->value)){
    //   show_ast(std::get<InitValListAST *>(node->value), depth + 1);
        for (auto init_val_list : std::get<InitValListAST *>(node->value)->init_vals) {
            show_ast(init_val_list, depth + 1);
        }
    } else {
        std::cout << indent + std::string(4, ' ') << "InitValAST" << std::endl;
        std::cout << indent + std::string(8, ' ') << "{ }" << std::endl;
    }

  } else if (dynamic_cast<InitValListAST *>(ast)) {
    auto node = dynamic_cast<InitValListAST *>(ast);
    std::cout << indent << "InitValListAST" << std::endl;
    for (auto init_val : node->init_vals) {
      show_ast(init_val, depth + 1);
    }

  } else if (dynamic_cast<FuncDefAST *>(ast)) {
    auto node = dynamic_cast<FuncDefAST *>(ast);
    std::cout << indent << "FuncDefAST: " << node->ident << std::endl;
    for (auto f_arg : node->f_args) {
      show_ast(f_arg, depth + 1);
    }
    show_ast(node->block, depth + 1);

  } else if (dynamic_cast<FuncFParamAST *>(ast)) {
    auto node = dynamic_cast<FuncFParamAST *>(ast);
    std::cout << indent << "FuncFParamAST: " << node->ident << std::endl;
    for (auto exp : node->dim) {
      show_ast(exp, depth + 1);
    }

  } else if (dynamic_cast<BlockAST *>(ast)) {
    auto node = dynamic_cast<BlockAST *>(ast);
    std::cout << indent << "BlockAST" << std::endl;
    for (auto block_item : node->block_items) {
      show_ast(block_item, depth + 1);
    }

  } else if (dynamic_cast<BlockItemAST *>(ast)) {
    auto node = dynamic_cast<BlockItemAST *>(ast);
    std::cout << indent << "BlockItemAST" << std::endl;
    if (std::holds_alternative<StmtAST *>(node->block_item)) {
      show_ast(std::get<StmtAST *>(node->block_item), depth + 1);
    } else {
      show_ast(std::get<DeclAST *>(node->block_item), depth + 1);
    }

  } else if (dynamic_cast<AssignStmtAST *>(ast)) {
    auto node = dynamic_cast<AssignStmtAST *>(ast);
    std::cout << indent << "AssignStmtAST" << std::endl;
    show_ast(node->lvalue, depth + 1);
    show_ast(node->rvalue, depth + 1);

  } else if (dynamic_cast<NullStmtAST *>(ast)) {
    std::cout << indent << "NullStmtAST" << std::endl;

  } else if (dynamic_cast<ExpStmtAST *>(ast)) {
    auto node = dynamic_cast<ExpStmtAST *>(ast);
    std::cout << indent << "ExpStmtAST" << std::endl;
    show_ast(node->exp, depth + 1);

  } else if (dynamic_cast<BlockStmtAST *>(ast)) {
    auto node = dynamic_cast<BlockStmtAST *>(ast);
    std::cout << indent << "BlockStmtAST" << std::endl;
    for (auto block_item : node->block_items) {
      show_ast(block_item, depth + 1);
    }

  } else if (dynamic_cast<IfStmtAST *>(ast)) {
    auto node = dynamic_cast<IfStmtAST *>(ast);
    std::cout << indent << "IfStmtAST" << std::endl;
    show_ast(node->cond, depth + 1);
    show_ast(node->then_stmt, depth + 1);
    if (node->else_stmt) {
      show_ast(node->else_stmt, depth + 1);
    }

  } else if (dynamic_cast<WhileStmtAST *>(ast)) {
    auto node = dynamic_cast<WhileStmtAST *>(ast);
    std::cout << indent << "WhileStmtAST" << std::endl;
    show_ast(node->cond, depth + 1);
    show_ast(node->stmt, depth + 1);

  } else if (dynamic_cast<BreakStmtAST *>(ast)) {
    std::cout << indent << "BreakStmtAST" << std::endl;

  } else if (dynamic_cast<ContinueStmtAST *>(ast)) {
    std::cout << indent << "ContinueStmtAST" << std::endl;

  } else if (dynamic_cast<ReturnStmtAST *>(ast)) {
    auto node = dynamic_cast<ReturnStmtAST *>(ast);
    std::cout << indent << "ReturnStmtAST" << std::endl;
    if (node->exp) {
      show_ast(node->exp, depth + 1);
    }

  } else if (dynamic_cast<LValAST *>(ast)) {
    auto node = dynamic_cast<LValAST *>(ast);
    std::cout << indent << "LValAST: " << node->ident << std::endl;
    for (auto exp : node->dim) {
      show_ast(exp, depth + 1);
    }

  } else if (dynamic_cast<BinaryExpAST *>(ast)) {
    auto node = dynamic_cast<BinaryExpAST *>(ast);
    std::cout << indent << "BinaryExpAST: " << node->op << std::endl;
    show_ast(node->lhs, depth + 1);
    show_ast(node->rhs, depth + 1);

  } else if (dynamic_cast<VarExpAST *>(ast)) {
    auto node = dynamic_cast<VarExpAST *>(ast);
    std::cout << indent << "VarExpAST: " << node->ident << std::endl;
    for (auto exp : node->dim) {
      show_ast(exp, depth + 1);
    }

  } else if (dynamic_cast<NumExpAST *>(ast)) {
    auto node = dynamic_cast<NumExpAST *>(ast);
    std::cout << indent << "NumExpAST: " << node->value << std::endl;

  } else if (dynamic_cast<UnaryExpAST *>(ast)) {
    auto node = dynamic_cast<UnaryExpAST *>(ast);
    std::cout << indent << "UnaryExpAST: " << node->op << std::endl;
    show_ast(node->value, depth + 1);

  } else if (dynamic_cast<FuncCallAST *>(ast)) {
    auto node = dynamic_cast<FuncCallAST *>(ast);
    std::cout << indent << "FuncCallAST: " << node->ident << std::endl;
    if (node->r_args[0] == nullptr) {
        std::cout << indent << "No Args" << std::endl;
    } else {
        if (node->format_output != "") {
            std::cout << indent << "\tformat output: " << node->format_output << std::endl;
        }
        for (auto r_arg : node->r_args) {
        show_ast(r_arg, depth + 1);
        }
    }

  } else if (dynamic_cast<ArrDefAST *>(ast)) {
    auto node = dynamic_cast<ArrDefAST *>(ast);
    std::cout << indent << "ArrDefAST" << std::endl;
    for (auto exp : node->dim) {
      show_ast(exp, depth + 1);
    }

  } else if (dynamic_cast<FuncRParamsAST *>(ast)) {
    auto node = dynamic_cast<FuncRParamsAST *>(ast);
    std::cout << indent << "FuncRParamsAST" << std::endl;
    if (node->str != "") {
      std::cout << indent << "format output: " << node->str << std::endl;
    }
    for (auto r_arg : node->r_args) {
      show_ast(r_arg, depth + 1);
    }

  } else {
    std::cout << indent << "Unknown AST Node Type" << std::endl;
  }
}
BaseAST *root;