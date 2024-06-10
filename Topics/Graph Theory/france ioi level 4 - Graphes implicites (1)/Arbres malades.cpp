#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,c,k,res;
vector < vector < int > > graph;
struct elt{
int x;
int y;
int r;
};
vector< elt > tab;
bool shouldAdd(elt e1 , elt e2)
{
   int i=e1.x,j=e1.y,x=e2.x,y=e2.y;
   return pow(i-x,2)+pow(j-y,2) <= pow(e1.r,2);
}
bool visited[300];

void dfs(int pos)
{
    visited[pos]=true;
    res++;
    for (int i=0 ; i<(int)graph[pos].size() ; i++)
    {
        int x = graph[pos][i];
        if(!visited[x])
            dfs(x);
    }
    return;

}

int main(){
cin>>n>>m;
graph.clear();
graph.resize(n);

while(n--)
{
    cin>>a>>b>>c;
    elt p;
    p.x=a;
    p.y=b;
    p.r=c;
    tab.push_back(p);
}
n=tab.size();

for (int i=0 ; i<n ; i++)
{
    for (int j=0 ; j<n ; j++)
    {
        if(i!=j && shouldAdd(tab[i],tab[j]))
            graph[i].push_back(j);
    }
}
/*for (int i=0 ; i<n ; i++)
{
    cout<<" i "<<i<<" : ";
    for (int j=0 ; j<graph[i].size() ; j++)
    {
        cout<<graph[i][j]<<" ";
    }
    cout<<endl;
}*/

while(m--)
{
    memset(visited,false, sizeof visited);
    res=0;
    //cout<<"input :";
    cin>>k;
    dfs(k);
    cout<<res<<'\n';
}
return 0;
}
