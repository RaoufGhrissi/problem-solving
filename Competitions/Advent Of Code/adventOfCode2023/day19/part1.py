from collections import defaultdict
import json

def solve():
    graph = defaultdict(list)
    ans = 0
    workflows = True

    def dfs(parent, entry):
        if parent == 'A':
            return True
        
        if parent == 'R':
            return False
        
        for condition in graph[parent]:
            type, func, next, elsee = condition
            if func(entry[type]):
                return dfs(next, entry)
            elif elsee != -1:
                return dfs(elsee, entry)
        
        return False


    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day19/a.txt", "r") as file:
        for line in file:
            line = line.strip()
            if line == '':
                workflows = False
                continue
            
            if workflows:
                node, conditions = line.split('{')
                conditions = conditions.split('}')[0].split(',')
                elsee = conditions.pop()
                for condition in conditions:
                    expression, next = condition.split(':')
                    graph[node].append((expression[0], eval(f"lambda {expression[0]}: {expression}"), next, -1))
                
                last = graph[node].pop()
                graph[node].append((last[0], last[1], last[2], elsee))
            else:
                line = line.replace('=', ':')
                for c in ['a', 'x', 'm', 's']:
                    line = line.replace(c, f'"{c}"')
                entry = json.loads(line)
                if dfs("in", entry):
                    ans += sum(list(entry.values()))

    return ans

if __name__ == "__main__":
    print(solve())
