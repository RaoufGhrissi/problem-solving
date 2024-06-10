#define pp pair<string, int>

#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        char val;
        vector<TrieNode*> next;
        bool last;
    
    TrieNode(char val = -1, bool last = 0)
    {
        val = val;
        last = last;
        next.resize(26, nullptr);
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

        while(!last && curr->next[s[i]-'a'])
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
            curr->next[s[i]-'a'] = new TrieNode(s[i], last);
            curr = curr->next[s[i]-'a'];
            i++;
        }
    }

    int get(string &s) {
        int res = -1;
        int i = 0;
        int n = s.size();
        TrieNode* curr = head;

        while(i<n && curr->next[s[i]-'a'])
        {
            curr = curr->next[s[i]-'a'];
            i++;
        } 

        return res;
    }
};