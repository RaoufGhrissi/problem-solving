#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    int maxK(vector<int>& v, int k) {
        int i=0, j=0, ans=0, n=v.size();
        int odd = 0;

        while(j<n) {
            if (!(v[j]&1) || (odd+1 <= k)) {
                odd += v[j]&1;
                j++;
            }
            else {
                ans += j-i;
                odd -= v[i]&1;
                i++;
            }
        }

        while(i<n) { // tnajem tgedha toul b formule ama bekhel 
            ans += j-i;
            i++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& v, int k) {
        return maxK(v, k) - maxK(v, k-1);
    }
};

int main() {
    vector<int> v = {2,2,2,1,2,2,1,2,2,2};
    cout<<Solution().numberOfSubarrays(v, 2);
}