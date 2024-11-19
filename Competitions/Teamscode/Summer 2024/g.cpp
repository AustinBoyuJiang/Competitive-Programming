/*
 * Author: Austin Jiang
 * Date: 7/28/2024 1:04:25 PM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
#define FASTIO
//#define NDEBUG
#define OPTIMIZE
#define INTTOLL

#ifdef OPTIMIZE
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#endif

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifdef INTTOLL
#define int long long
#endif

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

/* Pair */
#define fir first
#define sec second

/* Segment Tree */
#define lc (rt << 1)
#define rc (rt << 1 | 1)

/* STL */
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()

/* Random */
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a,b) rng()%(b-a+1)+a

/* Data type */
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
template <class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

/* Set up */
namespace FastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<class T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<class T> inline void write(T x,char ch) {write(x),putchar(ch);}
} using namespace FastIO;

void SETUP(){
	#ifdef FASTIO
	cin.tie(nullptr)->sync_with_stdio(false);
	#endif
	#ifdef READLOCAL
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	#endif
	srand(time(0));
}

/* Constants */
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#ifndef int
const int INF = 0x3f3f3f3f;
#else
const ll INF = LLINF;
#endif
const int MOD = 998244353;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
const unordered_set<char> vowel = {'a','e','i','o','u'};

/* Common functions */

namespace Comfun{
	template<class T> inline T lowbit(T x){return x&-x;}
	template<class T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<class T> inline T qpow(T a,T b){T ans=1;
	while(b){if(b&1)ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	inline int mex(VI v){VI vis(v.size(),0);for(int x:v) if(x<v.size()) vis[x]=1;
	int pos=0;while(pos<v.size()&&vis[pos]) pos++;return pos;}
	template<class T> inline void discrete(T *st,T *ed,T offset=0){ set<T> num(st,ed); Vec<T> pos(all(num));
	for (T *itr=st;itr!=ed;++itr){*itr=lb(all(pos),*itr)-pos.begin()+offset;}}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 3e5+10;

int n,m,q,s[N],t[N],v[N],c[N];
int tot,siz[N],dep[N],fa[N][20],hson[N],top[N],dfn[N],rnk[N];
int sum[N<<2],lazy[N<<2];
VI e[N];

void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void push_down(int rt,int l,int mid,int r){
	sum[rt<<1]+=lazy[rt]*(mid-l+1);
	sum[rt<<1|1]+=lazy[rt]*(r-mid);
	lazy[rt<<1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		sum[rt]+=v*(r-l+1);
		lazy[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

void dfs1(int u,int father){
	siz[u]=1;
	fa[u][0]=father;
	dep[u]=dep[father]+1;
	for(int i=1;i<=19;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v==father) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
}

void dfs2(int u,int tp){
	top[u]=tp;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v==fa[u][0]) continue;
		if(v!=hson[u]) dfs2(v,v);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	per(i,19,0){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
			if(x==y) return x;
		}
	}
	per(i,19,0){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

void add_path(int x,int y,int k){
	while(top[x]!=top[y]){
		update(1,1,n,min(dfn[top[x]],dfn[x]),max(dfn[top[x]],dfn[x]),k);
		x=fa[top[x]][0];
	}
	update(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),k);
}

int ask_path(int x,int y){
	int sum=0;
	while(top[x]!=top[y]){
		sum+=query(1,1,n,min(dfn[top[x]],dfn[x]),max(dfn[top[x]],dfn[x]));
		x=fa[top[x]][0];
	}
	sum+=query(1,1,n,min(dfn[x],dfn[y]),max(dfn[x],dfn[y]));
	return sum;
}

void upd(int s,int t,int v){
	int lca=LCA(s,t);
	add_path(s,lca,v);
	add_path(t,lca,v);
	add_path(lca,lca,-v);
}

int ask(int s,int t){
	int lca=LCA(s,t);
	return ask_path(s,lca)+ask_path(t,lca)-ask_path(lca,lca);
}

inline void SOLVE(int Case){
	cin>>n>>m>>q;
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	rep(i,1,m){
		cin>>s[i]>>t[i]>>v[i]>>c[i];
		if(c[i]){
			upd(s[i],t[i],v[i]);
		}
	}
	rep(i,1,q){
		int opt;
		cin>>opt;
		if(opt==1){
			int x;
			cin>>x;
			upd(s[x],t[x],v[x]);
		}
		else if(opt==2){
			int x;
			cin>>x;
			upd(s[x],t[x],-v[x]);
		}
		else{
			int u,v;
			cin>>u>>v;
			cout<<ask(u,v)<<endl;
		}
	}
}

/* =====================================| End of Main Program |===================================== */

signed main(){
	#ifdef SETMEM
    int size(512<<20);  //512MB
    __asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	#endif
	#ifndef FILESCOMP
	SETUP();
	int CASE=1;
	#ifdef MULTICASES
	cin>>CASE;
	#endif
	rep(i,1,CASE){
		#ifdef LOCAL
		printf("Case #%d: \n",i);
		#endif
		SOLVE(i);
	}
	#else
	system("fc stdout.txt out.txt");
	#endif
	#ifdef SETMEM
    exit(0);
    #endif
	return 0;
}

/* stuff you should look for
	* read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow and edge case
    * Debug: (b) create your own test case
    * Debug: (c) adversarial testing
*/

