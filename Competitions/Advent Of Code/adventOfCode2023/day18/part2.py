next = {
    0: (0, 1),
    1: (1, 0),
    2: (0, -1),
    3: (-1, 0),
}

# can be solved with the same solution from part1 by compressing the graph, i was lazy to implement it so i used geometry instead

with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day18/a.txt", "r") as file:
    ans = 0
    limit = 0
    points = [(0, 0)]
    for line in file:
        line = line.strip()
        color = line.split()[2]
        steps = int(color[2:7], 16)
        direction = int(color[7:8])
        dx, dy = next[direction]
        limit += steps
        line, col = points[-1]
        points.append((line + dx * steps, col + dy * steps))

s = abs(sum(points[i][0] * (points[i - 1][1] - points[(i + 1) % len(points)][1]) for i in range(len(points)))) // 2
i = s - limit // 2 + 1

print(i + limit)