#include<bits/stdc++.h>
using namespace std;

const int N=2000;
vector<vector<int> > graph;
bool visited[N];
int level[N];
int maxLevel=0;
vector<int> roots;

void bfs(int pos)
{
        visited[pos]=true;
        queue<int> q;
        q.push(pos);
        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            for (auto child:graph[parent])
            {
                if (!visited[child]){
                    level[child] = level[parent]+1;
                    maxLevel=max(maxLevel,level[child]);
                    visited[child]=true;
                    q.push(child);
                }
            }
        }
        return ;
}


int main(){
    int n;
    cin>>n;

    graph.clear();
    graph.resize(n);

    for (int i=0; i<n ; i++)
    {
        int a;
        cin>>a;
        if (a != -1)
            graph[a-1].push_back(i);
        else
            roots.push_back(i);
    }
    memset(visited, false,sizeof(visited));
    memset(level,0,sizeof(level));
    for (auto root:roots)
    {
        level[root]=1;
        bfs(root);
    }

    cout<<max(maxLevel,1);
	return 0;
}
