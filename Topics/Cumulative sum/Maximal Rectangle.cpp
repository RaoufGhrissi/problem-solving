#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& t) {
        int n = t.size();
        int m = t[0].size();

        vector<vector<int>> v(n, vector<int>(m));

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                v[i][j] = t[i][j]-'0';
            }
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=1 ; j<m ; j++) {
                v[i][j] += v[i][j-1];
            }
        }

        for (int i=1 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                v[i][j] += v[i-1][j];
            }
        }

        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (!v[i][j]) continue;
                for (int l=i ; l<n ; l++) {
                    int s = j;
                    int e = m-1;

                    while(s<e) {
                        int mid = (s+e+1)/2;
                        int cnt = v[l][mid];
                        if (i) cnt -= v[i-1][mid];
                        if (j) cnt -= v[l][j-1];
                        if (i && j) cnt += v[i-1][j-1];
                        
                        if (cnt == (l-i+1)*(mid-j+1)) s=mid;
                        else e = mid-1;
                    }

                    int cnt = v[l][s];
                    if (i) cnt -= v[i-1][s];
                    if (j) cnt -= v[l][j-1];
                    if (i && j) cnt += v[i-1][j-1];
                    
                    if (cnt == (l-i+1)*(s-j+1)) ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};
