#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& v) {
        ll n = v.size();
        int j = n-1;

        while(j>0 && v[j] > v[j-1])
            j--;

        if (j == 0)
            return n*(n+1)/2;

        ll ans = n-j+1;
        int i = 0;
        while(i<n-1) {
            if (i && v[i] <= v[i-1])
                break;

            while(j<n && v[i] >= v[j])
                j++;
            
            if (j==n)
                break;

            ans += n-j+1;
            i++;
        }

        while(i<n && (!i || v[i]>v[i-1])) {
            ans++;
            i++;
        }

        return ans;
    }
};