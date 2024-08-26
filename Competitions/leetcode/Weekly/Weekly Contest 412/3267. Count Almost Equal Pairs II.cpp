#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, x;
    map<int, int> occ;

    set<int> build(string s) {
        if (n==1) return {stoi(s)};
        
        while(s.size() < n)
            s = '0' + s;

        set<int> st;

        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                swap(s[i], s[j]);

                x = stoi(s);
                st.insert(x); // swap wahda

                for (int i1=0 ; i1<n ; i1++) {
                    for (int j1=i1+1 ; j1<n ; j1++) {
                        swap(s[i1], s[j1]);
                        x = stoi(s);
                        st.insert(x); // swap thenya
                        swap(s[i1], s[j1]);
                    }
                }

                swap(s[i], s[j]);
            }
        }

        return st;
    }

    int countPairs(vector<int>& v) {
        x = *max_element(v.begin(), v.end());
        n = to_string(x).size();
        
        int ans = 0;
        for (int &c:v) {
            for (auto &child:build(to_string(c))) {
                if (occ.count(child)) {
                    ans += occ[child];
                }
            }

            occ[c]++;
        }

        return ans;
    }
};