# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        def isBadVersion(i):
            return True

        i = 1
        j = n
        
        while i<j:
            mid = (i+j)/2
            isBad = isBadVersion(mid)
            if isBad:
                j = mid
            else:
                i = mid + 1
                
        return i
        