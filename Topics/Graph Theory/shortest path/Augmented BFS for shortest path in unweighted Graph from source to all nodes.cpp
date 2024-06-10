#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define INF (ll)(1e18)

using namespace std;

const int N = 1e5+7;
vector<int> graph[N];
bool visited[N];
int dist[N];

void augmentedBfs (int src, int dest){
	queue<int> q;
    q.push(src);
    visited[src]=true;

    dist[src]=0;

	while (!q.empty()){
        int parent = q.front();
        q.pop();
        for (auto child:graph[parent])
        {
             if (!visited[child])
             {
                 visited[child]=true;
                 q.push(child);

                 dist[child]=1+dist[parent];

             }
        }
	}
}

int main()
{

    return 0;
}
