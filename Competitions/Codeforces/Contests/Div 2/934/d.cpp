/*
 * Author: Austin Jiang
 * Date: 3/16/2024 7:59:34 AM
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
//#define NDEBUG
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

const int N = 1e6+10;
const int base=121;
const int base2=131;

int n,q,same[N],same2[N];
int HASHl[N],HASHr[N],basepow[N];
int HASHl2[N],HASHr2[N],basepow2[N];
char a[N];

void init(){
	HASHl[0]=0;
	rep(i,1,n){
		HASHl[i]=HASHl[i-1]*base%MOD+(a[i]-'a');
		HASHl[i]%=MOD;
	}
	HASHr[n+1]=0;
	per(i,n,1){
		HASHr[i]=HASHr[i+1]*base%MOD+(a[i]-'a');
		HASHr[i]%=MOD;
	}
//	cout<<HASHl[3]<<" "<<(HASHr[1]-HASHr[4])*inv(base)%MOD<<endl;
	basepow[0]=1;
	rep(i,1,n){
		basepow[i]=basepow[i-1]*base%MOD;
	}
}

void init2(){
	HASHl2[0]=0;
	rep(i,1,n){
		HASHl2[i]=HASHl2[i-1]*base2%MOD+(a[i]-'a');
		HASHl2[i]%=MOD;
	}
	HASHr2[n+1]=0;
	per(i,n,1){
		HASHr2[i]=HASHr2[i+1]*base2%MOD+(a[i]-'a');
		HASHr2[i]%=MOD;
	}
	basepow2[0]=1;
	rep(i,1,n){
		basepow2[i]=basepow2[i-1]*base2%MOD;
	}
}

int qqpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=MOD;
		}
		a*=a;
		a%=MOD;
		b>>=1; 
	}
	return ans;
}

int check(int l,int r){
	int aa=(HASHl[r]-HASHl[l-1]*basepow[r-l+1]%MOD+MOD)%MOD;
	int bb=(HASHr[l]-HASHr[r+1]*basepow[r-l+1]%MOD+MOD)%MOD;
//	cout<<aa<<" "<<bb<<endl;
	return aa==bb;
}

int check2(int l,int r){
	int aa=(HASHl2[r]-HASHl2[l-1]*basepow2[r-l+1]%MOD+MOD)%MOD;
	int bb=(HASHr2[l]-HASHr2[r+1]*basepow2[r-l+1]%MOD+MOD)%MOD;
	return aa==bb;
}

inline void SOLVE(int Case){
	cin>>n>>q;
	rep(i,1,n){
		cin>>a[i];
		same[i]=same[i-1]+(a[i]!=a[i-1]);
		if(i>1) same2[i]=same2[i-1]+(a[i]!=a[i-2]);
	}
	init();
	init2();
	//如果交替: 减去单数 
	//全部一样：减去全部 
	rep(i,1,q){
		int l,r;
		cin>>l>>r;
		int res1=same[r]-same[l];
		int res2=same2[r]-same2[l+1];
		if(!res1){
			cout<<0<<endl;
			continue;
		}
		if(!res2){
			int k=r-l+1;
			if(k%2==1) k--;
			cout<<(2+k)*(k/2)/2<<endl;
			continue;
		}
		int add=0;
		if(check(l,r)&&check2(l,r)){
			add=r-l+1;
		}
		int k=r-l+1;
		cout<<(2+k)*(k-1)/2-add<<endl;
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

