/*
 * Author: Austin Jiang
 * Date: 8/7/2025 11:11:34 PM
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

const int N = 2e5+10;

int n,k,a[N],b[N];

bool check(VI& v, int lo, int hi) {
    if (v.empty() || lo > hi) return false;
    auto it = lb(all(v), lo);
    return it != v.end() && *it <= hi;
}

int get(set<int>& S, int x) {
    auto it = S.lb(-x);
    return it == S.end() ? INT_MAX : x + *it;
}

inline void SOLVE(int Case){
	cin>>n>>k;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
	}
	rep(i,1,n){
		int mx=max(a[i],b[i]);
		int mn=min(a[i],b[i]);
		a[i]=mx;
		b[i]=mn;
	}
	bool ok=1;
	
	vector<pair<int,int>> seg;
	seg.reserve(n);
	for (int i = 1; i <= n; ++i) seg.pb({b[i], a[i]});
	
	sort(all(seg),
	     [](PI &x, PI &y){ return x.fir < y.fir; });
	
	int maxA = -INT_MAX;
	
	for (size_t idx = 0; idx < seg.size(); ++idx) {
	    int curB = seg[idx].fir;
	    int curA = seg[idx].sec;
	    if (maxA >= curB) {
	        ok = false;
	        break;
	    }
	    maxA = max(maxA, curA);
	}	
	
	ll ans=0;
	rep(i,1,n){
		ans+=abs(a[i]-b[i]);
	}
	if(!ok){
		cout<<ans<<endl;
		return;
	}
	set<int> s1,s2;
	int mn=INT_MAX;
	rep(i,1,n){
		if(i>1){
			int x1=a[i]+b[i]-(max(a[i],b[i])-min(a[i],b[i]));
			int x2=-a[i]-b[i]-(max(a[i],b[i])-min(a[i],b[i]));
			mn=min(mn,min(get(s1,x1),get(s2,x2)));
		}
		s1.insert(-a[i]-b[i]-(max(a[i],b[i])-min(a[i],b[i])));
		s2.insert(a[i]+b[i]-(max(a[i],b[i])-min(a[i],b[i])));
	}
//	cout<<ans<<" "<<mn<<endl;
	if (mn == INT_MAX) {
	    cout << ans << '\n';
	} else {
	    cout << ans + mn << '\n';
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

