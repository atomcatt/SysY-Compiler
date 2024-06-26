import re
import sys

def build_parsing_table(rules):
    l = []
    r = []
    for rule in rules:
        lhs, rhs = rule.split('->')
        l_list = lhs.split()
        rsh = rhs.replace(" ", "").replace("\n", "")
        sb_list = ['{', '}', ';', ',', '[', ']', '(', ')', '<', '>', '=', '==', '!=', '<=', '>=']
        for x in l_list:
            if x in sb_list:
                l_list[l_list.index(x)] = "\\" + x
        l.append(l_list)
        r.append(rsh)
    return l, r

idx = 0
def build_tree(fa, part, curName, l, r):
    global idx

    idx = idx + 1
    cur = idx

    itemIdx = -1
    for i in range(len(l)):
        if r[i] == curName:
            itemIdx = i
            break
    
    if itemIdx == -1:
        print(curName + " is a terminal")
        # g.write("\"node"+str(cur)+"\"[label=\"<f0> " + curName + "\"];\n")
        # g.write("\"node"+str(fa)+"\""+":f"+str(part)+"->\"node"+str(cur)+"\";\n")
        return
        
    curl = l.pop(itemIdx)
    curr = r.pop(itemIdx)

    assert curr == curName

    info = "node"+str(cur)+"[label = \""
    for i in range(len(curl)):
        info = info + "<f"+str(i)+"> "+curl[i]+"|"
    info = info[:-1] + "\"];"

    g.write(info + "\n")
    g.write("\"node"+str(fa)+"\""+":f"+str(part)+"->\"node"+str(cur)+"\";\n")
    
    for i in range(len(curl)):
        v = curl[len(curl) - i - 1]
        build_tree(cur, len(curl) - i - 1, v, l, r)

open_file = sys.argv[1]
write_file = sys.argv[2]
print(open_file, write_file)
# with open('./results/1-array') as f:
with open(open_file) as f:
    rules = f.readlines()
    l, r = build_parsing_table(rules);
    l.reverse(), r.reverse();
    # with open('./results/1-array.dot', 'w') as g:
    with open(write_file, 'w') as g:
        g.write("digraph \" \"{")
        g.write("node [shape = record,height=.1]")
        g.write("node0[label=\"<f0> CompUnit\"]")
        build_tree(0, 0, r[0], l, r)
        g.write("}")