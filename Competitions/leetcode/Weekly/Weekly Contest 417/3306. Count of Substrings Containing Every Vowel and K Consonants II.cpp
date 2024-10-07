#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution {
public:
    set<char> st = {'a', 'e', 'i', 'o', 'u'};
    map<char,int> occ;
    int v = 0;

    bool is(char c) {
        return st.count(c);
    }

    void add(char c) {
        if (is(c)) {
            occ[c]++;
            v++;
        }
    }

    long long countOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> cum(n, 0);

        map<int,int> comp;
        map<char,int> occ;
        for (int i=0 ; i<n ; i++) {
            cum[i] = !is(s[i]);
            if (i)
                cum[i] += cum[i-1];

            comp[cum[i]]++;
        }

        int j=0;
        int cm = 0;
        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            while(j<n && (!is(s[j]) || occ.size() != 4 || occ.count(s[j]))) {
                occ[s[j]]++;

                cm += !is(s[j]);

                comp[cm]--;

                if (!comp[cm])
                    comp.erase(cm);
                
                j++;
            }

            int target = k;
            if (i)
                target += cum[i-1];
            
            if (comp.count(target))
                ans += comp[target];

            occ[s[i]]--;
            if (!occ[s[i]])
                occ.erase(s[i]);
        }

        return ans;
    }
};

int main() {
    cout<<Solution().countOfSubstrings("aeioqq", 1);
}