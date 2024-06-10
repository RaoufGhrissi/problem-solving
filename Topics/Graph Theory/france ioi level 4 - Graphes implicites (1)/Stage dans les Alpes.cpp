#include <bits/stdc++.h>

using namespace std;
vector < vector < int > > graph ;
int k,n;
bool visited[120];
vector<int> path;

void printPathsUtile(int currentNode)
{
    visited[currentNode]=true;
    path.push_back(currentNode);
    int dim=path.size();
    if(dim==n)
    {
        for(int i=0 ; i<dim ; i++)
            cout<<path[i]<<" ";
        cout<<'\n';
    }
    else
    {
        for (int i=0 ; i<graph[currentNode].size(); i++)
        {
            int x=graph[currentNode][i];
            if(!visited[x] || x==currentNode)
                    printPathsUtile(x);
        }
    }
    path.pop_back();
    visited[currentNode]=false;
}

//print all Paths with arret edges starting from s
void printPaths(int s)
{
    memset(visited,false,sizeof visited);
    path.clear();
    printPathsUtile(s);
}


int main(){
cin>>k>>n;
graph.clear();
graph.resize(k+1);
for (int i=1 ; i<k+1 ; i++)
{
    for (int j=i ; j<k+1 ; j++)
    {
        graph[i].push_back(j);
    }
}
for (int i=1 ; i<k+1 ; i++)
printPaths(i);

return 0 ;
}
