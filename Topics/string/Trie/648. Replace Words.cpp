#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        vector<TrieNode*> next;
        bool last;
    
    TrieNode(bool l = 0) {
        last = l;
        next.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* head;

    Trie() {
        head = new TrieNode();    
    }
    
    void add(string &s) {
        int i = 0;
        int n = s.size();
        bool last = 0;
        TrieNode* curr = head;

        while(!last && curr->next[s[i]-'a']) {
            last = i == n-1;
            curr = curr->next[s[i]-'a'];

            if (last) {
                curr->last = 1;
                break;
            }

            i++;
        }

        while(i<n) {
            last = i==n-1;
            curr->next[s[i]-'a'] = new TrieNode(last);
            curr = curr->next[s[i]-'a'];
            i++;
        }
    }

    string get(string &s) {
        string res = "";
        int i = 0;
        int n = s.size();
        TrieNode* curr = head;

        while(i<n && curr->next[s[i]-'a']) {
            res += s[i];
            curr = curr->next[s[i]-'a'];
            if (curr->last)
                break;
            i++;
        }

        return curr->last ? res : "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& keys, string s) {
        Trie* trie = new Trie();
        int n = s.size();
        string ch = "";
        string ans = "";
        for (auto a:keys)
            trie->add(a);

        for (int i=0 ; i<n ; i++) {
            if (s[i] == ' ') {
                string t = trie->get(ch);
                ans += !t.empty() ? t : ch;
                ans += ' ';
                ch = "";
            } else {
                ch += s[i];
            }
        }

        string t = trie->get(ch); 
        ans += !t.empty() ? t : ch;

        return ans;
    }
};