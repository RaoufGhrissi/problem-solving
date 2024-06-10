from collections import defaultdict

def dfs(parent, number, convert):
    if parent == "location":
        return number
    
    ans = -1
    dest: str
    for dest, a, b, c in convert[parent]:
        a, b, c = int(a), int(b), int(c)
        if (a <= number < a+c):
            ans = dfs(dest, b+(number-a), convert)
            break

    return ans if ans > -1 else dfs(dest, number, convert)

def solve():
    ans = 1e9
    seeds = []
    convert = defaultdict(list)

    with open("a.txt", "r") as file:
        for line in file:
            line = line.strip()
            if line == '':
                continue

            if line.startswith("seeds: "):
                line = line.split(': ')
                seeds = line[1].split()
                continue

            if line.endswith(" map:"):
                src, _, dest = line.split()[0].split('-')
            else:
                a, b, c = line.split()
                convert[src].append((dest, b, a, c))       

    ans = 1e9
    for seed in seeds:
        res = dfs("seed", int(seed), convert)
        ans = min(ans, res)

    return ans

if __name__ == "__main__":
    print(solve())
