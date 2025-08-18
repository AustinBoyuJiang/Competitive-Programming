#include<bits/stdc++.h>
using namespace std;


inline int mex(vector<int> &v) {
    vector<int> vis(v.size(), 0);
    for (int x : v) {
        if (x < (int)v.size()) vis[x] = 1;
    }
    int pos = 0;
    while (pos < (int)v.size() && vis[pos]) pos++;
    return pos;
}


template<class T>
inline void discrete(T *st, T *ed, T offset = 0) {
    set<T> num(st, ed);
    vector<T> pos(num.begin(), num.end());
    for (T *itr = st; itr != ed; ++itr) {
        *itr = (T)(lower_bound(pos.begin(), pos.end(), *itr) - pos.begin()) + offset;
    }
}