#include<bits/stdc++.h>
using namespace std;


template<class T>
struct fenwick {
    int n;
    vector<T> bit;
    T identity;

	// [0, n)
    fenwick(int n, T identity = T{}) : n(n), identity(identity), bit(n + 1, identity) {}

	fenwick(const vector<T>& a, T identity=T{}) : fenwick((int)a.size(), identity) {
	    for (int i = 1; i <= n; ++i) bit[i] += a[i-1];
	    for (int i = 1; i <= n; ++i) {
	        int j = i + (i & -i);
	        if (j <= n) bit[j] += bit[i];
	    }
	}

    void add(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    T sum(int idx) const {
        T res = identity;
        for (++idx; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    T sum(int l, int r) const {
        return sum(r) - sum(l - 1);
    }

    T at(int idx) const {
        return sum(idx, idx);
    }

    void assign(int idx, T val) {
        T cur = sum(idx, idx);
        add(idx, val - cur);
    }

    void reset() {
        fill(bit.begin(), bit.end(), identity);
    }
};


template<class T>
struct range_fenwick {
    int n;
    vector<T> b1, b2;
    T identity;

    // [0, n)
    range_fenwick(int n, T identity = T{})
        : n(n), b1(n+1, identity), b2(n+1, identity), identity(identity) {}
        
	range_fenwick(const vector<T>& a, T identity=T{})
	    : range_fenwick((int)a.size(), identity) {
	    vector<T> diff(n+1, identity);
	    for (int i = 1; i <= n; ++i) {
	        T cur = a[i-1];
	        T prev = (i == 1 ? identity : a[i-2]);
	        diff[i] = cur - prev;
	    }
	    vector<T> b1_raw(n+1, identity), b2_raw(n+1, identity);
	    for (int i = 1; i <= n; ++i) {
	        b1_raw[i] = diff[i];
	        b2_raw[i] = diff[i] * (T)(i-1);
	    }
	    for (int i = 1; i <= n; ++i) { b1[i] += b1_raw[i]; int j=i+(i&-i); if (j<=n) b1[j]+=b1[i]; }
	    for (int i = 1; i <= n; ++i) { b2[i] += b2_raw[i]; int j=i+(i&-i); if (j<=n) b2[j]+=b2[i]; }
	}

    static inline int lowbit(int x){ return x & -x; }

    void _add(vector<T>& bit, int idx1, T val){
        for (; idx1 <= n; idx1 += lowbit(idx1)) bit[idx1] += val;
    }
    
    T _sum(const vector<T>& bit, int idx1) const {
        T res = identity;
        for (; idx1 > 0; idx1 -= lowbit(idx1)) res += bit[idx1];
        return res;
    }

	void add(int l, int r, T val){
	    int L = l + 1, R = r + 1;
	    _add(b1, L,   val);
	    _add(b1, R+1, -val);
	    _add(b2, L,   val * (T)(L - 1));
	    _add(b2, R+1, -val * (T)R);
	}

    T prefix_sum(int idx) const {
        int X = idx + 1;
        T s1 = _sum(b1, X);
        T s2 = _sum(b2, X);
        return (T)X * s1 - s2;
    }

    T sum(int l, int r) const {
        if (l > r) return identity;
        return prefix_sum(r) - (l ? prefix_sum(l-1) : identity);
    }

    void add(int idx, T val){ add(idx, idx, val); }

    T at(int idx) const {
        return sum(idx, idx);
    }

    void assign(int idx, T val){
        T cur = at(idx);
        add(idx, val - cur);
    }

    void reset(){
        fill(b1.begin(), b1.end(), identity);
        fill(b2.begin(), b2.end(), identity);
    }
};
