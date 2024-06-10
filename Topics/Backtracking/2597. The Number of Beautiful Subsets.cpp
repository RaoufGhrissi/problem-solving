#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int solve(int i, int mask, vector<int>& v, map<int, vector<int>> &mp, int &k) {
        if (i == v.size())
            return mask ? 1 : 0;

        int ans = solve(i+1, mask, v, mp, k);

        int target = v[i]-k;
        if (mp.count(target)) {
            bool exist = 0;
            for (auto &index:mp[target]) {
                exist = mask&(1<<index);
                if (exist)
                    return ans;
            }
        }

        ans += solve(i+1, mask&(1<<i), v, mp, k);
        return ans; 
    }

    int beautifulSubsets(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        map<int, vector<int>> mp;
        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            mp[v[i]].push_back(i);
        }

        return solve(0, 0, v, mp, k);
    }
};


int main() {
    vector<int> v = {1};
    cout<<Solution().beautifulSubsets(v, 2);
    return 0;
}