
def getValue(vals):
    allZeros = all(x == 0 for x in vals)
    if allZeros:
        return 0

    nextVals = [vals[i+1] - vals[i] for i in range(len(vals)-1)]
    return vals[0] - getValue(nextVals)


def solve():
    ans = 0
    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day9/a.txt", "r") as file:
        
        for i, line in enumerate(file):
            line = [int(nb) for nb in line.strip().split()]
            ans += getValue(line)
            
    return ans

if __name__ == "__main__":
    print(solve())
