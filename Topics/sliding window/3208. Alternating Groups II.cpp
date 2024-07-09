#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k) {
        int n = v.size();

        for (int i=0 ; i<k-1 ; i++)
            v.push_back(v[i]);

        n = v.size();
        int i = 0, j = 0;
        
        int ans = 0;
        while(j<n) {
            if (j-i+1 <= k) {
                if (j==i || v[j] != v[j-1])
                    j++;
                else
                    i = j;
            } else {
                ans++;
                i++;
            }
        }

        if (j-i+1 == k)
            ans++;
        
        return ans;
    }
};


int main() {
    vector<int> v = {0, 1, 1};
    int k = 3;
    cout<<Solution().numberOfAlternatingGroups(v, k);
}