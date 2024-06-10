#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define Pair pair<ll,ll>
#define iPair pair<int,int>
#define newL cout<<endl
#define ll_max 1e18
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define forn(j,n) for (int i=j ; i<n ; i++)

using namespace std;

int t,n,m;
int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int mat[n][n];

        for (int i=0 ; i<n ; i++)
        {
            string c;
            cin>>c;
            for (int j=0 ; j<n ;j++)
            {
                if (c[j]=='1')
                    mat[i][j]=1;
                else
                    mat[i][j]=0;

                //cout<<mat[i][j]<<" ";
            }
            //newL;
        }

        //newL;

        int ans=0;
        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                int zeros=0;
                int ones=0;
                zeros+=mat[i][j] == 0;
                zeros+=mat[j][n-1-i] == 0;
                zeros+=mat[n-1-i][n-1-j] == 0;
                zeros+=mat[n-1-j][i] == 0;

                mat[i][j] = 0;
                mat[j][n-1-i] = 0;
                mat[n-1-i][n-1-j] = 0;
                mat[n-1-j][i] = 0;

                ans+=min(zeros, 4-zeros);
                //cout<<"ans = "<<ans<<" zeros ="<<zeros<<endl;


            }
        }

        cout<<ans;
        newL;


    }

    return 0;
}