// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << cutRod(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends

int dp[1001][1001];

int f(int price[], int n, int N)
{
    if (dp[n][N] != -1)
        return dp[n][N];

    if (n == 0 || N == 0)
        dp[n][N] = 0;
    else
    {
        if (n<=N)
            dp[n][N] = max(price[n-1]+f(price,n,N-n), f(price,n-1,N));
        else
            dp[n][N] = f(price,n-1,N);
    }

    return dp[n][N];
}

int cutRod(int price[], int n)
{
    memset(dp,-1,sizeof(dp));
    return f(price,n,n);
}
