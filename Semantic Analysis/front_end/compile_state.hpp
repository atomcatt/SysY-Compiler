#pragma once
#include <vector>
#include <map>
class CompileState {
private:
    std::map<std::string, int> format_string_map;
    int offset, peak_offset, param_size, count;
    std::vector<int> offsets, peak_offsets, param_sizes;
public:
    int get_offset();
    void reset_offset();
    void update_offset(int val);
    void dump_offset();
    void recover_offset();
    void updateParamSize(int val);
    int getPeak_offset();
    void insert_format_string(std::string format_string);
    int get_format_string_count(std::string format_string);
    bool get_format_string_status(std::string format_string);
};