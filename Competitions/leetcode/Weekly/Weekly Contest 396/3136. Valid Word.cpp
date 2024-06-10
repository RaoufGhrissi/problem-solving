#include <bits/stdc++.h>

#define ll long long
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 3) return 0;
        bool v = 0, c = 0;
        set<char> vs = {'a', 'e' , 'o', 'i', 'u'};
        for (auto &x:s) {
            char cc = tolower(x);
            if (!isalnum(cc)) return 0;
            if (isdigit(cc)) continue;
            
            if (vs.count(cc)) v=1;
            else c=1;

            
        }

        cout<<v<<" "<<c<<endl;
        if (!v || !c) return 0;

        return 1;
    }
};