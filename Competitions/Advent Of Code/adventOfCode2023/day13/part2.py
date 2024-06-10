def diff(s1, s2):
    res = 0 
    for i in range(len(s1)):
        res += s1[i] != s2[i]

    return res

def solve():
    ans = 0

    def compute(rows):
        n = len(rows[0])
        cols = []
        for col in range(n):
            s = ""
            for row in rows:
                s += row[col]
            cols.append(s)
        totCols = 0
        totRows = 0
        for sep in range(1, n):
            i = sep-1
            j = sep
            pal = True
            tot = 0
            while i > -1 and j<n:
                tot += diff(cols[i], cols[j])
                if tot > 1:
                    break
                i -= 1
                j += 1
            if tot == 1:
                totCols += sep
        n = len(rows)
        for sep in range(1, n):
            i = sep-1
            j = sep
            pal = True
            tot = 0
            while i > -1 and j<n:
                tot += diff(rows[i], rows[j])
                if tot > 1:
                    break
                i -= 1
                j += 1
            if tot == 1:
                totRows += sep

        return totCols + 100*totRows

    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day12/a.txt", "r") as file:
        rows = []
        for line in file:
            line = line.strip()

            if line != '':
                rows.append(line)
            else:
                ans += compute(rows)
                rows = []
        ans += compute(rows)

    return ans

if __name__ == "__main__":
    print(solve())
