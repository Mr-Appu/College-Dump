#Graph 

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


cost = {
        'A': {'C' : 1, 'E' : 2, 'S' : 2},
        'B': {'I' : 5, 'Q' : 3, 'S' : 4},
        'C': {'A' : 1, 'D' : 2},
        'D': {'C' : 2, 'H' : 1, 'P' : 3},
        'E': {'A' : 2, 'H' : 4, 'I' : 3, 'S' : 5},
        'G': {'I' : 9, 'N' : 4},
        'H': {'D' : 1, 'E' : 4, 'N' : 3},
        'I': {'B' : 5, 'E' : 3, 'G' : 9},
        'J': {'K' : 2, 'S' : 1},
        'K': {'J' : 2, 'L' : 5},
        'L': {'K' : 5, 'Q' : 2, 'S' : 4},
        'Q': {'B' : 3, 'L' : 2},
        'P': {'D' : 3},
        'N': {'G' : 4, 'H' : 3},
        'S': {'A' : 2, 'B' : 4, 'E' : 5, 'J' : 1, 'L' : 4}
    }

def calcost(s):
    ans = 0
    for i in range(len(s)-1):
        ans += cost[s[i]][s[i+1]]
    return ans
        
ans = ['S']

for i in ans:
    for j in graph[i[-1]]:
        if j not in i:
            ans.append(i+j)

count = 0

print("All Paths : ")

for i in ans:
    if(i[-1] == 'G'):
        count += 1
        print(i,calcost(i),end = '\n\n')
        
        
        
