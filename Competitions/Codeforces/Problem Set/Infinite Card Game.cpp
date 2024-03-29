/*
 * Author: Austin Jiang
 * Date: 11/13/2023 11:06:34 AM
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
	inline int mex(VI s){sort(all(s));int j=0;rep(i,0,s[s.size()-1]+1){
	while(j<s.size()&&s[j]<i) j++;if(s[j]!=i) return i;}}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0){set<int> num;Vec<T> pos;
	for(T x:v)num.insert(x);for(T x:num)pos.pb(x);for(T &x:v) x=lb(all(pos),x)-pos.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 3e5+10;
const int C = 1e6+10;

int n,m,ans[3],vis[C];
PI a[N],b[N];

struct Segtree{
	
	int st[C<<2];
	
	void clear(int rt,int l,int r,int x){
		if(l==r){
			st[rt]=0;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) clear(lc,l,mid,x);
		else clear(rc,mid+1,r,x);
		st[rt]=max(st[lc],st[rc]);
	}
	
	void update(int rt,int l,int r,int x,int y){
		if(l==r){
			chkmax(st[rt],y);
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(lc,l,mid,x,y);
		else update(rc,mid+1,r,x,y);
		st[rt]=max(st[lc],st[rc]);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return max(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
	}
	
	void upd(int pos,int val){
		update(1,1,1e6+1,pos,val);
	}
	
	int ask(int l,int r){
		return query(1,1,1e6+1,l,r);
	}
	
} A,B;

int check(int x){
	if(vis[x]) return 1;
	vis[x]=1;
	int mxb=B.ask(x+1,1e6+1);
	if(!mxb) return 0;
	int mxa=A.ask(mxb+1,1e6+1);
	if(!mxa) return 2;
	return check(mxa);
}

int find(int x){
	rep(i,1,n){
		vis[a[i].sec]=0;
	}
	return check(x);
}

inline void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>a[i].fir;
	}
	rep(i,1,n){
		cin>>a[i].sec;
		A.upd(a[i].fir,a[i].sec);
	}
	cin>>m;
	rep(i,1,m){
		cin>>b[i].fir;
	}
	rep(i,1,m){
		cin>>b[i].sec;
		B.upd(b[i].fir,b[i].sec);
	}
	
	sort(a+1,a+n+1,[](PI a,PI b){
		return a.sec<b.sec;
	});
	
	ans[0]=0;
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(find(a[mid].sec)==0){
			ans[0]=n-mid+1;
			r=mid-1;
		}
		else l=mid+1;
	}
	ans[2]=0;
	l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(find(a[mid].sec)==2){
			ans[2]=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	ans[1]=n-ans[0]-ans[2];
	cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	
	rep(i,1,n){
		A.clear(1,1,1e6+1,a[i].fir);
	}
	rep(i,1,m){
		B.clear(1,1,1e6+1,b[i].fir);
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

