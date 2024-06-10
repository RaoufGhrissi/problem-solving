class Solution(object):
    def sortSentence(self, s):
        arr = [0] * 10
        def is_majus(c):
            return ord(c)>=ord('A') and ord(c)<=ord('Z')

        def is_minus(c):
            return ord(c)>=ord('a') and ord(c)<=ord('z')
        
        def is_alpha(c):
            return is_majus(c) or is_minus(c)
        
        def add(s):
            c = ""
            n = 0
            for i in s:
                if is_alpha(i):
                    c += i
                else:
                    n = int(i)
                
            arr[n] = c
                
        c = ""
        sz = 0
        for i in s:
            if i == ' ':
                sz += 1
                add(c)
                c = ""
            else:
                c += i
                
        add(c)
        
        c = ""
        sz += 1
        for i in range(1, sz + 1):
            c += arr[i]
            if i < sz:
                c += " "
                
        return c