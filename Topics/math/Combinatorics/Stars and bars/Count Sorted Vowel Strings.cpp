//https://leetcode.com/problems/count-sorted-vowel-strings/submissions/1200518937/

#include <bits/stdc++.h>

using namespace std;

class Cnk {
    public:
        int dp[101][101];

        Cnk() {
            memset(dp, -1, sizeof dp);
        }

        int compute(int n, int k) {
            if (!k)
                return 1;

            if (!n)
                return 0;

            if (dp[n][k] != -1)
                return dp[n][k];

            return dp[n][k] = compute(n-1, k) + compute(n-1, k-1);
        }

        int starsAndbars(int objects, int places) {
            return compute(objects+places-1, objects);
        }
};

class Solution {
public:
    int countVowelStrings(int n) {
        // place 4 separators in n+1 places
        int k = 4;
        Cnk cnk = Cnk();
        return cnk.starsAndbars(4, n+1);
    }
};

int main() {
    cout<<Solution().countVowelStrings(2);
    return 0;
}