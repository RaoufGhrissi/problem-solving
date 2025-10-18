#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

class Sieve {
    public:
        const static int N = 6*1e6 + 1;
        bool prime[N];
        vector<int> primes;
    
        Sieve() {
            memset(prime, 1, sizeof prime);
            prime[0] = 0;
            prime[1] = 0;
            for (int i=2 ; i<=sqrt(N) ; i++) {
                if (!prime[i]) continue;
                int x = 2*i;
                while(x<N) {
                    prime[x] = 0;
                    x += i;
                }
            }

            for (int i=1 ; i<N ; i++) {
                if (prime[i]) primes.push_back(i);
            }
        }
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    Sieve sieve = Sieve();
    
    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        sort(v.begin(), v.end());

        int ans = 0;
        ll coins = 0;
        int j = 0;
        for (int i=n-1 ; i>-1 ; i--) {
            if (v[i] >= sieve.primes[j]) {
                coins += v[i]-sieve.primes[j];
                j++;
            } else {
                ll diff = sieve.primes[j] - v[i];
                if (diff <= coins) {
                    coins -= diff;
                    j++;
                } else {
                    ans++;
                }
            }
        }

        cout<<ans<<'\n';
    }
}

int main() {
    solve();
    return 0;
}