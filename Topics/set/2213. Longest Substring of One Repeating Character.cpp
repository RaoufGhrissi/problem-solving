#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        set<pp> ranges;
        multiset<int> sz;
        
        int n = s.size();
        int q = queryCharacters.size();

        int start = 0;
        int end = 0;
        for (int i=1 ; i<n ; i++) {
            if (s[i] == s[i-1]) {
                end++;
            } else {
                ranges.insert({start, end});
                sz.insert(end-start+1);
                start = i;
                end = i;
            }
        }

        if (start < n) {
            ranges.insert({start, end});
            sz.insert(end-start+1);
        }

        vector<int> ans(q);

        for (int i=0 ; i<q ; i++) {
            // search the first range containing the index
            int id = queryIndices[i];
            char c = queryCharacters[i];

            if (s[id] == c) {
                ans[i] = *sz.rbegin();
                continue;
            }   

            s[id] = c;
            auto it = ranges.lower_bound({id, 0});

            if (it == ranges.end() || (*it).first > id)
                it--;

            pp range = *it;

            int start = range.first;
            int end = range.second;

            if (id < end && id > start) { // ---x--- => --- x ---- 
                ranges.erase(range);
                sz.erase(sz.lower_bound(end-start+1));

                ranges.insert({start, id-1});
                sz.insert(id-start);

                ranges.insert({id, id});
                sz.insert(1);

                ranges.insert({id+1, end});
                sz.insert(end-id);
            } else if (id < end) { // x---- => ---x --- if can be merged with previous or ---- x ---
                if (it != ranges.begin() && s[id-1] == s[id]) { // previous ranges
                    pp p = *prev(it);
                    int ps = p.first;
                    int pe = p.second;

                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.erase(p);
                    sz.erase(sz.lower_bound(pe-ps+1));

                    ranges.insert({p.first, id});
                    sz.insert(pe-ps+2);

                    ranges.insert({id+1, end});
                    sz.insert(end-id);

                } else { // no previous ranges
                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.insert({id, id});
                    sz.insert(1);

                    ranges.insert({id+1, end});
                    sz.insert(end-id);
                }
            } else if (id > start) { // ----x ---- => ---- x----- or ---- x ---- 
                if (it != ranges.end() && s[id+1] == s[id]) { // merge with next ranges
                    pp p = *next(it);
                    int ps = p.first;
                    int pe = p.second;

                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.erase(p);
                    sz.erase(sz.lower_bound(pe-ps+1));

                    ranges.insert({start, end-1});
                    sz.insert(end-start);

                    ranges.insert({id, pe});
                    sz.insert(pe-id+1);

                } else { // no next ranges to merge with => .... x ....
                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.insert({id, id});
                    sz.insert(1);

                    ranges.insert({start, id-1});
                    sz.insert(id-start);
                }
            } else { // x
                // merge with both left and right
                if (it != ranges.begin() && it != ranges.end() && s[id-1] == s[id] && s[id] == s[id+1]) {
                    pp p = *prev(it);
                    int ps = p.first;
                    int pe = p.second;

                    pp nxt = *next(it);
                    int ns = nxt.first;
                    int ne = nxt.second;

                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.erase(p);
                    sz.erase(sz.lower_bound(pe-ps+1));

                    ranges.erase(nxt);
                    sz.erase(sz.lower_bound(ne-ns+1));

                    ranges.insert({ps, ne});
                    sz.insert(ne-ps+1);
                } else if (it != ranges.end() && s[id] == s[id+1]) { // only next
                    pp nxt = *next(it);
                    int ns = nxt.first;
                    int ne = nxt.second;

                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.erase(nxt);
                    sz.erase(sz.lower_bound(ne-ns+1));

                    ranges.insert({id, ne});
                    sz.insert(ne-id+1);
                } else if (it != ranges.begin() && s[id] == s[id-1]) { // only previous
                    pp p = *prev(it);
                    int ps = p.first;
                    int pe = p.second;

                    ranges.erase(range);
                    sz.erase(sz.lower_bound(end-start+1));

                    ranges.erase(p);
                    sz.erase(sz.lower_bound(pe-ps+1));

                    ranges.insert({ps, id});
                    sz.insert(id-ps+1);
                }
            }

            ans[i] = *sz.rbegin();
        }

        return ans;
    }
};