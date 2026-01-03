/*
 * Author: Austin Jiang
 * Date: 6/7/2023 9:13:45 AM
 * Problem: Pudding Monsters
 * Source: ZeptoLab Code Rush 2015
 * Description:
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
//#define FASTIO
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

/* ========================================| Main Program |======================================== */

const int N = 3e5+10;

int n,h[N];
ll ans;

struct segtree{
	PI mn[N<<2];
	int lazy[N<<2];
	
	void push_down(int rt,int l,int mid,int r){
		if(lazy[rt]!=0){
			mn[lc].fir+=lazy[rt];
			mn[rc].fir+=lazy[rt];
			lazy[lc]+=lazy[rt];
			lazy[rc]+=lazy[rt];
			lazy[rt]=0;
		}
	}
	
	PI merge(PI x,PI y){
		PI res;
		if(x.fir<y.fir) res=x;
		else if(x.fir>y.fir) res=y;
		else{
			res=x;
			res.sec+=y.sec;
		}
		return res;
	}
	
	void build(int rt,int l,int r){
		if(l==r){
			mn[rt]={l,1};
			return;
		}
		int mid=l+r>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		mn[rt]=merge(mn[lc],mn[rc]);
	}
	
	void update(int rt,int l,int r,int x,int y,int v){
		if(l==x&&r==y){
			mn[rt].fir+=v;
			lazy[rt]+=v;
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(lc,l,mid,x,y,v);
		else if(x>mid) update(rc,mid+1,r,x,y,v);
		else{
			update(lc,l,mid,x,mid,v);
			update(rc,mid+1,r,mid+1,y,v);
		}
		mn[rt]=merge(mn[lc],mn[rc]);
	}
	
	PI query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y){
			return mn[rt];
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return merge(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
	}
} st;

stack<int> mn,mx;

void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		h[x]=y;
	}
	st.build(1,1,n);
	rep(i,1,n){
		while(!mn.empty()&&h[i]<h[mn.top()]){
			int pre=mn.top(); mn.pop();
			st.update(1,1,n,mn.empty()?1:mn.top()+1,pre,h[pre]-h[i]);
		} mn.push(i);
		while(!mx.empty()&&h[i]>h[mx.top()]){
			int pre=mx.top(); mx.pop();
			st.update(1,1,n,mx.empty()?1:mx.top()+1,pre,h[i]-h[pre]);
		} mx.push(i);
		PI res=st.query(1,1,n,1,i);
		ans+=res.sec*(res.fir==i);
	}
	cout<<ans<<endl;
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

