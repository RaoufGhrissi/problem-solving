#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Compressor {
    public:
        set<int> v;
        map<int, int> match;
        map<int, int> inversedMatch;
        int last;

    Compressor(vector<int> a) {
        for (auto &e:a)
            v.insert(e);
        
        build();
    }

    void build() {
        last = 1;
        for (auto &a: v) {
            match[a] = last;
            inversedMatch[last] = a;
            last++;
        }
    }
};

class BIT {
    public:
        vector<int> tree;
        int n;

        BIT(int k) {
            n = k;
            tree.resize(n);
        }   
        
        void update(int x, int val)
        {
            while(x<n)
            {
                tree[x] += val;
                x+=(x)&(-x);
            }
        }

        int get(int x)
        {
            int res=0;
            while(x>0)
            {
                res += tree[x];
                x-=(x)&(-x);
            }

            return res;
        }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& v) {
        vector<int> arr1 = {v[0]};
        vector<int> arr2 = {v[1]};
        int n = v.size();
        
        Compressor comp = Compressor(v);
        
        int m = comp.last;
                
        BIT sorted1 = BIT(m);
        BIT sorted2 = BIT(m);
       
        sorted1.update(comp.match[v[0]], 1);
        sorted2.update(comp.match[v[1]], 1);
        
        for (int i=2 ; i<n ; i++) {
            int x = comp.match[v[i]];
            int cnt1 = sorted1.get(m-1) - sorted1.get(x);
            int cnt2 = sorted2.get(m-1) - sorted2.get(x);
            
            if (cnt1 > cnt2) {
                arr1.push_back(v[i]);
                sorted1.update(x, 1); 
            } else if (cnt1 < cnt2) {
                arr2.push_back(v[i]);
                sorted2.update(x, 1);
            } else {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(v[i]);
                    sorted1.update(x, 1);
                } else {
                    arr2.push_back(v[i]);
                    sorted2.update(x, 1);
                }
            }
        }
        
        for (auto &a:arr2)
            arr1.push_back(a);
        
        return arr1;
    }
};