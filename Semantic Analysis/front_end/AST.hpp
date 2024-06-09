#pragma once
#include <stdexcept>
#include <vector>
#include <string>
#include <memory>
#include <variant>
// #include "const_eval_helper.hpp"

struct BaseAST;
struct CompUnitAST;
struct ExternalDefAST;
struct DeclAST;

struct ConstDeclAST;
struct ConstDefListAST;
struct ConstDefAST;
struct ConstArrDefAST;
struct ConstInitValAST;
struct ConstInitValListAST;

struct VarDeclAST;
struct VarDefListAST;
struct VarDefAST;
struct ArrDefAST;
struct InitValAST;
struct InitValListAST;

struct FuncDefAST;
struct FuncFParamsAST;
struct FuncFParamAST;

struct BlockAST;
struct BlockGroupAST;
struct BlockItemAST;
/**
 * Stmt :== ; -> NullStmtAST
 *          | Exp ; -> ExpStmtAST
 *          | LVal = Exp ;  -> AssignStmtAST
            | Block     -> BlockStmtAST
            | if ( Cond ) Stmt | if ( Cond ) Stmt else Stmt -> IfStmtAST
            | while ( Cond ) Stmt   -> WhileStmtAST
            | break ;   -> BreakStmtAST
            | continue ;    -> ContinueStmtAST
            | return ;  -> ReturnStmtAST
            | return Exp ;  -> ReturnStmtAST
*/
struct StmtAST;
struct NullStmtAST;
struct AssignStmtAST;
struct ExpStmtAST;
struct BlockStmtAST;
struct IfStmtAST;
struct WhileStmtAST;
struct BreakStmtAST;
struct ContinueStmtAST;
struct ReturnStmtAST;

struct LValAST;

struct ExpAST;
struct BinaryExpAST;
struct VarExpAST;
struct NumExpAST;
struct UnaryExpAST;
struct FuncCallAST;
struct UnaryOpAST;
struct FuncRParamsAST;

struct BaseAST {
public:
    BaseAST() {}
    virtual ~BaseAST() = default;
    virtual void const_eval(BaseAST *&root) {
        throw std::logic_error("This function is not implemented");
    }
    virtual void code_gen() {
        throw std::logic_error("This function is not implemented");
    }
};

struct DeclAST : public BaseAST {
public:
    std::variant<ConstDeclAST*, VarDeclAST*> decl;
    DeclAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct ExpAST : public BaseAST {
public:
    int offset;
    bool is_pointer = false;
    ExpAST() {}
};

struct StmtAST : public BaseAST {
public:
    StmtAST() {}
};

struct CompUnitAST : public BaseAST {
public:
    std::vector<ExternalDefAST*> external_defs;
    std::vector<DeclAST*> decls;
    std::vector<FuncDefAST*> func_defs;
    CompUnitAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct ExternalDefAST : public BaseAST {
public:
    std::string value = "#include ";
    ExternalDefAST(std::string header_file) {
        value += header_file;
    }
    void code_gen();
};

struct ConstArrDefAST : public BaseAST {
public:
    std::string ident;
    std::vector<ExpAST*> dim;
    ConstArrDefAST() {}
    // void const_eval(BaseAST *&root) {};
};

struct ConstDeclAST : public BaseAST {
public:
    std::vector<ConstDefAST*> const_defs;
    ConstDeclAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct ConstDefAST : public BaseAST {
public:
    std::string ident;
    // 数组维度，普通变量为空，数组变量为数组维度
    // 维度不一定是字面值常量，有可能是表达式
    // std::vector<ConstExpAST*> dim;
    std::vector<ExpAST*> dim;
    ConstInitValAST* const_init_val;
    ConstDefAST() {}
    // void const_eval(BaseAST *&root) {};
    void code_gen();
};

struct ConstDefListAST : public ConstDefAST {
public:
    std::vector<ConstDefAST*> const_defs;
    ConstDefListAST() {}
    // void const_eval(BaseAST *&root) {};
};


struct ConstInitValAST : public BaseAST {
public:
    // std::variant<ConstExpAST*, ConstInitValListAST*> value;
    std::variant<std::monostate, ExpAST*, ConstInitValListAST*> value;
    ConstInitValAST() {}
    void const_eval(BaseAST *&root) ;
};

struct ConstInitValListAST : public ConstInitValAST {
public:
    std::vector<ConstInitValAST*> const_init_vals;
    ConstInitValListAST() {}
    void const_eval(BaseAST *&root) ;
};

struct ArrDefAST : public BaseAST {
public:
    std::string ident;
    std::vector<ExpAST*> dim;
    ArrDefAST() {}
    // void const_eval(BaseAST *&root) {};
};

struct VarDeclAST : public BaseAST {
public:
    std::vector<VarDefAST*> var_defs;
    VarDeclAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct VarDefAST : public BaseAST {
public:
    std::string ident;
    std::vector<ExpAST*> dim;
    InitValAST* init_val;
    VarDefAST() {}
    // void const_eval(BaseAST *&root) {};
    void code_gen();
};

struct VarDefListAST : public VarDefAST {
public:
    std::vector<VarDefAST*> var_defs;
    VarDefListAST() {}
    // void const_eval(BaseAST *&root) {};
};

struct InitValAST : public BaseAST {
public:
    std::variant<std::monostate, ExpAST*, InitValListAST*> value;
    InitValAST() {}
    void const_eval(BaseAST *&root) ;
};

struct InitValListAST : public InitValAST {
public:
    std::vector<InitValAST*> init_vals;
    InitValListAST() {}
    void const_eval(BaseAST *&root) ;
};

struct FuncDefAST : public BaseAST {
public:
    bool return_type;
    std::string ident;
    std::vector<FuncFParamAST*> f_args;
    BlockAST* block;
    FuncDefAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct FuncFParamAST : public BaseAST {
public:
    std::string ident;
    std::vector<ExpAST*> dim;
    FuncFParamAST() {}
    void const_eval(BaseAST *&root) ;
};

struct FuncFParamsAST : public FuncFParamAST {
public:
    std::vector<FuncFParamAST*> f_args;
    FuncFParamsAST() {
    }
    // void const_eval(BaseAST *&root) {};
};

struct BlockAST : public BaseAST {
public:
    std::vector<BlockItemAST*> block_items;
    BlockAST() {
    }
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct BlockGroupAST : public BaseAST {
public:
    std::vector<BlockItemAST*> block_items;
    BlockGroupAST() {
    }
    // void const_eval(BaseAST *&root) {};
};

struct BlockItemAST : public BaseAST {
public:
    std::variant<StmtAST*, DeclAST*> block_item;
    BlockItemAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct  LValAST : public BaseAST {
public:
    std::string ident;
    std::vector<ExpAST*> dim;
    LValAST() {}
    // void const_eval(BaseAST *&root) {};
};

struct NullStmtAST : public StmtAST {
public:
    NullStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct AssignStmtAST : public StmtAST {
public:
    LValAST* lvalue;
    ExpAST* rvalue;
    AssignStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct ExpStmtAST : public StmtAST {
public:
    ExpAST* exp;
    ExpStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct BlockStmtAST : public StmtAST {
public:
    // BlockAST* block;
    std::vector<BlockItemAST*> block_items;
    BlockStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct IfStmtAST : public StmtAST {
public:
    ExpAST* cond;
    StmtAST* then_stmt;
    StmtAST* else_stmt;
    IfStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct WhileStmtAST : public StmtAST {
public:
    ExpAST* cond;
    StmtAST* stmt;
    WhileStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct BreakStmtAST : public StmtAST {
public:
    BreakStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct ContinueStmtAST : public StmtAST {
public:
    ContinueStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct ReturnStmtAST : public StmtAST {
public:
    ExpAST* exp;
    ReturnStmtAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct UnaryExpAST : public ExpAST {
public:
    std::string ident;
    std::string op;
    // std::variant<ExpAST*, UnaryExpAST*, FuncRParamsAST*> value;
    ExpAST* value;
    UnaryExpAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct FuncCallAST : public ExpAST {
public:
    std::string ident;
    // FuncRParamsAST* r_params;
    std::string format_output = "";
    std::vector<ExpAST*> r_args;
    FuncCallAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct BinaryExpAST : public ExpAST {
public:
    std::string op;
    ExpAST* lhs;
    ExpAST* rhs;
    std::vector<int> true_list, false_list;
    BinaryExpAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct VarExpAST : public ExpAST {
public:
    std::string ident;
    std::vector<ExpAST*> dim;
    VarExpAST() {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct NumExpAST : public ExpAST {
public:
    int value;
    NumExpAST() {}
    NumExpAST(int _value) : value(_value) {}
    void const_eval(BaseAST *&root) ;
    void code_gen();
};

struct UnaryOpAST : public BaseAST {
public:
    std::string op;
    UnaryOpAST() {}
    // void const_eval(BaseAST *&root) {};
};

struct FuncRParamsAST : public ExpAST {
public:
    std::string str = std::string("");
    std::vector<ExpAST*> r_args;
    FuncRParamsAST() {}
    // void const_eval(BaseAST *&root) {};
};

extern BaseAST* root;
void show_ast(BaseAST *ast, int depth = 0);

/* Deprecated */

// enum struct Type {
//     COMPUNIT,
//     EXTERNALDEF,
//     DECL,
//     CONSTDECL,
//     CONSTDEFLIST,
//     CONSTDEF,
//     CONSTARRDEF,
//     CONSTINITVAL,
//     CONSTINITVALLIST,
//     CONSTEXP,
//     VARDECL,
//     VARDEFLIST,
//     VARDEF,
//     ARRDEF,
//     INITVAL,
//     INITVALLIST,
//     FUNCDEF,
//     FUNCFPARAMS,
//     FUNCFPARAM,
//     BLOCK,
//     BLOCKGROUP,
//     BLOCKITEM,
//     STMT,
//     NULLSTMT,
//     ASSIGNSTMT,
//     EXPSTMT,
//     BLOCKSTMT,
//     IFSTMT,
//     WHILESTMT,
//     BREAKSTMT,
//     CONTINUESTMT,
//     RETURNSTMT,
//     LVAL,
//     COND,
//     EXP,
//     PRIMARYEXP,
//     UNARYEXP,
//     BINARYEXP,
//     VAREXP,
//     FUNCCALL,
//     UNARYOP,
//     FUNCRPARAMS,
//     MULEXP,
//     ADDEXP,
//     RELEXP,
//     EQEXP,
//     LANDEXP,
//     LOREXP,
// };

// struct ConstExpAST;
// struct CondAST;
// struct PrimaryExpAST;
// struct MulExpAST;
// struct AddExpAST;
// struct RelExpAST;
// struct EqExpAST;
// struct LAndExpAST;
// struct LOrExpAST;

// struct ConstExpAST : public BaseAST {
// public:
//     AddExpAST* add_exp;
//     ConstExpAST() {
//         type = Type::CONSTEXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };


// struct CondAST : public BaseAST {
// public:
//     LOrExpAST* l_or_exp;
//     CondAST() {
//         type = Type::COND;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct PrimaryExpAST : public BaseAST {
// public:
//     std::variant<LValAST*, int, ExpAST*> value;
//     PrimaryExpAST() {
//         type = Type::PRIMARYEXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct MulExpAST : public BaseAST {
// public:
//     UnaryExpAST* unary_exp;
//     MulExpAST* mul_exp;
//     std::string op;
//     MulExpAST() {
//         type = Type::MULEXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct AddExpAST : public BaseAST {
// public:
//     MulExpAST* mul_exp;
//     AddExpAST* add_exp;
//     std::string op;
//     AddExpAST() {
//         type = Type::ADDEXP;
//     }
//     //int get_value();
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct RelExpAST : public BaseAST {
// public:
//     AddExpAST* add_exp;
//     RelExpAST* rel_exp;
//     std::string rel_op;
//     RelExpAST() {
//         type = Type::RELEXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct EqExpAST : public BaseAST {
// public:
//     RelExpAST* rel_exp;
//     EqExpAST* eq_exp;
//     std::string eq_op;
//     EqExpAST() {
//         type = Type::EQEXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct LAndExpAST : public BaseAST {
// public:
//     EqExpAST* eq_exp;
//     LAndExpAST* l_and_exp;
//     LAndExpAST() {
//         type = Type::LANDEXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };

// struct LOrExpAST : public BaseAST {
// public:
//     LAndExpAST* l_and_exp;
//     LOrExpAST* l_or_exp;
//     LOrExpAST() {
//         type = Type::LOREXP;
//     }
//     // void const_eval(BaseAST *&root) {};
//     // template <typename Ty>
//     // typename std::enable_if_t<std::is_base_of_v<BaseAST, Ty>, void>
//     // const_eval(Ty *&root) {}
// };