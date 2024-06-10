class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();        
        int div = pow(10, n-k);
        int nb = num / div;
        int ans = num%nb == 0;
        
        
        div = pow(10, k-1);
        int i = 0;
        
        while(i+k<n)
        {            
            nb %= div;
            nb *= 10;
            nb += s[i+k]-'0';
            
            if (nb && num%nb == 0)
                ans++;
            
            i++;
        }
        return ans;
    }
};