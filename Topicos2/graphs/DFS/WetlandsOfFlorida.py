import sys
sys.setrecursionlimit(15000)

x_correction = [1, 1, 1, 0, 0, -1, -1, -1]
y_correction = [-1, 0, 1, -1, 1, -1, 0, 1]
matriz = []
visited = []
results = []

def calculate_area(i, j):
    if i < 0 or j < 0 or i >= len(matriz) or j >= len(matriz[0]):
        return 0
    
    if visited[i][j]:
        return 0
    
    if matriz[i][j] == "L":
        return 0
    
    visited[i][j] = True
    res = 1
    
    for idx in range(8):
        new_i = i + x_correction[idx]
        new_j = j + y_correction[idx]

        res += calculate_area(new_i, new_j)

    return res
    
def update_area(i, j, res):
    if i < 0 or j < 0 or i >= len(matriz) or j >= len(matriz[0]):
        return
    
    if results[i][j]:
        return
    
    if matriz[i][j] == "L":
        return

    results[i][j] = res
    
    for idx in range(8):
        new_i = i + x_correction[idx]
        new_j = j + y_correction[idx]
        update_area(new_i, new_j, res)

n = int(input())
input()

for i in range(n):
    inp = ""
    matriz = []
    while True:
        inp = input()
        if inp[0].isdigit():
            break
        
        matriz.append(inp)

    visited = [[False]*len(matriz[0]) for _ in range(len(matriz))]
    results = [[0]*len(matriz[0]) for _ in range(len(matriz))]

    while True:
        try:
            x, y = [int(x) for x in inp.split()]
            x -= 1
            y -= 1
            
            if results[x][y] == 0:
                res = calculate_area(x, y)
                update_area(x, y, res)
            print(results[x][y])

            inp = input()
            if inp == "":
                print()
                break

        except EOFError:
            break
