#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int getAire(int is, int js, int ie, int je, vector<vector<int>>& v) {
        int imi = 1e9, jmi = 1e9;
        int imx = -1, jmx = -1;

        for (int i=is ; i<=ie ; i++) {
            for (int j=js ; j<=je ; j++) {
                if (v[i][j]) {
                    imi = min(i, imi);
                    jmi = min(j, jmi);
                    imx = max(i, imx);
                    jmx = max(j, jmx);
                }
            }
        }

        return imx == -1 ? 1e9 : (jmx - jmi + 1) * (imx - imi + 1);
    }

    int minimumSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 1e8;

        /*    
        __________
        |________|
        |________|
        |________|

        */

        for (int i=0 ; i<n-2 ; i++) {
            for (int j=i+1 ; j<n-1 ; j++) {
                ans = min(
                    ans,
                    getAire(0, 0, i, m-1, v) + getAire(i+1, 0, j, m-1, v) + getAire(j+1, 0, n-1, m-1, v)
                );
            }
        }
        
        /*    
        __________
        |    |    |
        |____|____|
        |_________|

        */

        for (int i=0 ; i<n-1 ; i++) {
            for (int j=0 ; j<m-1 ; j++) {
                ans = min(
                    ans,
                    getAire(0, 0, i, j, v) + getAire(0, j+1, i, m-1, v) + getAire(i+1, 0, n-1, m-1, v)
                );
            }
        }

        /*  can be combined with the previous, seperated only for better readability
        __________ 
        |         |
        |____ ____|
        |____|____|
                    
        */
        for (int i=0 ; i<n-1 ; i++) {
            for (int j=0 ; j<m-1 ; j++) {
                ans = min(
                    ans,
                    getAire(0, 0, i, m-1, v) + getAire(i+1, 0, n-1, j, v) + getAire(i+1, j+1, n-1, m-1, v)
                );
            }
        }

        /*    
        __________
        |    |  | |
        |    |  | |
        |____|__|_|

        */
        for (int i=0 ; i<m-2 ; i++) {
            for (int j=i+1 ; j<m-1 ; j++) {
                ans = min(
                    ans,
                    getAire(0, 0, n-1, i, v) + getAire(0, i+1, n-1, j, v) + getAire(0, j+1, n-1, m-1, v)
                );
            }
        }

        /*    
        __________
        |    |   |
        |    |___|
        |____|___|

        */
        for (int i=0 ; i<m-1 ; i++) {
            for (int j=0 ; j<n-1 ; j++) {
                ans = min(
                    ans,
                    getAire(0, 0, n-1, i, v) + getAire(0, i+1, j, m-1, v) + getAire(j+1, i+1, n-1, m-1, v)
                );
            }
        }

        /*  can be combined with the previous, seperated only for better readability
        __________
        |    |   |
        |____|   |
        |____|___|

        */

        for (int i=0 ; i<m-1 ; i++) {
            for (int j=0 ; j<n-1 ; j++) {
                ans = min(
                    ans,
                    getAire(0, 0, j, i, v) + getAire(j+1, 0, n-1, i, v) + getAire(0, i+1, n-1, m-1, v)
                );
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> v = {{1,0,1},{1,1,1}};
    cout<<Solution().minimumSum(v);
}