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
    for (string s; getline(file, s);) {
        vector<string> game = split(s, ": ");
        game = split(game[1], " | ");
        set<int> st;
        for (auto &part:split(game[0], " ")) {
            if (part == "" || part == " ") continue;
            st.insert(stoi(part));
        }
        int res = 0;
        for (auto &part:split(game[1], " ")) {
            if (part == "" || part == " ") continue;
            if (st.count(stoi(part))) {
                res = !res ? 1 : res*2;
            }
        }

        ans += res;
    }

    return ans;
    
}

int main() {
    cout<<solve();
    return 0;
}