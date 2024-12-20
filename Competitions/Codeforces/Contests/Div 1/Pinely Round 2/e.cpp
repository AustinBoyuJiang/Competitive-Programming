/*
 * Author: Austin Jiang
 * Date: 8/31/2023 12:05:22 AM
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
	template<class T> inline T qpow(T a,T b){T ans=1;
	while(b){if(b&1)ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	inline int mex(VI s){sort(all(s));int j=0;rep(i,0,s[s.size()-1]+1){
	while(j<s.size()&&s[j]<i) j++;if(s[j]!=i) return i;}}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0) /*discretize*/ {Vec<T> num=v;sort(all(num));
	for(T &x:v) x=lb(all(num),x)-num.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 2e5+10;

int n,m,k,cnt,h[N],f[N],in[N],day[N],id[N];
PI tv[N],dp[N][2];
VI e[N];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	if(find(x)==find(y)) return;
	f[find(x)]=find(y);
}

int check(int l,int r,PI p){
	return max(p.sec,r)-min(p.fir,l);
}

inline void SOLVE(int Case){
	cin>>n>>m>>k;
	cnt=0;
	rep(i,1,n){
		cin>>h[i];
		in[i]=0;
		day[i]=0;
		e[i].clear();
		f[i]=i;
		tv[i].fir=INF;
		tv[i].sec=-INF;
		id[i]=0;
	}
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		merge(u,v);
		in[v]++;
		e[u].pb(v);
	}
	queue<int> q;
	rep(i,1,n){
		if(!in[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:e[u]){
			if(h[v]>=h[u]){
				chkmax(day[v],day[u]);
			}
			else{
				chkmax(day[v],day[u]+1);
			}
			in[v]--;
			if(!in[v]){
				q.push(v);
			}
		}
	}
	rep(i,1,n){
		if(!id[find(i)]) id[find(i)]=++cnt;
		chkmax(tv[id[find(i)]].sec,day[i]*k+h[i]);
		chkmin(tv[id[find(i)]].fir,day[i]*k+h[i]);
	}
	int ans=INF;
	rep(j,1,cnt){
		int x=tv[j].fir;
		int mn=INF,mx=-INF;
		rep(i,1,cnt){
			if(tv[i].fir<x){
				chkmax(mx,tv[i].sec+k);
				chkmin(mn,tv[i].fir+k);
			}
			else{
				chkmax(mx,tv[i].sec);
				chkmin(mn,tv[i].fir);
			}
		}
		chkmin(ans,mx-mn);
	}
	cout<<ans<<endl;
//	sort(tv+1,tv+cnt+1);
//	dp[0][0]={INF,-INF};
//	dp[0][1]={INF,-INF};
//	rep(i,1,cnt){
//		if(check(tv[i].fir,tv[i].sec,dp[i-1][0])<check(tv[i].fir,tv[i].sec,dp[i-1][1])){
//			dp[i][0].fir=min(tv[i].fir,dp[i-1][0].fir);
//			dp[i][0].sec=max(tv[i].sec,dp[i-1][0].sec);
//		}
//		else{
//			dp[i][0].fir=min(tv[i].fir,dp[i-1][1].fir);
//			dp[i][0].sec=max(tv[i].sec,dp[i-1][1].sec);
//		}
//		if(check(tv[i].fir+k,tv[i].sec+k,dp[i-1][0])<check(tv[i].fir,tv[i].sec,dp[i-1][1])){
//			dp[i][1].fir=min(tv[i].fir+k,dp[i-1][0].fir);
//			dp[i][1].sec=max(tv[i].sec+k,dp[i-1][0].sec);
//		}
//		else{
//			dp[i][1].fir=min(tv[i].fir+k,dp[i-1][1].fir);
//			dp[i][1].sec=max(tv[i].sec+k,dp[i-1][1].sec);
//		}
//	}
//	cout<<min(dp[cnt][0].sec-dp[cnt][0].fir,dp[cnt][1].sec-dp[cnt][1].fir)<<endl;
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

