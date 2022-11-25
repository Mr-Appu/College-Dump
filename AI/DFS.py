import numpy as np

graph = {
    "A" : sorted("S E C".split()),
    "B" : sorted("S Q I".split()),
    "C" : sorted("A D".split()),
    "D" : sorted("C H P".split()),
    "E" : sorted("S A H I".split()),
    "G" : sorted("N I".split()),
    "H" : sorted("D E N".split()),
    "I" : sorted("E B G".split()),
    "J" : sorted("K S".split()),
    "K" : sorted("L J".split()),
    "L" : sorted("K Q S".split()),
    "Q" : sorted("L B".split()),
    "P" : sorted("D".split()),
    "N" : sorted("H G".split()),
    "S" : sorted("A E B L J".split())
    }

ans = ['S']

while(ans[0][-1] != 'G'):
    for i in reversed(graph[ans[0][-1]]):
        if(i not in ans[0]):
            ans.insert(1,ans[0]+i)
    ans.pop(0)
    
print("DFS Path : ",ans[0])
