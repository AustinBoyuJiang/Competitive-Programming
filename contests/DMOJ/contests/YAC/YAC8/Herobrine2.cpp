/*
 * Author: Austin Jiang
 * Date: 2/3/2024 8:34:24 PM
 * Problem: Herobrine
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

const int N = 1e6+10;
const int M = 2e6+10;

int n,mx,fa[N],siz[N],hson[N],cnt[N],ans[N];
VI e[N],o[N],stk;
int tot,ed,l[M],r[M],pos[N];
array<int,3> val[M];

inline void init(int u){
	siz[u]=1;
	for(int v:e[u]){
		init(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]]){
			hson[u]=v;
		}
	}
}

inline void check(int x){
	chkmax(mx,val[x][0]*val[x][1]);
}

inline void upd(int x){
	if(!cnt[x]){
		cnt[x]=1;
		stk.pb(x);
		if(ed&&val[ed][0]==1){
			val[ed][1]++;
			val[ed][2]++;
			pos[x]=ed;
			check(ed);
		}
		else{
			r[ed]=++tot;
			l[tot]=ed;
			r[tot]=0;
			val[tot][0]=1;
			val[tot][1]=val[ed][1]+1;
			val[tot][2]=1;
			pos[x]=tot;
			check(tot);
			ed=tot;
		}
		return;
	}
	cnt[x]++;
	int p=pos[x];
	val[p][2]--;
	if(l[p]&&val[l[p]][0]==cnt[x]){
		val[l[p]][1]++;
		val[l[p]][2]++;
		pos[x]=l[p];
		check(l[p]);
	}
	else{
		tot++;
		val[tot][0]=cnt[x];
		val[tot][1]=val[l[p]][1]+1;
		val[tot][2]=1;
		l[tot]=l[p];
		r[tot]=p;
		r[l[p]]=tot;
		l[p]=tot;
		pos[x]=tot;
		check(tot);
	}
	if(!val[p][2]){
		if(p==ed){
			ed=l[p];
			r[l[p]]=0;
		}
		else{
			l[r[p]]=l[p];
			r[l[p]]=r[p];
		}
	}
}

inline void add(int u){
	for(int x:o[u]) upd(x);
	for(int v:e[u]) add(v);
}

inline void clean(){
	mx=tot=ed=0;
	while(!stk.empty()){
		cnt[stk.back()]=0;
		pos[stk.back()]=0;
		stk.pop_back();
	}
}

inline void dfs(int u){
	for(int v:e[u]) if(v!=hson[u]) dfs(v),clean();
	if(hson[u]) dfs(hson[u]);
	for(int v:e[u]) if(v!=hson[u]) add(v);
	for(int x:o[u]) upd(x);
	ans[u]=mx;
}

inline void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>fa[i];
		e[fa[i]].pb(i);
	}
	rep(i,1,n){
		int m;
		cin>>m;
		o[i].resize(m);
		for(int &x:o[i]){
			cin>>x;
		}
	}
	init(0);
	dfs(0);
	rep(i,1,n){
		cout<<ans[i]<<endl;
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
    * Debug: (c) Adversarial Testing
*/

