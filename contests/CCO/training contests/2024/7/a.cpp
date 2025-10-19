/*
 * Author: Austin Jiang
 * Date: 5/10/2024 7:02:42 PM
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

const int N = 2010;

int n,m,mx0,a[N][N],flag[N][N];

bool check1(int x){
	rep(i,1,n) rep(j,1,m){
		if(mx0-a[i][j]<=x){
			flag[i][j]=1;
		}
		else{
			flag[i][j]=0;
		}
	}
	if(!flag[1][1]) return 0;
	rep(i,1,n){
		bool val=1;
		rep(j,1,m){
			if(flag[i][j]==0) val=0;
			if(flag[i-1][j]==0) val=0;
			flag[i][j]=val;
		}
	}
	int mx=a[n][m],mn=mx;
	rep(i,1,n) rep(j,1,m){
		if(flag[i][j]) continue;
		chkmax(mx,a[i][j]);
		chkmin(mn,a[i][j]);
	}
	return mx-mn<=x;
}

bool check2(int x){
	rep(i,1,n) rep(j,1,m){
		if(mx0-a[i][j]<=x){
			flag[i][j]=1;
		}
		else{
			flag[i][j]=0;
		}
	}
	if(!flag[1][m]) return 0;
	rep(i,1,n){
		bool val=1;
		per(j,m,1){
			if(flag[i][j]==0) val=0;
			if(flag[i-1][j]==0) val=0;
			flag[i][j]=val;
		}
	}
	int mx=a[n][1],mn=mx;
	rep(i,1,n) rep(j,1,m){
		if(flag[i][j]) continue;
		chkmax(mx,a[i][j]);
		chkmin(mn,a[i][j]);
	}
	return mx-mn<=x;
}

bool check3(int x){
	rep(i,1,n) rep(j,1,m){
		if(mx0-a[i][j]<=x){
			flag[i][j]=1;
		}
		else{
			flag[i][j]=0;
		}
	}
	if(!flag[n][1]) return 0;
	per(i,n,1){
		bool val=1;
		rep(j,1,m){
			if(flag[i][j]==0) val=0;
			if(flag[i+1][j]==0) val=0;
			flag[i][j]=val;
		}
	}
	int mx=a[1][m],mn=mx;
	rep(i,1,n) rep(j,1,m){
		if(flag[i][j]) continue;
		chkmax(mx,a[i][j]);
		chkmin(mn,a[i][j]);
	}
	return mx-mn<=x;
}

bool check4(int x){
	rep(i,1,n) rep(j,1,m){
		if(mx0-a[i][j]<=x){
			flag[i][j]=1;
		}
		else{
			flag[i][j]=0;
		}
	}
	if(!flag[n][m]) return 0;
	per(i,n,1){
		bool val=1;
		per(j,m,1){
			if(flag[i][j]==0) val=0;
			if(flag[i+1][j]==0) val=0;
			flag[i][j]=val;
		}
	}
	int mx=a[1][1],mn=mx;
	rep(i,1,n) rep(j,1,m){
		if(flag[i][j]) continue;
		chkmax(mx,a[i][j]);
		chkmin(mn,a[i][j]);
	}
	return mx-mn<=x;
}

inline void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,m){
		flag[0][i]=1;
		flag[n+1][i]=1;
	}
	rep(i,1,n){
		rep(j,1,m){
			cin>>a[i][j];
			chkmax(mx0,a[i][j]);
		}
	}
	int l=0,r=1e9,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check1(mid)||check2(mid)||check3(mid)||check4(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
//	rep(i,1,n){
//		rep(j,1,m){
//			cout<<flag[i][j];
//		}
//		cout<<endl;
//	}
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

