#solution 1 : Time limit Exceeded

class Solution(object):
    def missingNumber(self, tab):
        n = len(tab)
        for i in range(n+1):
            exist = False
            for j in tab:
                if j == i:
                    exist = True
                    break
            if not exist:
                return i
        
        return 0

    
#Solution 2 : Binary search
class Solution(object):
    def missingNumber(self, tab):
        def search(v, t):
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
        
        def tri_bulle(tab):
            n = len(tab)

            for i in range(n):
                for j in range(n-i-1):
                    if tab[j]>tab[j+1]:
                        tab[j], tab[j+1] = tab[j+1], tab[j]
                        
        
        tri_bulle(tab)
        #tab.sort()

        n = len(tab)
        for i in range(n+1):
            if search(tab, i) == -1:
                return i
        
        return 0

# solution 3: using sort
class Solution(object):
    def missingNumber(self, tab):        
        def tri_bulle(tab):
            n = len(tab)

            for i in range(n):
                for j in range(n-i-1):
                    if tab[j]>tab[j+1]:
                        tab[j], tab[j+1] = tab[j+1], tab[j]
                        
        
        tab.sort()
        n = len(tab)
        for i in range(n):
            if i != tab[i]:
                return i
        
        return n
            
#Solution 4:
class Solution(object):
    def missingNumber(self, tab):        
        sm = 0
        for i in tab:
            sm += i
        
        n = len(tab)
        ssa = n * (n+1) / 2
        
        return ssa - sm
     