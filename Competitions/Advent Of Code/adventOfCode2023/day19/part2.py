from collections import defaultdict

def compute(init):
    ans = 1
    for range in init.values():
        ans *= range[1]-range[0]+1

    return ans

def solve():
    graph = defaultdict(list)

    def dfs(parent, init):
        if parent == 'A':
            return compute(init)
        
        if parent == 'R':
            return 0
        
        ans = 0
        for condition in graph[parent]:
            vals, next = condition

            match = True
            nxt = dict(init)
            for key, val in vals.items():
                start, end = val
                s, e = nxt[key]
                            
                if e < start or s > end:
                    match = False
                    break
                
                nxt[key] = (max(s, start), min(e, end))
            
            if match:
                ans += dfs(next, nxt)
        
        return ans


    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day19/a.txt", "r") as file:
        for line in file:
            line = line.strip()
            if line == '':
                break
            
            node, conditions = line.split('{')
            conditions = conditions.split('}')[0].split(',')
            elsee = conditions.pop()

            ifs = {}
            for i in ['a', 'x', 's', 'm']:
                ifs[i] = (1, 4000)

            for condition in conditions:
                expression, next = condition.split(':')
                x = dict(ifs)

                if '>' in expression:
                    key, value = expression.split('>')
                    value = int(value)
                    s, e = x[key]
                    range = (value + 1, 4000)
                    comp = (1, value)
                    start, end = range
                    x[key] = (max(s, start), min(e, end))
                    start, end = comp
                    ifs[key] = (max(s, start), min(e, end))
                else:
                    key, value = expression.split('<')
                    value = int(value)
                    s, e = x[key]
                    range = (1, value - 1)
                    comp = (value, 4000)
                    start, end = range
                    x[key] = (max(s, start), min(e, end))
                    start, end = comp
                    ifs[key] = (max(s, start), min(e, end))

                graph[node].append((x, next))
            
            graph[node].append((ifs, elsee))

    init = {}
    for i in ['a', 'x', 's', 'm']:
        init[i] = (1, 4000)

    return dfs('in', init)

if __name__ == "__main__":
    print(solve())
