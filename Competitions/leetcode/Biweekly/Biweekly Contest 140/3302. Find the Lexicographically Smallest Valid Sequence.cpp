#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        vector<int> suffix(n, 0);
        int j = m-1;
        int cnt = 0;

        for (int i=n-1 ; i>-1 ; i--) {
            if (j>-1 && s1[i] == s2[j]) {
                cnt++;
                suffix[i] = cnt;
                j--;
            } else if (i<n-1) {
                suffix[i] = suffix[i+1];
            }
        }

        cout<<suffix[1]<<endl;
        
        bool used = 0;
        vector<int> ans;
        j = 0;
        for (int i=0 ; j<m && i<n ; i++) {
            int rest = m-j-1;
            
            if (s1[i] == s2[j]) {
                ans.push_back(i);
                j++;
            } else if (i+1<n && suffix[i+1] >= rest && !used) {
                used = 1;
                ans.push_back(i);
                j++;
            }
        }

        if (ans.size() < m) return {};

        return ans;
    }
};