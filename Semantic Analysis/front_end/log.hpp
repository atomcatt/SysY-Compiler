#pragma once
#include <iostream>
#include <fstream>
#include <string_view>
#include <iomanip>
#include <memory>

class Log {
public:
    Log(const std::string &filename);
    ~Log();

    std::ostream &log(std::string_view module);
    std::ostream &err(std::string_view module);

    std::ostream &log_console(std::string_view module);
    std::ostream &err_console(std::string_view module);

private:
    inline static std::ostream &log_(std::ostream &out, std::string_view module, bool critical);
    std::unique_ptr<std::ofstream> logfile;
};