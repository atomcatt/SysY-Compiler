// // Log.cpp
// #include "log.hpp"

// Log logger = Log("logfile.json");

// Log::Log(const std::string &filename) {
//     logfile = std::make_unique<std::ofstream>(filename, std::ios::out | std::ios::app);
//     if (!logfile->is_open()) {
//         std::cerr << "Failed to open log file: " << filename << std::endl;
//         throw std::runtime_error("Failed to open log file");
//     }
// }

// Log::~Log() {
//     if (logfile && logfile->is_open()) {
//         logfile->close();
//     }
// }

// std::ostream &Log::log(std::string_view module) {
//     return log_(*logfile, module, false);
// }

// std::ostream &Log::err(std::string_view module) {
//     return log_(*logfile, module, true);
// }

// std::ostream &Log::log_console(std::string_view module) {
//     return log_(std::cout, module, false);
// }

// std::ostream &Log::err_console(std::string_view module) {
//     return log_(std::cout, module, true);
// }

// std::ostream &Log::log_(std::ostream &out, std::string_view module, bool critical) {
//     char leading = critical ? '!' : '+';
//     out << "[" << leading << "] [" << std::setw(10) << std::left << module << std::right << "] ";
//     return out;
// }

// Log.cpp
#include "log.hpp"

Log::Log(const std::string& filename) {
    // 打开文件时同时设置创建和追加模式
    logfile = std::make_unique<std::ofstream>(filename, std::ios::out | std::ios::app);
    if (!logfile->is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
        std::cerr << "Error: " << strerror(errno) << std::endl; // 打印 errno
        throw std::runtime_error("Failed to open log file");
    }
}

Log::~Log() {
    // 如果文件流不为空，则关闭文件
    if (logfile && logfile->is_open()) {
        logfile->close();
    }
}

std::ostream& Log::log(std::string_view module) {
    // 检查文件流是否为空
    if (!logfile) {
        throw std::runtime_error("Log file is not open");
    }
    return log_(*logfile, module, false);
}

std::ostream& Log::err(std::string_view module) {
    // 检查文件流是否为空
    if (!logfile) {
        throw std::runtime_error("Log file is not open");
    }
    return log_(*logfile, module, true);
}

std::ostream& Log::log_console(std::string_view module) {
    return log_(std::cout, module, false);
}

std::ostream& Log::err_console(std::string_view module) {
    return log_(std::cout, module, true);
}

std::ostream& Log::log_(std::ostream& out, std::string_view module, bool critical) {
    char leading = critical ? '!' : '+';
    out << "[" << leading << "] [" << std::setw(10) << std::left << module << std::right << "] ";
    return out;
}

