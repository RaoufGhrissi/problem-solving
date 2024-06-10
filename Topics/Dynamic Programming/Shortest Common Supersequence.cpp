// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n
int dp[101][101];
int f(char* x, char* y, int m, int n) {
    if (dp[m][n] != -1)
        return dp[m][n];
    
    if (m == 0)
        dp[m][n] = n;
    else if (n == 0)
        dp[m][n] = m;
    else
    {
        if (x[m-1] == y[n-1])
            dp[m][n] = 1 + f(x,y,m-1,n-1);
        else
        {
            dp[m][n] = 1+min(f(x,y,m-1,n), f(x,y,m,n-1));
        }
    }
    return dp[m][n];
}

int shortestCommonSupersequence(char* x, char* y, int m, int n)
{
    memset(dp, -1, sizeof(dp));
    return f(x,y,m,n);
}
