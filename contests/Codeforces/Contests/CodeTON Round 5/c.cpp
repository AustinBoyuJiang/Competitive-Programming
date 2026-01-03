/*
 * Author: Austin Jiang
 * Date: 6/25/2023 8:35:24 PM
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
//#define FASTIO
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

/* Common functions and data structures */

namespace Comfun{
	template<class T> inline T lowbit(T x){return x&-x;}
	template<class T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<class T> inline T qpow(T a,T b){T ans=1;while(b){if(b&1)ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0) /*discretize*/ {Vec<T> num=v;sort(all(num));
	for(T &x:v) x=lb(all(num),x)-num.begin()+st;}
} using namespace Comfun;

template<class T,class Fun=function<T(const T,const T)>> struct Segtree{
	int L=0,R=-1,ini=0; Fun F; Vec<T> st;
	inline Segtree(){}
	inline Segtree(int L,int R,int val,Fun F){this->L=L,this->R=R,this->F=F;st.resize(R-L+1<<2,ini=val);}
	inline Segtree(int L,int R,Fun F){this->L=L,this->R=R,this->F=F;st.resize(R-L+1<<2,0);}
	inline Segtree(Vec<T> v,Fun F){this->R=v.size()-1,this->F=F;st.resize(v.size()<<2);rep(i,0,this->R) upd(i,v[i],true);}
	inline void init(int L,int R,int val,Fun F){this->L=L,this->R=R,this->F=F;st.resize(R-L+1<<2,ini=val);}
	inline void init(int L,int R,Fun F){this->L=L,this->R=R,this->F=F;st.resize(R-L+1<<2,0);}
	inline void init(Vec<T> v,Fun F){this->R=v.size()-1,this->F=F;st.resize(v.size()<<2);rep(i,0,this->R) upd(i,v[i],true);}
	inline T query(int rt,int l,int r,int x,int y){
		if(x>y) return ini;
		if(l==x&&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return F(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));}
	inline void update(int rt,int l,int r,int x,int v,bool cover){
		if(l==r){st[rt]=cover?v:F(st[rt],v);return;}
		int mid=l+r>>1;
		if(x<=mid) update(lc,l,mid,x,v,cover);
		else update(rc,mid+1,r,x,v,cover);
		st[rt]=F(st[lc],st[rc]);}
	inline T ask(int x,int y){return query(1,L,R,x,y);}
	inline void upd(int x,int y,bool cover=false){update(1,L,R,x,y,cover);}
};

template<class T> struct Fenwick{
	int n=0; Vec<array<T,2>> d;
	inline Fenwick(){}
	inline Fenwick(int n){d.resize(this->n=n);}
	inline void resize(int n){d.resize(this->n=n,{0,0});}
	inline T query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	inline T ask(int x,int y){return (y+2)*query(y+1,0)-query(y+1,1)-(x+1)*query(x,0)+query(x,1);}
	inline void update(int x,int v){for(int i=x;i<=n;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	inline void add(int x,int y,int v){update(x+1,v),update(y+2,-v);}
	inline void add(int x,int v){add(x,x,v);}
};

/* ========================================| Main Program |======================================== */

const int N = 1e6+10;

int n,a[N],dp[N][2],mx1[N],mx2[N];

void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		mx1[i]=-INF;
		mx2[i]=-INF;
	}
	rep(i,1,n){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
		chkmax(dp[i][1],mx1[a[i]]+i);
		chkmax(dp[i][1],mx2[a[i]]+i);
		chkmax(mx1[a[i]],dp[i][0]-i+1);
		chkmax(mx2[a[i]],dp[i][1]-i);
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
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

