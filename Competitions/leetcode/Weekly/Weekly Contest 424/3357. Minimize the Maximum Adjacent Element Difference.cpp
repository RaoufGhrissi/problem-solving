#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& t) {
        int s = 0;
        int e = 1e9;

        int n = t.size();

        vector<int> v;

        for (int i=0 ; i<n ; i++) { // observation 1: 4 -1 -1 -1 .. -1  5 => 4 -1 -1 5 
            if (t[i] == -1 && i && t[i-1] == -1 && ((i+1<n && t[i+1]==-1) || i==n-1)) {
                continue;
            }

            v.push_back(t[i]);
        }

        n = v.size();

        while(s<e) {
            int mid = (s+e)/2;

            int mxl = 0, mir = 1e9;

            bool ok = 1;
            for (int x=0 ; x<n ; x++) {
                if (v[x] > 0) continue;

                int l = -1, r = -1;
                if (x && v[x-1] > 0) {
                    l = max(1, v[x-1]-mid);
                    r = min((int)1e9, v[x-1]+mid);
                }

                if (x+1<n && v[x+1] > 0) {
                    int l1 = max(1, v[x+1]-mid);
                    int r1 = min((int)1e9, v[x+1]+mid);

                    if (l == -1) {
                        l = l1;
                        r = r1;
                    } else {
                        if (l1>r || r1<l) { // idha mayet9at3ouch, ne9ef => false famech solution
                            ok = 0;
                            break;
                        } else {
                            l = max(l1, l);
                            r = min(r1, r);
                        }
                    }
                }
                
                if (l == -1) continue;
                mxl = max(mxl, l);
                mir = min(mir, r);
            }

            if (!ok) {
                s = mid+1;
                continue;
            }

            int i = 0;
            int ans = 0;
            while(i<n) {
                if (v[i] == -1) {
                    if (i == n-1 || v[i+1]>0) { // one -1
                        int mi = 1e9;
                        for (const int &xx:{mxl, mir}) { // try mxl and mir
                            int x1 = 0;
                            if (i)
                                x1 = abs(xx-v[i-1]);

                            if (i<n-1)
                                x1 = max(x1, abs(xx-v[i+1]));

                            mi = min(mi, x1);
                        }
                        ans = max(ans, mi);
                        i+=2;
                    } else { // two -1
                        // try all combinations
                        vector<vector<int>> cc = {{mxl, mxl}, {mxl, mir}, {mir, mxl}, {mir, mir}};
                        int mi = 1e9;
                        for (auto &xx:cc) { // try mxl and mir
                            int x1 = abs(xx[1]-xx[0]);
                            if (i)
                                x1 = max(x1, abs(xx[0]-v[i-1]));

                            if (i<n-2)
                                x1 = max(x1, abs(xx[1]-v[i+2]));

                            mi = min(mi, x1);
                        }
                        ans = max(ans, mi);
                        i += 3;
                    }
                } else if (i) {
                    ans = max(ans, abs(v[i]-v[i-1]));
                    i++;
                } else {
                    i++;
                }
            }

            if (ans > mid) {
                s = mid+1;
            } else {
                e = mid;
            }
        }

        return s;
    }
};