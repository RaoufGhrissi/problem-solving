#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution {
public:
    ll repairCars(vector<int>& v, int n) {
        ll i=0;
        ll j=1e14;

        while(i<j) {
            ll mid = (i+j)/2;
            ll cars = 0;
            for (int &x:v) {
                cars += sqrt(mid/x);
            }

            if (cars >= n)
                j = mid;
            else
                i = mid+1;
        }

        return i;
    }
};