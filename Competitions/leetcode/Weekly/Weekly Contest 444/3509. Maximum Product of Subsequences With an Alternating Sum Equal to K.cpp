#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, vector<int>>

using namespace std;


class Solution {
public:
    const int static mxSum = 50; // 12*150;
    unordered_map<int, int> dp[150][3][2*mxSum + 1];
    int k, limit;
    // state:
    // 0: not taken
    // 1: last -
    // 2: last +
    vector<int> v;

    int rec(int i, int state, int sm, int product) {
        if (i==v.size()) {
            if (!state) return -1;
            return sm-mxSum == k && product <= limit ? product : -1; 
        }

        if (dp[i][state][sm].count(product))
            return dp[i][state][sm][product];
        
        int &ans = dp[i][state][sm][product];

        int sign = state < 2 ? 1 : -1;
        return ans = max(
            rec(i+1, state, sm, product),
            rec(i+1, state < 2 ? 2 : 1, sm + sign*v[i], min(limit+1, v[i]*product))
        );
    }

    int id=0;
    int all[5001];
    bool dp1[150][5002];

    void generate(int i, int product) {
        if (i==v.size()) {
            if (product > limit) return;
            if (all[product] == -1)
                all[product] = id++;

            return;
        }

        if (dp1[i][product] == 1)
            return;

        dp1[i][product] = 1;

        generate(i+1, product);

        if (v[i]*product <= limit)
            generate(i+1, v[i]*product);
        
        if (v[i] > 1 && v[i]*product <= limit)
            generate(i, v[i]*product);
    } 

    int maxProduct(vector<int>& nums, int _k, int l) {
        k = _k;
        limit = 5000; // l;
        v = nums;

        id = 0;
        v.clear();
        for (int i=0 ; i<13 ; i++)
            v.push_back(i);

        memset(all, -1, sizeof all);
        memset(dp1, 0, sizeof dp1);
        generate(0, 1);

        cout<<id<<endl;

        return 0;
        //return rec(0, 0, mxSum, 1);
    }
};

int main() {
    vector<int> v = {6,3,3};
    int k = 6;
    int l = 20;
    cout<<Solution().maxProduct(v, k, l);
    return 0;
}