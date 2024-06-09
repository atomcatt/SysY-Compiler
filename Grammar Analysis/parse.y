%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(const char *s);
%}

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
%token NOT
%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token LBRACK
%token RBRACK
%token COMMA
%token SEMI
%token <const_string_val> Ident
%token <const_int_val> IntConst
 /*%token <const_int_val> Number*/


%left OR
%left AND
%left LT LE GT GE EQ NE
%right NOT
%left ADD SUB
%left MUL DIV MOD

%start CompUnit

%union {
    int const_int_val;
    char *const_string_val;
}

%%

CompUnit
:   Decl    //{printf("CompUnit -> Decl\n");}
    {
        printf("Decl -> CompUnit\n");
    
    }
|   FuncDef //{printf("CompUnit -> FuncDef\n");}
    {
        printf("FuncDef -> CompUnit\n");
    }
|   CompUnit Decl //{printf("CompUnit -> CompUnit Decl\n");}
    {
        printf("CompUnit Decl -> CompUnit\n");
    }
|   CompUnit FuncDef //{printf("CompUnit -> CompUnit FuncDef\n");}
    {
        printf("CompUnit FuncDef -> CompUnit\n");
    }
;

Decl
:   ConstDecl   //{printf("Decl -> ConstDecl\n");}
    {
        printf("ConstDecl -> Decl\n");
    }
|   VarDecl //{printf("Decl -> VarDecl\n");}
    {
        printf("VarDecl -> Decl\n");
    }
;

ConstDecl
:   CONST INT ConstDefList SEMI   //{printf("ConstDecl -> CONST INT ConstDef {COMMA ConstDef} SEMI\n");}
    {
        printf("const int ConstDefList ; -> ConstDecl\n");
    }
//|   CONST INT ConstDef ConstDefList SEMI   {printf("ConstDecl -> ConstDecl COMMA ConstDef SEMI\n");}
;

ConstDefList
:   ConstDef    
    {
        printf("ConstDef -> ConstDefList\n");
    }
|   ConstDefList COMMA ConstDef 
    {
        printf("ConstDef , ConstDef -> ConstDefList\n");
    }
;

/*
BType
:   INT {printf("BType -> INT\n");}
;
*/

ConstDef
:   Ident ASSIGN ConstInitVal   //{printf("ConstDef -> Ident ASSIGN ConstInitVal\n");}
    {
        printf("%s = ConstInitVal -> ConstDef\n", $1);
    }
|   Ident ConstDefGroup ASSIGN ConstInitVal     //{printf("ConstDef -> Ident {LBRACK ConstExp RBRACK} ASSIGN ConstInitVal\n");}
    {
        printf("%s ConstDefGroup = ConstInitVal -> ConstDef\n", $1);
    }
;

ConstDefGroup
:   LBRACK ConstExp RBRACK 
    {
        printf("[ ConstExp ] -> ConstDefGroup\n");
    }
|   ConstDefGroup LBRACK ConstExp RBRACK   
    {
        printf("ConstDefGroup [ ConstExp ] -> ConstDefGroup\n");
    }
;

ConstInitVal
:   ConstExp    //{printf("ConstInitVal -> ConstExp\n");}
    {
        printf("ConstExp -> ConstInitVal\n");
    
    }
|   LBRACE RBRACE   //{printf("ConstInitVal -> LBRACE RBRACE\n");}
    {
        printf("{ } -> ConstInitVal\n");
    
    }
|   LBRACE ConstInitValGroup RBRACE  //{printf("ConstInitVal -> LBRACE [COMMA ConstInitVal] RBRACE\n");}
    {
        printf("{ ConstInitValGroup } -> ConstInitVal\n");
    }
;

ConstInitValGroup
:   ConstInitVal  
    {
        printf("ConstInitVal -> ConstInitValGroup\n");
    }
|   ConstInitValGroup COMMA ConstInitVal   
    {
        printf("ConstInitValGroup , ConstInitVal -> ConstInitValGroup\n");
    
    }
;

VarDecl
:   INT VarDeclGroup SEMI  //{printf("VarDecl -> INT VarDef {COMMA VarDef} SEMI\n");}
    {
        printf("int VarDeclGroup ; -> VarDecl\n");
    }
;

VarDeclGroup
:   VarDef  
    {
        printf("VarDef -> VarDeclGroup\n");
    }
|   VarDeclGroup COMMA VarDef   
    {
        printf("VarDef , VarDef -> VarDeclGroup\n");
    }
;

VarDef
:   Ident   //{printf("VarDef -> Ident\n");}
    {
        printf("%s -> VarDef\n", $1);
    }
|   Ident ASSIGN InitVal    //{printf("VarDef -> Ident ASSIGN InitVal\n");}
    {
        printf("%s = InitVal -> VarDef\n", $1);
    }
|   Ident ArrDef    //{printf("VarDef -> Ident {LBRACK ConstExp RBRACK}\n");}
    {
        printf("%s ArrDef -> VarDef\n", $1);
    }
|   Ident ArrDef ASSIGN InitVal  //{printf("VarDef -> Ident {LBRACK ConstExp RBRACK} ASSIGN InitVal\n");}
    {
        printf("%s Arrdef = InitVal -> VarDef\n", $1);
    }
;

ArrDef
:   LBRACK ConstExp RBRACK  
    {
        printf("[ ConstExp ] -> ArrDef\n");
    }
|   ArrDef LBRACK ConstExp RBRACK   
    {
        printf("ArrDef [ ConstExp ] -> ArrDef\n");
    
    }
;

InitVal
:   Exp //{printf("InitVal -> Exp\n");}
    {
        printf("Exp -> InitVal\n");
    }
|   LBRACE RBRACE   //{printf("InitVal -> LBRACE RBRACE\n");}
    {
        printf("{ } -> InitVal\n");
    }
|   LBRACE InitValGroup RBRACE  //{printf("InitVal -> LBRACE [InitVal {COMMA InitVal}] RBRACE\n");}
    {
        printf("{ InitValGroup } -> InitVal\n");
    }
;

InitValGroup
:   InitVal   
    {
        printf("InitVal -> InitValGroup\n");
    }
|   InitValGroup COMMA InitVal  //{printf("InitValGroup -> InitValGroup COMMA InitVal\n");}
    {
        printf("InitValGroup , InitVal -> InitValGroup\n");
    }
;

FuncDef
:   VOID Ident LPAREN RPAREN Block  //{printf("FuncDef -> VOID Ident LPAREN RPAREN Block\n");}
    {
        printf("void %s ( ) Block -> FuncDef\n", $2);
    }
|   INT Ident LPAREN RPAREN Block  //{printf("FuncDef -> INT Ident LPAREN RPAREN Block\n");}
    {
        printf("int %s ( ) Block -> FuncDef\n", $2);
    }
|   VOID Ident LPAREN FuncFParams RPAREN Block  //{printf("VOID -> FuncType Ident LPAREN FuncFParams RPAREN Block\n");}
    {
        printf("void %s ( FuncFParams ) Block -> FuncDef\n", $2);
    }
|   INT Ident LPAREN FuncFParams RPAREN Block  //{printf("INT -> FuncType Ident LPAREN FuncFParams RPAREN Block\n");}
    {
        printf("int %s ( FuncFParams ) Block -> FuncDef\n", $2);
    }
;

/*
FuncType
:   VOID    {printf("FuncType -> VOID\n");}
|   INT {printf("FuncType -> INT\n");}
;
*/

FuncFParams
:   FuncFParam  //{printf("FuncFParams -> FuncFParam\n");}
    {
        printf("FuncFParam -> FuncFParams\n");
    }
|   FuncFParams COMMA FuncFParam    //{printf("FuncFParams -> FuncFParam {COMMA FuncFParam}\n");}
    {
        printf("FuncFParams , FuncFParam -> FuncFParams\n");
    }
;

FuncFParam
:   INT Ident //{printf("FuncFParam -> INT Ident\n");}
    {
        printf("int %s -> FuncFParam\n", $2);
    }
|   INT Ident LBRACK RBRACK   //{printf("FuncFParam -> INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}]\n");}
    {
        //printf("INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}] -> FuncFParam\n");
        printf("int %s [ ] -> FuncFParam\n", $2);
    }
|   INT Ident LBRACK RBRACK FuncFParamArr //{printf("FuncFParam -> INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}]\n");}
    {
        //printf("INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}] -> FuncFParam\n");
        printf("int %s [ ] FuncFParamArr -> FuncFParam\n", $2);
    }
;

FuncFParamArr
:   LBRACK Exp RBRACK   //{printf("FuncFParamArr -> LBRACK Exp RBRACK\n");}
    {
        printf("[ Exp ] -> FuncFParamArr\n");
    }
|   FuncFParamArr LBRACK Exp RBRACK //{printf("FuncFParamArr -> FuncFParamArr LBRACK Exp RBRACK\n");}
    {
        printf("FuncFParamArr [ Exp ] -> FuncFParamArr\n");
    }
;

Block
:   LBRACE RBRACE   //{printf("Block -> LBRACE RBRACE\n");}
    {
        //printf("LBRACE RBRACE -> Block\n");
        printf("{ } -> Block\n");
    }
|   LBRACE BlockGroup RBRACE //{printf("Block -> LBRACE {BlockItem} RBRACE\n");}
    {
        //printf("LBRACE {BlockItem} RBRACE -> Block\n");
        printf("{ BlockGroup } -> Block\n");
    }
;

BlockGroup
:   BlockItem   //{printf("BlockGroup -> BlockItem\n");}
    {
        printf("BlockItem -> BlockGroup\n");
    }
|   BlockGroup BlockItem    //{printf("BlockGroup -> BlockGroup BlockItem\n");}
    {
        printf("BlockGroup BlockItem -> BlockGroup\n");
    }
;

BlockItem
:   Decl    //{printf("BlockItem -> Decl\n");}
    {
        printf("Decl -> BlockItem\n");
    }
|   Stmt    //{printf("BlockItem -> Stmt\n");}
    {
        printf("Stmt -> BlockItem\n");
    
    }
;

Stmt
:   LVal ASSIGN Exp SEMI    //{printf("Stmt -> LVal ASSIGN Exp SEMI\n");}
    {
        printf("LVal = Exp ; -> Stmt\n");
    
    }
|   SEMI    //{printf("Stmt -> SEMI\n");}
    {
        printf("; -> Stmt\n");
    }
|   Exp SEMI       //{printf("Stmt -> Exp SEMI\n");}
    {
        printf("Exp ; -> Stmt\n");
    }
|   Block   //{printf("Stmt -> Block\n");}
    {
        printf("Block -> Stmt\n");
    }
|   IF LPAREN Cond RPAREN Stmt %prec IF //{printf("Stmt -> IF LPAREN Cond RPAREN Stmt\n");}
    {
        printf("if ( Cond ) Stmt -> Stmt\n");
    }
|   IF LPAREN Cond RPAREN Stmt ELSE Stmt    //{printf("Stmt -> IF LPAREN Cond RPAREN Stmt ELSE Stmt\n");}
    {
        //printf("IF LPAREN Cond RPAREN Stmt ELSE Stmt -> Stmt\n");
        printf("if ( Cond ) Stmt else Stmt -> Stmt\n");
    }
|   WHILE LPAREN Cond RPAREN Stmt   //{printf("Stmt -> WHILE LPAREN Cond RPAREN Stmt\n");}
    {
        //printf("WHILE LPAREN Cond RPAREN Stmt -> Stmt\n");
        printf("while ( Cond ) Stmt -> Stmt\n");
    }
|   BREAK SEMI  //{printf("Stmt -> BREAK SEMI\n");}
    {
        //printf("BREAK SEMI -> Stmt\n");
        printf("break ; -> Stmt\n");
    }
|   CONTINUE SEMI   //{printf("Stmt -> CONTINUE SEMI\n");}
    {
        //printf("CONTINUE SEMI -> Stmt\n");
        printf("continue ; -> Stmt\n");
    }
|   RETURN SEMI //{printf("Stmt -> RETURN SEMI\n");}
    {
        //printf("RETURN SEMI -> Stmt\n");
        printf("return ; -> Stmt\n");
    }
|   RETURN Exp SEMI //{printf("Stmt -> RETURN Exp SEMI\n");}
    {
        //printf("RETURN Exp SEMI -> Stmt\n");
        printf("return Exp ; -> Stmt\n");
    }
;

Exp
:   AddExp  //{printf("Exp -> AddExp\n");}
    {
        printf("AddExp -> Exp\n");
    }
;

Cond
:   LOrExp   //{printf("Cond -> LOrExp\n");}
    {
        printf("LOrExp -> Cond\n");
    }
;

LVal
:   Ident   //{printf("LVal -> Ident\n");}
    {
        printf("%s -> LVal\n", $1);
    }
|   LVal Arr    //{printf("LVal -> Ident {LBRACK Exp RBRACK}\n");}
    {
        //printf("Ident {LBRACK Exp RBRACK} -> LVal\n");
        printf("LVal Arr -> LVal\n");
    }
;

Arr
:   LBRACK Exp RBRACK   //{printf("Arr -> LBRACK Exp RBRACK\n");}
    {
        printf("[ Exp ] -> Arr\n");
    }
|   Arr LBRACK Exp RBRACK   //{printf("Arr -> Arr LBRACK Exp RBRACK\n");}
    {
        printf("Arr [ Exp ] -> Arr\n");
    }
;

PrimaryExp
:   LPAREN Exp RPAREN   //{printf("PrimaryExp -> LPAREN Exp RPAREN\n");}
    {
        //printf("LPAREN Exp RPAREN -> PrimaryExp\n");
        printf("( Exp ) -> PrimaryExp\n");
    
    }
|   LVal    //{printf("PrimaryExp -> LVal\n");}
    {
        printf("LVal -> PrimaryExp\n");
    }
|   IntConst  //{printf("PrimaryExp -> Number\n");}
    {
        printf("%d -> PrimaryExp\n", $1);
    }
;

// Number
// :   IntConst    //{printf("Number -> IntConst\n");}
// ;

UnaryExp
:   PrimaryExp  //{printf("UnaryExp -> PrimaryExp\n");}
    {
        printf("PrimaryExp -> UnaryExp\n");
    }
|   Ident LPAREN RPAREN   //{printf("UnaryExp -> Ident LPAREN RPAREN\n");}
    {
        //printf("Ident LPAREN RPAREN -> UnaryExp\n");
        printf("%s ( ) -> UnaryExp\n", $1);
    }
|   Ident LPAREN FuncRParams RPAREN  //{printf("UnaryExp -> Ident LPAREN FuncRParams RPAREN\n");}
    {
        //printf("Ident LPAREN FuncRParams RPAREN -> UnaryExp\n");
        printf("%s ( FuncRParams ) -> UnaryExp\n", $1);
    }
|   UnaryOp UnaryExp    //{printf("UnaryExp -> UnaryOp UnaryExp\n");}
    {
        printf("UnaryOp UnaryExp -> UnaryExp\n");
    }
;

UnaryOp
:   ADD //{printf("UnaryOp -> ADD\n");}
    {
        //printf("ADD -> UnaryOp\n");
        printf("+ -> UnaryOp\n");
    }
|   SUB //{printf("UnaryOp -> SUB\n");}
    {
        //printf("SUB -> UnaryOp\n");
        printf("- -> UnaryOp\n");
    }
|   NOT //{printf("UnaryOp -> NOT\n");}
    {
        //printf("NOT -> UnaryOp\n");
        printf("! -> UnaryOp\n");
    }
;

FuncRParams
:   Exp //{printf("FuncRParams -> Exp\n");}
    {
        printf("Exp -> FuncRParams\n");
    }
|   Exp FuncRParamsGroup    //{printf("FuncRParams -> Exp {COMMA Exp}\n");}
    {
        //printf("Exp {COMMA Exp} -> FuncRParams\n");
        printf("Exp FuncRParamsGroup -> FuncRParams\n");
    }
;

FuncRParamsGroup
:   COMMA Exp   //{printf("FuncRParamsGroup -> COMMA Exp\n");}
    {
        printf(", Exp -> FuncRParamsGroup\n");
    }  
|   FuncRParamsGroup COMMA Exp  //{printf("FuncRParamsGroup -> FuncRParamsGroup COMMA Exp\n");}
    {
        printf("FuncRParamsGroup , Exp -> FuncRParamsGroup\n");
    }
;

MulExp
:   UnaryExp    //{printf("MulExp -> UnaryExp\n");}
    {
        printf("UnaryExp -> MulExp\n");
    
    }
|   MulExp MUL UnaryExp   //{printf("MulExp -> MulExp MUL UnaryExp\n");}
    {
        //printf("MulExp MUL UnaryExp -> MulExp\n");
        printf("MulExp * UnaryExp -> MulExp\n");
    }
|   MulExp DIV UnaryExp  //{printf("MulExp -> MulExp DIV UnaryExp\n");}
    {
        //printf("MulExp DIV UnaryExp -> MulExp\n");
        printf("MulExp / UnaryExp -> MulExp\n");
    }
|   MulExp MOD UnaryExp //{printf("MulExp -> MulExp MOD UnaryExp\n");}
    {
        //printf("MulExp MOD UnaryExp -> MulExp\n");
        printf("MulExp %% UnaryExp -> MulExp\n");
    }
;

AddExp
:   MulExp  //{printf("AddExp -> MulExp\n");}
    {
        printf("MulExp -> AddExp\n");
    
    }
|   AddExp ADD MulExp   //{printf("AddExp -> AddExp ADD MulExp\n");}
    {
        //printf("AddExp ADD MulExp -> AddExp\n");
        printf("AddExp + MulExp -> AddExp\n");
    }
|   AddExp SUB MulExp   //{printf("AddExp -> AddExp SUB MulExp\n");}
    {
        //printf("AddExp SUB MulExp -> AddExp\n");
        printf("AddExp - MulExp -> AddExp\n");
    }
;

RelExp
:   AddExp  //{printf("RelExp -> AddExp\n");}
    {
        printf("AddExp -> RelExp\n");
    }
|   RelExp LT AddExp    //{printf("RelExp -> RelExp LT AddExp\n");}
    {
        //printf("RelExp LT AddExp -> RelExp\n");
        printf("RelExp < AddExp -> RelExp\n");
    }
|   RelExp LE AddExp    //{printf("RelExp -> RelExp LE AddExp\n");}
    {
        //printf("RelExp LE AddExp -> RelExp\n");
        printf("RelExp <= AddExp -> RelExp\n");
    }
|   RelExp GT AddExp    //{printf("RelExp -> RelExp GT AddExp\n");}
    {
        //printf("RelExp GT AddExp -> RelExp\n");
        printf("RelExp > AddExp -> RelExp\n");
    }
|   RelExp GE AddExp    //{printf("RelExp -> RelExp GE AddExp\n");}
    {
        //printf("RelExp GE AddExp -> RelExp\n");
        printf("RelExp >= AddExp -> RelExp\n");
    }
;

EqExp
:   RelExp  //{printf("EqExp -> RelExp\n");}
    {
        printf("RelExp -> EqExp\n");
    }
|   EqExp EQ RelExp //{printf("EqExp -> EqExp EQ RelExp\n");}
    {
        //printf("EqExp EQ RelExp -> EqExp\n");
        printf("EqExp == RelExp -> EqExp\n");
    }
|   EqExp NE RelExp //{printf("EqExp -> EqExp NE RelExp\n");}
    {
        //printf("EqExp NE RelExp -> EqExp\n");
        printf("EqExp != RelExp -> EqExp\n");
    }
;

LAndExp
:   EqExp   //{printf("LAndExp -> EqExp\n");}
    {
        printf("EqExp -> LAndExp\n");
    }
|   LAndExp AND EqExp   //{printf("LAndExp -> LAndExp AND EqExp\n");}
    {
        //printf("LAndExp AND EqExp -> LAndExp\n");
        printf("LAndExp && EqExp -> LAndExp\n");
    }
;

LOrExp
:   LAndExp   //{printf("LOrExp -> LAndExp\n");}
    {
        printf("LAndExp -> LOrExp\n");
    }
|   LOrExp OR LAndExp   //{printf("LOrExp -> LOrExp OR LAndExp\n");}
    {
        //printf("LOrExp OR LAndExp -> LOrExp\n");
        printf("LOrExp || LAndExp -> LOrExp\n");
    }
;

ConstExp
:   AddExp  //{printf("ConstExp -> AddExp\n");}
    {
        printf("AddExp -> ConstExp\n");
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}