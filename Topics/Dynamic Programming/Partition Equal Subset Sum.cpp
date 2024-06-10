// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[101][100001];

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        for (int i=0 ; i<N ; i++)
            total+= arr[i];

        if (total %2 != 0)
            return 0;

        for (int n=0 ; n<=N ; n++)
        {
            for (int s=0 ; s<=total ; s++)
            {
                if (n == 0)
                {
                    if (s == total/2)
                        dp[n][s] = 1;
                    else
                        dp[n][s] = 0;
                }
                else
                {
                    if (s-arr[n-1]>=total/2)
                        dp[n][s] = dp[n-1][s] + dp[n-1][s-arr[n-1]];
                    else
                        dp[n][s] = dp[n-1][s];
                }
            }
        }
        return dp[N][total];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
