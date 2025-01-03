/*
 * Author: Austin Jiang
 * Date: 1/12/2023 11:57:13 PM
 * Problem: Roger Says Yabe
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
#define OPTIMIZE
//#define INTTOLL

#ifdef OPTIMIZE
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#endif

#include<bits/stdc++.h>
using namespace std;

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

/* STL Data Structures */
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

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <typename T> using VEC = vector<T>;
template <typename T> using US = unordered_set<T>;
template <typename T> using MS = multiset<T>;
template <typename T1, typename T2> using UM = unordered_map<T1,T2>;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace fastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {write(x),putchar(let);}
} using namespace fastIO;

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

/* Commonly used constants variables, functions, and data structures */
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#ifndef int
const int INF = 0x3f3f3f3f;
#else
const ll INF = LLINF;
#endif
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const US<char> vowel = {'a','e','i','o','u'};

namespace comfun{
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline T qpow(T a,T b){
	T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<typename T> inline T inv(T x){return qpow(x,MOD-2);}
	template<typename T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

struct fenwick{
	int sum[(int)1e6+10];
	void add(int x,int y){ for(int i=x;i<=1e6;i+=lowbit(i)) sum[i]+=y;}
	int ask(int x,int y){ int res=0; for(int i=y;i>0;i-=lowbit(i)) res+=sum[i];
	for(int i=x-1;i>0;i-=lowbit(i)) res-=sum[i]; return res;}
};

struct interval_fenwick{
	int d[(int)1e6+10][2];
	void update(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	int query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	void add(int x,int y,int v){update(x,v),update(y+1,-v);}
	int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
};

/* ========================================| Main Program |======================================== */

const int N = 510;

int adj[8][2]={{1,1},{1,-1},{-1,-1},{-1,1},{2,0},{0,2},{-2,0},{0,-2}};
int n,m,ans,cnt,a[N][N],d[N][N],vis[N][N],res[N*N];
map<int,bool> to[N*N];
PI flag[N][N][4];

int tot,colcnt,dfn[N][N],low[N][N],instk[N][N],col[N*N];
stack<PI> stk;

int in[N*N],root[N*N],f[N*N][20],dep[N*N];
VI e[N*N];

inline int id(int x,int y){
	return (x-1)*m+y;
}

inline bool ok(int x,int y){
	if(x<1||x>n) return 0;
	if(y<1||y>m) return 0;
	return d[x][y]!=-1;
}

inline void tarjan(int x,int y){
	dfn[x][y]=low[x][y]=++tot;
	instk[x][y]=1,stk.push({x,y});
	int nx=x+dir[d[x][y]][0];
	int ny=y+dir[d[x][y]][1];
	if(ok(nx,ny)){
		if(!dfn[nx][ny]) tarjan(nx,ny);
		if(instk[nx][ny]) chkmin(low[x][y],low[nx][ny]);
	}
	if(dfn[x][y]!=low[x][y]) return;
	col[id(x,y)]=++colcnt;
	while(stk.top()!=(PI){x,y}){
		PI top=stk.top();
		col[id(top.fir,top.sec)]=colcnt;
		instk[top.fir][top.sec]=0;
		stk.pop();
	}
	instk[x][y]=0;
	stk.pop();
}

inline void dfs(int u,int fa){
	if(fa){
		if(root[u]) return;
		root[u]=root[fa];
	}
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	rep(i,1,19) f[u][i]=f[f[u][i-1]][i-1];
	for(int v:e[u]){
		dfs(v,u);
	}
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	per(i,19,0){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
			if(x==y) return x;
		}
	}
	per(i,19,0){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

inline bool check(int nx,int ny,int j,int x,int y){
	int ox=flag[nx][ny][j].fir;
	int oy=flag[nx][ny][j].sec;
	if(!ox||!oy) return 1;
	if(col[id(ox,oy)]==col[id(x,y)]) return 0;
	return !to[id(x,y)][id(ox,oy)];
}

inline int count(int x,int y,int group){
	if(vis[x][y]) return res[col[id(x,y)]];
	vis[x][y]=group;
	int nx=x+dir[d[x][y]][0];
	int ny=y+dir[d[x][y]][1];
	int cnt=0;
	if(ok(nx,ny)){
		cnt=count(nx,ny,vis[x][y]);
		vis[x][y]=vis[nx][ny];
	}
	rep(i,0,3){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(a[nx][ny]){
			bool has=0;
			rep(j,0,3) has|=!check(nx,ny,j,x,y);
			if(!has) cnt++;
			flag[nx][ny][i]={x,y};
		}
	}
	return chkmax(res[col[id(x,y)]],cnt);
}

void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,n) rep(j,1,m){
		char x;
		cin>>x;
		d[i][j]=-1;
		if(x=='#') a[i][j]=1;
		else if(x!='.'){
			if(x=='v') d[i][j]=0;
			if(x=='>') d[i][j]=1;
			if(x=='^') d[i][j]=2;
			if(x=='<') d[i][j]=3;
		}
	}
	rep(i,1,n) rep(j,1,m) if(d[i][j]!=-1&&!dfn[i][j]) tarjan(i,j);
	rep(x,1,n) rep(y,1,m){
		if(d[x][y]==-1) continue; 
		int nx=x+dir[d[x][y]][0];
		int ny=y+dir[d[x][y]][1];
		if(!ok(nx,ny)) continue;
		int u=id(x,y),v=id(nx,ny);
		if(col[u]==col[v]) continue;
		e[col[v]].pb(col[u]);
		in[col[u]]++;
	}
	rep(i,1,colcnt){
		if(in[i]) continue;
		root[i]=i;
		dfs(i,0);
	}
	rep(x,1,n) rep(y,1,m){
		if(d[x][y]==-1) continue;
		rep(i,0,7){ 
			int nx=x+adj[i][0];
			int ny=y+adj[i][1];
			if(!ok(nx,ny)) continue;
			int u=id(x,y),v=id(nx,ny);
			to[u][v]=root[col[u]]==root[col[v]]&&LCA(col[u],col[v])==col[v];
		}
	}
	rep(i,1,n) rep(j,1,m){
		if(d[i][j]!=-1) count(i,j,++cnt);
		chkmax(ans,res[col[id(i,j)]]);
	}
	cout<<ans<<endl;
}

/* =====================================| End of Main Program |===================================== */

signed main(){
	#ifdef SETMEM
    int size(1<<30);  //1GB
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
		cout<<"Case #"<<i<<": "<<endl;
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
    * Debug: (c) duipai
*/

