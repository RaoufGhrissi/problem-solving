#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    unsigned int dp[1001][1001];
    unsigned int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        for (int i=0 ; i<=n ; i++)
        {
            for (int j=0 ; j<=m ; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else
                {
                    if (s[i-1] == t[j-1])
                        dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;

		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;


	}

}  // } Driver Code Ends
