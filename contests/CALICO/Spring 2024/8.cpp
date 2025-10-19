/*
 * Author: Austin Jiang
 * Date: 4/27/2024 4:35:35 PM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
#define FASTIO
//#define NDEBUG
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
const int MOD = 1e9+7;
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

const int N = 1e3+10;

int n,s,t,fa[N],vis[N];
ld dp[N];
pair<ld,ld> dp2[N];
VI e[N];

bool check(int u,int tar){
	if(u==tar) return 1;
	for(int v:e[u]){
		if(check(v,tar)) return 1;
	}
	return 0;
}

void dfs1(int u){
	dp[u]=0;
	if(s==u){
		int m=e[u].size()+1;
		for(int v:e[u]){
			dfs1(v);
			dp[u]+=(dp[v]+1)/m;
		}
		dp[u]=(dp[u]*m+1)/(m-1);
	}
	else{
		int m=e[u].size();
		for(int v:e[u]){
			dfs1(v);
			dp[u]+=(dp[v]+1)/m;
		}
	}
}

void solve1(){
	dfs1(1);
	printf("%.10Lf\n", dp[1]);
}

void dfs2(int u){
	if(vis[u]) return;
	vis[u]=1;
	dp[u]=0;
	int m=e[u].size();
	if(u==s) m++;
	for(int v:e[u]){
		dfs2(v);
		dp[u]+=(dp[v]+1)/m;
	}
	if(u==s){
		dfs2(t);
		dp[u]+=(dp[t]+1)/m;
	}
}

void solve2(){
	dfs2(1);
	printf("%.10Lf\n", dp[1]);
}

void dfs3(int u){
	if(vis[u]) return;
	vis[u]=1;
	dp[u]=0;
	int m=e[u].size();
	if(u==s) m++;
	if(m) dp[u]++;
	for(int v:e[u]){
		dfs3(v);
		dp[u]+=dp[v]/m;
	}
}

void dfs4(int u){
	vis[u]=1;
	dp2[u]={0,0};
	int m=e[u].size();
	for(int v:e[u]){
		if(v==s){
			dp2[u].fir+=1.0/m;
			dp2[u].sec+=1.0/m;
		}
		else{
			dfs4(v);
			dp2[u].fir+=dp2[v].fir/m;
			dp2[u].sec+=(dp2[v].sec+1)/m;
		}
	}
}

void dfs5(int u){
	if(vis[u]) return;
	vis[u]=1;
	dp[u]=0;
	int m=e[u].size();
	for(int v:e[u]){
		dfs5(v);
		dp[u]+=(dp[v]+1)/m;
	}
}

/*
1
3 2 1
1 2
*/

void solve3(){ // t is an ancestor of s
	dfs3(s);
	dfs4(t);
	int m=e[s].size()+1;
	ld a=dp2[t].fir;
	ld b=dp2[t].sec;
	dp[t]=(dp[s]*a+b)*(m/a)/(m/a-1);
	dfs5(1);
	printf("%.10Lf\n", dp[1]);
//	printf("%.10Lf\n", dp[s]);
//	printf("%.10Lf\n", dp2[t].fir);
//	printf("%.10Lf\n", dp2[t].sec);
	
	
	/*
		dp[s]=x+dp[t]/m
		dp[t]=dp[s]*a+b
		dp[t]=(x+dp[t]/m)a+b
		dp[t]-dp[t]/(m/a)=x*a+b
		dp[t]*(m/a-1)/(m/a)=x*a+b
		dp[t]=(dp[s]*a+b)*(m/a)/(m/a-1)
	*/
}

inline void SOLVE(int Case){
	read(n),read(s),read(t);
	rep(i,1,n){
		vis[i]=0;
		e[i].clear();
	}
	rep(i,2,n){
		read(fa[i]);
		e[fa[i]].pb(i);
	}
	if(s==t){
		solve1();
	}
	else if(!check(t,s)){
		solve2();
	}
	else{
		solve3();
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
	read(CASE);
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

