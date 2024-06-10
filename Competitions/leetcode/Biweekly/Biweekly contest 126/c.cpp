#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,char>
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> occ(26, 0);
        vector<int> ids;
        
        int n = s.size();
        for (int i=0 ; i<n ; i++) {
            char c = s[i];
            if (c!='?')
                occ[c-'a']++;
            else 
                ids.push_back(i);
        }

        vector<char> v;
        int m = ids.size();
                
        for (int i=0 ; i<26 ; i++) {
            if (v.size() == m)
                break;

            if (!occ[i])
                v.push_back(i+'a');        
        }

        for (int i=0 ; i<26 ; i++) {
            if (v.size() == m)
                break;

            if (occ[i] == 1)
                v.push_back(i+'a');        
        }

        while(v.size() < m)
            v.push_back('a');

        sort(v.begin(), v.end());
        int i = 0;     
        while(i<m) {
            s[ids[i]] = v[i];
            i++;
        }
        
        return s;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    cout<<Solution().minimizeStringValue("???");
    return 0;
}