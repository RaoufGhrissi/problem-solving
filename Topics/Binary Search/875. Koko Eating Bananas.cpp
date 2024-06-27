#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int div_ceil(int a, int b)
    {
        return a/b + (a%b > 0);
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int n = 1e9;
        int i = 1;
        int j = n;

        while(i<j)
        {
            int mid = (i+j)/2;
            int res = 0;
            for (auto a:v)
            {
                res += div_ceil(a, mid);
                if (res > h)
                    break;
            }

            if (res > h)
                i = mid+1;
            else
                j = mid;
        }

        return i;
    }
};