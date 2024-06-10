#include<bits/stdc++.h>

using namespace std;
const int N=1e5;
bool isBipartite;
int colors[N];
bool visited[N];
vector<vector<int> > graph;
vector<int> vb;
vector<int> vr;
int n,m;

void bfs(int pos)
{
        visited[pos]=true;
        colors[pos]=1; // bleu = 1;
        queue<int> q;
        q.push(pos);
        while(!q.empty())
        {
            int x=q.front();
            if (colors[x] == 1)
                vb.push_back(x+1);
            else
                vr.push_back(x+1);
            q.pop();
            for (int i=0 ; i<graph[x].size() ; i++)
            {
                int next = graph[x][i];
                if (colors[next] != 0 && colors[next] == colors[x])
                {
                    isBipartite = false;
                    return;
                }
                if (!visited[next])
                {
                    visited[next]=true;
                    if (colors[x] == 1)
                        colors[next] = 2; // parent bleu , child red
                    else
                        colors[next] = 1; // parent red , child bleu
                    q.push(next);
                }
            }
        }
}


int main(){
    cin>>n>>m;
    graph.clear();
    graph.resize(n);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    memset(visited,false,sizeof(visited));
    memset(colors,0,sizeof(colors));
    for (int i=0 ; i<n ; i++)
    {
        if (!visited[i]){
            if (graph[i].empty())
                continue;

            isBipartite = true;
            bfs(i);
            if (!isBipartite)
            {
                cout<<-1;
                return 0;
            }
        }
    }

    if (isBipartite)
    {
        int s1=vb.size();
        cout<<s1<<'\n';
        for (int i=0; i<s1 ; i++)
            cout<<vb[i]<<" ";
        cout<<'\n';

        int s2=vr.size();
        cout<<s2<<'\n';
        for (int i=0; i<s2 ; i++)
            cout<<vr[i]<<" ";
    }
    else
        cout<<-1;
	return 0;
}
