#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        vector<TrieNode*> next;
        int cost;
        bool last;

    TrieNode(bool _last = 0, int _cost = -1) {
        last = _last;
        cost = _cost;
        next.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* head;

    Trie() {
        head = new TrieNode();    
    }
    
    void add(string &s, int &cost) {
        int i = 0;
        int n = s.size();
        bool last = 0;
        TrieNode* curr = head;

        while(!last && curr->next[s[i]-'a'])
        {
            last = i==n-1;
            curr = curr->next[s[i]-'a'];

            if (last) {
                curr->last = 1;
                if (curr->cost == -1)
                    curr->cost = cost;
                else // strings are not unique
                    curr->cost = min(curr->cost, cost);
            }

            i++;
        }

        while(!last) {
            last = i==n-1;
            curr->next[s[i]-'a'] = new TrieNode(last, last ? cost : -1);
            curr = curr->next[s[i]-'a'];
            i++;
        }
    }
};

class Solution {
public:  
    int dp[50000];

    int rec(int i, Trie &trie, int &n, string &s) {
        if (i==n)
            return 0;

        int &ans = dp[i];
        if (dp[i] != -1)
            return dp[i];
        ans = 1e9;
        TrieNode* curr = trie.head;
        int j = i;
        while(j<n && curr->next[s[j]-'a']) {
            curr = curr->next[s[j++]-'a'];
            if (curr->last) {
                ans = min(ans, curr->cost + rec(j, trie, n, s));
            }
        } 
        return ans;
    }
    int minimumCost(string s, vector<string>& v, vector<int>& costs) {
        memset(dp, -1, sizeof dp);
        Trie trie;
        int n = v.size();
        for (int i=0 ; i<n ; i++)
            trie.add(v[i], costs[i]);

        n = s.size();
        int ans = rec(0, trie, n, s);
        return ans == 1e9 ? -1 : ans;
    }
};