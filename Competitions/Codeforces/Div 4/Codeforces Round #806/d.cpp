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
        vector<string> v(n);
        map<string,bool> mp;
        for (int i=0 ; i<n ; i++)
        {
            cin>>v[i];
            mp[v[i]]=1;
        }

        for (auto a:v)
        {
            bool found=0;
            for (int i=1 ; i<a.size() ; i++)
            {
                string s1=a.substr(0,i);
                string s2=a.substr(i);

                if (mp.find(s1) != mp.end() && mp.find(s2) != mp.end())
                {
                    found=1;
                    break;
                }
            }
            if (found)
                cout<<1;
            else
                cout<<0;

        }

        newL;


    }

    return 0;
}