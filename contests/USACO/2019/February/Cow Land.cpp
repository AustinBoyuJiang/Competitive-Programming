/*
 * Author: Austin Jiang
 * Date: 10/23/2022 11:06:34 PM
 * Problem: Cow Land
 * Description:
*/

//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define fir first
#define sec second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
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

/* Common constants, functions, and data structures */
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

namespace comfun{
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline T pow(T a,T b){T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<typename T> inline T inv(T x){return pow(x,MOD-2);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

struct fenwick{
	int sum[(int)1e6+10];
	void add(int x,int y){ for(int i=x;i<=1e6;i+=lowbit(i)) sum[i]+=y;}
	int ask(int x,int y){ int res=0; for(int i=y;i>0;i-=lowbit(i)) res+=sum[i];
	for(int i=x-1;i>0;i-=lowbit(i)) res-=sum[i]; return res;}
};

struct fenwick_interval{
	int d[(int)1e6+10][2];
	void update(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	int query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	int add(int x,int y,int v){update(x,v),update(y+1,-v);}
	int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
};

/* ========================================| Main Program |======================================== */

const int N = 1e5+10;
int n,q,a[N],st[N<<2];
int dep[N],f[N][20];
int tot,dfn[N],rnk[N],siz[N],hson[N],top[N];
VI e[N];

void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	rep(i,1,19) f[u][i]=f[f[u][i-1]][i-1];
	siz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]])
			hson[u]=v;
	}
}

void dfs2(int u,int tp){
	top[u]=tp;
	dfn[u]=++tot;
	rnk[tot]=u;
	if(hson[u]) dfs2(hson[u],tp);
	for(auto v:e[u]){
		if(v==hson[u]||v==f[u][0]) continue;
		dfs2(v,v);
	}
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]=a[rnk[l]];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	st[rt]=st[rt<<1]^st[rt<<1|1];
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		st[rt]=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x,y);
	else update(rt<<1|1,mid+1,r,x,y);
	st[rt]=st[rt<<1]^st[rt<<1|1];
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	return query(rt<<1,l,mid,x,mid)^query(rt<<1|1,mid+1,r,mid+1,y);
}

int check(int x,int tar){
	int ans=0;
	while(top[x]!=top[tar]){
		ans^=query(1,1,n,dfn[top[x]],dfn[x]);
		x=f[top[x]][0];
	}
	ans^=query(1,1,n,dfn[tar],dfn[x]);
	return ans;
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	per(i,19,0){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	per(i,19,0){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

void solve(int Case){
	cin>>n>>q;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	rep(i,1,q){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1) update(1,1,n,dfn[x],y);
		else{
			int lca=LCA(x,y);
			cout<<(check(x,lca)^check(y,lca)^query(1,1,n,dfn[lca],dfn[lca]))<<endl;
		}
	}
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int CASE=1;
	//cin>>CASE;
	rep(Case,1,CASE) solve(Case);
    //exit(0);
	//system("fc stdout.txt out.txt");
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
    * Debug: (c) duipai
*/

