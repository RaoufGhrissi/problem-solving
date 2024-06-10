class Solution:
    def __init__(self):
        self.dp = {}

    def rec(self, i, k, isStart, v):
        if i == len(v):
            if not isStart and k == 1:
                return 0
            return -10**15

        if not k:
            return 0

        p = (i, k, isStart)
        if p in self.dp:
            return self.dp[p]

        ans = -10**15
        coef = 1 if k & 1 else -1  # If k is odd, coef = 1
        if isStart:
            ans = max(
                ans,
                self.rec(i + 1, k, 1, v),
                coef * k * v[i] + self.rec(i + 1, k, 0, v),
            )
        else:
            ans = max(
                ans,
                coef * k * v[i] + self.rec(i + 1, k, 0, v),
                self.rec(i, k - 1, 1, v),
            )

        self.dp[p] = ans
        return ans

    def maximumStrength(self, v, k):
        return self.rec(0, k, 1, v)