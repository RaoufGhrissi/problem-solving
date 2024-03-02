#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

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

class TrieNode {
    public:
        char val;
        vector<TrieNode*> next;
        int cnt;
        bool last;
    
    TrieNode(char val = -1, bool last = 0)
    {
        val = val;
        last = last;
        next.resize(26, nullptr);
        cnt = 0;
    }
};

class Trie {
public:
    TrieNode* head;

    Trie() {
        this->head = new TrieNode();    
    }
    
    int insert(string &s, int &start, int &l, int &lastIndex, StringHashing &hasher) {
        int i = 0;
        int n = s.size();
        bool last = 0;
        int ans = 0;
        TrieNode* curr = this->head;

        while(!last && curr->next[s[i]-'a'])
        {
            last = i==n-1;
            curr = curr->next[s[i]-'a'];

            int res;
            if (last) {
                curr->last = 1;
                res = curr->cnt;
            }

            int prefix1 = hasher.get1(start, start+i);
            int prefix2 = hasher.get2(start, start+i);
            int suffix1 = hasher.get1(lastIndex-i, lastIndex);
            int suffix2 = hasher.get2(lastIndex-i, lastIndex);
            if (prefix1 == suffix1 && prefix2 == suffix2) {
                curr->cnt++;
            }

            if (last)
                return res;

            i++;
        }

        while(!last)
        {
            last = i==n-1;
            curr->next[s[i]-'a'] = new TrieNode(s[i], last);
            curr = curr->next[s[i]-'a'];

            int prefix1 = hasher.get1(start, start+i);
            int prefix2 = hasher.get2(start, start+i);
            int suffix1 = hasher.get1(lastIndex-i, lastIndex);
            int suffix2 = hasher.get2(lastIndex-i, lastIndex);
            if (prefix1 == suffix1 && prefix2 == suffix2) {
                curr->cnt++;
            }

            i++;
        }
    }
};

class Solution {
public:
    ll countPrefixSuffixPairs(vector<string>& v) {
        ll ans = 0;
        int n = v.size();
        string str = "";
        map<int, int> start;

        for (int i=0 ; i<n ; i++) {
            start[i] = str.size();
            str += v[i];
        }

        StringHashing hasher = StringHashing(str);
        Trie trie = Trie();

        for (int i=n-1 ; i>-1 ; i--) {
            int s = start[i];
            int l = v[i].size();
            int last = s+l-1;

            ans += trie.insert(v[i], s, l, last, hasher);
        }

        return ans;
    }
};

int main() {
    vector<string> v = {"a","aba","ababa","aa"};
    ll ans = Solution().countPrefixSuffixPairs(v);
    return 0;
}