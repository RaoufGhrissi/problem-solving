from collections import defaultdict

directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]
graph = defaultdict(list)
choiceNodes = []

class Cell:
    def __init__(self, x: int, y: int, vis):
        self.i = x
        self.j = y
        self.vis = vis

dp = {}

def safe(i: int, j: int, n: int, m: int) -> bool:
    return 0 <= i < n and 0 <= j < m

vis = {}

def dfs(i, j, n, m):
    if i == n-1:
        return 0

    ans = -1e9    
    for child in graph[(i, j)]:
        x, y, d = child
        if (x, y) in vis:
            continue

        vis[(x, y)] = 1
        ans = max(ans, d + dfs(x, y, n, m))
        del vis[(x, y)]

    return ans

# i added momrization to optimize the backtracking but i was surprised the normal dfs was quicker
# maybe the hashing of the Cell class as a dict key is taking time.
def get_paths(c, v, n, m):
    if c.i == n - 1 and v[c.i][c.j] == '.':
        return 0

    if c in dp:
        return dp[c]

    dp[c] = -1e9
    for child in graph[(c.i, c.j)]:
        x, y, d = child

        if (not safe(x, y, n, m)) or ((x, y) in c.vis):
            continue

        nxt = set(c.vis)
        nxt.add((x, y))
        next_cell = Cell(x, y, nxt)
        dp[c] = max(dp[c], d + get_paths(next_cell, v, n, m))

    return dp[c]

def solve():
    v = []
    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day23/a.txt", 'r') as file:
        for line in file:
            v.append(line.strip())

    n, m = len(v), len(v[0])
    col = v[0].index('.')

    choiceNodes.append((0, col))
    choiceNodes.append((n-1, v[n-1].index('.')))
    for i in range(n):
        for j in range(m):
            if v[i][j] == '#':
                continue

            next = 0
            for dir in directions:
                x, y = i + dir[0], j + dir[1]
                if safe(x, y, n, m) and v[x][y] != '#':
                    next += 1

            if next > 2:
                choiceNodes.append((i, j))
    
    
    for si, sj in choiceNodes:
        stack = [(si, sj, 0)]
        vis = {(si, sj)}

        while len(stack) > 0:
           i, j, d = stack.pop()
           if d > 0 and (i, j) in choiceNodes:
                graph[(si, sj)].append((i, j, d))
                continue

           for dir in directions:
                x, y = i + dir[0], j + dir[1]

                if safe(x, y, n, m) and v[x][y] != '#' and ((x, y) not in vis):
                    vis.add((x, y))
                    stack.append((x, y, d+1))

    #return get_paths(Cell(0, col, set()), v, n, m)
    return dfs(0, col, n, m)

print(solve())