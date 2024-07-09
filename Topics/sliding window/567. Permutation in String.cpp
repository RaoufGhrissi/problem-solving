#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string p, string s) {
        vector<int> occS(26, 0), occP(26, 0);
        int n = s.size(), m = p.size();

        for (char &c:p)
            occP[c-'a']++;

        int i = 0, j = 0;

        while(j<n) {
            if (occS[s[j]-'a'] + 1 <= occP[s[j]-'a']) {
                occS[s[j]-'a']++;
                j++;
            } else {
                if (j-i == m)
                    return 1;

                occS[s[i]-'a']--;
                i++;
            }
        }

        if (j-i == m)
            return 1;

        return 0;
    }
};

int main() {
    vector<int> v = {2,3,1,2,4,3};
    cout<<Solution().checkInclusion("ab", "daedexbapii");
}