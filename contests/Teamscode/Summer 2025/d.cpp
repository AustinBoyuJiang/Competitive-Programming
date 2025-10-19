#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

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

const int N = 2e5+10;

int n,q,l,p[N],ans[N];

struct query{
	int a,k,id;
};

vector<query> qq[N];

void SOLVE(int Case){
	cin>>n>>q>>l;
	rep(i,1,n){
		cin>>p[i];
	}
	rep(i,1,q){
		int a,k;
		cin>>a>>k;
		int l=0,r=n,pos=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(p[mid]<=k){
				pos=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		qq[pos].pb({a,k,i});
	}
	segtree<int> st1(n+1),st2(n+1);
	int cnt=0;
	per(i,n,0){
		for(auto [a,k,id]:qq[i]){
			int res=n-i;
			res-=st2.query(a+1,n)-st1.query(a+1,n)*a;
			ans[id]=res*2+a;;
		}
		if(i>=1){
			cnt++;
			if(p[i]!=p[i-1]){
				st1.update(cnt,1,true);
				st2.update(cnt,cnt,true);
				cnt=0;
			}
		}
	}
	rep(i,1,q){
		cout<<ans[i]<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	// cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}