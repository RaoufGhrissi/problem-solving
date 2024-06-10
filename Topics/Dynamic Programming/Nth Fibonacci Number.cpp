#include <bits/stdc++.h>
using namespace std;

long long int dp[1001];

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        if (dp[n]!=0)
            return dp[n];

        if (n<=2)
            dp[n] = 1;
        else
            dp[n] = (nthFibonacci(n-1)+nthFibonacci(n-2))%1000000007;

        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
