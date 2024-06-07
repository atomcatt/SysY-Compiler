#include <stdio.h>
#include "assemble.hpp"
#include "AST.hpp"
#include "symbol_table.hpp"
#include "log.hpp"
#include <fstream>
#include <iostream>
#include "const_eval_helper.hpp"
#include "parse.tab.hpp"

extern int yyparse();

int main() {
    yyparse();
    // FILE *fp = fopen("1.s", "w");
    // assemble.print_info(fp);
    // fclose(fp);
    logger.log("----------------------------------------------------------------------") << std::endl;
    return 0;
}