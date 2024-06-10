#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delimiter){
    vector<string> list;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

int solve() {
    ifstream file("a.txt");
    int ans = 0;
    int card;
    unordered_map<int,int> occ; 
    for (string s; getline(file, s);) {
        vector<string> game = split(s, ": ");
        card = stoi(split(game[0], " ")[1]);
        occ[card]++;
        game = split(game[1], " | ");
        set<int> st;
        for (auto &part:split(game[0], " ")) {
            if (part == "" || part == " ") continue;
            st.insert(stoi(part));
        }

        int cnt = 0;
        for (auto &part:split(game[1], " ")) {
            if (part == "" || part == " ") continue;
            if (st.count(stoi(part))) {
                cnt++;
            }
        }

        for (int i=1 ; i<=cnt ; i++) {
            occ[card+i] += occ[card];
        }
    }

    for (auto &a:occ)
        if (a.first <= card)
            ans += a.second;
    
    return ans;
}

int main() {
    cout<<solve();
    return 0;
}