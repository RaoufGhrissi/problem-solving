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
            while i > -1 and j<n:
                if cols[i] != cols[j]:
                    pal = False
                    break
                i -= 1
                j += 1
            if pal:
                totCols += sep
        n = len(rows)
        for sep in range(1, n):
            i = sep-1
            j = sep
            pal = True
            while i > -1 and j<n:
                if rows[i] != rows[j]:
                    pal = False
                    break
                i -= 1
                j += 1
            if pal:
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
