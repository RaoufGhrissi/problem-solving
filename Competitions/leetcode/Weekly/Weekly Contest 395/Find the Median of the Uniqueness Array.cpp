#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& v) {
        int n = v.size();
        int m = (n+1)*n/4;
        map<int,int> occ;

        for (int i=0 ; i<n ; i++) {
            occ[v[i]]++;
        }

        int i = 1;
        int j = occ.size();

        while (i<j) {
            int mid = (i+j+1)/2;
            // check the first mid position, get the subarrays with value < mid
            int s = 0;
            int e = 0;
            int cnt = 0;
            occ.clear();

            while(e<n) {
                if (occ.count(v[e]) || occ.size()+1 < mid) {
                    occ[v[e]]++;
                    e++;
                } else {
                    cnt += (e-s);
                    occ[v[s]]--;
                    if (!occ[v[s]])
                        occ.erase(v[s]);
                    s++;
                }
            }

            while(s<e) {
                cnt += (e-s);
                s++;
            }

            if (cnt >= m) {
                j = mid-1;
            } else {
                i = mid;
            }
        }

        return i;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    cout<<Solution().medianOfUniquenessArray(v);
    return 0;
}