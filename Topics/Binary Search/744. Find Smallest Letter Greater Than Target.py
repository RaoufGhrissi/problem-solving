class Solution(object):
    def nextGreatestLetter(self, v, t):
        n = len(v)
        i = 0
        j = n-1
        
        while i<j:
            mid = (i+j)/2
            
            if v[mid] > t: # larget than target
                j = mid
            else:
                i = mid + 1
                
        if v[i] > t:
            return v[i]
        else:
            return v[0]