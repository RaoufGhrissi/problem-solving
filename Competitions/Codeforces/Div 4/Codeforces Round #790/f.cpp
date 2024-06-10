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
ll t,n,m,k;

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        vector<ll> v;
        map<ll,int> mp;
        for (int i=0 ; i<n ; i++)
        {
            cin>>k;
            mp[k]++;
            if (mp[k]==1)
                v.pb(k);
        }

        ll mi=INT_MAX;
        ll ma=0;
        for (auto a:mp)
        {
            if (a.s>=m)
            {
                mi=min(mi, a.f);
                ma=max(ma, a.f);
            }
        }
        if (ma == 0)
        {
            cout<<-1;
            newL;
            continue;
        }

        sortt(v);
        vector<ll> succ(v.size(),0);
        Pair ans={0,0};
        for (int i=0 ; i<v.size() ; i++)
        {
            if (v[i]>ma)
                break;

            if (v[i]<mi || mp[v[i]]<m)
                continue;

            succ[i]=1;

            if (i>0 && v[i]==v[i-1]+1)
                succ[i]+=succ[i-1];

            if (succ[i]>=ans.s-ans.f+1)
                ans={v[i]-succ[i]+1, v[i]};
        }
        cout<<ans.f<<" "<<ans.s;

        newL;
    }


    return 0;
}