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

unordered_map<string, int> mx = {
    {"red", 12},
    {"green", 13},
    {"blue", 14},
};

int solve() {
    ifstream file("a.txt");
    int ans = 0;
    for (string s; getline(file, s);) {
        vector<string> game = split(s, ": ");
        int id = stoi(split(game[0], " ")[1]);
        bool ok = 1;

        game = split(game[1], "; ");
        int n = game.size();
        for (int i=0 ; i<n ; i++) {
            vector<string> parts = split(game[i], ", ");
            for (auto &part:parts) {
                vector<string> x = split(part, " ");
                int cnt = stoi(x[0]);
                string color = x[1];

                if (mx[color] < cnt) {
                    ok = 0;
                    break;
                }
            }

            if (!ok)
                break;
        }

        if (ok) 
            ans += id;
    }

    return ans;
    
}

int main() {
    cout<<solve();
    return 0;
}