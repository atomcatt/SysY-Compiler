parser: parse.tab.o lex.yy.o
	gcc -Wall -g -o parser parse.tab.o lex.yy.o

parse.tab.o: parse.tab.c parse.tab.h
	gcc -Wall -g -c parse.tab.c

parse.tab.c parse.tab.h: parse.y
	bison -d parse.y

lex.yy.o: lex.yy.c parse.tab.h
	gcc -Wall -g -c lex.yy.c

lex.yy.c: lex.l
	flex lex.l

clean:
	rm -f parser parse.tab.c parse.tab.h lex.yy.c *.o