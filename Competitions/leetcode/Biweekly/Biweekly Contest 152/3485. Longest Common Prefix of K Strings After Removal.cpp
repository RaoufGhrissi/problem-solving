#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        vector<TrieNode*> next;
        int cnt;
        bool last;
    
    TrieNode(bool _last = 0, int _cnt = 0) {
        last = _last;
        cnt = _cnt;
        next.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* head;
    map<TrieNode*, int> dp;

    Trie() {
        head = new TrieNode();    
    }
    
    void add(string &s) {
        int i = 0;
        int n = s.size();
        bool last = 0;
        TrieNode* curr = head;

        while(!last && curr->next[s[i]-'a']) {
            last = i==n-1;
            curr = curr->next[s[i]-'a'];

            if (last) {
                curr->last = 1;
            }
            
            curr->cnt++;
            i++;
        }

        while(!last)
        {
            last = i==n-1;
            curr->next[s[i]-'a'] = new TrieNode(last, 1);
            curr = curr->next[s[i]-'a'];
            i++;
        }
    }

    int build(TrieNode* head, int & k) {
        dp[head] = 0;

        for (int j=0 ; j<26 ; j++) {
            if (!head->next[j])
                continue;

            if (head->next[j]->cnt >= k) {
                dp[head] = max(dp[head], 1 + build(head->next[j], k));
            }
        }

        return dp[head];
    }

    int get(TrieNode* head, string &s, int i, int & k) {
        int ans = 0;
        
        for (int j=0 ; j<26 ; j++) {
            if (!head->next[j])
                continue;

            if (head->next[j]->cnt >= k && (i >= s.size() || j != s[i]-'a'))
                ans = max(ans, 1 + dp[head->next[j]]);
            else {
                int cnt = head->next[j]->cnt - 1;
                
                if (cnt >= k) {
                    ans = max(ans, 1 + get(head->next[j], s, i+1, k));
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& v, int k) {
        Trie trie = Trie();
        
        int n = v.size();

        for (auto &c:v)
            trie.add(c);

        vector<int> ans(n, 0);

        trie.build(trie.head, k);

        for (int i=0 ; i<n ; i++) {
            ans[i] = trie.get(trie.head, v[i], 0, k);    
        }

        return ans;
    }
};