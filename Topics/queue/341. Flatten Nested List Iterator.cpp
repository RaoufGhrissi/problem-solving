#include <bits/stdc++.h>

using namespace std;


class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    queue<int> ans;
    void get(vector<NestedInteger> &v) { // tfakeke f lista
        for (int i=0 ; i<v.size() ; i++) { // bech tparcouri lista
            if (v[i].isInteger()) { // idha elemnt entier, maach 3andi manfakeke => khlat l ekher level
                ans.push(v[i].getInteger()); // bech tpushih
            } else { // lezem nzid nahbet nfakek
                get(v[i].getList());  // b recursion n3ayet ll get eli objectif mte3ha tfakeke f lista bech tfakek lista hedhi
            }
        }        
    }

    NestedIterator(vector<NestedInteger> &v) {
        get(v);
    }
    
    int next() {
        int x = ans.front();
        ans.pop();
        return x;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */