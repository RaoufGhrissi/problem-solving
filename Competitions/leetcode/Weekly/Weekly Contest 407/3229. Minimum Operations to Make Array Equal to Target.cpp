#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:

    long long minimumOperations(vector<int>& v, vector<int>& t) {
        int n = v.size();
        ll prev = 0;
        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            int diff = v[i] - t[i];

            if (diff > 0 && prev < 0 || diff < 0 && prev > 0)
                ans += abs(diff);
            else if (abs(diff) > abs(prev))
                ans += abs(diff-prev);

            prev = diff;
        }

        return ans;
    }
};

int main() {
    vector<int> t = {4,6,2,4};
    vector<int> v = {3,5,1,2};

    cout<<Solution().minimumOperations(v, t);
}