/*
 * Author: Austin Jiang
 * Date: 5/18/2025 2:46:13 AM
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

const int N = 1e5+10;

int n,q,a[N],mx[N],mn[N],dp[N],val[N];

struct Fenwick2DMax { //sourced by GPT
    using Val = int;
    int X, Y;

    struct Node {
        vector<int> ys;
        vector<Val> bit;
    };
    vector<Node> tree;

    explicit Fenwick2DMax(int X_MAX, int Y_MAX)
        : X(X_MAX), Y(Y_MAX), tree(X_MAX + 1) {}

    void reserve_point(int x, int y) {
        for (int ix = x; ix <= X; ix += ix & -ix)
            tree[ix].ys.push_back(y);
    }

    void build() {
        for (auto &nd : tree) {
            auto &v = nd.ys;
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            nd.bit.assign(v.size() + 1, 0);
        }
    }

    static int idx_exact(const vector<int>& ys, int y) {
        return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
    }
    static int idx_prefix(const vector<int>& ys, int y) { 
        return int(upper_bound(ys.begin(), ys.end(), y) - ys.begin());
    }

    void update(int x, int y, Val v) {
        for (int ix = x; ix <= X; ix += ix & -ix) {
            Node &nd = tree[ix];
            for (int iy = idx_exact(nd.ys, y); iy < (int)nd.bit.size(); iy += iy & -iy)
                nd.bit[iy] = max(nd.bit[iy], v);
        }
    }

    Val query(int x, int y) const {
        Val ans = 0;
        for (int ix = x; ix > 0; ix -= ix & -ix) {
            const Node &nd = tree[ix];
            int iy = idx_prefix(nd.ys, y);
            while (iy > 0) {
                ans = max(ans, nd.bit[iy]);
                iy -= iy & -iy;
            }
        }
        return ans;
    }
};

inline void SOLVE(int Case){
	cin>>n>>q;
	rep(i,1,n){
		cin>>a[i];
		mx[i]=mn[i]=a[i];
	}
	rep(i,1,q){
		int p,v;
		cin>>p>>v;
		chkmax(mx[p],v);
		chkmin(mn[p],v);
	}
    Fenwick2DMax ft(1e5, 1e5);
    rep(i,1,n){
    	ft.reserve_point(mn[i],a[i]);
		ft.reserve_point(a[i],mx[i]);
	}
	ft.build();
	int ans=0;
	dp[1]=1;
	rep(i,1,n){
		dp[i]=1;
//		rep(j,1,i-1){
//			if(mn[i]>=a[j]&&a[i]>=mx[j]){
//				chkmax(dp[i],dp[j]+1);
//			}
//		}
//		rep(j,1,mn[i]){
//			chkmax(dp[i],val[j]+1);
//		}
//		chkmax(val[mx[i]],dp[i]);
		dp[i]=ft.query(mn[i],a[i])+1;
		ft.update(a[i],mx[i],dp[i]);
		chkmax(ans,dp[i]);
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

