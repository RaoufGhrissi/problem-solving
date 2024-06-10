#include <bits/stdc++.h>

using namespace std;

#define pp pair<string, int>

using namespace std;

class TrieNode {
    public:
        char val;
        map<int, TrieNode*> next;
        int index;
        bool last;
    
    TrieNode(char val = -1, bool last = 0, int id = -1)
    {
        val = val;
        last = last;
        index = id;
    }
};

class Trie {
public:
    TrieNode* head;

    Trie() {
        head = new TrieNode();    
    }
    
    void add(string &s, int &id) {
        int i = 0;
        int n = s.size();
        bool last = 0;
        TrieNode* curr = head;

        while(!last && curr->next.count(s[i]-'a'))
        {
            last = i==n-1;
            curr = curr->next[s[i]-'a'];

            if (last) {
                curr->last = 1;
            }

            i++;
        }

        while(!last)
        {
            last = i==n-1;
            curr->next[s[i]-'a'] = new TrieNode(s[i], last, id);
            curr = curr->next[s[i]-'a'];
            i++;
        }
    }

    int get(string &s) {
        int res = -1;
        int i = 0;
        int n = s.size();
        TrieNode* curr = head;

        while(i<n && curr->next.count(s[i]-'a'))
        {
            curr = curr->next[s[i]-'a'];
            res = curr->index;
            i++;
        } 

        return res;
    }
};

class Solution {
public:
    bool static compare(pp &p1, pp &p2) {
        if (p1.first.size() == p2.first.size())
            return p1.second < p2.second;

        return p1.first.size() < p2.first.size();
    }

    vector<int> stringIndices(vector<string>& c, vector<string>& q) {
        int n = c.size();
        vector<pp> v;
        for (int i=0 ; i<n ; i++)
            v.push_back({c[i], i});

        sort(v.begin(), v.end(), compare);

        Trie trie = Trie();
        for (auto &s:v) {
            reverse(s.first.begin(), s.first.end());
            trie.add(s.first, s.second);
        }
        
        vector<int> ans;
        for (auto &a:q) {
            reverse(a.begin(), a.end());
            int res = trie.get(a);
            if (res == -1)
                res = v[0].second;

            ans.push_back(res);
        }

        return ans;
    }
};