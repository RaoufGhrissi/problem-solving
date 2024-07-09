#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> occS(26, 0), occP(26, 0);
        int n = s.size(), m = p.size();

        for (char &c:p)
            occP[c-'a']++;

        int i = 0, j = 0;
        vector<int> ans;

        while(j<n) {
            if (occS[s[j]-'a'] + 1 <= occP[s[j]-'a']) {
                occS[s[j]-'a']++;
                j++;
            } else {
                if (j-i == m)
                    ans.push_back(i);
                occS[s[i]-'a']--;
                i++;
            }
        }

        if (j-i == m)
            ans.push_back(i);

        return ans;
    }
};

int main() {
    auto a = Solution().findAnagrams("cbaebabacd", "abc");
}