#include "symbol_table.hpp"
#include <iostream>
#include <string>
int SymbolTable::get_level() {
    return symbol_table_stack.size();
}

void SymbolTable::push_scope() {
    size_t level = get_level();
    logger.log("sym_table") << "[" << level << "->" << (level + 1) << "] push" << std::endl;
    symbol_table_stack.emplace_back();
}

void SymbolTable::pop_scope() {
    size_t level = get_level();
    logger.log("sym_table") << "[" << level << "->" << (level - 1) << "] pop" << std::endl;
    symbol_table_stack.pop_back();
}

void SymbolTable::insert(const std::string &name, Symbol *symbol) {
    size_t level = get_level();
    logger.log("sym_table") << "[" << level << "] insert '" << name << "'" << std::endl;
    symbol->level = level;
    if(symbol->is_array) {
        logger.log("symbol_value");
        for (auto &value : symbol->const_array_values) {
            logger.log(std::to_string(value));
        }
        logger.log("end") << std::endl;
    }else {
        logger.log("symbol_value") << symbol->const_value << std::endl;
    }
    auto &curr_scope = symbol_table_stack.back();
    if(curr_scope.find(name) != curr_scope.end()) {
        throw std::runtime_error("Variable " + name + " already declared in this scope");
    }
    symbol_table_stack.back()[name] = symbol;
    logger.log("offset") << symbol->offset << std::endl;
}

Symbol* SymbolTable::try_lookup(const std::string &name) {
    size_t level = get_level();
    logger.log("sym_table") << "[" << level << "] lookup '" << name << "'" << std::endl;
    for(auto it = symbol_table_stack.rbegin(); it != symbol_table_stack.rend(); ++it) {
        auto item = it->find(name);
        // std::cout << "item: " << item->first << std::endl;
        // std::cout << "item: " << item->second->const_value << std::endl;
        if(item != it->end()) {
            return item->second;
        }
    }
    return nullptr;
}

Symbol* SymbolTable::lookup(const std::string &name) {
    auto value = try_lookup(name);
    if(value == nullptr) {
        throw std::runtime_error("Variable " + name + " not declared in this scope");
    }
    return value;
}