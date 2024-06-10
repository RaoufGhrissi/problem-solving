#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

// trie

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& v) {
        vector<string> ans;
        vector<vector<string>> x;
        vector<set<string>> ss;
        int n = v.size();
        
        for (int i = 0 ; i<n ; i++) {
            string vv = v[i];
            int nn = vv.size();
            vector<string> st;
            set<string> sss;
            for (int s=0 ; s<nn ; s++) {
                string c = "";
                for (int e=s ; e<nn ; e++) {
                    c += vv[e];
                    st.push_back(c);
                    sss.insert(c);
                }
            }
            
            sort(st.begin(), st.end(), [](const string &a, const string &b)
            {
                if (a.size() == b.size())
                    return a<b;
                
                return a.size() < b.size(); 
            });

            x.push_back(st);
            ss.push_back(sss);
        }
        
        for (int i=0 ; i<n ; i++) { //n = 100
            bool ok;
            string res;
            for (auto &a:x[i]) { // 400
                ok = 1;
                for (int j=0 ; j<n ; j++) { // n = 100
                    if (i==j) continue;
                    if (ss[j].count(a)) { // log(400)
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    res = a;
                    break;
                }
            }
            
            if(!ok) {
                ans.push_back("");    
            } else {
                ans.push_back(res);
            }
        }
         // => 4*1e6*8 <<<< 1e9
        return ans;
    }
};