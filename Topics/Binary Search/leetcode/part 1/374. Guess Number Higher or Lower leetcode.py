# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        def guess(a):
            return a
        
        i = 0
        j = n
        while i<=j:
            mid = (i+j)/2
            #interactive problems
            res = guess(mid)
            if res == 0:
                return mid
            elif res == -1:
                j = mid -1
            else:
                i = mid + 1
                
        return 0
        