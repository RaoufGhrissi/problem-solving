#include <bits/stdc++.h>
#define inf (int)1e9;
using namespace std;

//https://leetcode.com/problems/student-attendance-record-ii/

class Solution {
public:
    int dp[100000][2][3];
    int mod = 1e9 + 7;

    int rec(int i, int a, int l, int &n) {
        if (i == n)
            return 1;

        int &ans = dp[i][a][l];

        if (ans != -1)
            return ans;

        ans = rec(i+1, a, 0, n)%mod; // ans = 1

        if (a<1)
            ans += rec(i+1, a+1, 0, n)%mod;

        ans %= mod;

        if (l<2)
            ans += rec(i+1, a, l+1, n)%mod;

        ans %= mod;

        return ans;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, 0, n);
    }
};

int raouf[6];

int fib(int n) {
    if (n<2)
        return n;

    if (raouf[n] != -1) // rahi ma7souba 9bal
        return raouf[n]; // khoudha sta3mlha toul mat3awdch tehseb

    return raouf[n] = fib(n-1) + fib(n-2);
}

int main() {
    
    for (int i=0 ; i<6 ; i++)
        raouf[i] = -1;
    
    cout<<fib(3);
    return 0;
}