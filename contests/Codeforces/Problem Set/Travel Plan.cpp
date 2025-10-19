/*
 * Author: Austin Jiang
 * Date: 10/29/2023 11:39:11 PM
 * Problem: Travel Plan
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
	inline int mex(VI s){sort(all(s));int j=0;rep(i,0,s[s.size()-1]+1){
	while(j<s.size()&&s[j]<i) j++;if(s[j]!=i) return i;}}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0){set<int> num;Vec<T> pos;
	for(T x:v)num.insert(x);for(T x:num)pos.pb(x);for(T &x:v) x=lb(all(pos),x)-pos.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 200;

int n,m,cnt[N],ppow[N];

int get(int len,int n,int h){
	if(len==0) return 1;
	if(len<h) return ppow[len-1];
	return (n%MOD-ppow[len-1]+MOD+1)%MOD;
}

void solve(int n,int dep){
	if(n==0) return;
	rep(h,1,dep){
		rep(len,3,h*2-1){
			cnt[len]+=ppow[dep-h+len-3]*min(len-2,h*2-len)%MOD;
			cnt[len]%=MOD;
		}
		rep(len,1,h){
			cnt[len]+=ppow[dep-h+len-1]%MOD;
			cnt[len]%=MOD;
		}
	}
}

void dfs(int n){
	if(n==0) return;
	int h=log2(n)+1,sizl,sizr,hl,hr;
	int mid=(1ll<<h-1)+(1ll<<h-2)-1;
	if(n>mid){
		sizl=(1ll<<h-1)-1;
		sizr=n-1-sizl;
		hl=h-1,hr=h-1;
		solve(sizl,h-1);
		dfs(sizr);
	}
	else if(n<mid){
		sizr=(1ll<<h-2)-1;
		sizl=n-1-sizr;
		hl=h-1,hr=h-2;
		solve(sizr,h-2);
		dfs(sizl);
	}
	else{
		sizl=(1ll<<h-1)-1;
		sizr=(1ll<<h-2)-1;
		hl=h-1,hr=h-2;
		solve(sizl,h-1);
		solve(sizr,h-2);
	}
	rep(lenl,0,hl){
		rep(lenr,0,hr){
			int len=lenl+lenr+1;
			cnt[len]+=get(lenl,sizl,hl)*get(lenr,sizr,hr)%MOD;
			cnt[len]%=MOD;
		}
	}
}

inline void SOLVE(int Case){
	memset(cnt,0,sizeof(cnt));
	cin>>n>>m;
	ppow[0]=1;
	rep(i,1,N-1){
		ppow[i]=ppow[i-1]*2;
		ppow[i]%=MOD;
	}
	int h=log2(n)+1;
	if((1ll<<h)-1==n) solve(n,h);
	else dfs(n);
	int ans=0;
	rep(len,1,min(n,N-1)){
		int tot=0;
		rep(i,1,m){
			tot+=(qpow(i,len)-qpow(i-1,len)+MOD)%MOD*i%MOD;
			tot%=MOD;
		}
		ans+=cnt[len]*tot%MOD*qpow(m,n-len)%MOD;
		ans%=MOD;
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

