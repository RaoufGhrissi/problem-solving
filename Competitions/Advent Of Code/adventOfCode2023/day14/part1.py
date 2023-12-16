import copy

def solve():
    ans = 0
    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day14/a.txt", "r") as file:
        rows = []
        for line in file:
            line = line.strip()
            l = [c for c in line]
            rows.append(l)

    lines = len(rows)
    cols = len(rows[0])
    #you can use a set to make the search more optimized (log(n)) but you need to deal with tuples as we can't create a set of list
    cycles = []
    while True:
        #north
        for col in range(cols):
            queue = []
            for line in range(lines):
                if rows[line][col] == '#':
                    queue = []
                elif rows[line][col] == '.':
                    queue.append(line)
                elif len(queue) > 0:
                    front = queue.pop(0)
                    rows[front][col] = 'O'
                    rows[line][col] = '.'
                    queue.append(line)

        #west
        for line in range(lines):
            queue = []
            for col in range(cols):
                if rows[line][col] == '#':
                    queue = []
                elif rows[line][col] == '.':
                    queue.append(col)
                elif len(queue) > 0:
                    front = queue.pop(0)
                    rows[line][front] = 'O'
                    rows[line][col] = '.'
                    queue.append(col)

        #south
        for col in range(cols):
            queue = []
            for line in range(lines-1, -1, -1):
                if rows[line][col] == '#':
                    queue = []
                elif rows[line][col] == '.':
                    queue.append(line)
                elif len(queue) > 0:
                    front = queue.pop(0)
                    rows[front][col] = 'O'
                    rows[line][col] = '.'
                    queue.append(line)

        #east
        for line in range(lines):
            queue = []
            for col in range(cols-1, -1, -1):
                if rows[line][col] == '#':
                    queue = []
                elif rows[line][col] == '.':
                    queue.append(col)
                elif len(queue) > 0:
                    front = queue.pop(0)
                    rows[line][front] = 'O'
                    rows[line][col] = '.'
                    queue.append(col)

    
        copiedRows = copy.deepcopy(rows)
        if copiedRows in cycles:
            break
        
        cycles.append(copiedRows)

    deleted = 0
    while(cycles[0] != rows):
        deleted += 1
        cycles.pop(0)
    

    l = len(cycles)
    id = (1000000000 - 1 - deleted)%l

    rows = cycles[id]
    
    ans = 0
    for col in range(cols):
        for line in range(lines):
            if rows[line][col] == 'O':
                ans += lines - line

    return ans

if __name__ == "__main__":
    print(solve())
