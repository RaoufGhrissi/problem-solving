#include <bits/stdc++.h>

#define pp pair<int,string>

using namespace std;


#define pp pair<int,string>

class CompareMax {
    public:
        bool operator()(pp a, pp b) {
            if (a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
};

class CompareMin {
    public:
        bool operator()(pp a, pp b) {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        }
};

class SORTracker {
public:
    priority_queue<pp, vector<pp>, CompareMax> mx;
    priority_queue<pp, vector<pp>, CompareMin> mi;
    int size;

    SORTracker() {
        size = 1;
    }
    
    void add(string name, int score) {
        if (mi.size() < size)
            mi.push({score, name});
        else {
            pp top = mi.top();
            if (top.first < score || (top.first == score && top.second > name))  {
                mi.pop();
                mx.push(top);
                mi.push({score, name});
            } else {
                mx.push({score, name});
            }
        }
    }
    
    string get() {
        while (mi.size() < size) {
            mi.push(mx.top());
            mx.pop();
        }

        string res = mi.top().second;

        size++;
        if (!mx.empty()) {
            mi.push(mx.top());
            mx.pop();
        }
        return res;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

// mi = "branford",3
// mx = "bradford", 2


int main() {
    SORTracker* obj = new SORTracker();
    obj->add("bradford", 2);
    obj->add("branford", 3);
    obj->get();
    string param_2 = obj->get();
    return 0;
}