#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
ll t,n,m;

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        ll mat[n][m];

        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<m ; j++)
            {
                cin>>mat[i][j];
            }
        }

        /*// diag decending

        for (int i=0 ; i<n  ; i++)
        {
            int j=0;
            int x=i;
            ll ans=0;
            while(x<n && j<m)
            {
                ans+=mat[x][j];
                j++;
                x++;
            }
            mp[{i,0}]=ans;
        }

        for (int j=0 ; j<m  ; j++)
        {
            int i=0;
            int x=j;
            ll ans=0;
            while(i<n && x<m)
            {
                ans+=mat[i][x];
                i++;
                x++;
            }
            mp[{0,j}]=ans;
        }

        // diag ascending

        for (int i=0 ; i<n  ; i++)
        {
            int j=0;
            int x=i;
            ll ans=0;
            while(x<n && j<m)
            {
                ans+=mat[x][j];
                j++;
                x--;
            }
            mp1[{i,0}]=ans;
        }

        for (int j=0 ; j<m  ; j++)
        {
            int i=0;
            int x=j;
            ll ans=0;
            while(i<n && x<m)
            {
                ans+=mat[i][x];
                i++;
                x++;
            }
            mp[{0,j}]=ans;
        }*/

        ll res=0;
        ll ans;
        int x,y;
        for (int i=0 ;i<n ; i++)
        {
            for (int j=0 ; j<m ; j++)
            {
                ans=0;
                x=i;
                y=j;
                while(x<n && x>-1 && y>-1 && y<m)
                {
                    ans+=mat[x][y];
                    x++;
                    y++;
                }

                x=i+1;
                y=j-1;
                while(x<n && x>-1 && y>-1 && y<m)
                {
                    ans+=mat[x][y];
                    x++;
                    y--;
                }

                x=i-1;
                y=j+1;
                while(x<n && x>-1 && y>-1 && y<m)
                {
                    ans+=mat[x][y];
                    x--;
                    y++;
                }

                x=i-1;
                y=j-1;
                while(x<n && x>-1 && y>-1 && y<m)
                {
                    ans+=mat[x][y];
                    x--;
                    y--;
                }
                res=max(res,ans);
            }


        }
        cout<<res;
        newL;
    }


    return 0;
}