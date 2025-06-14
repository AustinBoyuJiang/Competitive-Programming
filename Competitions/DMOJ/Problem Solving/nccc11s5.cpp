/*
 * Author: Austin Jiang
 * Date: 1/6/2025 11:53:04 PM
 * Problem: https://dmoj.ca/problem/nccc11s5
 * Source: Mock CCC '23 1 S5 - The Obligatory Data Structures Problem
 * Description: Segment tree & president tree
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

const int N = 1e5+10;
const int Q = 3e6+10;

int n,m,a[N],b[N];

int A, B, C = ~(1<<31), M = (1<<16)-1;
inline int rnd(int last) {
  A = (36969 + (last >> 3)) * (A & M) + (A >> 16);
  B = (18000 + (last >> 3)) * (B & M) + (B >> 16);
  return (C & ((A << 16) + B)) % 1000000000;
}

int tot,root[N];

struct node{
	int lc,rc,val;
} stb[N*20];

inline void build1(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return;
	int mid=l+r>>1;
	build1(stb[rt].lc,l,mid);
	build1(stb[rt].rc,mid+1,r);
}

inline void update1(int &rt,int rtk,int l,int r,int x){
	stb[rt=++tot]=stb[rtk];
	stb[rt].val++;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) update1(stb[rt].lc,stb[rtk].lc,l,mid,x);
	else update1(stb[rt].rc,stb[rtk].rc,mid+1,r,x);
}

int sta[N<<2],lazy[N<<2];

inline void push_down(int rt,int l,int mid,int r){
	if(lazy[rt]){
		sta[rt<<1]=stb[stb[lazy[rt]].lc].val;
		sta[rt<<1|1]=stb[stb[lazy[rt]].rc].val;
		lazy[rt<<1]=stb[lazy[rt]].lc;
		lazy[rt<<1|1]=stb[lazy[rt]].rc;
		lazy[rt]=0;
	}
}

inline void build2(int rt,int l,int r){
	if(l==r){
		sta[rt]=a[l]>=b[l];
		return;
	}
	int mid=l+r>>1;
	build2(rt<<1,l,mid);
	build2(rt<<1|1,mid+1,r);
	sta[rt]=sta[rt<<1]+sta[rt<<1|1];
}

inline void update2(int rt,int rtk,int l,int r,int x,int y){
	if(l==x&&r==y){
		sta[rt]=stb[rtk].val;
		lazy[rt]=rtk;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update2(rt<<1,stb[rtk].lc,l,mid,x,y);
	else if(x>mid) update2(rt<<1|1,stb[rtk].rc,mid+1,r,x,y);
	else{
		update2(rt<<1,stb[rtk].lc,l,mid,x,mid);
		update2(rt<<1|1,stb[rtk].rc,mid+1,r,mid+1,y);
	}
	sta[rt]=sta[rt<<1]+sta[rt<<1|1];
}

inline int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sta[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

inline void SOLVE(int Case){
	cin>>n>>m>>A>>B;
	VPI p;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
		p.pb({b[i],i});
	}
	sort(all(p));
	build1(root[0],1,n);
	rep(i,1,n){
		update1(root[i],root[i-1],1,n,p[i-1].sec);
	}
	build2(1,1,n);
	int last=0,ans=0;
	rep(i,1,m){
		int l=rnd(last)%n+1;
		int r=rnd(last)%n+1;
		int x=rnd(last)+1;
		if(l>r) swap(l,r);
		if(l+r+x&1){
			int pos=ub(all(p),make_pair(x,n+1))-p.begin();
			update2(1,root[pos],1,n,l,r);
		}
		else{
			last=query(1,1,n,l,r);
			ans=(ans+i*1ll*last)%MOD;
		}
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
    * Debug: (c) adversarial testing
*/

