#include <bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/longest-happy-prefix/description/
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
    int countSubstrings(string s) {

        StringHashing sHashing = StringHashing(s);
        string inv = s;
        reverse(inv.begin(), inv.end());
        StringHashing invHashing = StringHashing(inv);

        int ans = 0;
        int n = s.size();
        for (int start=0 ; start<n ; start++)
        {
            for (int end=start ; end<n ; end++) {
                int invStart = n-1-end;
                int invEnd = n-1-start;
                int hashS1 = sHashing.get(sHashing.k1, sHashing.p1, sHashing.m1, start, end);
                int hashS2 = sHashing.get(sHashing.k2, sHashing.p2, sHashing.m2, start, end);
                int hashInv1 = invHashing.get(invHashing.k1, invHashing.p1, invHashing.m1, invStart, invEnd);
                int hashInv2 = invHashing.get(invHashing.k2, invHashing.p2, invHashing.m2, invStart, invEnd);
                if (hashS1 == hashInv1 && hashS2 == hashInv2)
                    ans++;
            }
        }

        return ans;
    }
};

int main() {

    cout<<Solution().countSubstrings("abc");
    return 0;
}