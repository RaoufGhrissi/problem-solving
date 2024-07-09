#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();

        for (char c = 'A' ; c <= 'Z' ; c++) {
            int i=0, j=0;
            int diff = 0;

            while(j<n) {
                if (s[j]==c || diff<k) {
                    if (s[j] != c)
                        diff++;
                    j++;
                } else {
                    ans = max(ans, j-i);
                    if (s[i] != c)
                        diff--;
                    i++;
                }
            }
            ans = max(ans, j-i);
        }

        return ans;
    }
};

int main() {
    vector<int> v = {2,3,1,2,4,3};
    cout<<Solution().characterReplacement("ABAB", 2);
}