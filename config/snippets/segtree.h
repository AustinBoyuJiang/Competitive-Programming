#include <bits/stdc++.h>
using namespace std;


template<class T>
struct segtree {
    int n;
    vector<T> st;
    function<T(const T&, const T&)> merge;
    T identity;

    segtree(int n,
            function<T(const T&, const T&)> merge = [](const T& a, const T& b){ return a + b; },
            T identity = T{})
        : n(n), st(4*n, identity), merge(std::move(merge)), identity(identity) {}

    segtree(const vector<T>& a,
            function<T(const T&, const T&)> merge = [](const T& a, const T& b){ return a + b; },
            T identity = T{})
        : segtree((int)a.size(), merge, identity) { build(a); }

    void build(int rt, int l, int r, const vector<T>& a) {
        if (l == r) { st[rt] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(rt<<1, l, mid, a);
        build(rt<<1|1, mid+1, r, a);
        st[rt] = merge(st[rt<<1], st[rt<<1|1]);
    }
    void build(const vector<T>& a) { build(1,0,n-1,a); }

    void update(int rt, int l, int r, int x, T v, bool acc) {
        if (l == r) {
        	if(acc) st[rt] = merge(st[rt], v);
        	else st[rt] = v;
        	return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) update(rt<<1, l, mid, x, v, acc);
        else update(rt<<1|1, mid+1, r, x, v, acc);
        st[rt] = merge(st[rt<<1], st[rt<<1|1]);
    }
    void update(int x, T v, bool acc = false) { update(1,0,n-1,x,v,acc); }

    T query(int rt, int l, int r, int x, int y) const {
        if (y < l || x > r) return identity;
        if (l == x && r == y) return st[rt];
        int mid = (l + r) >> 1;
        if(y <= mid) return query(rt<<1, l, mid, x, y);
        else if(x > mid) return query(rt<<1|1, mid+1, r, x, y);
        return merge(query(rt<<1, l, mid, x, mid), query(rt<<1|1, mid+1, r, mid+1, y));
    }
    T query(int l, int r) const { return query(1,0,n-1,l,r); }
    T query(int x) const { return query(x,x); }
};


template<class T>
struct dynamic_segtree {
    struct node {
        int lc, rc;
        T val;
        node(int lc=0, int rc=0, const T& val=T{}) : lc(lc), rc(rc), val(val) {}
    };

    int n, root;
    vector<node> st;
    function<T(const T&, const T&)> merge;
    T identity;

    dynamic_segtree(int n,
            function<T(const T&, const T&)> merge = [](const T& a, const T& b){ return a + b; },
            T identity = T{})
        : n(n), root(0), merge(std::move(merge)), identity(identity) {
        // st.reserve(1<<20);
        st.push_back(node());
    }

    int new_node() {
        st.push_back(node(0, 0, identity));
        return (int)st.size()-1;
    }

    void push_up(int rt) {
        const T& L = st[rt].lc ? st[ st[rt].lc ].val : identity;
        const T& R = st[rt].rc ? st[ st[rt].rc ].val : identity;
        st[rt].val = merge(L, R);
    }

    int update(int rt, int l, int r, int x, const T& v, bool acc) {
        if (!rt) rt = new_node();
        if (l == r) {
        	if(acc) st[rt].val = merge(st[rt].val, v);
        	else st[rt].val = v;
        	return rt;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) st[rt].lc = update(st[rt].lc, l, mid, x, v, acc);
        else st[rt].rc = update(st[rt].rc, mid+1, r, x, v, acc);
        push_up(rt);
        return rt;
    }
    void update(int x, const T& v, bool acc = false) { root = update(root, 0, n-1, x, v, acc); }
    
	T query(int rt, int l, int r, int x, int y) const {
        if (!rt || y < l || x > r) return identity;
        if (l == x && r == y) return st[rt].val;
        int mid = (l + r) >> 1;
        if(y <= mid) return query(st[rt].lc, l, mid, x, y);
        if(x > mid) return query(st[rt].rc, mid+1, r, x, y);
        return merge(query(st[rt].lc, l, mid, x, mid),query(st[rt].rc, mid+1, r, mid+1, y));
    }
    T query(int l, int r) const {
        if (l > r) return identity;
        l = max(l, 0); r = min(r, n-1);
        if (l > r) return identity;
        return query(root, 0, n-1, l, r);
    }
    T query(int x) const { return query(x, x); }
};


template<class T>
struct lazy_segtree {
    int n;
    vector<T> st;
    vector<bool> hasSet;
    vector<T> lzSet, lzAdd;
    T identity;

    lazy_segtree(int n, T identity = T{})
        : n(n), st(4*n, identity), hasSet(4*n, 0),
          lzSet(4*n, T{}), lzAdd(4*n, T{}), identity(identity) {}

    lazy_segtree(const vector<T>& a, T identity = T{})
        : lazy_segtree((int)a.size(), identity) { build(a); }

    void build(int rt, int l, int r, const vector<T>& a) {
        if (l == r) { st[rt] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(rt<<1, l, mid, a);
        build(rt<<1|1, mid+1, r, a);
        st[rt] = st[rt<<1] + st[rt<<1|1];
    }
    void build(const vector<T>& a) { build(1, 0, n-1, a); }

    void apply_set(int rt, int l, int r, const T& v) {
        st[rt] = v * (r - l + 1);
        hasSet[rt] = 1;
        lzSet[rt] = v;
        lzAdd[rt] = T{};
    }

    void apply_add(int rt, int l, int r, const T& d) {
        st[rt] += d * (r - l + 1);
        if (hasSet[rt]) lzSet[rt] += d;
        else            lzAdd[rt] += d;
    }

    void push_down(int rt, int l, int mid, int r) {
        int lc = rt<<1, rc = rt<<1|1;
        if (hasSet[rt]) {
            apply_set(lc, l, mid, lzSet[rt]);
            apply_set(rc, mid+1, r, lzSet[rt]);
            hasSet[rt] = 0;
        }
        if (lzAdd[rt] != T{}) {
            apply_add(lc, l, mid, lzAdd[rt]);
            apply_add(rc, mid+1, r, lzAdd[rt]);
            lzAdd[rt] = T{};
        }
    }

    void update(int rt, int l, int r, int x, int y, const T& v, bool acc) {
        if (y < l || x > r) return;
        if (l == x && r == y) {
            if (!acc) apply_set(rt, l, r, v);
            else      apply_add(rt, l, r, v);
            return;
        }
        int mid = (l + r) >> 1;
        push_down(rt, l, mid, r);
        if (y <= mid) update(rt<<1, l, mid, x, y, v, acc);
        else if (x >  mid) update(rt<<1|1, mid+1, r, x, y, v, acc);
        else update(rt<<1, l, mid, x, mid, v, acc), update(rt<<1|1, mid+1, r, mid+1, y, v, acc);
        st[rt] = st[rt<<1] + st[rt<<1|1];
    }
    void update(int l, int r, const T& v, bool acc=false) { update(1, 0, n-1, l, r, v, acc); }

    T query(int rt, int l, int r, int x, int y) {
        if (y < l || x > r) return identity;
        if (x == l && r == y) return st[rt];
        int mid = (l + r) >> 1;
        push_down(rt, l, mid, r);
        if (y <= mid) return query(rt<<1, l, mid, x, y);
        if (x >  mid) return query(rt<<1|1, mid+1, r, x, y);
        return query(rt<<1, l, mid, x, mid) + query(rt<<1|1, mid+1, r, mid+1, y);
    }
    T query(int l, int r) { return query(1, 0, n-1, l, r); }
    T query(int x) { return query(x, x); }
};
