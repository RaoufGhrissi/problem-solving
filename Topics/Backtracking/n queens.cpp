//https://leetcode.com/problems/n-queens/description/

#define pb push_back
class Solution {
public:
    /*
    observation: as we can't have 2 queens on the same line
    no need to store the result as ....Q....
    we just store the Q position as its unique
    [[".Q..","...Q","Q...","..Q."] = [1, 3, 0, 2]
    */
    int dx[4] = {-1, 1, -1, 1};
    int dy[4] = {-1, 1, 1, -1};

    bool safe(int i, int j, int n) {
        return i>-1 && j>-1 && i<n && j<n;
    }

    void backtrack(int line, int &n, vector<int> &mp, vector<vector<int>> &ans) {
        if (line == n)
        {
            ans.pb(mp);
            return;
        }
        
        for (int i=0 ; i<n ; i++)
        {
            // queen on the same column
            if (mp[i] != -1)
                continue; // i can't put a queen on the cell

            // queen on left top diagonal
            bool ok = 1;

            for (int d=0 ; d<4 ; d++) {
                int x = line;
                int y = i;
                while(safe(x, y, n)) {
                    ok &= !(mp[y] == x);
                    x += dx[d];
                    y += dy[d];
                }

                if (!ok) // queen on diagonal
                    break;
            }
        
            if (!ok) // queen on diagonal
                continue;

            mp[i] = line;
            backtrack(line+1, n, mp, ans);
            mp[i] = -1;
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<int>> v;
        vector<int> t(n, -1);
        backtrack(0, n, t, v);

        vector<vector<string>> ans;
        vector<string> res(n);

        for (auto a:v) {
            res.clear();
            res.resize(n);
            for (int i=0 ; i<n ; i++)
            {
                res[i] = "";
                for (int j=0 ; j<n ; j++)
                    res[i] += a[j] == i ? 'Q' : '.';
            }

            ans.pb(res);
        }

        return ans;
    }
};