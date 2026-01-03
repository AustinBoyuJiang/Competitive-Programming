/*
 * Author: Austin Jiang
 * Date: 1/29/2025 9:39:13 AM
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
#define random(a,b) rng()%(b-a+1)+a

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

const int N = 5e5+10;
const int A = N*20;

int n,a[N],p[N][2],sum[N][2];

struct segtree{
	struct node{
		int val,lc,rc;
	} st[N*20];
	
	int root=0,tot=0;
	
	void update(int &rt,int l,int r,int x,int y){
		if(!rt) rt=++tot;
		st[rt].val+=y;
		if(l==r) return;
		int mid=l+r>>1;
		if(x<=mid) update(st[rt].lc,l,mid,x,y);
		else update(st[rt].rc,mid+1,r,x,y);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(!rt) return 0;
		if(l==x&&r==y) return st[rt].val;
		int mid=l+r>>1;
		if(y<=mid) return query(st[rt].lc,l,mid,x,y);
		else if(x>mid) return query(st[rt].rc,mid+1,r,x,y);
		return query(st[rt].lc,l,mid,x,mid)+query(st[rt].rc,mid+1,r,mid+1,y);
	}
} dif1,dif2,cnt;

inline void SOLVE(int Case){
	cin>>n;
	int ans=0;
	rep(i,1,n){
		cin>>a[i];
		int cnt10=0;
		while(a[i]%10==0){
			a[i]/=10;
			cnt10++;
		}
		while(a[i]%2==0){
			a[i]/=2;
			p[i][0]++;
		}
		while(a[i]%5==0){
			a[i]/=5;
			p[i][1]++;
		}
		ans+=cnt10*i*(n-i+1);
		sum[i][0]=sum[i-1][0]+p[i][0];
		sum[i][1]=sum[i-1][1]+p[i][1];
	}
	per(i,n,1){
		int pos1=sum[i][0]-sum[i][1];
		int pos2=sum[i-1][0]-sum[i-1][1];
		dif1.update(dif1.root,-A,A,pos1,sum[i][0]);
		dif2.update(dif2.root,-A,A,pos1,sum[i][1]);
		cnt.update(cnt.root,-A,A,pos1,1);
		ans+=dif1.query(dif1.root,-A,A,-A,pos2-1);
		ans+=dif2.query(dif2.root,-A,A,pos2,A);
		int res=cnt.query(cnt.root,-A,A,-A,pos2-1);
		ans-=res*sum[i-1][0];
		ans-=(n-i+1-res)*sum[i-1][1];
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

