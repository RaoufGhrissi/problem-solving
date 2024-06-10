class Solution {
public:
    int is_pal(string s)
    {
        int n=s.size();
        for (int i=0 ; i<n/2 ; i++)
            if (s[i] != s[n-1-i])
                return 0;
        
        return 1;
    }
    
    int removePalindromeSub(string s) {
        if (is_pal(s))
            return 1;
        
        return 2;
    }
};