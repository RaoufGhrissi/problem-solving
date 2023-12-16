
def rec(i, j, cnt, s, l):
    if i>=len(s):
        return j == len(l) 
    
    if dp[i][j][cnt] != -1:
        return dp[i][j][cnt]
    
    dp[i][j][cnt] = 0

    if s[i] == '.':
        if cnt > 0:
            return 0
        
        dp[i][j][cnt] = rec(i+1, j, 0, s, l)
    elif s[i] == '#':
        if j >= len(l):
            pass
        elif cnt+1 > l[j]:
            pass
        elif cnt+1 < l[j]:
            dp[i][j][cnt] = rec(i+1, j, cnt+1, s, l)
        else:
            if i+1<len(s) and s[i+1] == '#':
                pass
            else:
                dp[i][j][cnt] = rec(i+2, j+1, 0, s, l)
    else:
        if j >= len(l):
            dp[i][j][cnt] = rec(i+1, j, 0, s, l)
        elif cnt+1 > l[j]:
            dp[i][j][cnt] = rec(i+1, j, 0, s, l)
        elif cnt+1 < l[j]:
            dp[i][j][cnt] = rec(i+1, j, cnt+1, s, l)
            if cnt == 0:
                dp[i][j][cnt] += rec(i+1, j, cnt, s, l)
        else:
            if i+1<len(s) and s[i+1] == '#':
                if cnt == 0:
                    dp[i][j][cnt] = rec(i+1, j, 0, s, l)
                else:
                    pass
            else:
                dp[i][j][cnt] = rec(i+2, j+1, 0, s, l)
                if cnt == 0:
                    dp[i][j][cnt] += rec(i+1, j, cnt, s, l)

    return dp[i][j][cnt]
        

def solve():
    ans = 0

    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day12/a.txt", "r") as file:
        for line in file:
            line = line.split(" ")
            s = line[0] + "?"
            l = []
            for x in line[1].split(','):
                l.append(int(x))
            
            global dp
            dp = [[ [-1 for col in range(22)] for col in range(22)] for row in range(22)]
            res = rec(0, 0, 0, s, l)
            ans += pow(res, 5)
    return ans

if __name__ == "__main__":
    print(solve())
