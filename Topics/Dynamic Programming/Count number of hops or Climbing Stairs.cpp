// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long dp[100001];
    // function to count number of ways to reach top of the stair
    long long countWays(int N){

        for (int n=0 ; n<=N ; n++)
        {
            if (n == 0)
                dp[n] = 1;
            else if (n>=3)
                dp[n] = (dp[n-1]+dp[n-2]+dp[n-3])%1000000007;
            else if (n>=2)
                dp[n] = (dp[n-1]+dp[n-2])%1000000007;
            else
                dp[n] = dp[n-1]%1000000007;
        }
        return dp[N];
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;

	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}

    return 0;

}
  // } Driver Code Ends
