/*
 * Author: Austin Jiang
 * Date: 5/10/2025 11:47:36 PM
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
#define INTTOLL

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
#define mp make_pair
#define all(v) v.begin(), v.end()

/* Random */
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a,b) (ll)rng()%(b-a+1)+a

struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.fir) ^ (hash<T2>{}(p.sec) << 1);
    }
};

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
template <class T> using UM = unordered_map<int,T>;
template <class T> using UPM = unordered_map<PI,T,pair_hash>;

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

const int N = 3e5+10;
const int A = 100;
const int B = 100;
const int C = 300;
const int D = 1;

int n,sum[N],st[N][20];
PI p[N];

int get(int x,int y){
	y--;
	int k=log2(y-x+1);
	return min(st[x][k],st[y-(1<<k)+1][k]);
}

int dis(int x,int y){
	return abs(p[x].fir-p[y].fir)+abs(p[x].sec-p[y].sec);
}

int check1(int a,int b,int i,int j){
	return min(sum[b]-sum[a],sum[a]-sum[i]+sum[j]-sum[b]+dis(i,j));
}

int check3(int a,int i,int j){
	return min(sum[a],sum[j]-sum[a]+dis(i,j)+sum[i]);
}

int check4(int a,int i,int j){
	return min(sum[n]-sum[a],sum[a]-sum[i]+dis(i,j)+sum[n]-sum[j]);
}

int check5(int a,int i,int j){
	int res=0;
	int l=a+1,r=j;
	while(l<=r){
		int mid=(l+r)/2;
		int midl=l+(r-l)/3;
		int midr=l+(r-l)*2/3;
		int ansm=check1(a,mid,i,j);
		int ansl=check1(a,midl,i,j);
		int ansr=check1(a,midr,i,j);
		chkmax(res,max({ansm,ansl,ansr}));
		if(ansl>ansr){
			r=midr-1;
		}
		else{
			l=midl+1;
		}
	}
	rep(mid,max(l-D,a+1),min(l+D,j)){
		chkmax(res,check1(a,mid,i,j));
	}
	return res;
}

int check2(int i,int j){
	int res=0;
	chkmax(res,sum[i]+sum[n]-sum[j]+dis(i,j));
	int l=i,r=j;
	while(l<=r){
		int mid=(l+r)/2;
		int midl=l+(r-l)/3;
		int midr=l+(r-l)*2/3;
		int ansm=check3(mid,i,j);
		int ansl=check3(midl,i,j);
		int ansr=check3(midr,i,j);
		chkmax(res,max({ansm,ansl,ansr}));
		if(ansl>ansr){
			r=midr-1;
		}
		else{
			l=midl+1;
		}
	}
	rep(mid,max(l-C,i),min(l+C,j)){
		chkmax(res,check3(mid,i,j));
	}
	l=i,r=j;
	while(l<=r){
		int mid=(l+r)/2;
		int midl=l+(r-l)/3;
		int midr=l+(r-l)*2/3;
		int ansm=check4(mid,i,j);
		int ansl=check4(midl,i,j);
		int ansr=check4(midr,i,j);
		chkmax(res,max({ansm,ansl,ansr}));
		if(ansl>ansr){
			r=midr-1;
		}
		else{
			l=midl+1;
		}
	}
	rep(mid,max(l-C,i),min(l+C,j)){
		chkmax(res,check4(mid,i,j));
	}
	l=i,r=j-1;
	while(l<=r){
		int mid=(l+r)/2;
		int midl=l+(r-l)/3;
		int midr=l+(r-l)*2/3;
		int ansm=check5(mid,i,j);
		int ansl=check5(midl,i,j);
		int ansr=check5(midr,i,j);
		chkmax(res,max({ansm,ansl,ansr}));
		if(ansl>=ansr){
			r=midr-1;
		}
		else{
			l=midl+1;
		}
	}
	rep(mid,max(l-C,i),min(l+C,j-1)){
		chkmax(res,check5(mid,i,j));
	}
	return res;
}

int check6(int i){
	int ans=INF;
	int l=i+1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		int midl=l+(r-l)/3;
		int midr=l+(r-l)*2/3;
		int ansm=check2(i,mid);
		int ansl=check2(i,midl);
		int ansr=check2(i,midr);
		chkmin(ans,min({ansm,ansl,ansr}));
		if(ansl<ansr){
			r=midr-1;
		}
		else{
			l=midl+1;
		}
	}
	rep(a,max(l-B,i+1),min(l+B,n)){
		chkmin(ans,check2(i,a));
	}
	return ans;
}

inline void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>p[i].fir>>p[i].sec;
	}
	rep(i,1,n-1){
		sum[i+1]=dis(i,i+1)+sum[i];
		st[i][0]=dis(i,i+1);
	}
	for(int j=1;(1<<j)<n;j++){
		for(int i=1;i+(1<<j)-1<n;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
	int ans=INF;
	int l=1,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		int midl=l+(r-l)/3;
		int midr=l+(r-l)*2/3;
		int ansm=check6(mid);
		int ansl=check6(midl);
		int ansr=check6(midr);
		chkmin(ans,min({ansm,ansl,ansr}));
		if(ansl<ansr){
			r=midr-1;
		}
		else{
			l=midl+1;
		}
	}
	rep(a,max(l-A,1ll),min(l+A,n-1)){
		chkmin(ans,check6(a));
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

