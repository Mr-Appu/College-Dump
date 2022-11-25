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
flag = 1
size = -1

arr = []

while(flag):
    if(size != -1 and len(ans[0]) > size):
        break
    
    if(ans[0][-1] == 'G'):
        size =len(ans[0])
        arr.append(ans[0])
        ans.pop(0)
        continue
    
    for i in graph[ans[0][-1]]: 
        if(i not in ans[0]):
            ans.append(ans[0]+i)
    ans.pop(0)
    
print("BFS Path : ",arr)
