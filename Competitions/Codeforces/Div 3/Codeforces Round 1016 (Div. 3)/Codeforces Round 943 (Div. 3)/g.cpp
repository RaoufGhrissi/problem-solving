#include <bits/stdc++.h>

using namespace std;

#define pp pair<string, int>

using namespace std;

class TrieNode {
    public:
        vector<TrieNode*> next;
        int minId;
        bool last;
    
    TrieNode(bool _last = 0, int _minId = 1e9)
    {
        last = _last;
        minId = _minId;
        next.clear();

        for (int i=0 ; i<2 ; i++)
            next.push_back(nullptr);
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

        while(!last && curr->next[s[i]-'0'])
        {
            last = i==n-1;
            curr = curr->next[s[i]-'0'];
            curr->minId = min(curr->minId, id);

            if (last) {
                curr->last = 1;
            }

            i++;
        }

        while(!last)
        {
            last = i==n-1;
            curr->next[s[i]-'0'] = new TrieNode(last, id);
            curr = curr->next[s[i]-'0'];
            i++;
        }
    }

    int get(string &s, string &k) {
        int mi = 2*1e9;
        int i = 0;
        int n = s.size();
        bool greater = 0;
        TrieNode* curr = head;
        int needed;

        while(i<n) {
            if (k[i] == '1') { 
                needed = 1 - (s[i]-'0');
                if (!curr->next[needed]) {
                    break;
                } else {
                    curr = curr->next[needed];
                    i++;
                    if (curr->last) mi = min(mi, curr->minId);
                }
            } else {
                int toOne = 1 - (s[i]-'0');
                if (curr->next[toOne]) {
                    mi = min(mi, curr->next[toOne]->minId);
                }

                int toZero = s[i]-'0';
                if (curr->next[toZero]) {
                    curr = curr->next[toZero];
                    i++;
                    if (curr->last) mi = min(mi, curr->minId);
                } else {
                    break;
                }
            }
        } 

        return mi;
    }
};

string getrep(int k) {
    string s = "";

    for (int i=30 ; i>-1 ; i--) {
        int mask = 1<<i;
        if (mask&k) {
            s += '1';
        } else {
            s += '0';
        }
    }

    return s;
}

void solve() {
    freopen("a.txt", "r", stdin);   
    int t;
    cin>>t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<string> a(n);

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;

            a[i] = getrep(x);
        }

        if (k == 0) {
            cout<<1<<endl;
            continue;
        }

        string sk = getrep(k);

        Trie trie = Trie();
        
        int mi = 2*1e9;
        for (int i=n-1 ; i>-1 ; i--) {
            mi = min(mi, trie.get(a[i], sk)-i+1);

            // add in trie

            trie.add(a[i], i);
        }


        if (mi > n) {
            cout<<-1;
        } else {
            cout<<mi;
        }

        cout<<endl;
   }
}

int main() {
    solve();
    return 0;
}