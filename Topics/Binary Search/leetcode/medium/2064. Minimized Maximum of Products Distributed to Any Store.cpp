#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& v) {
        int i=1;
        int j=10;

        while(i<j) {
            int mid = (i+j)/2;
            int nn = 0;
            for (int &x:v) {
                nn += x%mid ? x/mid + 1 : x/mid;
            }

            if (nn > n)
                i = mid+1;
            else
                j = mid-1;
        }

        return i;
    }
};


int main() {
    vector<int> v=  {5, 7};
    cout<<Solution().minimizedMaximum(2, v);
}