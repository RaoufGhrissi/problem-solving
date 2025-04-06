#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

class Sieve {
    public:
        const static int N = 1e7 + 1;
        bool prime[N];
    
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
        }
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    Sieve sieve = Sieve();
    vector<int> primes;

    for (int i=2 ; i<sieve.N ; i++) {
        if (sieve.prime[i]) {
            primes.push_back(i);
        }
    }

    while(t--) {
        int n;
        cin>>n;

        int j = primes.size()-1;
        ll ans = 0;
        for (int i=1 ; i<n ; i++) {
            while(j>-1 && primes[j]*i > n) {
                j--;
            }

            ans += j+1;
        }

        cout<<ans<<endl; 
    }
}

int main() {
    solve();
    return 0;
}