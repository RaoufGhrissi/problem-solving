// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends

int dp[13][1001];

int f(int n, int l, string line, vector<string> &dict, int N)
{
    if (dp[n][l] != -1)
        return dp[n][l];

    if (l == 0)
        dp[n][l] = 1;
    else if (n == 0)
        dp[n][l] = 0;
    else
    {
        string ch = line.substr(0,l);
        int p = ch.rfind(dict[n-1]);

        if ( p != -1 && p == ch.size()-dict[n-1].size())
        {
            dp[n][l] = f(N, l - dict[n-1].size(), line, dict, N) + f(n-1, l, line, dict, N);
        }
        else
            dp[n][l] = f(n-1, l, line, dict, N);
    }
    return dp[n][l];
}

int wordBreak(string A, vector<string> &B) {
    memset(dp, -1, sizeof(dp));
    if (f(B.size(), A.size(), A, B, B.size()) != 0)
        return 1;
    else
        return 0;
}
