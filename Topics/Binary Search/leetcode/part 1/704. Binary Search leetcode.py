class Solution(object):
    def search(self, v, t):
        n = len(v)
        i = 0  # i = 0
        j = n-1 # j = 1-1 = 0
        
        while i<=j:
            mid = (i+j)/2
            if v[mid] == t:
                return mid
            elif v[mid] > t:
                j = mid - 1
            else:
                i = mid + 1
                
        return -1
        