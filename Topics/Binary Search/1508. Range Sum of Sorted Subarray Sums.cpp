#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    
    pair<int, int> get(vector<int> &v, int mx) {
        int i=0, j=0, n=v.size();
        
        int cnt = 0;
        int sm = 0;
        int tot = 0;
        int prev = 0;

        while(j<n) {
            if (sm + v[j] <= mx) {
                sm += v[j];
                prev += v[j]*(j-i+1);
                tot += prev;
                j++;
            } else {
                cnt += j-i;
                prev -= sm;

                if (i<j)
                    sm -= v[i++];
                else {
                    j++;
                    i = j;
                }
            }
        }

        while(i<j) {
            cnt += j-i;
            i++;
        }

        return {cnt, tot};
    }

    int rangeSum(vector<int>& v, int n, int left, int right) {
        int s=0;
        int e=100;
        int cnt;
        pair<int,int> pp;

        while(s<e) {
            int mid = (s+e)/2;

            pp = get(v, mid);
            cnt = pp.first;
            
            if (cnt < left) {
                s = mid+1;
            } else {
                e = mid;
            }
        }

        int l = s;

        pp = get(v, l);
        
        int before = pp.second - (pp.first-left+1)*l;

        s=0;
        e=100;

        while(s<e) {
            int mid = (s+e)/2;
            pp = get(v, mid);
            cnt = pp.first;

            if (cnt < right) {
                s = mid+1;
            } else {
                e = mid;
            }
        }

        int r = s;

        pp = get(v, r);

        int after = pp.second - (pp.first-right)*r;
        
        return after-before;
    }
};

int main() {
    vector<int> v = {7,5,8,5,6,4,3,3};
    cout<<Solution().rangeSum(v, 8, 2, 6);
}