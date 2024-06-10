#include <bits/stdc++.h>

using namespace std;

const int N = 52;
char tab[N][N];
int oPerL[N];
int oPerC[N];

struct compare {
    bool operator()(vector<pair<int,int>> v1, vector<pair<int,int>> v2)
    {
        if (v1.size() != v2.size())
            return v1.size()<v2.size();

        for (int i=0 ; i<v1.size() ; i++)
        {
            if (v1[i].first != v2[i].first)
                return v1[i].first<v2[i].first;

            if (v1[i].second != v2[i].second)
                return v1[i].second<v2[i].second;
        }
    }
};

int main(){

freopen("a.txt","r",stdin);
freopen("a.out","w",stdout);

int t,n;
string s;
cin>>t;
for (int cas=1 ; cas<=t ; cas++)
{
    cin>>n;
    memset(oPerL, 0, sizeof oPerL);
    memset(oPerC, 0, sizeof oPerC);

    for (int i=0 ; i<n ; i++)
    {
        cin>>s;
        for (int j=0 ; j<n ; j++)
        {
            tab[i][j]=s[j];
            if (tab[i][j]=='O')
            {
                oPerL[i]++;
                oPerC[j]++;
            }
        }
    }

    set<vector<pair<int,int>>, compare> canWin;
    vector<pair<int,int>> v;
    for (int l=0 ; l<n ; l++)
    {
        v.clear();
        if (oPerL[l]!=0)
            continue;

        for (int c=0 ; c<n ; c++)
        {
            if (tab[l][c]=='.')
                v.push_back({l,c});
        }
        sort(v.begin(), v.end());
        canWin.insert(v);
    }

    for (int c=0 ; c<n ; c++)
    {
        v.clear();
        if (oPerC[c]!=0)
            continue;

        for (int l=0 ; l<n ; l++)
        {
            if (tab[l][c]=='.')
                v.push_back({l,c});
        }
        sort(v.begin(), v.end());
        canWin.insert(v);
    }

    if (canWin.empty())
    {
        cout<<"Case #"<<cas<<": Impossible"<<'\n';
        continue;
    }
    v=*canWin.begin();
    int m=v.size();
    int ans=0;

    for (auto a:canWin)
    {
        if(a.size()>m)
            break;
        ans++;
    }
    cout<<"Case #"<<cas<<": "<<m<<" "<<ans<<'\n';
}
    return 0;
}
