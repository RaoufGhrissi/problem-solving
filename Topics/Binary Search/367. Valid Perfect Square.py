class Solution(object):
    def isPerfectSquare(self, num):
        i = 1
        j = 46342
        
        while i<=j:
            mid = (i+j)/2
            s = mid*mid
            if s == num:
                return True
            elif s<num:
                i = mid + 1
            else:
                j = mid - 1
                
        return False
        