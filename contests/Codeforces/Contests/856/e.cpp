/*
 * Author: Austin Jiang
 * Date: 3/6/2023 10:11:56 PM
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
#define OPTIMIZE
#define INTTOLL

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

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using PPI = pair<PI,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using VEC = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace FastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<class T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<class T> inline void write(T x,char let) {write(x),putchar(let);}
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

/* Commonly used constants variables, functions, and data structures */
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#ifndef int
const int INF = 0x3f3f3f3f;
#else
const ll INF = LLINF;
#endif
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
const unordered_set<char> vowel = {'a','e','i','o','u'};

namespace Comfun{
	template<class T> inline T lowbit(T x){return x&-x;}
	template<class T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<class T> inline T qpow(T a,T b){
	T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace Comfun;

template<class T,class Fun=function<T(const T,const T)>> struct Segtree{ // for maximum and minimum
	int n; Fun f; VEC<T> st;
	Segtree(int n,int val,Fun f){this->n=n; this->f=f; st.resize(n+1<<2,val);}
	T query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return f(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));}
	T ask(int x,int y){return query(1,0,n,x,y);}
	void update(int rt,int l,int r,int x,int v){
		if(l==r){st[rt]=f(st[rt],v);return;}
		int mid=l+r>>1;
		if(x<=mid) update(lc,l,mid,x,v);
		else update(rc,mid+1,r,x,v);
		st[rt]=f(st[lc],st[rc]);}
	void upd(int x,int y){update(1,0,n,x,y);}
};

template<class T> struct Fenwick{
	int n; VEC<array<T,2>> d;
	Fenwick(int n){d.resize(this->n=n);}
	inline T query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	inline T ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
	inline void update(int x,int v){for(int i=x;i<=n;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	inline void add(int x,int y,int v){update(x,v),update(y+1,-v);}
	inline void add(int x,int v){add(x,x,v);}
};

/* ========================================| Main Program |======================================== */

const int N = 2e5+10;
const int base1 = 1331;
const int base2 = 7853;
const int base3 = 998244353;

int n,a[N],cnt[N],dp11[N],dp12[N],dp21[N],dp22[N],dp31[N],dp32[N];
VI e[N];

void dfs1(int u,int fa){
	dp11[u]=1;
	dp21[u]=1;
	dp31[u]=1;
	for(int v:e[u]){
		if(v==fa) continue;
		dfs1(v,u);
		dp11[u]+=dp11[v]*base1;
		dp11[u]%=MOD;
		dp21[u]+=dp21[v]*base2;
		dp21[u]%=MOD;
		dp31[u]+=dp31[v]*base3;
		dp31[u]%=MOD;
	}
}

void dfs2(int u,int fa){
	if(fa){
		dp12[u]=(dp12[fa]+dp11[fa]-dp11[u]*base1%MOD+MOD)*base1%MOD;
		dp22[u]=(dp22[fa]+dp21[fa]-dp21[u]*base2%MOD+MOD)*base2%MOD;
		dp32[u]=(dp32[fa]+dp31[fa]-dp31[u]*base3%MOD+MOD)*base3%MOD;
	}
	for(int v:e[u]){
		if(v==fa) continue;
		dfs2(v,u);
	}
}

void SOLVE(int Case){
	cin>>n;
	rep(i,1,n-1){
		cin>>a[i];
		cnt[a[i]]++;
	}
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	int p1=0,p2=0,p3=0;
	per(i,n-1,0){
		p1=(p1*base1+cnt[i])%MOD;
		p2=(p2*base2+cnt[i])%MOD;
		p3=(p3*base3+cnt[i])%MOD;
	}
	map<int,bool> flag1,flag2,flag3;
	rep(i,0,n-1){
		flag1[(qpow(base1,i)+p1)%MOD]=1;
		flag2[(qpow(base2,i)+p2)%MOD]=1;
		flag3[(qpow(base3,i)+p3)%MOD]=1;
	}
	dfs1(1,0);
	dfs2(1,0);
	VI ans;
	rep(i,1,n){
		if(flag1[(dp11[i]+dp12[i])%MOD]&&
			flag2[(dp21[i]+dp22[i])%MOD]&&
			flag3[(dp31[i]+dp32[i])%MOD]){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int x:ans){
		cout<<x<<" ";
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

