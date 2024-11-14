#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    const static int N = 1001;
    bool prime[N];
    int ge[N];

    void sieve() {
        memset(prime, 1, sizeof prime);
        memset(ge, -1, sizeof ge);

        prime[1] = 0;

        for (int i=2 ; i<N ; i++) {
            int x = i*i;
            while(x < N) {
                prime[x] = 0;
                x += i;
            }
        }

        queue<int> pp;
        for (int i=2 ; i<N ; i++) {
            if (prime[i])
                pp.push(i);
        }

        for (int i=1 ; i<N ; i++) {
            while(!pp.empty() && pp.front() < i)
                pp.pop();

            if (!pp.empty())
                ge[i] = pp.front();
        }
    }

    bool primeSubOperation(vector<int>& v) {
        sieve();

        int n = v.size();

        
        for (int i=n-2 ; i>-1 ; i--) {
            if (v[i] < v[i+1]) continue;

            int diff = v[i]-v[i+1]+1;

            if ((ge[diff] >= v[i]) || ge[diff] == -1) return 0;

            v[i] -= ge[diff];
        }


        return 1;
    }

};