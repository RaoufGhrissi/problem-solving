#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    bool solve(int k, int tot, int mask, vector<int> &v, int &n, int &sm) {
        if (!k)
            return 1;

        bool ans = 0;
        for (int i=0 ; i<n ; i++) {
            int msk = 1<<i;

            if (mask&msk)
                continue;

            if (v[i] < tot)
                ans |= solve(k, tot-v[i], mask|msk, v, n, sm);
            else if (v[i] == tot)
                ans |= solve(k-1, sm, mask|msk, v, n, sm);
        }

        return ans;
    }

    bool canPartitionKSubsets(vector<int>& v, int k) {
        int n = v.size();
        int tot = 0;
        for (auto &a:v)
            tot += a;

        if (tot%k) return 0;
        int sm = tot/k;

        return solve(k, sm, 0, v, n, sm);
    }
};

int main() {
    vector<int> v = {4,3,2,3,5,2,1};
    cout<<Solution().canPartitionKSubsets(v, 4);
    return 0;
}