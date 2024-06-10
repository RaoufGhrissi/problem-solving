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

ll t,n,k;
const int l=32;

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        vector<ll> v(n);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        ll cum[l][n];

        for (int i=0 ; i<n ; i++)
            cum[0][i] = v[i];

        for (int i=1 ; i<l ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                cum[i][j]=cum[i-1][j]/2;
            }
        }

        /*for (int i=0 ; i<l ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                cout<<cum[i][j]<<" ";
            }
            newL;
        }*/

        for (int i=0 ; i<l ; i++)
        {
            for (int j=1 ; j<n ; j++)
            {
                cum[i][j]+=cum[i][j-1];
            }
        }



        ll balance=0;
        ll res=0;
        int badKey=1;
        for (int i=-1 ; i<n ; i++)
        {
            balance=0;
            badKey=1;
            if (i>-1)
                balance+=cum[0][i]-(k*(i+1));

            int j=i+1;
            while(cum[badKey][n-1] && j<n && badKey<l)
            {
                balance+=cum[badKey][j];
                if (j>0)
                    balance-=cum[badKey][j-1];
                badKey++;
                j++;
            }

            res=max(res, balance);
        }

        cout<<res;
        newL;
    }

    return 0;
}