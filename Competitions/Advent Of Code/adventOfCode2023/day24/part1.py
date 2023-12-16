
def solve():
    lines = []
    ans = 0
    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day24/a.txt", 'r') as file:
        for line in file:
            temp, v = line.split(' @ ')
            x, y, z = [int(c) for c in temp.split(', ')]
            vx, vy, vz = [int(c) for c in v.split(', ')]

            x1, y1, = x + vx, y + vy
            #verified the input, no x or y = 0
            a = (y1-y)/(x1-x)
            b = y - a*x

            ranges = {}

            if vx > 0:
                ranges['x'] = (x, float("inf"))
            else:
                ranges['x'] = (float("-inf"), x)

            if vy > 0:
                ranges['y'] = (y, float("inf"))
            else:
                ranges['y'] = (float("-inf"), y)

            lines.append((a, b, ranges))

    for i in range(len(lines)):
        a1, b1, ranges1 = lines[i]
        for j in range(i+1, len(lines)):
            a2, b2, ranges2 = lines[j]

            # // lines
            if a1 == a2:
                continue

            x = (b2 - b1)/(a1 - a2)
            y = a1*x + b1

            s, e = ranges1['x']
            if x > e or x < s:
                continue

            s, e = ranges1['y']
            if y > e or y < s:
                continue

            s, e = ranges2['x']
            if x > e or x < s:
                continue

            s, e = ranges2['y']
            if y > e or y < s:
                continue

            if y < 200000000000000 or x < 200000000000000 or y > 400000000000000 or x > 400000000000000:
                continue

            ans += 1
    
    return ans

print(solve())