#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (ll)1e15

class Floyd {
public:
    static const int N = 200;
    ll dist[N][N];
    int n;

    Floyd(int _n) {
        n = _n;
        init();
    }

    void init() {
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                dist[i][j] = (i==j) ? 0 : inf;
            }
        }
    }

    void add(int u, int v, ll c) {
        dist[u][v] = min(dist[u][v], c);
    }

    void build() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
};

class Solution {
public:
    ll dp[1000];
    map<string,int> stringId;
    ll rec(int i, int &n, string &source, string &target, Floyd &floyd) {
        if (i==n) return 0;
        ll &ans = dp[i];
        if (ans != -1)
            return ans;
            
        ans = inf;
        string s = "", t = ""; 
        for (int j=i ; j<n ; j++) {
            s += source[j];
            t += target[i]; 
            if (s == t) {
                ans = min(ans, rec(j+1, n, source, target, floyd)); 
            } else if (stringId.count(s) && stringId.count(t) && floyd.dist[stringId[s]][stringId[t]] < inf) { 
                ans = min(ans, floyd.dist[stringId[s]][stringId[t]] + rec(j+1, n, source, target, floyd)); 
            } 
        } 
        return ans; 
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();

        int id = 0;

        for (int i = 0; i < m; i++) {
            if (!stringId.count(original[i])) {
                stringId[original[i]] = id++;
            }
            
            if (!stringId.count(changed[i])) {
                stringId[changed[i]] = id++;
            }
        }

        Floyd floyd(id);
        for (int i = 0; i < m; i++) {
            int u = stringId[original[i]];
            int v = stringId[changed[i]];
            floyd.add(u, v, cost[i]);
        }
        floyd.build();

        memset(dp, -1, sizeof dp);

        ll ans = rec(0, n, source, target, floyd);

        return ans >= inf ? -1 : ans;
    }
};


int main() {
    string source = "abcd", target = "acbe";
    vector<string> original = {"a","b","c","c","e","d"}, changed = {"b","c","b","e","b","e"};
    vector<int> cost = {2,5,5,1,2,20};

    cout<<Solution().minimumCost(source, target, original, changed, cost);
}