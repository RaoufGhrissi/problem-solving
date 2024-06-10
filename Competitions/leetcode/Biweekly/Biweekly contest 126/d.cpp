#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

#define ll long long
class Solution {
public:
    ll p[101];
    int m = 1e9 + 7;
    
    void init() {
        p[0] = 1;
        for (int i=1 ; i<101 ; i++) {
            p[i] = 2*p[i-1];
            p[i] %= m;
        }
    }
    
    void backtrack(int i, vector<int>& v, int &sm, int &k, int &cnt, int &ans) {
        if (i==v.size()) {
            if (sm == k)
                ans += p[(int)v.size()-cnt];
            return;
        }
        
        backtrack(i+1, v, sm, k, cnt, ans);
        if (sm + v[i] > k)
            return;
        
        sm += v[i];
        cnt++;
        backtrack(i+1, v, sm, k, cnt, ans);
        cnt--;
        sm -= v[i];
    }
    
    int sumOfPower(vector<int>& v, int k) {
        init();
        int sm = 0, cnt = 0, ans = 0;
        backtrack(0, v, sm, k, cnt, ans);
        return ans;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    cout<<Solution().sumOfPower(v, 3);
    return 0;
}