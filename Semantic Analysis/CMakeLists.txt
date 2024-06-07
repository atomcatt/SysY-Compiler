# cmake 最低版本需求
cmake_minimum_required(VERSION 3.13)

# 工程名称
project(compiler)

# 设置
set(CMAKE_CXX_STANDARD 20)

aux_source_directory(./front_end/ FRONT_END_SRC)

# 编译源码生成目标
add_executable(compiler ${FRONT_END_SRC})