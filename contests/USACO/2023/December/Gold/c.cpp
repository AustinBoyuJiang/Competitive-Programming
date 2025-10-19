#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using PPI = pair<PI,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace Comfun{
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
} using namespace Comfun;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

const int N=2e5+10;
const int A=1e6+10;
const int K=2;

int n,q,p[N],sum[N],suml[N],sumr[N];

struct Segtree{
	struct node{double b,k;};
	Vec<node> seg;
	VI st;
	
	Segtree(int n){
		seg.resize(n+1);
		st.resize(A<<(2+K));
	}
	
	inline double calc(int id,int x){
		if(!id) return INF;
		return seg[id].k*x+seg[id].b;
	}
	
	inline int chk(int a,int b,int x){
		if(calc(a,x)<calc(b,x)) return a;
		return b;
	}
	
	inline double ask(double x,int rt=1,int l=0,int r=(int)(1e6)<<K){
		if(l==r) return calc(st[rt],x);
		int mid=l+r>>1;
		if(x<=mid) return min(ask(x,lc,l,mid),calc(st[rt],x));
		else return min(ask(x,rc,mid+1,r),calc(st[rt],x));
	}
	
	inline void upd(int id,int rt=1,int l=0,int r=(int)(1e6)<<K){
		int mid=l+r>>1;
		int a=chk(st[rt],id,mid),b=st[rt]+id-a; st[rt]=a;
		if(chk(a,b,l)==b) upd(b,lc,l,mid);
		if(chk(a,b,r)==b) upd(b,rc,mid+1,r);
	}
	
	inline void add(int id){
		seg[id].b=suml[id];
		seg[id].k=sumr[id]*1.0/(1<<K);
		upd(id);
	}
};

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	rep(i,1,n){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	rep(i,1,n){
		sum[i]=sum[i-1]+p[i];
	}
	Segtree st(n);
	rep(i,1,n){
		suml[i]=p[i]*i-sum[i];
		sumr[i]=(sum[n]-sum[i])-p[i]*(n-i);
		st.add(i);
	}
	cin>>q;
	rep(i,1,q){
		int a,b;
		cin>>a>>b;
		cout<<(int)(st.ask((int)((b<<K)*1.0/a))*a+0.5)<<endl;
	}
	return 0;
}
