%{
    #include <stdio.h>
    #include "assemble.hpp"
    #include "AST.hpp"
    #include "symbol_table.hpp"
    #include "log.hpp"
    #include <fstream>
    #include <iostream>
    #include <variant>
    #include <typeinfo>
    #include "const_eval_helper.hpp"
    // #include "parse.tab.hpp"

    int yylex(void);
    extern int yyparse(void);
    void yyerror(const char *s);
    
    char message[1024];

    FILE* detail_fp;

    extern int lines;
    extern int chars;
    
    Log logger = Log("./logfile.json");

    extern BaseAST* root;

    int offset;

    extern Assemble rodata, data, bss, text;

    // SymbolTable *symbol_table = new SymbolTable();
    // Assemble assemble = Assemble();
%}


%token INCLUDE
%token CONST
%token INT
%token VOID
%token IF
%token ELSE
%token WHILE
%token BREAK
%token CONTINUE
%token RETURN
%token ASSIGN
%token AND
%token OR
%token EQ
%token LT
%token LE
%token GT
%token GE
%token NE
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token SINGLEAND
%token SINGLEOR
%token NOT
%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token LBRACK
%token RBRACK
%token COMMA
%token SEMI
%token HASH
%token <const_string_val> Ident
 /* %token <const_string_val> GetAddressOfIdent */
%token <const_int_val> IntConst
%token <const_string_val> HeaderFile
%token <const_string_val> String

%type <compunit_type> CompUnit Start
%type <externaldef_type> ExternalDef
%type <decl_type> Decl
%type <exp_type> ConstExp
%type <constdecl_type> ConstDecl
%type <constdeflist_type> ConstDefList
%type <constdef_type> ConstDef
%type <constarrdef_type> ConstArrDef
%type <constinitval_type> ConstInitVal
%type <constinitvallist_type> ConstInitValList
%type <vardecl_type> VarDecl
%type <vardeflist_type> VarDefList
%type <vardef_type> VarDef
%type <arrdef_type> ArrDef
%type <initval_type> InitVal
%type <initvallist_type> InitValList
%type <funcdef_type> FuncDef
%type <funcfparams_type> FuncFParams
%type <funcfparam_type> FuncFParam
%type <block_type> Block
%type <blockgroup_type> BlockGroup
%type <blockitem_type> BlockItem
%type <stmt_type> Stmt
 /* %type <nullstmt_type> NullStmt
%type <assignstmt_type> AssignStmt
%type <expstmt_type> ExpStmt
%type <blockstmt_type> BlockStmt
%type <ifstmt_type> IfStmt
%type <whilestmt_type> WhileStmt
%type <breakstmt_type> BreakStmt
%type <continuestmt_type> ContinueStmt
%type <returnstmt_type> ReturnStmt */
%type <lval_type> LVal
 /* %type <cond_type> Cond
%type <exp_type> Exp
%type <primaryexp_type> PrimaryExp
%type <unaryexp_type> UnaryExp */
%type <unaryop_type> UnaryOp
%type <exp_type> Cond Exp PrimaryExp UnaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp
%type <funcrparams_type> FuncRParams
 /* %type <mulexp_type> MulExp
%type <addexp_type> AddExp
%type <relexp_type> RelExp
%type <eqexp_type> EqExp
%type <landexp_type> LAndExp
%type <lorexp_type> LOrExp */

%nonassoc IFX
%nonassoc ELSE

 /* %left IF ELSE */
%left OR
%left AND
%left LT LE GT GE EQ NE
%right NOT
%left ADD SUB
%left MUL DIV MOD

%start Start

%union {
    int const_int_val;
    char *const_string_val;
    struct BaseAST* base_type;
    struct CompUnitAST* compunit_type;
    struct ExternalDefAST* externaldef_type;
    struct DeclAST* decl_type;
    // struct ConstExpAST* constexp_type;
    struct ConstDeclAST* constdecl_type;
    struct ConstDefListAST* constdeflist_type;
    struct ConstDefAST* constdef_type;
    struct ConstArrDefAST* constarrdef_type;
    struct ConstInitValAST* constinitval_type;
    struct ConstInitValListAST* constinitvallist_type;
    struct VarDeclAST* vardecl_type;
    struct VarDefListAST* vardeflist_type;
    struct VarDefAST* vardef_type;
    struct ArrDefAST* arrdef_type;
    struct InitValAST* initval_type;
    struct InitValListAST* initvallist_type;
    struct FuncDefAST* funcdef_type;
    struct FuncFParamsAST* funcfparams_type;
    struct FuncFParamAST* funcfparam_type;
    struct BlockAST* block_type;
    struct BlockGroupAST* blockgroup_type;
    struct BlockItemAST* blockitem_type;
    struct StmtAST* stmt_type;
    struct NullStmtAST* nullstmt_type;
    struct AssignStmtAST* assignstmt_type;
    struct ExpStmtAST* expstmt_type;
    struct BlockStmtAST* blockstmt_type;
    struct IfStmtAST* ifstmt_type;
    struct WhileStmtAST* whilestmt_type;
    struct BreakStmtAST* breakstmt_type;
    struct ContinueStmtAST* continuestmt_type; 
    struct ReturnStmtAST* returnstmt_type;
    struct LValAST* lval_type;
    // struct CondAST* cond_type;
    struct ExpAST* exp_type;
    // struct PrimaryExpAST* primaryexp_type;
    struct BinaryExpAST* binaryexp_type;
    struct VarExpAST* varexp_type;
    struct NumExpAST* numexp_type;
    struct UnaryExpAST* unaryexp_type;
    struct FuncCallAST* funccall_type;
    struct UnaryOpAST* unaryop_type;
    struct FuncRParamsAST* funcrparams_type;
    // struct MulExpAST* mulexp_type;
    // struct AddExpAST* addexp_type;
    // struct RelExpAST* relexp_type;
    // struct EqExpAST* eqexp_type;
    // struct LAndExpAST* landexp_type;
    // struct LOrExpAST* lorexp_type;
}

%%
Start
:   CompUnit
    {
        fprintf(detail_fp, "CompUnit -> Start\n");
        root = $1;
        // const std::type_info& objType = typeid($1);
        // 使用type_info的name()成员函数获取类型名
        // std::cout << "Type of obj: " << objType.name() << std::endl;
        // fprintf(detail_fp, "root type: %s\n", std::holds_alternative<CompUnitAST*>(root) ? "CompUnit" : "Other");
    } 
|   /* empty */
    {
        fprintf(detail_fp, "empty -> Start\n");
        root = new CompUnitAST();
    }
;

CompUnit
:   Decl
    {
        fprintf(detail_fp, "Decl -> CompUnit\n");
        $$ = new CompUnitAST();
        $$->decls.push_back($1);
    }
|   FuncDef
    {
        fprintf(detail_fp, "FuncDef -> CompUnit\n");
        $$ = new CompUnitAST();
        $$->func_defs.emplace_back($1);
    }
|   ExternalDef
    {
        fprintf(detail_fp, "ExternalDef -> CompUnit\n");
        $$ = new CompUnitAST();
        $$->external_defs.emplace_back($1);
    }
|   CompUnit Decl
    {
        fprintf(detail_fp, "CompUnit Decl -> CompUnit\n");
        $1->decls.emplace_back($2);
        $$ = $1;
    }
|   CompUnit FuncDef
    {
        fprintf(detail_fp, "CompUnit FuncDef -> CompUnit\n");
        $1->func_defs.emplace_back($2);
        $$ = $1;
    }
|   CompUnit ExternalDef
    {
        fprintf(detail_fp, "CompUnit ExternalDef -> CompUnit\n");
        $1->external_defs.emplace_back($2);
        $$ = $1;
    }
;

ExternalDef
:   HASH INCLUDE HeaderFile
    {
        fprintf(detail_fp, "# include %s -> ExternalDef\n", $3);
        $$ = new ExternalDefAST($3);
    }
;

Decl
:   ConstDecl
    {
        fprintf(detail_fp, "ConstDecl -> Decl\n");
        $$ = new DeclAST();
        $$->decl = $1;
    }
|   VarDecl
    {
        fprintf(detail_fp, "VarDecl -> Decl\n");
        $$ = new DeclAST();
        $$->decl = $1;
    }
;

ConstDecl
:   CONST INT ConstDefList SEMI
    {
        fprintf(detail_fp, "const int ConstDefList ; -> ConstDecl\n");
        $$ = new ConstDeclAST();
        $$->const_defs = $3->const_defs;
    }

;

ConstDefList
:   ConstDef    
    {
        fprintf(detail_fp, "ConstDef -> ConstDefList\n");
        $$ = new ConstDefListAST();
        $$->const_defs.emplace_back($1);
    }
|   ConstDefList COMMA ConstDef 
    {
        fprintf(detail_fp, "ConstDef , ConstDef -> ConstDefList\n");
        $1->const_defs.emplace_back($3);
        $$ = $1;
    }
;

ConstDef
:   Ident ASSIGN ConstInitVal
    {
        fprintf(detail_fp, "%s = ConstInitVal -> ConstDef\n", $1);
        $$ = new ConstDefAST();
        $$->ident = $1;
        $$->const_init_val = $3;
    }
|   Ident ConstArrDef ASSIGN ConstInitVal
    {
        fprintf(detail_fp, "%s ConstArrDef = ConstInitVal -> ConstDef\n", $1);
        $$ = new ConstDefAST();
        $$->ident = $1;
        $$->dim = $2->dim;
        $$->const_init_val = $4;
    }
;

ConstArrDef
:   LBRACK ConstExp RBRACK
    {
        fprintf(detail_fp, "[ ConstExp ] -> ConstArrDef\n");
        $$ = new ConstArrDefAST();
        $$->dim.emplace_back($2);
    }
|   ConstArrDef LBRACK ConstExp RBRACK
    {
        fprintf(detail_fp, "ConstArrDef [ ConstExp ] -> ConstArrDef\n");
        $1->dim.emplace_back($3);
        $$ = $1;
    }
;

ArrDef
:   LBRACK Exp RBRACK  
    {
        fprintf(detail_fp, "[ Exp ] -> ArrDef\n");
        $$ = new ArrDefAST();
        $$->dim.emplace_back($2);
    }
|   ArrDef LBRACK Exp RBRACK   
    {
        fprintf(detail_fp, "ArrDef [ Exp ] -> ArrDef\n");
        $1->dim.emplace_back($3);
        $$ = $1;
    }
;

ConstInitVal
:   ConstExp
    {
        fprintf(detail_fp, "ConstExp -> ConstInitVal\n");
        $$ = new ConstInitValAST();
        $$->value = $1;
    }
|   LBRACE RBRACE
    {
        fprintf(detail_fp, "{ } -> ConstInitVal\n");
        $$ = new ConstInitValAST();
    }
|   LBRACE ConstInitValList RBRACE
    {
        fprintf(detail_fp, "{ ConstInitValList } -> ConstInitVal\n");
        $$ = new ConstInitValAST();
        $$->value = $2;
    }
;

ConstInitValList
:   ConstInitVal  
    {
        fprintf(detail_fp, "ConstInitVal -> ConstInitValList\n");
        $$ = new ConstInitValListAST();
        $$->const_init_vals.emplace_back($1);
    }
|   ConstInitValList COMMA ConstInitVal   
    {
        fprintf(detail_fp, "ConstInitValList , ConstInitVal -> ConstInitValList\n");
        $1->const_init_vals.emplace_back($3);
        $$ = $1;
    }
;

VarDecl
:   INT VarDefList SEMI
    {
        fprintf(detail_fp, "int VarDeclList ; -> VarDecl\n");
        $$ = new VarDeclAST();
        $$->var_defs = $2->var_defs;
    }
;

VarDefList
:   VarDef  
    {
        fprintf(detail_fp, "VarDef -> VarDefList\n");
        $$ = new VarDefListAST();
        $$->var_defs.emplace_back($1);
    }
|   VarDefList COMMA VarDef   
    {
        fprintf(detail_fp, "VarDef , VarDef -> VarDefList\n");
        $1->var_defs.emplace_back($3);
        $$ = $1;
    }
;

VarDef
:   Ident
    {
        fprintf(detail_fp, "%s -> VarDef\n", $1);
        $$ = new VarDefAST();
        $$->ident = $1;
    }
|   Ident ASSIGN InitVal
    {
        fprintf(detail_fp, "%s = InitVal -> VarDef\n", $1);
        $$ = new VarDefAST();
        $$->ident = $1;
        $$->init_val = $3;
    }
|   Ident ArrDef
    {
        fprintf(detail_fp, "%s ArrDef -> VarDef\n", $1);
        $$ = new VarDefAST();
        $$->ident = $1;
        $$->dim = $2->dim;
    }
|   Ident ArrDef ASSIGN InitVal
    {
        fprintf(detail_fp, "%s Arrdef = InitVal -> VarDef\n", $1);
        $$ = new VarDefAST();
        $$->ident = $1;
        $$->dim = $2->dim;
        $$->init_val = $4;
    }
;

InitVal
:   Exp
    {
        fprintf(detail_fp, "Exp -> InitVal\n");
        $$ = new InitValAST();
        $$->value = $1;
    }
|   LBRACE RBRACE
    {
        fprintf(detail_fp, "{ } -> InitVal\n");
        $$ = new InitValAST();
    }
|   LBRACE InitValList RBRACE
    {
        fprintf(detail_fp, "{ InitValList } -> InitVal\n");
        $$ = new InitValAST();
        $$->value = $2;
    }
;

InitValList
:   InitVal   
    {
        fprintf(detail_fp, "InitVal -> InitValList\n");
        $$ = new InitValListAST();
        $$->init_vals.emplace_back($1);
    }
|   InitValList COMMA InitVal
    {
        fprintf(detail_fp, "InitValList , InitVal -> InitValList\n");
        $1->init_vals.emplace_back($3);
        $$ = $1;
    }
;

FuncDef
:   VOID Ident LPAREN RPAREN Block
    {
        fprintf(detail_fp, "void %s ( ) Block -> FuncDef\n", $2);
        $$ = new FuncDefAST();
        $$->return_type = false;
        $$->ident = $2;
        $$->block = $5;
    }
|   INT Ident LPAREN RPAREN Block
    {
        fprintf(detail_fp, "int %s ( ) Block -> FuncDef\n", $2);
        $$ = new FuncDefAST();
        $$->return_type = true;
        $$->ident = $2;
        $$->block = $5;
    }
|   VOID Ident LPAREN FuncFParams RPAREN Block
    {
        fprintf(detail_fp, "void %s ( FuncFParams ) Block -> FuncDef\n", $2);
        $$ = new FuncDefAST();
        $$->return_type = false;
        $$->ident = $2;
        $$->f_args.emplace_back($4);
        $$->block = $6;
    }
|   INT Ident LPAREN FuncFParams RPAREN Block
    {
        fprintf(detail_fp, "int %s ( FuncFParams ) Block -> FuncDef\n", $2);
        $$ = new FuncDefAST();
        $$->return_type = true;
        $$->ident = $2;
        $$->f_args.emplace_back($4);
        $$->block = $6;
    }
;

FuncFParams
:   FuncFParam
    {
        fprintf(detail_fp, "FuncFParam -> FuncFParams\n");
        $$ = new FuncFParamsAST();
        $$->f_args.emplace_back($1);
    }
|   FuncFParams COMMA FuncFParam
    {
        fprintf(detail_fp, "FuncFParams , FuncFParam -> FuncFParams\n");
        $1->f_args.emplace_back($3);
        $$ = $1;
    }
;

FuncFParam
:   INT Ident
    {
        fprintf(detail_fp, "int %s -> FuncFParam\n", $2);
        $$ = new FuncFParamAST();
        $$->ident = $2;
    }
|   INT Ident LBRACK RBRACK
    {
        fprintf(detail_fp, "int %s [ ] -> FuncFParam\n", $2);
        $$ = new FuncFParamAST();
        $$->ident = $2;
        $$->dim.emplace_back(nullptr);
    }
|   INT Ident LBRACK RBRACK ArrDef
    {
        fprintf(detail_fp, "int %s [ ] ArrDef -> FuncFParam\n", $2);
        $$ = new FuncFParamAST();
        $$->ident = $2;
        $5->dim.emplace_back(nullptr);
        $$->dim = $5->dim;
        /* TODO */
    }
;

Block
:   LBRACE RBRACE
    {
        fprintf(detail_fp, "{ } -> Block\n");
        $$ = new BlockAST();
    }
|   LBRACE BlockGroup RBRACE
    {
        fprintf(detail_fp, "{ BlockGroup } -> Block\n");
        $$ = new BlockAST();
        $$->block_items = $2->block_items;
    }
;

BlockGroup
:   BlockItem
    {
        fprintf(detail_fp, "BlockItem -> BlockGroup\n");
        $$ = new BlockGroupAST();
        $$->block_items.emplace_back($1);
    }
|   BlockGroup BlockItem
    {
        fprintf(detail_fp, "BlockGroup BlockItem -> BlockGroup\n");
        $1->block_items.emplace_back($2);
        $$ = $1;
    }
;

BlockItem
:   Decl
    {
        fprintf(detail_fp, "Decl -> BlockItem\n");
        $$ = new BlockItemAST();
        $$->block_item = $1;
    }
|   Stmt
    {
        fprintf(detail_fp, "Stmt -> BlockItem\n");
        $$ = new BlockItemAST();
        $$->block_item = $1;
    }
;

Stmt
:   LVal ASSIGN Exp SEMI
    {
        fprintf(detail_fp, "LVal = Exp ; -> Stmt\n");
        auto ptr = new AssignStmtAST();
        ptr->lvalue = $1;
        ptr->rvalue = $3;
        $$ = ptr;
    }
|   SEMI
    {
        fprintf(detail_fp, "; -> Stmt\n");
        $$ = new NullStmtAST();
    }
|   Exp SEMI
    {
        fprintf(detail_fp, "Exp ; -> Stmt\n");
        auto ptr = new ExpStmtAST();
        ptr->exp = $1;
        $$ = ptr;
    }
|   Block
    {
        fprintf(detail_fp, "Block -> Stmt\n");
        auto ptr = new BlockStmtAST();
        ptr->block_items = $1->block_items;
        $$ = ptr;
    }
|   IF LPAREN Cond RPAREN Stmt %prec IFX
    {
        fprintf(detail_fp, "if ( Cond ) Stmt -> Stmt\n");
        auto ptr = new IfStmtAST();
        ptr->cond = $3;
        ptr->then_stmt = $5;
        ptr->else_stmt = nullptr;
        $$ = ptr;
    }
|   IF LPAREN Cond RPAREN Stmt ELSE Stmt
    {
        fprintf(detail_fp, "if ( Cond ) Stmt else Stmt -> Stmt\n");
        auto ptr = new IfStmtAST();
        ptr->cond = $3;
        ptr->then_stmt = $5;
        ptr->else_stmt = $7;
        $$ = ptr;
    }
|   WHILE LPAREN Cond RPAREN Stmt
    {
        fprintf(detail_fp, "while ( Cond ) Stmt -> Stmt\n");
        auto ptr = new WhileStmtAST();
        ptr->cond = $3;
        ptr->stmt = $5;
        $$ = ptr;
    }
|   BREAK SEMI
    {
        fprintf(detail_fp, "break ; -> Stmt\n");
        $$ = new BreakStmtAST();
    }
|   CONTINUE SEMI
    {
        fprintf(detail_fp, "continue ; -> Stmt\n");
        $$ = new ContinueStmtAST();
    }
|   RETURN SEMI
    {
        fprintf(detail_fp, "return ; -> Stmt\n");
        auto ptr = new ReturnStmtAST();
        ptr->exp = nullptr;
        $$ = ptr;
    }
|   RETURN Exp SEMI
    {
        fprintf(detail_fp, "return Exp ; -> Stmt\n");
        auto ptr = new ReturnStmtAST();
        ptr->exp = $2;
        $$ = ptr;
    }
;

Exp
:   AddExp
    {
        fprintf(detail_fp, "AddExp -> Exp\n");
        $$ = $1;
    }
;

ConstExp
:   AddExp
    {
        fprintf(detail_fp, "AddExp -> ConstExp\n");
        $$ = $1;
    }
;

Cond
:   LOrExp
    {
        fprintf(detail_fp, "LOrExp -> Cond\n");
        $$ = $1;
    }
;

LVal
:   Ident
    {
        fprintf(detail_fp, "%s -> LVal\n", $1);
        $$ = new LValAST();
        $$->ident = $1;
    }
|   Ident ArrDef
    {
        fprintf(detail_fp, "Ident ArrDef -> LVal\n");
        $$ = new LValAST();
        $$->ident = $1;
        $$->dim = $2->dim;
    }
;

PrimaryExp
:   LPAREN Exp RPAREN
    {
        fprintf(detail_fp, "( Exp ) -> PrimaryExp\n");
        $$ = $2;
    }
|   LVal
    {
        fprintf(detail_fp, "LVal -> PrimaryExp\n");
        auto ptr = new VarExpAST();
        ptr->ident = $1->ident;
        ptr->dim = $1->dim;
        $$ = ptr;
    }
|   IntConst
    {
        fprintf(detail_fp, "%d -> PrimaryExp\n", $1);
        auto ptr = new NumExpAST();
        ptr->value = $1;
        $$ = ptr;
    }
|   SINGLEAND Ident
    {
        fprintf(detail_fp, "&%s -> PrimaryExp\n", $2);
        auto ptr = new VarExpAST();
        ptr->ident = $2;
        ptr->is_pointer = true;
        $$ = ptr;
    }
|   SINGLEAND Ident ArrDef
    {
        fprintf(detail_fp, "&%s ArrDef -> PrimaryExp\n", $2);
        auto ptr = new VarExpAST();
        ptr->ident = $2;
        ptr->dim = $3->dim;
        ptr->is_pointer = true;
        $$ = ptr;
    }
;

UnaryExp
:   PrimaryExp
    {
        fprintf(detail_fp, "PrimaryExp -> UnaryExp\n");
        $$ = $1;
    }
|   Ident LPAREN RPAREN
    {
        fprintf(detail_fp, "%s ( ) -> UnaryExp\n", $1);
        auto ptr = new FuncCallAST();
        ptr->ident = $1;
        // ptr->r_args.emplace_back(nullptr);
        $$ = ptr;
        $$ = ptr;
    }
|   Ident LPAREN FuncRParams RPAREN
    {
        fprintf(detail_fp, "%s ( FuncRParams ) -> UnaryExp\n", $1);
        auto ptr = new FuncCallAST();
        ptr->ident = $1;
        if($3->str != "") {
            ptr->format_output = $3->str;
        }
        ptr->r_args = $3->r_args;
        $$ = ptr;
    }
|   UnaryOp UnaryExp
    {
        fprintf(detail_fp, "UnaryOp UnaryExp -> UnaryExp\n");
        auto ptr = new UnaryExpAST();
        ptr->op = $1->op;
        ptr->value = $2;
        $$ = ptr;
    }
;

UnaryOp
:   ADD
    {
        fprintf(detail_fp, "+ -> UnaryOp\n");
        $$ = new UnaryOpAST();
        $$->op = "+";
    }
|   SUB
    {
        fprintf(detail_fp, "- -> UnaryOp\n");
        $$ = new UnaryOpAST();
        $$->op = std::string("-");
    }
|   NOT
    {
        fprintf(detail_fp, "! -> UnaryOp\n");
        $$ = new UnaryOpAST();
        $$->op = std::string("!");
    }
;

FuncRParams
:   Exp
    {
        fprintf(detail_fp, "Exp -> FuncRParams\n");
        $$ = new FuncRParamsAST();
        $$->r_args.emplace_back($1);
    }
|    Exp COMMA FuncRParams
    {
        fprintf(detail_fp, "Exp , FuncRParams -> FuncRParams\n");
        $3->r_args.emplace_back($1);
        $$ = $3;
    }
|    String COMMA FuncRParams
    {
        fprintf(detail_fp, "%s , FuncRParams -> FuncRParams\n", $1);
        $3->str = $1;
        $$ = $3;
    }
;

MulExp
:   UnaryExp
    {
        fprintf(detail_fp, "UnaryExp -> MulExp\n");
        $$ = $1;
    }
|   MulExp MUL UnaryExp
    {
        fprintf(detail_fp, "MulExp * UnaryExp -> MulExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("*");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   MulExp DIV UnaryExp
    {
        fprintf(detail_fp, "MulExp / UnaryExp -> MulExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("/");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   MulExp MOD UnaryExp
    {
        fprintf(detail_fp, "MulExp %% UnaryExp -> MulExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("%");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
;

AddExp
:   MulExp
    {
        fprintf(detail_fp, "MulExp -> AddExp\n");
        $$ = $1;
    }
|   AddExp ADD MulExp
    {
        fprintf(detail_fp, "AddExp + MulExp -> AddExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("+");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   AddExp SUB MulExp
    {
        fprintf(detail_fp, "AddExp - MulExp -> AddExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("-");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
;

RelExp
:   AddExp
    {
        fprintf(detail_fp, "AddExp -> RelExp\n");
        $$ = $1;
    }
|   RelExp LT AddExp
    {
        fprintf(detail_fp, "RelExp < AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("<");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   RelExp LE AddExp
    {
        fprintf(detail_fp, "RelExp <= AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("<=");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   RelExp GT AddExp
    {
        fprintf(detail_fp, "RelExp > AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string(">");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   RelExp GE AddExp
    {
        fprintf(detail_fp, "RelExp >= AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string(">=");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
;

EqExp
:   RelExp
    {
        fprintf(detail_fp, "RelExp -> EqExp\n");
        $$ = $1;
    }
|   EqExp EQ RelExp
    {
        fprintf(detail_fp, "EqExp == RelExp -> EqExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("==");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
|   EqExp NE RelExp
    {
        fprintf(detail_fp, "EqExp != RelExp -> EqExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("!=");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
;

LAndExp
:   EqExp
    {
        fprintf(detail_fp, "EqExp -> LAndExp\n");
        $$ = $1;
    }
|   LAndExp AND EqExp
    {
        fprintf(detail_fp, "LAndExp && EqExp -> LAndExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("&&");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
;

LOrExp
:   LAndExp
    {
        fprintf(detail_fp, "LAndExp -> LOrExp\n");
        $$ = $1;
    }
|   LOrExp OR LAndExp
    {
        fprintf(detail_fp, "LOrExp || LAndExp -> LOrExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("||");
        ptr->lhs = $1;
        ptr->rhs = $3;
        $$ = ptr;
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, column %d\n", s, lines, chars);
}

int main() {
    detail_fp = fopen("./results/plot/detail.txt", "w");
    printf("Start\n");
    FILE *file = fopen("out.s", "w");
    rodata.append(".section .rodata\n");
    data.append(".section .data\n");
    bss.append(".section .bss\n");
    text.append(".section .text\n");
    yyparse();
    std::ofstream out("results/plot/tree.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); // 保存旧的缓冲区
    std::cout.rdbuf(out.rdbuf()); // 重定向
    // 显示 AST
    show_ast(root, 0);
    // 恢复 std::cout 的缓冲区
    std::cout.rdbuf(coutbuf);
    root = (dynamic_cast<CompUnitAST*>(root));
    root->const_eval(root);
    root->code_gen();
    logger.log("----------------------------------------------------------------------") << std::endl;
    rodata.print_info(file);
    data.print_info(file);
    bss.print_info(file);
    text.print_info(file);
    fclose(file);
    return 0;
}