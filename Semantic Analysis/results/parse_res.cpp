#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <algorithm>

#define SIZE 8

using namespace std;

const int N = 100010;

typedef vector<string> State;

struct Variable
{
    string name;
    int offset = 0, size, val;
    bool isGlobal = false, isConst;
    vector<int> arr = vector<int>();
    string addrReg;
    string trueName;
};

struct Node
{
    State state;
    vector<int> son;
} node[N];

unordered_set<string> nonTerminator = {"CompUnit", "Decl", "ConstDecl", "ConstDefList", "ConstDef", "ConstArray",
                                       "array", "ConstInitVal", "ConstInitValList", "VarDecl", "VarDefList",
                                       "VarDef", "InitVal", "InitValList", "FuncDef", "FuncDef", "FuncFParams",
                                       "FuncFParam", "Block", "BlockItemList", "BlockItem", "Stmt",
                                       "Exp", "Cond", "LVal", "PrimaryExp", "UnaryExp",
                                       "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp",
                                       "LAndExp", "LOrExp", "ConstExp"};
stack<string> statements;
vector<string> codes;
unordered_map<string, string> varRegister;
stack<unordered_set<string>> S;
vector<unordered_map<string, Variable>> varMap;
stack<pair<string, string>> stk;
fstream sourceFile, writeFile;
int offset, tmp, jumpNum, idx;
string firstOp, info;
bool isFirst = true;

void init();
vector<string> getNext();
Variable operate(const Variable &a, const Variable &b, string op);
Variable unOperate(const Variable &a, string op);
Variable getVar(string name);
int buildSyntaxTree(int u);
string findFree();
void saveReg();
void popReg();

void doCompUnit(int u);
void doDecl(int u);
void doFuncDef(int u);
void doConstDecl(int u);
void doConstDefList(int u);
void doConstDef(int u);
int doConstInitVal(int u);
int doConstExp(int u);
void doVarDecl(int u);
void doVarDefList(int u);
void doVarDef(int u);
Variable doArray(int u, int t, vector<int> arr);
vector<int> doConstArray(int u);
Variable doInitVal(int u);
Variable doExp(int u);
Variable doAddExp(int u);
Variable doMulExp(int u);
Variable doUnaryExp(int u);
Variable doPrimaryExp(int u);
Variable doLVal(int u);
vector<Variable> doFuncRParams(int u);
vector<Variable> doFuncFParams(int u, int off);
Variable doFuncFParam(int u, int off);
void doBlock(int u, bool flag);
void doBlockItemList(int u);
void doBlockItem(int u);
void doStmt(int u);
void doReturn(int u, int size);
void doIf(int u);
Variable doCond(int u);
Variable doLOrExp(int u);
Variable doLAndExp(int u);
Variable doEqExp(int u);
Variable doRelExp(int u);
void doWhile(int u);
void doBreak(int u);
void doContinue(int u);
void doScanf(const Variable &v);
void doPrintf(const Variable &var);

int main()
{
    init();
    sourceFile.open("./6/6-substr", ios::in);

    while (getline(sourceFile, info))
        statements.push(info);

    buildSyntaxTree(0);

    sourceFile.close();
    varMap.emplace_back();

    doCompUnit(0);

    writeFile.open("test.s", ios::out);
    bool flag = true;
    for (auto &it : codes)
    {
        if (!flag || (it.substr(1, 4) != "movq" && it.substr(1, 4) != "leaq" &&
                      it.substr(1, 4) != "addq" && it.substr(1, 5) != "imulq"))
            writeFile << it << endl;
        if (it.substr(1, 6) == ".globl")
            flag = false;
    }
    writeFile.close();

    return 0;
}

void init()
{
    varRegister["t-1"] = "%rcx";
    codes.emplace_back(".LC0:");
    codes.emplace_back("\t.string\t\"%lld\"");
    codes.emplace_back(".LC1:");
    codes.emplace_back("\t.string\t\"%lld\\n\"");
    S.emplace();
    for (int i = 8; i <= 15; i++)
    {
        string regv = "%r" + to_string(i);
        S.top().insert(regv);
    }
    S.top().insert("%rbx");
}

State getNext()
{
    info = statements.top();
    statements.pop();
    stringstream ss(info);
    State items;
    string item;
    while (ss >> item)
        items.emplace_back(item);
    items.pop_back();
    items.pop_back();
    return items;
}

Variable operate(const Variable &a, const Variable &b, string op)
{
    string reg1 = varRegister[a.name], reg2 = varRegister[b.name];
    Variable var = {"t" + to_string(++tmp), 0, SIZE};
    if (op == "+")
    {
        codes.emplace_back("\taddq\t" + reg2 + ", " + reg1);
        var.val = a.val + b.val;
    }
    if (op == "-")
    {
        codes.emplace_back("\tsubq\t" + reg2 + ", " + reg1);
        var.val = a.val - b.val;
    }
    if (op == "*")
    {
        codes.emplace_back("\timulq\t" + reg2 + ", " + reg1);
        var.val = a.val * b.val;
    }
    if (op == "/")
    {
        codes.emplace_back("\tmovq\t" + reg1 + ", " + "%rax");
        codes.emplace_back("\tcltq");
        codes.emplace_back("\tidivlq\t" + reg2);
        codes.emplace_back("\tmovqt%rax, " + reg1);
        var.val = a.val / b.val;
    }
    varRegister[var.name] = reg1;
    S.top().insert(reg2);
    S.top().insert(a.addrReg);

    return var;
}

Variable unOperate(const Variable &a, string op)
{
    string reg = varRegister[a.name];
    Variable var = {"t" + to_string(++tmp) + "d", 0, SIZE};
    if (op == "-")
    {
        codes.emplace_back("\tneg\t\t" + reg);
        var.val = -a.val;
    }
    if (op == "!")
    {
        codes.emplace_back("\tmovq\t$0, %rax");
        codes.emplace_back("\tmovq\t$1, %rcx");
        codes.emplace_back("\tcmpq\t" + reg + ", %rax");
        codes.emplace_back("\tcmove\t%rcx, %rax");
        codes.emplace_back("\tmovq\t%rax, " + reg);
        var.val = !a.val;
    }
    varRegister[var.name] = reg;
    return var;
}

Variable getVar(string name)
{
    for (int i = varMap.size() - 1; i >= 0; i--)
    {
        auto it = varMap[i];
        for (auto t : it)
        {
            if (t.first == name)
            {
                if (!i)
                    t.second.isGlobal = true;
                return t.second;
            }
        }
    }
    return {};
}

int buildSyntaxTree(int u)
{
    node[u].state = getNext();
    for (int i = node[u].state.size() - 1; i >= 0; i--)
        if (nonTerminator.count(node[u].state[i]))
            node[u].son.push_back(buildSyntaxTree(++idx));
    reverse(node[u].son.begin(), node[u].son.end());
    return u;
}

string findFree()
{
    for (int i = 8; i <= 15; i++)
    {
        string regv = "%r" + to_string(i);
        if (S.top().count(regv))
            return regv;
    }
    if (S.top().count("%rbx"))
        return "%rbx";
    return "";
}

void saveReg()
{
    S.emplace();
    S.top().insert("%rbx");
    codes.emplace_back("\tpushq\t%rbx");
    codes.emplace_back("\tpushq\t%rcx");
    for (int i = 8; i <= 15; i++)
    {
        string regv = "%r" + to_string(i);
        codes.emplace_back("\tpushq\t" + regv);
        S.top().insert(regv);
    }
}
void popReg()
{
    for (int i = 15; i >= 8; i--)
        codes.emplace_back("\tpopq\t %r" + to_string(i));
    codes.emplace_back("\tpopq\t%rcx");
    codes.emplace_back("\tpopq\t%rbx");
}

void doCompUnit(int u)
{
    State state = node[u].state;
    if (state.size() == 1)
    {
        if (state[0] == "Decl")
            doDecl(node[u].son[0]);
        else
            doFuncDef(node[u].son[0]);
    }
    if (state.size() == 2)
    {
        doCompUnit(node[u].son[0]);
        if (state[1] == "Decl")
            doDecl(node[u].son[1]);
        else
            doFuncDef(node[u].son[1]);
    }
}

void doDecl(int u)
{
    State state = node[u].state;
    if (state[0] == "ConstDecl")
        doConstDecl(node[u].son[0]);
    else
        doVarDecl(node[u].son[0]);
}

void doFuncDef(int u)
{
    offset = 8;
    isFirst = false;
    State state = node[u].state;
    codes.emplace_back("\t.globl\t" + state[1]);
    if (isFirst)
        codes.emplace_back("\t.type\tmain, @function");
    codes.emplace_back(state[1] + ":");
    codes.emplace_back("\tpushq\t%rbp");
    saveReg();
    codes.emplace_back("\tmovq\t%rsp, %rbp");
    codes.emplace_back("\tsubq\t$32, %rsp");
    varMap.emplace_back();
    auto vars = doFuncFParams(node[u].son[0], offset);
    for (int i = 0; i < vars.size(); i++)
    {
        auto var = vars[i];
        if (var.name.empty())
            continue;
        varMap[varMap.size() - 1][var.name] = var;
        int size = var.size / 16 * 16 + 16;
        codes.emplace_back("\tsubq\t$" + to_string(size) + ", %rsp");
        if (!i)
            codes.emplace_back("\tmovq\t %rdi, " + to_string(-offset) + "(%rbp)");
        else
            codes.emplace_back("\tmovq\t %rsi, " + to_string(-offset) + "(%rbp)");
        offset += size;
    }
    doBlock(node[u].son[1], false);
    if (state[0] == "void")
        popReg();
    codes.emplace_back("\tmovq\t%rbp, %rsp");
    popReg();
    S.pop();
    codes.emplace_back("\tpopq\t%rbp");
    codes.emplace_back("\tret");
}

void doConstDecl(int u)
{
    State state = node[u].state;
    doConstDefList(node[u].son[0]);
}

void doConstDefList(int u)
{
    State state = node[u].state;
    doConstDef(node[u].son[0]);
}

void doConstDef(int u)
{
    State state = node[u].state;
    int val = doConstInitVal(node[u].son[1]);
    Variable var = {state[0], 0, SIZE, val, true, true};
    varMap[varMap.size() - 1].insert({state[0], var});
    codes.emplace_back(state[0] + ":");
    codes.emplace_back("\t.long\t" + to_string(val));
}

int doConstInitVal(int u)
{
    State state = node[u].state;
    return doConstExp(node[u].son[0]);
}

int doConstExp(int u)
{
    State state = node[u].state;
    auto var = doExp(node[u].son[0]);
    S.top().insert(varRegister[var.name]);
    S.top().insert(var.addrReg);
    return var.val;
}

void doVarDecl(int u)
{
    State state = node[u].state;
    doVarDefList(node[u].son[0]);
}

void doVarDefList(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        doVarDefList(node[u].son[0]);
        doVarDef(node[u].son[1]);
    }
    else
    {
        doVarDef(node[u].son[0]);
    }
}

void doVarDef(int u)
{
    State state = node[u].state;
    Variable init;
    if (state.size() == 4)
        init = doInitVal(node[u].son[1]);
    vector<int> arr = doConstArray(node[u].son[0]);
    Variable var;
    int size = SIZE;
    for (auto it : arr)
        size *= it;
    var = {state[0], offset, size, 0, false, false, arr};
    varMap[varMap.size() - 1][state[0]] = var;
    size = size / 16 * 16 + 16;
    if (varMap.size() == 1)
        codes.emplace_back("\t.comm\t" + state[0] + +"," + to_string(size) + ",32");
    else
    {
        codes.emplace_back("\tsubq\t$" + to_string(size) + ", %rsp");
        offset += size;
    }
    if (!varRegister[init.name].empty())
        codes.emplace_back("\tmovq\t" + varRegister[init.name] + ", " + to_string(-var.offset) + "(%rbp)");
    S.top().insert(varRegister[init.name]);
    S.top().insert(init.addrReg);
}

Variable doArray(int u, int t, vector<int> arr)
{
    State state = node[u].state;
    if (state[0] == "empty")
    {
        if (!t)
            return {"t-1", 0, SIZE};
        Variable var = {"t" + to_string(++tmp), 0, SIZE};
        varRegister[var.name] = findFree();
        S.top().erase(varRegister[var.name]);
        codes.emplace_back("\tmovq\t$0, " + varRegister[var.name]);
        return var;
    }
    auto var = doArray(node[u].son[0], t + 1, arr);
    Variable exp = doExp(node[u].son[1]);
    int res = 1;
    for (int i = arr.size() - t; i < arr.size(); i++)
        res *= arr[i];
    codes.emplace_back("\tmovq\t$" + to_string(res) + ", " + "%rcx");
    codes.emplace_back("\timulq\t%rcx, " + varRegister[exp.name]);
    codes.emplace_back("\taddq\t" + varRegister[exp.name] + ", " + varRegister[var.name]);
    S.top().insert(varRegister[exp.name]);
    S.top().insert(exp.addrReg);
    return var;
}

vector<int> doConstArray(int u)
{
    State state = node[u].state;
    if (state[0] == "empty")
        return {};
    vector<int> vec = doConstArray(node[u].son[0]);
    int v = doConstExp(node[u].son[1]);
    vec.emplace_back(v);
    return vec;
}

Variable doInitVal(int u)
{
    State state = node[u].state;
    return doExp(node[u].son[0]);
}

Variable doExp(int u)
{
    State state = node[u].state;
    return doAddExp(node[u].son[0]);
}

Variable doAddExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        auto v1 = doAddExp(node[u].son[0]);
        auto v2 = doMulExp(node[u].son[1]);
        return operate(v1, v2, state[1]);
    }
    else
    {
        return doMulExp(node[u].son[0]);
    }
}

Variable doMulExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        auto v1 = doMulExp(node[u].son[0]);
        auto v2 = doUnaryExp(node[u].son[1]);
        return operate(v1, v2, state[1]);
    }
    else
    {
        return doUnaryExp(node[u].son[0]);
    }
}

Variable doUnaryExp(int u)
{
    State state = node[u].state;
    if (state.size() == 1)
    {
        return doPrimaryExp(node[u].son[0]);
    }
    else if (state.size() == 4)
    {
        vector<Variable> varList = doFuncRParams(node[u].son[0]);
        if (state[0] == "scanf")
        {
            doScanf(varList[0]);
            return {};
        }
        if (state[0] == "printf")
        {
            doPrintf(varList[0]);
            return {};
        }
        for (int i = 0; i < varList.size(); i++)
        {
            string reg = varRegister[varList[i].name];
            if (i == 0)
                codes.emplace_back("\tmovq\t" + reg + ", " + "%rdi");
            else
                codes.emplace_back("\tmovq\t" + reg + ", " + "%rsi");
            S.top().insert(varRegister[varList[i].name]);
            S.top().insert(varList[i].addrReg);
        }
        codes.emplace_back("\tcall\t" + state[0]);
        Variable var = {"t" + to_string(++tmp), 0, SIZE};
        varRegister[var.name] = "%rax";
        return var;
    }
    else if (state.size() == 2 && state[0] != "!")
    {
        codes.emplace_back("\tcall\t" + state[0]);
        Variable var = {"t" + to_string(++tmp), 0, SIZE};
        varRegister[var.name] = "%rax";
        return var;
    }
    else
    {
        Variable v = doUnaryExp(node[u].son[0]);
        return unOperate(v, state[0]);
    }
}

Variable doPrimaryExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
        return doExp(node[u].son[0]);
    if (isdigit(state[0][0]))
    {
        Variable var = {"t" + to_string(++tmp), 0, 4, stoi(state[0])};
        varRegister[var.name] = findFree();
        S.top().erase(varRegister[var.name]);
        codes.emplace_back("\tmovq\t$" + state[0] + ", " + varRegister[var.name]);
        return var;
    }
    else
    {
        return doLVal(node[u].son[0]);
    }
}

Variable doLVal(int u)
{
    State state = node[u].state;
    string name = state[0];
    Variable v = getVar(name);
    Variable off = doArray(node[u].son[0], 0, v.arr);

    Variable var = {"t" + to_string(++tmp), v.offset, 4, v.val, v.isGlobal};
    varRegister[var.name] = findFree();
    S.top().erase(varRegister[var.name]);

    string regv = varRegister[var.name];
    string offsetReg = varRegister[off.name];
    var.addrReg = offsetReg;
    if (v.isGlobal)
    {
        var.trueName = v.name;
        if (v.isConst)
        {
            codes.emplace_back("\tmovq\t$" + to_string(v.val) + ", " + regv);
            codes.emplace_back("\tmovq\t$" + to_string(0) + ", " + var.addrReg);
        }
        else
        {
            codes.emplace_back("\tleaq\t" + var.trueName + "(%rip), %rax");
            if (off.name != "t-1")
            {
                codes.emplace_back("\tmovq\t$" + to_string(SIZE) + " , %rcx");
                codes.emplace_back("\timulq\t%rcx, " + varRegister[off.name]);
                codes.emplace_back("\taddq\t$" + to_string(v.offset) + ", " + offsetReg);
                codes.emplace_back("\taddq\t" + offsetReg + ", %rax");
                codes.emplace_back("\tmovq\t(%rax), " + regv);
            }
            else
            {
                codes.emplace_back("\tmovq\t(%rax), " + regv);
                codes.emplace_back("\tmovq\t$" + to_string(0) + ", " + var.addrReg);
            }
        }
    }
    else
    {
        if (off.name != "t-1")
        {
            codes.emplace_back("\tmovq\t$" + to_string(SIZE) + " , %rcx");
            codes.emplace_back("\timulq\t%rcx, " + varRegister[off.name]);
            codes.emplace_back("\taddq\t$" + to_string(v.offset) + ", " + offsetReg);
            codes.emplace_back("\tneg\t\t" + offsetReg);
            codes.emplace_back("\tmovq\t(%rbp, " + offsetReg + "), " + regv);
            codes.emplace_back("\tneg\t\t" + offsetReg);
        }
        else
        {
            codes.emplace_back("\tmovq\t" + to_string(-v.offset) + "(%rbp), " + regv);
            codes.emplace_back("\tmovq\t$" + to_string(v.offset) + ", " + var.addrReg);
        }
    }
    return var;
}

vector<Variable> doFuncRParams(int u)
{
    State state = node[u].state;
    vector<Variable> res;
    Variable var;
    if (state.size() == 3)
    {
        var = doExp(node[u].son[1]);
        res.push_back(var);
        auto last = doFuncRParams(node[u].son[0]);
        for (const auto &it : last)
            res.push_back(it);
    }
    else
    {
        var = doExp(node[u].son[0]);
        res.push_back(var);
    }
    S.top().insert(varRegister[var.name]);
    S.top().insert(var.addrReg);
    return res;
}

vector<Variable> doFuncFParams(int u, int off)
{
    State state = node[u].state;
    vector<Variable> res;
    auto var = doFuncFParam(node[u].son[0], off);
    res.emplace_back(var);
    if (state.size() == 3)
    {
        auto last = doFuncFParams(node[u].son[0], off + var.offset);
        for (const auto &it : last)
            res.emplace_back(it);
    }
    return res;
}

Variable doFuncFParam(int u, int off)
{
    State state = node[u].state;
    if (state[0] == "empty")
        return {};
    Variable var = {state[1], off, 4};
    if (state.size() > 2)
    {
        auto arr = doConstArray(node[u].son[0]);
        (int)arr.size();
    }
    return var;
}

void doBlock(int u, bool flag)
{
    if (flag)
        varMap.emplace_back();
    State state = node[u].state;
    doBlockItemList(node[u].son[0]);
    if (flag)
        varMap.pop_back();
}

void doBlockItemList(int u)
{
    State state = node[u].state;
    if (state[0] == "empty")
        return;
    doBlockItemList(node[u].son[0]);
    if (state.size() == 2)
        doBlockItem(node[u].son[1]);
}

void doBlockItem(int u)
{
    State state = node[u].state;
    if (state[0] == "Decl")
        doDecl(node[u].son[0]);
    else
        doStmt(node[u].son[0]);
}

void doStmt(int u)
{
    State state = node[u].state;
    if (state[0] == "return")
        doReturn(u, (int)state.size());
    if (state[0] == "LVal")
    {
        auto varl = doLVal(node[u].son[0]);
        auto varr = doExp(node[u].son[1]);
        if (varl.isGlobal)
        {
            codes.emplace_back("\tleaq\t" + varl.trueName + "(%rip), " + "%rax");
            codes.emplace_back("\taddq\t" + varl.addrReg + ", %rax");
            codes.emplace_back("\tmovq\t" + varRegister[varr.name] + ", (%rax)");
        }
        else
        {
            codes.emplace_back("\tneg\t\t" + varl.addrReg);
            if (varl.addrReg != "%rcx")
                codes.emplace_back("\tmovq\t" + varRegister[varr.name] + ", (%rbp, " + varl.addrReg + ")");
            else
                codes.emplace_back("\tmovq\t" + varRegister[varr.name] + ", " + to_string(-varl.offset) + "(%rbp)");
            codes.emplace_back("\tneg\t\t" + varl.addrReg);
        }
        S.top().insert(varl.addrReg);
        S.top().insert(varr.addrReg);
        S.top().insert(varRegister[varl.name]);
        S.top().insert(varRegister[varr.name]);
    }
    if (state[0] == "Exp")
        doExp(node[u].son[0]);
    if (state[0] == "Block")
        doBlock(node[u].son[0], true);
    if (state[0] == "if")
        doIf(u);
    if (state[0] == "while")
        doWhile(u);
    if (state[0] == "break")
        doBreak(u);
    if (state[0] == "continue")
        doContinue(u);
}

void doReturn(int u, int size)
{
    if (size == 3)
    {
        auto var = doExp(node[u].son[0]);
        codes.emplace_back("\tmovq\t" + varRegister[var.name] + ", " + "%rax");
        S.top().insert(varRegister[var.name]);
        S.top().insert(var.addrReg);
        codes.emplace_back("\tmovq\t%rbp, %rsp");
        popReg();
        codes.emplace_back("\tpopq\t%rbp");
        codes.emplace_back("\tret");
    }
}

void doIf(int u)
{
    State state = node[u].state;
    Variable var = doCond(node[u].son[0]);
    string reg = varRegister[var.name];
    if (state.size() == 5)
    {
        string LineNum = ".L" + to_string(++jumpNum);
        codes.emplace_back("\tmovq\t$0, " + string("%rcx"));
        codes.emplace_back("\tcmpq\t" + reg + ", " + "%rcx");
        codes.emplace_back("\tje\t" + LineNum);
        doStmt(node[u].son[1]);
        codes.emplace_back(LineNum + ":");
    }
    else
    {
        string Line1Num = ".L" + to_string(++jumpNum);
        string Line2Num = ".L" + to_string(++jumpNum);
        codes.emplace_back("\tmovq\t$0, " + string("%rcx"));
        codes.emplace_back("\tcmpq\t" + reg + ", " + "%rcx");
        codes.emplace_back("\tje\t" + Line1Num);
        doStmt(node[u].son[1]);
        codes.emplace_back("\tjmp\t" + Line2Num);
        codes.emplace_back(Line1Num + ":");
        doStmt(node[u].son[2]);
        codes.emplace_back(Line2Num + ":");
    }
}

Variable doCond(int u)
{
    State state = node[u].state;
    firstOp = "";
    return doLOrExp(node[u].son[0]);
}

Variable doLOrExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        auto var1 = doLOrExp(node[u].son[0]);
        auto var2 = doLAndExp(node[u].son[1]);
        if (firstOp.empty())
            firstOp = state[1];
        string reg1 = varRegister[var1.name], reg2 = varRegister[var2.name];
        codes.emplace_back("\torq\t\t" + reg2 + ", " + reg1);
        S.top().insert(varRegister[var2.name]);
        S.top().insert(var2.addrReg);
        return var1;
    }
    else
    {
        return doLAndExp(node[u].son[0]);
    }
}

Variable doLAndExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        auto var1 = doLAndExp(node[u].son[0]);
        auto var2 = doEqExp(node[u].son[1]);
        if (firstOp.empty())
            firstOp = state[1];
        string reg1 = varRegister[var1.name], reg2 = varRegister[var2.name];
        codes.emplace_back("\tandq\t" + reg2 + ", " + reg1);
        S.top().insert(varRegister[var2.name]);
        S.top().insert(var2.addrReg);
        return var1;
    }
    else
    {
        return doEqExp(node[u].son[0]);
    }
}

Variable doEqExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        auto var1 = doEqExp(node[u].son[0]);
        auto var2 = doRelExp(node[u].son[1]);
        if (firstOp.empty())
            firstOp = state[1];
        string reg1 = varRegister[var1.name], reg2 = varRegister[var2.name];
        codes.emplace_back("\tmovq\t$0, %rdx");
        codes.emplace_back("\tmovq\t$1, %rcx");
        codes.emplace_back("\tcmpq\t" + reg2 + ", " + reg1);

        codes.emplace_back("\tcmove\t%rcx, %rdx");
        codes.emplace_back("\tmovq\t%rdx, " + reg1);
        S.top().insert(varRegister[var2.name]);
        S.top().insert(var2.addrReg);
        return var1;
    }
    else
    {
        return doRelExp(node[u].son[0]);
    }
}

Variable doRelExp(int u)
{
    State state = node[u].state;
    if (state.size() == 3)
    {
        auto var1 = doRelExp(node[u].son[0]);
        auto var2 = doAddExp(node[u].son[1]);
        if (firstOp.empty())
            firstOp = state[1];
        string reg1 = varRegister[var1.name], reg2 = varRegister[var2.name];
        codes.emplace_back("\tmovq\t$0, %rdx");
        codes.emplace_back("\tmovq\t$1, %rcx");
        codes.emplace_back("\tcmpq\t" + reg2 + ", " + reg1);
        if (state[1] == "<")
            codes.emplace_back("\tcmovl\t%rcx, %rdx");
        if (state[1] == ">")
            codes.emplace_back("\tcmovg\t%rcx, %rdx");
        if (state[1] == "<=")
            codes.emplace_back("\tcmovle\t%rcx, %rdx");
        if (state[1] == ">=")
            codes.emplace_back("\tcmovge\t%rcx, %rdx");
        codes.emplace_back("\tmovq\t%rdx, " + reg1);
        S.top().insert(varRegister[var2.name]);
        S.top().insert(var2.addrReg);
        return var1;
    }
    else
    {
        return doAddExp(node[u].son[0]);
    }
}

void doWhile(int u)
{
    string backNum = ".L" + to_string(++jumpNum);
    string nextNum = ".L" + to_string(++jumpNum);
    stk.push({backNum, nextNum});
    codes.emplace_back(backNum + ":");
    Variable var = doCond(node[u].son[0]);
    string reg = varRegister[var.name];
    codes.emplace_back("\tmovq\t$0, " + string("%rcx"));
    codes.emplace_back("\tcmpq\t" + reg + ", " + "%rcx");
    codes.emplace_back("\tje\t" + nextNum);
    S.top().insert(reg);
    S.top().insert(var.addrReg);
    doStmt(node[u].son[1]);
    codes.emplace_back("\tjmp\t" + backNum);
    codes.emplace_back(nextNum + ":");
    stk.pop();
}

void doBreak(int u)
{
    auto num = stk.top();
    codes.emplace_back("\tjmp\t" + num.second);
}

void doContinue(int u)
{
    auto num = stk.top();
    codes.emplace_back("\tjmp\t" + num.first);
}

void doScanf(const Variable &v)
{
    codes.emplace_back("\tsubq\t$16, %rsp");
    if (v.isGlobal)
    {
        codes.emplace_back("\tleaq\t" + v.trueName + "(%rip), %rax");
        codes.emplace_back("\taddq\t" + v.addrReg + ", %rax");
    }
    else
    {
        codes.emplace_back("\tneg\t\t" + v.addrReg);
        codes.emplace_back("\tleaq\t" + string("(%rbp, ") + v.addrReg + "), %rax");
        codes.emplace_back("\tneg\t\t" + v.addrReg);
    }
    codes.emplace_back("\tmovq\t%rax, %rsi");
    codes.emplace_back("\tleaq\t.LC0(%rip), %rdi");
    codes.emplace_back("\tcall\t__isoc99_scanf@PLT");
    codes.emplace_back("\taddq\t$16, %rsp");
}

void doPrintf(const Variable &v)
{
    codes.emplace_back("\tsubq\t$16, %rsp");
    codes.emplace_back("\tmovq\t" + varRegister[v.name] + ", %rsi");
    codes.emplace_back("\tleaq\t.LC1(%rip), %rdi");
    codes.emplace_back("\tcall\tprintf@PLT");
    codes.emplace_back("\taddq\t$16, %rsp");
}
