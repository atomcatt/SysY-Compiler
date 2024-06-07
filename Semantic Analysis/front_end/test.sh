#!/bin/bash

# 创建日志文件
logfile="parser_errors.log"
> "$logfile"

# 遍历从1到10的索引
for index in {1..10}
do
    # 找到 ./tests/${index} 目录下的所有 .c 文件
    for c_file in ./tests/${index}/*.c
    do
        # 提取文件名（不带路径）
        base_filename=$(basename "$c_file" .c)
        
        # 创建结果目录（如果不存在）
        mkdir -p ./results/${index}
        
        # 运行 ./parser 并将输出重定向到相应的输出文件，同时记录错误
        if ! ./parser < "$c_file" > ./results/${index}/${base_filename}.parse.out 2>>"$logfile"; then
            echo "Error processing $c_file" >> "$logfile"
        fi
    done
done
