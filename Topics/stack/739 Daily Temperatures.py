#https://leetcode.com/problems/daily-temperatures/?envType=daily-question&envId=2024-01-31
class Solution:
    def dailyTemperatures(self, temps):
        results = [0] * len(temps)
        stack = []
        for i, temp in enumerate(temps):
            while stack and temps[stack[-1]] < temp:
                index = stack.pop()
                results[index] = i - index
            stack.append(i)

        return results