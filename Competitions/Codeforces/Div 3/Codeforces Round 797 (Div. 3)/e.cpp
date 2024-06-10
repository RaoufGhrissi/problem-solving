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

int main()
{
    ll t,n,k;
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        vector<ll> v(n);
        vector<ll> r(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        ll ans=0;


        for (int i=0 ; i<n ; i++)
        {
            ans+=v[i]/k;
            if (v[i]%k > 0)
                r.pb(v[i]%k);
        }

        sortt(r);

        int i=0;
        int j=r.size()-1;
        while(i<j)
        {
            if (r[i]+r[j]>=k)
            {
                i++;
                j--;
                ans++;
            }
            else
                i++;
        }


        cout<<ans;
        newL;
    }


    return 0;
}