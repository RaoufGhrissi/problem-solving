#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    long long maximumPoints(vector<int>& v, int e) {
        sort(v.begin(), v.end());
        int n = v.size();
        int i = 0, j = n-1;
        
        int p = 0;
        int mx = 0;
        
        while(i<=j) {
            if (e>=v[i]) {
                p++;
                mx = max(mx, p);
                e -= v[i];
            } else if (p > 0) {
                p--;
                e += v[j--];
            } else {
                 break;
            }
        }
        
        return mx;
    }
};

int main() {
    vector<int> v = {3,2,2};
    int k = 2;
    cout<<Solution().maximumPoints(v, k);
}