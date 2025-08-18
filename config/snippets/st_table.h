#include<bits/stdc++.h>
using namespace std;


template<class T>
struct st_table {
    int n, K;
    vector<int> lg;
    vector<vector<T>> st;
    function<T(const T&, const T&)> merge;
    
    st_table(const vector<T>& a,
                 function<T(const T&, const T&)> merge_ = [](const T& x, const T& y){ return max(x,y); })
        : n((int)a.size()), merge(std::move(merge_)) {
        if (n == 0) return;
        lg.resize(n+1);
        lg[1] = 0;
        for (int i = 2; i <= n; ++i) lg[i] = lg[i>>1] + 1;
        K = lg[n] + 1;

        st.assign(K, vector<T>(n));
        st[0] = a;
        for (int k = 1; k < K; ++k) {
            int len = 1 << k;
            int half = len >> 1;
            for (int i = 0; i + len - 1 < n; ++i) {
                st[k][i] = merge(st[k-1][i], st[k-1][i + half]);
            }
        }
    }

    T query(int l, int r) const {
        int k = lg[r - l + 1];
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
