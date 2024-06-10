class Solution {
public:
    void rev(string& s, int k, int pos)
    {
        k = min(pos+k, (int)s.size());
        int p = 0;
        for (int i=pos ; i<(k+pos)/2 ; i++)
        {
            swap(s[i], s[k-1-p]);
            p++;
        } 
    }
    
    int nxt(int pos, int k)
    {
        return pos + 2*k;
    }
    
    string reverseStr(string s, int k) {
        int n = s.size();
        int pos = 0;
        while(pos<n)
        {
            rev(s, k, pos);
            pos = nxt(pos, k);
        }
        
        return s;
    }
};