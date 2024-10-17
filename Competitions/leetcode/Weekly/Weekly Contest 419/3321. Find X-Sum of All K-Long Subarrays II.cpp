#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<ll,ll>

class Solution {
public:
    vector<long long> findXSum(vector<int>& v, int k, int x) {
        map<ll, ll> occ;
        set<pp> mx, mi;

        int n = v.size();
        vector<ll> ans;

        for (int i=0 ; i<k ; i++) {
            occ[v[i]]++;
        }

        ll sm = 0;
        for (auto &a:occ) {
            if (mx.size() < x) {
                mx.insert({a.second, a.first});
                sm += a.second*a.first;
            } else {
                if (a.second < (*mx.begin()).first) {
                    mi.insert({a.second, a.first});
                } else if (a.second == (*mx.begin()).first) {
                    if (a.first > (*mx.begin()).second) {
                        mi.insert(*mx.begin());
                        sm -= (*mx.begin()).first*(*mx.begin()).second;
                        mx.erase(*mx.begin());
                        mx.insert({a.second, a.first});
                        sm += a.second*a.first;
                    } else {
                        mi.insert({a.second, a.first});
                    }
                } else {
                    mi.insert(*mx.begin());
                    sm -= (*mx.begin()).first*(*mx.begin()).second;
                    mx.erase(*mx.begin());
                    mx.insert({a.second, a.first});
                    sm += a.second*a.first;
                }
            }
        }

        ans.push_back(sm);

        int i = 1;
        int j = k;

        while(j<n) {
            // remove v[i-1]
            ll oldOcc = occ[v[i-1]];
            
            occ[v[i-1]]--;
            if (!occ[v[i-1]])
                occ.erase(v[i-1]);

            
            pp p = {oldOcc, v[i-1]};
            auto it = mx.find(p);
            if (it != mx.end()) {
                mx.erase(it);
                sm -= oldOcc*v[i-1];
                if (oldOcc > 1) {
                    mx.insert({oldOcc-1, v[i-1]});
                    sm += (oldOcc-1)*v[i-1];
                }
            } else {
                auto it = mi.find(p);
                if (it != mi.end())
                    mi.erase(it);
            }

            if (!mi.empty() && (
                    (mx.size() < x) ||
                    ((*mi.rbegin()).first > (*mx.begin()).first) || 
                    ((*mi.rbegin()).first == (*mx.begin()).first && (*mi.rbegin()).second > (*mx.begin()).second)
                )
            ) {
                if (mx.size() < x) {
                    mx.insert(*mi.rbegin());
                    sm += (*mi.rbegin()).first*(*mi.rbegin()).second;
                    mi.erase(*mi.rbegin());
                } else {
                    mx.insert(*mi.rbegin());
                    sm += (*mi.rbegin()).first*(*mi.rbegin()).second;
                    mi.erase(*mi.rbegin());
                    mi.insert(*mx.begin());
                    sm -= (*mx.begin()).first*(*mx.begin()).second;
                    mx.erase(*mx.begin());
                }
            }
            
            // add v[j]
            oldOcc = occ.count(v[j]) ? occ[v[j]] : 0;
            occ[v[j]] = oldOcc + 1;
            p = {oldOcc, v[j]};
            it = mx.find(p);
            if (it != mx.end()) {
                mx.erase(it);
                sm -= oldOcc * v[j];
                mx.insert({oldOcc+1, v[j]});
                sm += (oldOcc+1ll)*v[j];
            } else if (mi.find(p) != mi.end()) {
                mi.erase(mi.find(p));
                mi.insert({oldOcc+1, v[j]}); // momken banak hedha wala bel occ jdida ahsen men akhyeb wehed ykawrou
            } else {
                mi.insert({oldOcc+1, v[j]});
            }

            if (!mi.empty() && (
                    (mx.size() < x) ||
                    ((*mi.rbegin()).first > (*mx.begin()).first) || 
                    ((*mi.rbegin()).first == (*mx.begin()).first && (*mi.rbegin()).second > (*mx.begin()).second)
                )
            ) {
                if (mx.size() < x) {
                    mx.insert(*mi.rbegin());
                    sm += (*mi.rbegin()).first*(*mi.rbegin()).second;
                    mi.erase(*mi.rbegin());
                } else {
                    mx.insert(*mi.rbegin());
                    sm += (*mi.rbegin()).first*(*mi.rbegin()).second;
                    mi.erase(*mi.rbegin());
                    mi.insert(*mx.begin());
                    sm -= (*mx.begin()).first*(*mx.begin()).second;
                    mx.erase(*mx.begin());
                }
            }

            i++;
            j++;

            ans.push_back(sm);
        }

        return ans;
    }
};

