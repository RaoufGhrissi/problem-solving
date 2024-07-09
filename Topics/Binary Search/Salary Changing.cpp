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
int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        vector<iPair> v(n);
        forn(0,n)
        {
            cin>>v[i].f>>v[i].s;
            k-=v[i].f;
        }

        int target=(n+1)/2;
        int l=1;
        int r=1e9;
        multiset<int> st;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            st.clear();
            for (auto a:v)
            {
                if (a.s>=mid && a.f<=mid)
                    st.insert(mid-a.f);
                else if (mid<a.f)
                    st.insert(0);
            }

            ll ss=k;
            int e=0;
            for (auto a:st)
            {
                if (ss-a>=0)
                {
                    ss-=a;
                    e++;
                }
                else
                    break;
            }

            if (e>=target)
                l=mid;
            else
                r=mid-1;
        }

        cout<<l;

        newL;
    }

    return 0;
}