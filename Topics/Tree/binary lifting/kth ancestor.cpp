// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/submissions/
class TreeAncestor {
    vector<vector<int>> up;
    vector<int> depth;
    vector<vector<int>> graph;
    int log;
public:
    void dfs(int p, vector<int>& parent)
    {       
        for (int j=1 ; j<log ; j++)
        {
            up[p][0]=parent[p];
            if (p>0)
                depth[p]=depth[parent[p]]+1;
            up[p][j] = up[up[p][j-1]][j-1];            
        }
        for (auto c:graph[p])
        {
            if (parent[p]==c)
                continue;
            dfs(c, parent);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        graph.clear();
        graph.resize(n);
        for (int i=0 ; i<n ; i++)
        {
            if (parent[i]!=-1)
            {
                graph[i].push_back(parent[i]);
                graph[parent[i]].push_back(i);
            }
        }
        
        log = log2(n);
        log++;
        
        up.clear();
        up.resize(n, vector<int>(log));
        
        depth.clear();
        depth.resize(n);
        
        parent[0]=0;
        depth[0]=0;
        
        dfs(0, parent);        
    }
    
    int getKthAncestor(int node, int k) {
        int l = log2(k);

        if (depth[node]<k)
            return -1;        
        
    
        for (int i=l ; i>-1 ; i--)
        {            
            if (k & (1<<i))
            {
                node=up[node][i];
            }
            
        }        
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */