#include <bits/stdc++.h>

using namespace std;

    class Solution {
    public:
        int minOrAfterOperations(vector<int>& v, int k) {
            vector<int> test;
            for (int i=30 ; i>-1 ; i--) {
                test.clear();
                int kk = k;
                bool ok = 1;
                int msk = (1<<i);

                int n = v.size();
                for (int i=0 ; i<n ; i++) {
                    if (msk&v[i]) {
                        int m = test.size();
                        if (test.empty())
                            test.push_back(v[i]);
                        else {
                            if (test[m-1]&msk) {
                                if (!kk) {
                                    ok = 0;
                                    break;
                                }

                                test[m-1] &= v[i];
                                kk--;
                            } else {
                                test.push_back(v[i]);
                            }    
                        }
                    } else {
                        int m = test.size();
                        if (!test.empty() && test[m-1]&msk) {
                            if (!kk) {
                                ok = 0;
                                break;
                            }

                            if (m>1) {
                                int x1 = test[m-1]&test[m-2];
                                int x2 = v[i]&test[m-1];
                                test.pop_back();

                                if (x1 < x2) {
                                    test.pop_back();
                                    test.push_back(x1);
                                    test.push_back(v[i]);
                                } else {
                                    test.push_back(x1);
                                }
                            } else {
                                test[m-1] &= v[i];
                            }
                            kk--;
                        }
                        else
                            test.push_back(v[i]);
                    }
                }

                if (ok) {
                    k = kk;
                    v = test;
                }
            }

            int ans = 0;
            for (auto &a:v)
                ans |= a;

            return ans;
        }
    };