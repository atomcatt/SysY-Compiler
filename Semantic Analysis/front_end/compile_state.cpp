#include "compile_state.hpp"
#include <algorithm>
#include <string>

int CompileState::get_offset() {
    return offset;
}

void CompileState::reset_offset() {
    offset = 0;
    peak_offset = 0;
    param_size = 0;
}

void CompileState::update_offset(int val) {
    offset += val;
    if (std::abs(offset) > std::abs(peak_offset))
        peak_offset = offset;
}

void CompileState::dump_offset() {
    offsets.push_back(offset);
    peak_offsets.push_back(peak_offset);
    param_sizes.push_back(param_size);
}

void CompileState::recover_offset() {
    offset = offsets.back();
    peak_offset = peak_offsets.back();
    param_size = param_sizes.back();
    offsets.pop_back();
    peak_offsets.pop_back();
    param_sizes.pop_back();

}

void CompileState::updateParamSize(int val) {
    param_size =  std::max(abs(val), param_size);
}

int CompileState::getPeak_offset() {
     return abs(peak_offset) + param_size;
}

void CompileState::insert_format_string(std::string format_string) {
    format_string_map[format_string] = count;
    count++;
}

int CompileState::get_format_string_count(std::string format_string) {
    return format_string_map.find(format_string)->second;
}

bool CompileState::get_format_string_status(std::string format_string) {
    return format_string_map.find(format_string) != format_string_map.end();
}