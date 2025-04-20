#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& v) {
        int ans = 0;

        int n = v.size();
        vector<bool> st(4097, 0);
        st[0] = 1;
        

        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                st[v[i]^v[j]] = 1;
            }
        }

        for (int num=0 ; num<=2048 ; num++) {
            for (int i=0 ; i<n ; i++) {
                int goal = 0;
                for (int bit=0 ; bit<=11 ; bit++) {
                    int mask = 1<<bit;

                    int target = mask&num;
                    int actual = mask&v[i];

                    if (target) {
                        if (!actual) goal += mask;
                    } else {
                        if (actual) goal += mask;
                    }
                }

                if (st[goal]) {
                    ans++;
                    break;
                }
            }
        }


        return ans;
    }
};