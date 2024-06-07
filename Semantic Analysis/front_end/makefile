CC = clang++
CFLAGS = -std=c++20 -stdlib=libc++ -Wall -o

parser: parse.tab.o lex.o symbol_table.o const_eval.o const_eval_helper.o log.o assemble.o AST.o code_gen.o compile_state.o
	${CC} ${CFLAGS} parser parse.tab.o lex.o AST.o const_eval.o assemble.o symbol_table.o const_eval_helper.o log.o code_gen.o compile_state.o

parse.tab.o: parse.tab.cpp symbol_table.o const_eval.o const_eval_helper.o log.o assemble.o
	clang++ -Wall -g -c parse.tab.cpp

AST.o: AST.cpp log.o
	clang++ -Wall -g -c AST.cpp

compile_state.o: compile_state.cpp log.o
	clang++ -Wall -g -c compile_state.cpp

assemble.o: assemble.cpp log.o compile_state.o
	clang++ -Wall -g -c assemble.cpp

symbol_table.o: symbol_table.cpp log.o
	clang++ -Wall -g -c symbol_table.cpp

code_gen.o: code_gen.cpp const_eval.o assemble.o compile_state.o
	clang++ -Wall -g -c code_gen.cpp

const_eval.o: const_eval_helper.o symbol_table.o const_eval.cpp
	clang++ -Wall -g -c const_eval.cpp

const_eval_helper.o: const_eval_helper.cpp log.o
	clang++ -Wall -g -c const_eval_helper.cpp

log.o: log.cpp
	clang++ -Wall -g -c log.cpp

parse.tab.cpp: parse.y	
	bison -d -v -o parse.tab.cpp parse.y

lex.o: lex.cpp parse.tab.o
	clang++ -Wall -g -c lex.cpp

lex.cpp: lex.l
	flex -o lex.cpp lex.l

clean:
	rm -f parser parse.tab.cpp parse.tab.hpp parse.output lex.cpp *.o