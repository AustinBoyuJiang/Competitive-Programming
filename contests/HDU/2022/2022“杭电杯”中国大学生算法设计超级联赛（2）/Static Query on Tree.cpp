/*
 * Author: Austin Jiang
 * Date: 7/24/2022 11:37:13 PM
 * Problem:
 * Description:
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
#define random(a,b) rand()%(b-a+1)+a
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;

namespace fast_io{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {write(x),putchar(let);}
} using namespace fast_io;

namespace comfun{
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 2e5+10;
int T=1,n,m,tot,fa[N],size[N],hs[N],top[N],dfn[N],rnk[N],hson[N];
VI e[N];

struct node{
	int flag1,flag12,flag123;
	bool lazy1,lazy2,lazy3,clear;
} st[N<<2];

inline void dfs1(int u){
	size[u]=1;
	for(auto v:e[u]){
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]])
			hson[u]=v;
	}
}

inline void dfs2(int u,int tp){
	dfn[u]=++tot;
	rnk[tot]=u;
	top[u]=tp;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v!=hson[u])
			dfs2(v,v);
	}
}

inline void push_down(int rt,int l,int mid,int r){
	if(st[rt].clear){
		st[rt<<1].flag1=0;
		st[rt<<1].flag12=0;
		st[rt<<1].flag123=0;
		st[rt<<1].lazy1=0;
		st[rt<<1].lazy2=0;
		st[rt<<1].lazy3=0;
		st[rt<<1|1].flag1=0;
		st[rt<<1|1].flag12=0;
		st[rt<<1|1].flag123=0;
		st[rt<<1|1].lazy1=0;
		st[rt<<1|1].lazy2=0;
		st[rt<<1|1].lazy3=0;
		st[rt<<1].clear=1;
		st[rt<<1|1].clear=1;
		st[rt].clear=0;
	}
	if(st[rt].lazy1){
		st[rt<<1].flag1=mid-l+1;
		st[rt<<1|1].flag1=r-mid;
		st[rt<<1].lazy1=1;
		st[rt<<1|1].lazy1=1;
		st[rt].lazy1=0;
	}
	if(st[rt].lazy2){
		st[rt<<1].flag12=st[rt<<1].flag1;
		st[rt<<1|1].flag12=st[rt<<1|1].flag1;
		st[rt<<1].lazy2=1;
		st[rt<<1|1].lazy2=1;
		st[rt].lazy2=0;
	}
	if(st[rt].lazy3){
		st[rt<<1].flag123=st[rt<<1].flag12;
		st[rt<<1|1].flag123=st[rt<<1|1].flag12;
		st[rt<<1].lazy3=1;
		st[rt<<1|1].lazy3=1;
		st[rt].lazy3=0;
	}
}

inline void push_up(int rt){
	st[rt].flag1=st[rt<<1].flag1+st[rt<<1|1].flag1;
	st[rt].flag12=st[rt<<1].flag12+st[rt<<1|1].flag12;
	st[rt].flag123=st[rt<<1].flag123+st[rt<<1|1].flag123;
}

inline void update(int rt,int l,int r,int x,int y,int k){
	if(l==x&&r==y){
		if(k==1){
			st[rt].flag1=r-l+1;
			st[rt].lazy1=1;
		}
		if(k==2){
			st[rt].flag12=st[rt].flag1;
			st[rt].lazy2=1;
		}
		if(k==3){
			st[rt].flag123=st[rt].flag12;
			st[rt].lazy3=1;
		}
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,k);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,k);
	else update(rt<<1,l,mid,x,mid,k),update(rt<<1|1,mid+1,r,mid+1,y,k);
	push_up(rt);
}

inline void mark1(int x){
	while(x){
		update(1,1,n,dfn[top[x]],dfn[x],1);
		x=fa[top[x]];
	}
}

inline void mark2(int x){
	while(x){
		update(1,1,n,dfn[top[x]],dfn[x],2);
		x=fa[top[x]];
	}
}

inline void mark3(int x){
	update(1,1,n,dfn[x],dfn[x]+size[x]-1,3);
}

inline void clear(){
	st[1].flag1=0;
	st[1].flag12=0;
	st[1].flag123=0;
	st[1].lazy1=0;
	st[1].lazy2=0;
	st[1].lazy3=0;
	st[1].clear=1;
}

inline void solve(int Case){
	read(n),read(m);
	rep(i,1,n) e[i].clear();
	rep(i,2,n){
		read(fa[i]);
		e[fa[i]].pb(i);
	}
	dfs1(1);
	dfs2(1,1);
	while(m--){
		int a=read(),b=read(),c=read();
		rep(i,1,a) mark1(read());
		rep(i,1,b) mark2(read());
		rep(i,1,c) mark3(read());
		write(st[1].flag123,'\n');
		clear();
	}
}

signed main(){
//	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	read(T);
	rep(Case,1,T) solve(Case);
	return 0;
}

/* stuff you should look for
    * read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow, check edge case
    * Debug: (b) create your own test case
    * Debug: (c) ╤тед
*/

