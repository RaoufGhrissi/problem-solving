class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int i=0;
        int j=0;
        int n=s1.size();
        int m=s2.size();
        string ans = "";
        while(i<n || j<m)
        {
            if (i>n-1)
                ans += s2[j++];
            else if (j>m-1)
                ans += s1[i++];
            else
            {
                ans += s1[i++];
                ans += s2[j++];
            }
        }
        
        return ans;
    }
};