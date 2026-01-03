/*
 * Author: Austin Jiang
 * Date: 12/31/2024 3:56:04 AM
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

const int N = 2e5+10;

int n,q,v[N];
char s[N];

struct node{
	int mx,lx,rx,l,r;
	bool c; // if only multiplications exist in the range
} st[N<<2];

node merge(node a,node b){
	node res={0,a.lx,b.rx,a.l,b.r,false};
	if(a.c&&b.c&&s[a.r]=='x') res.c=true;
	if(a.c){
		if(s[a.r]=='+') res.lx=a.lx;
		else res.lx=a.mx*b.lx%2;
	}
	if(b.c){
		if(s[a.r]=='+') res.rx=b.rx;
		else res.rx=b.mx*a.rx%2;
	}
	if(s[a.r]=='+') res.mx=(a.mx+b.mx)%2;
	else{
		if(a.c&&b.c) res.mx=a.mx*b.mx;
		else if(a.c) res.mx=(b.mx-b.lx+b.lx*a.mx%2+2)%2;
		else if(b.c) res.mx=(a.mx-a.rx+a.rx*b.mx%2+2)%2;
		else res.mx=(a.mx+b.mx-a.rx-b.lx+a.rx*b.lx%2+4)%2;
	}
	return res;
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]={v[l],v[l],v[l],l,r,true};
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	st[rt]=merge(st[lc],st[rc]);
}

void update1(int rt,int l,int r,int x){
	if(l==r){
		st[rt]={v[l],v[l],v[l],l,r,true};
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update1(lc,l,mid,x);
	else update1(rc,mid+1,r,x);
	st[rt]=merge(st[lc],st[rc]);
}

void update2(int rt,int l,int r,int x){
	if(r==x) return;
	int mid=l+r>>1;
	if(x<=mid) update2(lc,l,mid,x);
	else update2(rc,mid+1,r,x);
	st[rt]=merge(st[lc],st[rc]);
}

node query(int rt,int l,int r,int x,int y){
	if(y<x){
		if(y==0) return {0,0,0,0,0,true};
		else return {0,0,0,n,n,true};
	}
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(lc,l,mid,x,y);
	else if(x>mid) return query(rc,mid+1,r,x,y);
	return merge(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
}

inline void SOLVE(int Case){
	cin>>n>>q;
	rep(i,1,n){
		cin>>v[i];
		v[i]%=2;
	}
	rep(i,1,n-1){
		cin>>s[i];
	}
	s[0]=s[n]='+';
	build(1,1,n);
	rep(i,1,q){
		char opt;
		int l,r,x,ans;
		cin>>opt;
		if(opt=='V'){
			cin>>x;
			v[x]^=1;
			update1(1,1,n,x);
		}
		else if(opt=='O'){
			cin>>x;
			if(s[x]=='+') s[x]='x';
			else s[x]='+';
			update2(1,1,n,x);
		}
		else{
			cin>>l>>r;
			node res=query(1,1,n,l,r);
			node resl=query(1,1,n,1,l-1);
			node resr=query(1,1,n,r+1,n);
			node inbrac={res.mx,res.mx,res.mx,l,r,true};
			ans=merge(merge(resl,inbrac),resr).mx;
			if(ans%2==0) cout<<"even"<<endl;
			else cout<<"odd"<<endl;
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

