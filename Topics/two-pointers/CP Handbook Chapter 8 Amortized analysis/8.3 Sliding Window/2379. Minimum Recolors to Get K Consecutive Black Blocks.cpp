class Solution {
public:
    int minimumRecolors(string s, int k) {
        int b = 0, i;
       for  (i=0 ; i<k ; i++)
            if (s[i]=='B')
                b++;
        
        if (b==k)
            return 0;
        
        i=0;
        int ans = k-b;
        int n = s.size();
        while(i+k<n)
        {
            if (s[i]=='B')
                b--;
            
            if (s[i+k]=='B')
                b++;
            
            ans = min(ans, k-b);
            i++;
        }
        
        return ans;
    }
};