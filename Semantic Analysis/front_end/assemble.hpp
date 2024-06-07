#pragma once
#include <vector>
#include <string>
#include <cstdarg>
#include "AST.hpp"
#include "compile_state.hpp"

// extern SymbolTable symbol_table;

class Assemble {
public:
    std::vector<std::string> code;

    void append(const char *format, ...);
    void print_info(FILE *file);
    void var_initialize(CompUnitAST* node);
    void load_register(ExpAST* exp, std::string reg);
    int save_register(std::string reg, CompileState &compile_state);
    int get_line();
};

void assemble_init();

void assemble_print(FILE *file);

// void Assemble::var_initialize(CompUnitAST* node) {
//     for (auto &decl : node->decls) {
//         if (decl->var_decl != nullptr && decl->const_decl == nullptr) {
//             for (auto &var_def : decl->var_decl->var_defs) {
//                 if(symbol_table.lookup(var_def->ident) != nullptr) {
//                     throw std::runtime_error("Variable " + var_def->ident + " already declared in this scope");
//                 }else {
//                     symbol_table.insert(var_def->ident, new Symbol(SymbolType::INTCONST, 0, 0));
//                     data.append("%s:\n", var_def->ident.c_str());
//                     data.append(".int 0\n");
//                 }
//             }
//         }else if (decl->const_decl != nullptr && decl->var_decl == nullptr) {
//             for (auto &const_def : decl->const_decl->const_defs) {
//                 if(symbol_table.lookup(const_def->ident) != nullptr) {
//                     throw std::runtime_error("Variable " + const_def->ident + " already declared in this scope");
//                 }else {
//                     symbol_table.insert(const_def->ident, new Symbol(SymbolType::CONST_INT, 0, const_def->value));
//                     rodata.append("%s:\n", const_def->ident.c_str());
//                     rodata.append(".int %d\n", const_def->value);
//                 }
//             }
//         }
//     }
// }