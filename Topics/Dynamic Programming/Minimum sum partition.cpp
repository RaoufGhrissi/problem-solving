// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:

	int minDiffernce(int arr[], int N)
	{
        int total = 0;
        for (int i=0 ; i<N ; i++)
            total+= arr[i];

        int dp[N+1][total+1];
        for (int n=0 ; n<=N ; n++)
        {
            for (int s=0 ; s<=total ; s++)
            {
                if (n == 0)
                    dp[n][s] = abs(total-2*s);
                else
                {
                    if (s-arr[n-1]>=0)
                        dp[n][s] = min(dp[n-1][s], dp[n-1][s-arr[n-1]]);
                    else
                        dp[n][s] = dp[n-1][s];
                }
            }
        }
        return dp[N][total];
	}
};


// { Driver Code Starts.
int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];



	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";

    }
    return 0;
}  // } Driver Code Ends
