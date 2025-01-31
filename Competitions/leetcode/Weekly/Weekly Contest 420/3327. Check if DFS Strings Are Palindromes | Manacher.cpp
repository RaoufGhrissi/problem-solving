#include <bits/stdc++.h>
using namespace std;

class StringHashing {
    public:
        /*
            4 possible values => first 2 primes greater than 4 are 5 and 7 => a1=5 a2=7;
            h[0] = s[0]-'A'
            h[k] = (h[k-1]*a + s[k]-'A')%m

            p[0] = 1
            p[k] = (p[k-1]*a)%m

            substr(a, b) = (h[b] - h[a-1]*p[b-a+1])%m
        */

        int a1 = 5, a2 = 7, m1 = 1e9 + 7, m2 = 1e9 + 9;
        vector<int> k1;
        vector<int> k2;
        vector<int> p1;
        vector<int> p2;
        string s;
        int n;

        StringHashing(string str) {
            s = str;
            n = s.size();
            k1.resize(n);
            k2.resize(n);
            p1.resize(n);
            p2.resize(n);

            fill(k1.begin(), k1.end(), 0);
            fill(k2.begin(), k2.end(), 0);
            fill(p1.begin(), p1.end(), 0);
            fill(p2.begin(), p2.end(), 0);
        
            build();
        }

        void generate_hash_data(vector<int> &k, vector<int> &p, int a, int m)
        {
            k[0] = s[0]-'a'+1;
            p[0] = 1;
            int n = s.size();
            for (int i=1 ; i<n ; i++)
            {
                k[i] = (k[i-1]*1ll*a + s[i]-'a'+1)%m;
                p[i] = (p[i-1]*1ll*a)%m;
            }
        }

        void build() {
            int n = s.size();
            generate_hash_data(k1, p1, a1, m1);
            generate_hash_data(k2, p2, a2, m2);
        }

        int get(vector<int> &k, vector<int> &p, int &m, int a, int b) {
            int res = k[b];
            if (a)
                res = (res - k[a-1]*1ll*p[b-a+1])%m;

            if (res < 0)
                res += m;

            return res;
        }

        int get1(int a, int b) {
            return get(k1, p1, m1, a, b);
        }

        int get2(int a, int b) {
            return get(k2, p2, m2, a, b);
        }
};

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> sz;
    vector<bool> ans;

    int n;
    string str;

    int dfs(int root, string &s) {
        sz[root] = 0;
        for (auto &child:graph[root]) {
            sz[root] += dfs(child, s);
        }

        str += s[root];
        sz[root]++;

        return sz[root];
    }

    void dfsComp(int root, int s, int e, StringHashing &hash) {
        int l = e-s+1;
        int mid = l/2;

        if (l==1) ans[root] = 1;
        else {
            int s1 = n-1-e;
            int e1 = n-1-(l&1 ? s+mid+1 : s+mid);
            
            ans[root] = (hash.get1(s, s+mid-1) == hash.get1(n+s1, n+e1)) && (hash.get2(s, s+mid-1) == hash.get2(n+s1, n+e1));
        }

        for (auto &child:graph[root]) {
            l = sz[child];
            dfsComp(child, s, s+l-1, hash);
            s += l;
        }
    }

    vector<bool> findAnswer(vector<int>& p, string s) {
        n = p.size();

        graph.resize(n);
        sz.resize(n);

        for (int i=0 ; i<n ; i++) {
            if (p[i] != -1)
                graph[p[i]].push_back(i);
        }

        for (int i=0 ; i<n ; i++)
            sort(graph[i].begin(), graph[i].end());

        dfs(0, s);
        string cpy = str;
        reverse(cpy.begin(), cpy.end());

        StringHashing hash = StringHashing(str+cpy);

        ans.resize(n);
        dfsComp(0, 0, n-1, hash);
        
        return ans;
    }
};