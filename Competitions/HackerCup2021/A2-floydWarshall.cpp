#include <bits/stdc++.h>

using namespace std;

#define Inf 99999
const int N = 28;
int dist[N][N];

void floydWarshall()
{
    int s,d,inter;
    for (inter=0 ; inter<N ; inter++)
    {
        for (s=0 ; s<N ; s++)
        {
            for (d=0 ; d<N ; d++)
            {
                if (dist[s][inter]+dist[inter][d]<dist[s][d])
                    dist[s][d]=dist[s][inter]+dist[inter][d];
            }
        }
    }
}

int main(){

freopen("a.txt","r",stdin);
freopen("a.out","w",stdout);

int n,k;
string s,ch;
int occ[N];
cin>>n;

for (int cas=1 ; cas<=n ; cas++)
{
    cin>>s>>k;
    memset(occ, 0, sizeof occ);
    for (int i=0 ; i<s.size() ; i++)
        occ[s[i]-'A']++;

    for (int i=0 ; i<N ; i++)
    {
        for (int j=0 ; j<N ; j++)
        {
            if (i==j)
                dist[i][j]=0;
            else
                dist[i][j]=Inf;
        }
    }
    while(k--)
    {
        cin>>ch;
        dist[ch[0]-'A'][ch[1]-'A']=1;
    }
    floydWarshall();

    vector<int> canBeDestination;

    for (int j=0 ; j<N ; j++)
    {
        bool ok = true;
        for (int i=0 ; i<N ; i++)
        {
            if (occ[i] == 0)
                continue;
            if (dist[i][j] == Inf)
            {
                ok = false;
                break;
            }
        }
        if (ok)
           canBeDestination.push_back(j);
    }
    int ans=INT_MAX;
    if (canBeDestination.empty())
    {
        cout<<"Case #"<<cas<<": "<<-1<<'\n';
        continue;
    }
    for(auto a:canBeDestination)
    {
        int c=0;
        for (int i=0 ; i<N ; i++)
        {
            if (occ[i]==0)
                continue;
            c+=dist[i][a]*occ[i];
        }
        ans=min(ans,c);
    }

    cout<<"Case #"<<cas<<": "<<ans<<'\n';
}

    return 0;
}
