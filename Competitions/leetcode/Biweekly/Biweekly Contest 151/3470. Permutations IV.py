from typing import List


class Solution:
    def __init__(self):
        self.dp = [-1]*51


    def fact(self, n):
        if n <= 0:
            return 1

        if self.dp[n] != -1:
            return self.dp[n]

        self.dp[n] = n * self.fact(n-1)
        return self.dp[n]
    
    def permute(self, n: int, k: int) -> List[int]:
        p = int(n/2)
        imp = int(n/2) if n%2 == 0 else int(n/2)+1
        ans = []
        prev = 0
        used = set()

        for i in range(n):
            for j in range(1, n+1):
                if n%2 == 1 and not ans and j%2 == 0:
                    continue

                if j in used:
                    continue
                if ans:
                    if j%2 == 0 and ans[-1]%2 == 0:
                        continue
                    if j%2 == 1 and ans[-1]%2 == 1:
                        continue

                if j%2 == 0: # pair
                    cnt = prev + self.fact(p-1) * self.fact(imp)
                else:
                    cnt = prev + self.fact(p) * self.fact(imp-1)

                if cnt >= k:
                    ans.append(j)
                    
                    if j%2 == 0:
                        p -= 1
                    else:   
                        imp -= 1
                    used.add(j)
                    break
                else:
                    prev = cnt

        return ans if len(ans) == n else []

