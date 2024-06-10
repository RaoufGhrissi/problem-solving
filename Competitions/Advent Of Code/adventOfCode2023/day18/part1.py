from collections import defaultdict

next = {
    'R': (0, 1),
    'L': (0, -1),
    'U': (-1, 0),
    'D': (1, 0),
}

def solve():
    maze = set()
    vis = set()
    lines = defaultdict(list)

    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day18/a.txt", "r") as file:
        line = 0
        col = 0

        for s in file:
            s = s.strip()
            direction, steps, _ = s.split()

            steps = int(steps)
            nxt = next[direction]
            while steps:
                lines[line].append(col)
                maze.add((line, col))
                line += nxt[0]
                col += nxt[1]
                steps -= 1

    for line, cols in lines.items():
        cols.sort()

    x = None
    y = None
    for line, cols in lines.items():
        if type(x) == int:
            break
        for col in cols:
            x1 = line-1
            x2 = line+1

            if type(x) == int:
                break
            
            if (x1, col) in maze or (x2, col) in maze:
                continue
            
            r1 = col
            r2 = col
            l1 = col
            l2 = col
            up1 = x1
            up2 = x2
            d1 = x1
            d2 = x2

            while(True):
                if (line, r1) in maze and (line, l1) in maze and (up1, col) in maze and (d1, col) in maze:
                    x = x1
                    y = col
                    break

                if (line, r2) in maze and (line, l2) in maze and (up2, col) in maze and (d2, col) in maze:
                    x = x2
                    y = col
                    break

                if (line, r1) not in maze:
                    r1 += 1

                if (line, r2) not in maze:
                    r2 += 1

                if (line, l1) not in maze:
                    l1 -= 1

                if (line, l2) not in maze:
                    l2 -= 1

                if (up1, col) not in maze:
                    up1 += 1

                if (up2, col) not in maze:
                    up2 += 1

                if (d1, col) not in maze:
                    d1 -= 1

                if (d2, col) not in maze:
                    d2 -= 1

    ans = 0

    def dfs(i, j):
        stack = [(i, j)]
        vis.add((i, j))
        res = 1

        while len(stack) > 0:
            top = stack.pop()
            i, j = top[0], top[1]
        
            for dir, d in next.items():    
                dx = i + d[0]
                dy = j + d[1]

                if (dx, dy) not in maze and (dx, dy) not in vis:
                    stack.append((dx, dy))
                    vis.add((dx, dy))
                    res += 1

        return res

    ans = dfs(x, y) + len(maze)
    
    return ans

if __name__ == "__main__":
    print(solve())
