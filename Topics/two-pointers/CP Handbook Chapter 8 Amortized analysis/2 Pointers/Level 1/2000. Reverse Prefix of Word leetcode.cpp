class Solution {
public:
    string reversePrefix(string s, char d) {
        int pos = -1;
        int n = s.size();
        for (int i=0 ; i<n ; i++)
            if (s[i]==d) {
                pos = i;
                break;
            }
        
        if (pos == -1)
            return s;
        
        n = pos+1;
        
        for (int i=0 ; i<n/2 ; i++)
            swap(s[i], s[n-1-i]);
        
        return s;
    }
};