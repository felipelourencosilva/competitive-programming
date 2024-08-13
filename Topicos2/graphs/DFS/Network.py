import sys
sys.setrecursionlimit(15000)

def dfs(u, p, timer):
    visited[u] = 1
    tin[u] = timer
    low[u] = timer
    
    timer += 1
    child = 0
    for v in adj[u]:
        if v == p:
            continue
        if visited[v] == 0:
            dfs(v, u, timer)
            low[u] = min(low[u],low[v])
            if low[v] >= tin[u] and p != -1:
                mark[u] = 1
            child += 1
        else:
            low[u] = min(low[u], tin[v])
    
    if child > 1 and p == -1:
        mark[u] = 1

while (True):       
    timer = 1
    
    n = int(input())
    if n == 0:
        break

    adj = [[] for _ in range(n+1)]
    while True:
        line = [int(x) for x in input().split(" ")]
        if line == [0]:
            break
        
        for i in range(len(line)):
            if line[0] != line[i]:
                adj[line[0]].append(line[i])
                adj[line[i]].append(line[0])

    visited = [0] * (n+1)
    tin = [0] * (n+1)
    low = [0] * (n+1)
    mark = [0] * (n+1)

    for i in range(1, n+1):
        if(not visited[i]):
            dfs(i, -1, timer)

    print(mark.count(1))
