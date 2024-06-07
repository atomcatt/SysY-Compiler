#include "assemble.hpp"
#include "AST.hpp"
#include <vector>
#include <string>
#include <numeric>
#include "symbol_table.hpp"

/** 汇编语言中的段
  * .rodata 只读数据段，存放C中的字符串和#define定义的常量
  * .data 数据段，用来存放程序中已初始化的全局变量的一块内存区域
  * .bss 未初始化数据段
  * .text 代码段
*/
Assemble rodata, data, bss, text;
extern SymbolTable* symbol_table;
std::vector<std::string> param_regs = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
void Assemble::append(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[1024];
    vsnprintf(buffer, 1024, format, args);
    code.push_back(buffer);
    va_end(args);
    // code.push_back(buffer);
}

void Assemble::print_info(FILE *file) {
    for(auto &line : code) {
        fprintf(file, "%s", line.c_str());
    }
}

void Assemble::load_register(ExpAST* exp, std::string reg) {
    if (dynamic_cast<NumExpAST*>(exp)) {
        append("\tmovl\t$%d, %s\n", dynamic_cast<NumExpAST*>(exp)->value, reg.c_str());
    }
    if (dynamic_cast<VarExpAST*>(exp)) {
        Symbol *symbol = symbol_table->lookup(dynamic_cast<VarExpAST*>(exp)->ident);
        if (symbol->type == SymbolType::CONST_INT) {
            if (symbol->is_array) {
                int bias = 0;
                int dim_size = dynamic_cast<VarExpAST*>(exp)->dim.size();
                for (int i = 1; i <= dim_size; i++) {
                    if (i != dim_size) {
                        bias += dynamic_cast<NumExpAST*>(dynamic_cast<VarExpAST*>(exp)->dim[i-1])->value * std::reduce(symbol->dims.begin() + i, symbol->dims.end(), 1, std::multiplies<int>());
                    } else {
                        bias += dynamic_cast<NumExpAST*>(dynamic_cast<VarExpAST*>(exp)->dim[i-1])->value;
                    }
                }
                append("\tmovl\t$%d, %s\n", symbol->const_array_values[bias - 1], reg.c_str());
            } else {
                append("\tmovl\t$%d, %s\n", symbol->const_value, reg.c_str());
            }
        } else {
            if (symbol->level == 1) {
                append("\tmovl\t%s(%%rip), %s\n", dynamic_cast<VarExpAST*>(exp)->ident.c_str(), reg.c_str());
            } else {
                append("\tmovl\t%s(%%rbp), %s\n", dynamic_cast<VarExpAST*>(exp)->ident.c_str(), reg.c_str());
            }
        }
    }
    if (dynamic_cast<BinaryExpAST*>(exp)) {

    }
}

int Assemble::get_line() {
    return code.size() - 1;
}


int Assemble::save_register(std::string reg, CompileState &compile_state) {
    compile_state.update_offset(-4);
    append("\tmovl\t%s, %d(%%rbp)\n", reg.c_str(), compile_state.get_offset());
    return compile_state.get_offset();
}

void assemble_init() {
    rodata.append(".section .rodata\n");
    data.append(".section .data\n");
    bss.append(".section .bss\n");
    text.append(".section .text\n");
}

void assemble_print(FILE *file) {
    rodata.print_info(file);
    data.print_info(file);
    bss.print_info(file);
    text.print_info(file);
}