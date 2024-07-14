#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(string node, string parent, map<string, vector<string>> &tree) {
        int ans = 0;
        bool leaf = 1;
        for (string &child:tree[node]) {
            if (node != parent) {
                leaf = 0;
                ans = max(ans, dfs(child, node, tree));
            }
        }

        if (leaf) {
            if (!count(node.begin(), node.end(), '.')) return 0;
            return node.size() - 1;
        }

        return ans;
    }

    int lengthLongestPath(string s) {
        stack<pair<string, int>> st;
        map<string, vector<string>> tree;
        st.push({"", 0});

        int n = s.size();
        string actual = "";
        int level = 1;
        int i = 0;

        while(i<=n) {
            if (s[i] == '\n' || i == n) {
                while (!st.empty() && st.top().second >= level)
                    st.pop();
                
                if (!st.empty())
                    tree[st.top().first].push_back(st.top().first + "/" + actual);

                st.push({st.empty() ? actual : st.top().first + "/" + actual, level});
                actual = "";
                level = 1;
            } else if (s[i] == '\t') {
                level++;
            } else {
                actual += s[i];
            }
            i++;
        }
        
        int ans = dfs("", "-1", tree);
        return ans > 0 ? ans-1 : 0;
    }
};


int main() {
    cout<<Solution().lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
}