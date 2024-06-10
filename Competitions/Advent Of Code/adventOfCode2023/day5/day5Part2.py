from collections import defaultdict

def dfs(parent, ranges, convert):
    if parent == "location":
        return min([range[0] for range in ranges])
    
    ans = 1e18
    dest: str
    newRanges = []

    for range in ranges:
        s, e = range
        dest = convert[parent][0][0]
        inter = [match for match in convert[parent] if match[1] <= e and match[1]+match[3]-1 >= s]
        if len(inter) == 0:
            newRanges.append(range)

        for i, v in enumerate(inter):
            dest, a, b, c = v
            x = a
            y = a+c-1
            
            interS, interE = max(s, x), min(e, y)
            diff = interS - x
            size = interE - interS
            newRanges.append((b+diff, b+diff+size))
            
            if s < x:
                newRanges.append((s, x-1))

            if i==len(inter)-1 and e>y:
                newRanges.append((y+1, e))

            s = interE+1

    return dfs(dest, newRanges, convert)

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
                convert[src].append((dest, int(b), int(a), int(c))) 

    for key, val in convert.items():
        val.sort(key=lambda x: x[1])

    ranges = [(int(seeds[i]), int(seeds[i])+int(seeds[i+1])-1) for i in range(0, len(seeds), 2)]
    return dfs("seed", ranges, convert)

if __name__ == "__main__":
    print(solve())
