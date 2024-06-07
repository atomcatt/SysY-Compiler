#pragma once
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "log.hpp"

extern Log logger;

enum class SymbolType {
    FUNCTION, 
    INTCONST, 
    INT_ARRAY, 
    CONST_INT, 
    CONST_ARRAY ,
    STRING
};

class Symbol {
public:
    SymbolType type;
    bool return_type;
    int offset;
    bool is_array;
    int const_value;
    int level;
    std::vector<int> dims;
    std::vector<int> const_array_values;

    Symbol() : type(SymbolType::INTCONST), offset(0), const_value(0) {}
    Symbol(SymbolType _type, int _offset, bool _is_array, int _const_value) : type(_type), offset(_offset), is_array(_is_array), const_value(_const_value) {}
    Symbol(SymbolType _type, int _offset, bool _is_array, std::vector<int> _const_array_values) : type(_type), offset(_offset), is_array(_is_array), const_array_values(_const_array_values) {}
    Symbol(SymbolType _type, int _offset, bool _is_array, std::vector<int> _dims, std::vector<int> _const_array_values) : type(_type), offset(_offset), is_array(_is_array), dims(_dims), const_array_values(_const_array_values) {}
    Symbol(SymbolType _type, int _return_type) : type(_type), return_type(_return_type) {} // 函数
};

class SymbolTable {
    std::vector<std::map<std::string, Symbol *>> symbol_table_stack;
public:
    SymbolTable() {
        logger.log("sym_table") << "new symbol table" << std::endl;
        symbol_table_stack.emplace_back();
    }
    int get_level();
    void push_scope();
    void pop_scope();
    void insert(const std::string &name, Symbol *symbol);
    Symbol* try_lookup(const std::string &name);
    Symbol* lookup(const std::string &name);
};