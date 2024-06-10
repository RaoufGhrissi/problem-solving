class Solution:
    def isValid(self, i, actual, v, s):
        next_val = int(actual)
        if i == len(s):
            n = len(v)
            return n > 1 and (next_val == v[n - 1] + v[n - 2])

        ans = False
        if actual != "0":
            ans |= self.isValid(i + 1, actual + s[i], v, s)

        n = len(v)
        if n > 1 and next_val != (v[n - 1] + v[n - 2]):
            return ans

        v.append(next_val)
        ch = s[i]
        ans |= self.isValid(i + 1, ch, v, s)
        v.pop()

        return ans

    def isAdditiveNumber(self, s):
        v = []
        actual = s[0]
        return self.isValid(1, actual, v, s)
    
print(Solution().isAdditiveNumber("0235813"))