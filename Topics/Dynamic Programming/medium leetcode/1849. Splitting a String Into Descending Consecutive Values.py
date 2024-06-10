# i'm using python to save some time playing with strings in cpp as it doesn't support big int
# but it can be done with strings
class Solution:
    def __init__(self):
        self.dp = {}

    def solve(self, i, start, end, s):
        prev = int(s[start:end+1])
        actual = int(s[end+1:i+1])
        
        if i == len(s):
            return prev - 1 == actual

        if (i, start, end) in self.dp:
            return self.dp[(i, start, end)]

        self.dp[(i, start, end)] = self.solve(i+1, start, end, s)
        
        if prev - 1 == actual:
            if i == len(s) - 1:
                return True

            self.dp[(i, start, end)] |= self.solve(i+1, end+1, i, s)

        return self.dp[(i, start, end)]

    def splitString(self, s):
        ans = False
        n = len(s)

        for i in range(n - 1):
            ans |= self.solve(i + 1, 0, i, s)

        return ans
        