#include <bits/stdc++.h>
#define ll long long
#define mod (int)(1e9 + 7)

using namespace std;

class Cnk {
    public:
        ll compute(int n, int k, int mxK) {
            ll tot = 1;
            for (int i=1 ; i<=k ; i++) {
                tot = tot * (n-k+i) / i;

                if (tot >= mxK) return mxK;
            }

            return tot;
        }
};

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int prev = 0;
        int mxPos = n/2;
        int pos = mxPos;

        string ans = "";

        int m = n&1 ? n/2 + 1 : n/2;
        for (int i=0 ; i<m ; i++)
            ans += '.';
        
        Cnk cnk = Cnk();
        
        vector<int> occ(26, 0);
        
        for (char &c:s)
            occ[c-'a']++;

        for (int i=0 ; i<26 ; i++) {
            if (occ[i]&1) {
                ans[n/2] = char(i+'a');
                occ[i]--;
            }

            occ[i] /= 2;
        }

        ll totComb = 1;
        int used = 0;
        for (int i=0 ; i<26 ; i++) {
            if (totComb >= k) break;

            totComb *= cnk.compute(pos-used, occ[i], k);
            used += occ[i];
        }

        if (totComb < k) return "";
        
        for (int i=0 ; i<mxPos ; i++) {
            for (char c='a' ; c<='z' ; c++) {
                if (occ[c-'a'] == 0) continue;
                ll tot = 1;
                int used = 1;
                
                for (int j=0 ; j<26 ; j++) {
                    int _occ = occ[j];
                    if (j == (c-'a')) _occ--;

                    if (_occ == 0) continue;
                    
                    tot *= cnk.compute(pos-used, _occ, k);

                    if ((tot+prev) >= k) {
                        break;
                    }
                    used += _occ;
                }
                
                if ((tot + prev) >= k) {
                    ans[i] = c;
                    break;
                } else {
                    prev += tot;
                }
            }

            occ[ans[i] - 'a']--;
            pos--;
        }

        string x = ans;
        if (n&1) x.pop_back();

        reverse(x.begin(), x.end());        
        
        return ans + x;
    }
};