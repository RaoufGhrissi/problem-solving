#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    bool inY(int i, int j, int n) {
        int mid = n/2;
        return ((i==j || j==n-1-i) && i<=mid) || (j == mid && i > mid);    
    }
    
    int minimumOperationsToWriteY(vector<vector<int>>& v) {
        int o = 0, oy = 0;
        int t = 0, ty = 0;
        int z = 0, zy = 0;
        
        int n = v.size();
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                int x = v[i][j];
                if (inY(i, j, n)) {
                    oy += x == 1;
                    ty += x == 2;
                    zy += !x;
                } else {
                    o += x == 1;
                    t += x == 2;
                    z += !x;
                }
            }
        }

        int allY = oy+ty+zy;
        int all = o+t+z;

        return max({
            allY - oy + all - t,
            allY - oy + all - z,
            allY - ty + all - o,
            allY - ty + all - z,
            allY - zy + all - o,
            allY - zy + all - t,
        });   
    }
};

int main() {
    vector<vector<int>> v = {{0,1,0,1,0},{2,1,0,1,2},{2,2,2,0,1},{2,2,2,2,2},{2,1,2,2,2}};
    cout<<Solution().minimumOperationsToWriteY(v);
    return 0; 
}