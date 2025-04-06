#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll maximumSumOfHeights(vector<int>& v) {
        int n = v.size();

        vector<ll> left(n, 0), right(n, 0);
        ll ans = 0;
        stack<int> st;

        for (int i=0 ; i<n ; i++) {
            left[i] = v[i];
            while(!st.empty() && v[st.top()] > v[i]) {
                left[i] += v[i];
                st.pop();
            }

            if (!st.empty()) left[i] += left[st.top()];
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i=n-1 ; i>-1 ; i--) {
            right[i] = v[i];
            while(!st.empty() && v[st.top()] > v[i]) {
                right[i] += v[i];
                st.pop();
            }

            if (!st.empty()) right[i] += right[st.top()];
            st.push(i);

            cout<<left[i]<<" "<<right[i]<<endl;

            ans = max(ans, left[i] + right[i]- v[i]);
        }


        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> v = {6,5,3,9,2,7};
    cout << sol.maximumSumOfHeights(v) << endl;
    return 0;
}