class Solution(object):
    def mySqrt(self, x):
        i = 0
        j = 46342
        
        while i<j:
            mid = (i+j+1)/2
            s = mid*mid
            if s == x:
                return mid
            elif s<x:
                i = mid
            else:
                j = mid - 1
                
        return i
        