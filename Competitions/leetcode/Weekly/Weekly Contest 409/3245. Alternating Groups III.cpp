#include <bits/stdc++.h>

using namespace std;
#define pp pair<int,int>

#define ll long long

class SegTree {
    public:
        vector<pp> v;
        vector<pp> tree;
        int n;

        SegTree(vector<pp> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        pp mergee(pp l, pp r) {
            return {l.first + r.first, l.second + r.second};
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = v[ie];
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        pp get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return {0, 0};

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	pp l = get(qs, qe, left, is, mid);
        	pp r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }

        void update(int index, pp val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
        		tree[i].first += val.first;
                tree[i].second += val.second;
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	update(index, val, left, is, mid);
        	update(index, val, right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }
};

class Solution {
public:
    void create(int id, set<pp> &st, SegTree &seg, int &m) {
        if (id && id<m-1) {
            st.insert({id-1, id+1});
            seg.update(3, {3, 1}, 0, 0, m-1);
        } else if (id) {
            st.insert({id-1, id});
            seg.update(2, {2, 1}, 0, 0, m-1);
        } else if (id<m-1) {
            st.insert({id, id+1});
            seg.update(2, {2, 1}, 0, 0, m-1);
        }
    }

    void update(int id, int val, set<pp> &st, vector<int> &v, SegTree &seg, int &m) {
        if (v[id] == val)
            return;

                v[id] = val;

                if (st.empty()) {
                    create(id, st, seg, m);
                    return;
                }

                auto it = st.lower_bound({id, 0});
                
                if (it != st.end()) {
                    // case 1 (x....) index in the start => reduce the size by removing x
                    if (id == it->first) {
                        // old range
                        int oldX = it->first;
                        int oldY = it->second;
                        int oldSize = oldY - oldX + 1;

                        if (it != st.begin()) {
                            auto prevIt = prev(it);

                            // x can be merged with prev interval
                            if (prevIt->second == id-1) {
                                int old = prevIt->second - prevIt->first + 1;
                                st.erase(prevIt);

                                seg.update(old, {-old, -1}, 0, 0, m-1);
                                st.insert({prevIt->first, prevIt->second+1});
                                seg.update(old+1, {old+1, 1}, 0, 0, m-1);
                            } else { // create new interval of size 2
                                st.insert({id-1, id});
                                seg.update(2, {2, 1}, 0, 0, m-1);
                            }
                        } else if (id) { // no prev, we create an interval of size 2
                            st.insert({id-1, id});
                            seg.update(2, {2, 1}, 0, 0, m-1);
                        }

                        st.erase(it);
                        seg.update(oldSize, {-oldSize, -1}, 0, 0, m-1);
                        
                        int newSize = oldSize - 1;
                        if (newSize >= 2) {
                            st.insert({oldX+1, oldY});
                            seg.update(newSize, {newSize, 1}, 0, 0, m-1);
                        }
                    } else if (id+1 == it->first) { // case 2: x(....)
                        int sz = it->second - it->first + 1;
                        if (it != st.begin()) {
                            auto prevIt = prev(it);
                            // (....x)(....) => (....)(x.....)
                            if (prevIt->second == id) {
                                seg.update(sz, {-sz, -1}, 0, 0, m-1);
                                seg.update(1+sz, {1+sz, 1}, 0, 0, m-1);
                                
                                int sz2 = prevIt->second - prevIt->first + 1;
                                seg.update(sz2, {-sz2, -1}, 0, 0, m-1);
                                
                                sz2--;
                                if (sz2 >= 2) {
                                    seg.update(sz2, {sz2, 1}, 0, 0, m-1);
                                    st.insert({prevIt->first, prevIt->second-1});
                                }

                                int b = it->second;
                                st.erase(it);
                                st.erase(prevIt);
                                st.insert({id, b});
                            } else if (prevIt->second == id-1) { // (...)x(....)
                                seg.update(sz, {-sz, -1}, 0, 0, m-1);
                                
                                int sz2 = prevIt->second - prevIt->first + 1;
                                seg.update(sz2, {-sz2, -1}, 0, 0, m-1);
                                seg.update(sz2+1+sz, {sz2+1+sz, 1}, 0, 0, m-1);                                
                                st.insert({prevIt->first, it->second});

                                st.erase(it);
                                st.erase(prevIt);
                            } else if (id) { // create new interval  (...).x(....)
                                seg.update(sz, {-sz, -1}, 0, 0, m-1);

                                seg.update(2+sz, {2+sz, 1}, 0, 0, m-1);                                
                                st.insert({id-1, it->second});

                                st.erase(it);
                            } else { // (x.....)
                                seg.update(sz, {-sz, -1}, 0, 0, m-1);

                                seg.update(1+sz, {1+sz, 1}, 0, 0, m-1);                                
                                st.insert({id, it->second});
                                st.erase(it);
                            }
                        } else { // no prev 
                            if (id) { // .x(...) => (.x...)
                                seg.update(sz, {-sz, -1}, 0, 0, m-1);

                                seg.update(2+sz, {2+sz, 1}, 0, 0, m-1);                                
                                st.insert({id-1, it->second});

                                st.erase(it);
                            } else { // x(....) => (x....)
                                seg.update(sz, {-sz, -1}, 0, 0, m-1);

                                seg.update(1+sz, {1+sz, 1}, 0, 0, m-1);                                
                                st.insert({id, it->second});
                                st.erase(it);
                            }
                        }
                    }
                } else { // no ranges after x 
                    // we're sure there is a prev as we return at the beginning if st empty
                    auto prevIt = prev(it);

                    int x = prevIt->first;
                    int y = prevIt->second;
                    int sz = y - x + 1;
                    if (y == id) { // (....x) => (....)(x.)
                        seg.update(sz, {-sz, -1}, 0, 0, m-1);
                        st.erase(prevIt);

                        int nn = id-1-x+1;
                        if (nn >= 2) {
                            st.insert({x, id-1});
                            seg.update(nn, {nn, 1}, 0, 0, m-1);
                        }

                        if (id<m-1) {                          
                            st.insert({id, id+1});
                            seg.update(2, {2, 1}, 0, 0, m-1);
                        }
                    } else if (id<y) { // (....x.)
                        seg.update(sz, {-sz, -1}, 0, 0, m-1);
                        st.erase(prevIt);
                        int l = id - 1 - x + 1;
                        int r = y - (id + 1) + 1;

                        if (l>=2) {
                            st.insert({x, id-1});
                            seg.update(l, {l, 1}, 0, 0, m-1);
                        }

                        if (r>=2) {
                            st.insert({id+1, y});
                            seg.update(r, {r, 1}, 0, 0, m-1);
                        }
                    } else if (y == id-1) { // (.....)x..
                        seg.update(sz, {-sz, -1}, 0, 0, m-1);
                        st.erase(prevIt);

                        if (id<m-1) {
                            st.insert({x, id+1});
                            seg.update(sz+2, {sz+2, 1}, 0, 0, m-1);
                        } else {
                            st.insert({x, id});
                            seg.update(sz+1, {sz+1, 1}, 0, 0, m-1);
                        }
                    } else { // (.....).x
                        if (id<m-1) {
                            st.insert({id-1, id+1});
                            seg.update(3, {3, 1}, 0, 0, m-1);
                        } else {
                            st.insert({id-1, id});
                            seg.update(2, {2, 1}, 0, 0, m-1);
                        }
                    }
                }
    }

    vector<int> numberOfAlternatingGroups(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();

        for (int i=0 ; i<n ; i++) {
            v.push_back(v[i]);
        }

        int m = 2*n+1;

        vector<pp> a(m, {0, 0});

        set<pair<int,int>> st;

        int i = 0;
        int j = 1;

        while(j<v.size()) {
            if (v[j] != v[j-1] && (j==v.size()-1 || v[j+1] != v[j])) {
                j++;
            } else {
                int d = j-i+1;
                if (d >= 3 || v[j] != v[j-1]) {
                    st.insert({i, j});
                    a[d].first += d;
                    a[d].second++;
                }
                i = j;
                j++;
            }
        }
        
        j--;
        int d = j-i+1;
        if (d >= 3 || v[j] != v[j-1]) {
            st.insert({i, j});
            a[d].first += d;
            a[d].second++;
        }

        SegTree seg = SegTree(a);

        vector<int> ans;
        for (auto &qq:q) {
            int t = qq[0];
            if (t == 1) {
                int sz = qq[1];
                pp x = seg.get(sz, m-1, 0, 0, m-1);

                int f = min(n, 2*n-sz+1);
                ans.push_back(x.first - x.second*sz + x.second);
            } else {
                int id = qq[1];
                int val = qq[2];

                update(id, val, st, v, seg, m);

                if (id < n-1) {
                    int id1 = id+n; 
                    update(id1, val, st, v, seg, m);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v = {0,0,0,1};
    vector<vector<int>> q = {{2,1,1},{1,3}};
    auto a = Solution().numberOfAlternatingGroups(v, q);
}
