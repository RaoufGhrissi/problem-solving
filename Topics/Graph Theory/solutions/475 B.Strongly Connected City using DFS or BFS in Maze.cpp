#include<bits/stdc++.h>
using namespace std;
const int N=407;
int n,m;
bool vis[N][N];
char di[N];
char dj[N];

bool safe(int i, int j)
{
    return i>-1 && i<n && j>-1 && j<m;
}

void dfs(int pi, int pj)
{
    vis[pi][pj]=true;

    vector<pair<int,int>> children;

    int c1i = pi,c1j;

    if (dj[pi] == '<')
        c1j=pj-1;
    else
        c1j=pj+1;

    if (safe(c1i,c1j))
        children.push_back({c1i, c1j});

    int c2i,c2j = pj;

    if (di[pj] == '^')
        c2i=pi-1;
    else
        c2i=pi+1;

    if (safe(c2i,c2j))
        children.push_back({c2i, c2j});

    for (auto child:children)
    {
        int ci=child.first;
        int cj=child.second;
        if (!vis[ci][cj])
        {
            dfs(ci,cj);
        }
    }
    return;
}


int main(){
    cin>>n>>m;

    for (int j=0 ; j<n ; j++)
        cin>>dj[j];

    for (int i=0 ; i<m ; i++)
        cin>>di[i];

    for (int l=0 ; l<n ; l++)
    {
        for (int c=0; c<m ; c++)
        {
            memset(vis, false,sizeof(vis));
            dfs(l,c);
            for (int i=0 ; i<n ; i++)
            {
                for (int j=0 ; j<m ; j++)
                {
                    if (!vis[i][j])
                    {
                        cout<<"NO";
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"YES";
    return 0;
}
