#define ll long long
#define inf (ll)1e18

using namespace std;

class Floyd {
public:
    static const int n = 26;
    ll dist[n][n];

    Floyd() {
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = inf;
            }
        }
    }

    void build() {
        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                for (int k=0 ; k<n ; k++)
                {
                    if (dist[j][i] + dist[i][k] < dist[j][k])
                        dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
};

class Solution {
public:
    long long minimumCost(string src, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        Floyd floyd = Floyd();

        int n = o.size();

        for (int i=0 ; i<n ; i++) {
            if (cost[i] < floyd.dist[o[i]-'a'][c[i]-'a'])
                floyd.dist[o[i]-'a'][c[i]-'a'] = cost[i];
        }

        floyd.build();

        ll ans = 0;
        for (int i=0 ; i<src.size() ; i++) {
            ll d = floyd.dist[src[i]-'a'][t[i]-'a'];
            if (d == inf)
                return -1;

            ans += d;
        }

        return ans;
    }
};

