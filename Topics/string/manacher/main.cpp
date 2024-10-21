#include<bits/stdc++.h>

using namespace std;

class Manacher {
    vector<int> p;
    Manacher(string s) {
        p = manacher(s);
    }

    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }

    vector<int> manacher(string s) {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        return vector<int>(begin(res) + 1, end(res) - 1);
    }

    int get_lps(int center) {
        return p[center];
    }

    int is_pal(int l, int r) {
        int n = r-l+1;
        return get_lps(n/2) >= n;
    }
};


int main() {
    
}