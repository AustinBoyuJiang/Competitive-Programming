/*
 * Author: Austin Jiang
 * Date: 8/12/2023 11:29:49 PM
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
//#define lc (rt << 1)
//#define rc (rt << 1 | 1)

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
	template<class T> inline T qpow(T a,T b){T ans=1;
	while(b){if(b&1)ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	inline int mex(VI s){sort(all(s));int j=0;rep(i,0,s[s.size()]+1){
	while(j<s.size()&&s[j]<i) j++;if(s[j]!=i) return i;}}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0) /*discretize*/ {Vec<T> num=v;sort(all(num));
	for(T &x:v) x=lb(all(num),x)-num.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 1e6+10;

int n,q,ans[N];

struct start{
	int id,x,ans;
} s[N];

bool cmp3(start a,start b){
	return a.x<b.x;
}

struct Seg{
	int l,r,a,b,arr;
} seg[N];

bool cmp(Seg a,Seg b){
	return a.b<b.b;
}
bool cmp2(Seg a,Seg b){
	return a.r<b.r;
}

struct segment_tree{
	int root=0,tot=0,lc[N<<2],rc[N<<2],st[N<<2];
	
	void clear(){
		root=0;
		rep(i,0,tot){
			lc[i]=0;
			rc[i]=0;
			st[i]=0;
		}
		tot=0;
	}
	void update(int &rt,int l,int r,int x,int y){
		if(!rt) rt=++tot;
		if(l==r){
			chkmax(st[rt],y);
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(lc[rt],l,mid,x,y);
		else update(rc[rt],mid+1,r,x,y);
		st[rt]=max(st[lc[rt]],st[rc[rt]]);
	}
	int query(int &rt,int l,int r,int x,int y){
		if(!rt||y<x) return 0;
		if(l==x&&r==y){
			return st[rt];
		}
		int mid=l+r>>1;
		if(y<=mid) return query(lc[rt],l,mid,x,y);
		else if(x>mid) return query(rc[rt],mid+1,r,x,y);
		return max(query(lc[rt],l,mid,x,mid),query(rc[rt],mid+1,r,mid+1,y));
	}
} st;

inline void SOLVE(int Case){
	cin>>n;
	st.clear();
	rep(i,1,n){
		cin>>seg[i].l>>seg[i].r>>seg[i].a>>seg[i].b;
	}
	sort(seg+1,seg+n+1,cmp);
	int pos=0;
	per(i,n,1){
		seg[i].arr=seg[i].b;
		if(seg[i].b>=seg[pos].l){
			chkmax(seg[i].arr,seg[pos].arr);
		}
		if(pos==0||seg[i].l<seg[pos].l){
			pos=i;
		}
	}
	cin>>q;
	rep(i,1,q){
		cin>>s[i].x;
		s[i].ans=s[i].x;
		s[i].id=i;
	}
	sort(seg+1,seg+n+1,cmp2);
	sort(s+1,s+q+1,cmp3);
	int j=n;
	per(i,q,1){
		while(j>=1&&seg[j].r>=s[i].x){
			st.update(st.root,1,1e9,seg[j].l,seg[j].arr);
			j--;
		}
		chkmax(s[i].ans,st.query(st.root,1,1e9,1,s[i].x));
	}
	rep(i,1,q){
		ans[s[i].id]=s[i].ans;
	}
	rep(i,1,q){
		cout<<ans[i]<<" ";
	} cout<<endl;
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

