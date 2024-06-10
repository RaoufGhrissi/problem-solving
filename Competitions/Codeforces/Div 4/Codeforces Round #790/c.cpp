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
        vector<string> v(n);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        ll ans=INT_MAX;
        for (int i=0 ; i<n ; i++)
        {
            string s1=v[i];
            for (int j=i+1 ; j<n ; j++)
            {
                string s2=v[j];
                ll loc=0;
                for (int c=0 ; c<m ; c++)
                {
                    loc+=abs(s2[c]-s1[c]);
                }
                ans=min(loc,ans);
            }
        }

        cout<<ans;
        newL;
    }


    return 0;
}