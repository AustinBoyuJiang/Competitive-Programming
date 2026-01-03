/*
 * Author: Austin Jiang
 * Date: 7/28/2024 9:02:23 AM
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
const int Z = 316;

int n,q,res=0,a[N];
bool ans[N];
multiset<int> s;
vector<vector<bool>> choice;
vector<bool> cur(6);

struct Queue{
	int l,r,id;
} p[N];

VI v;

int check(int pos){
	cout<<"--->"<<endl;
	rep(i,0,5){
		cout<<v[pos+i]<<" ";
	} cout<<endl;
	for(vector<bool> d:choice){
		VI par[2];
		rep(i,0,5){
			par[d[i]].pb(v[pos+i]);
		}
		sort(all(par[0]));
		sort(all(par[1]));
		if(par[0][0]+par[0][1]<=par[0][2]) continue;
		if(par[1][0]+par[1][1]<=par[1][2]) continue;
		cout<<1<<endl;
		return 1;
	}
	cout<<0<<endl;
	return 0;
}

void add(int x){
	auto itr=s.insert(a[x]);
	if(s.size()<6) return;
	auto itr2=itr;
	v.clear();
	rep(i,1,5){
		if(itr==s.begin()) break;
		itr--;
		v.pb(*itr);
	}
	reverse(all(v));
	rep(i,1,6){
		v.pb(*itr2);
		itr2++;
		if(itr2==s.end()) break;
	}
//	rep(i,1,(int)v.size()-5){
//		res+=check(i-1);
//	}
}

void remove(int x){
	auto itr=s.find(a[x]);
	if(s.size()<6) return;
	auto itr2=itr;
	auto itr3=itr;
	v.clear();
	rep(i,1,5){
		if(itr==s.begin()) break;
		itr--;
		v.pb(*itr);
	}
	reverse(all(v));
	rep(i,1,6){
		v.pb(*itr2);
		itr2++;
		if(itr2==s.end()) break;
	}
//	for(int x:v){
//		cout<<x<<" ";
//	} cout<<endl;
//	rep(i,1,(int)v.size()-5){
//		res-=check(i-1);
//	}
	s.erase(itr3);
}

void dfs(int pos,int rem0,int rem1){
	if(pos==6){
		choice.pb(cur);
		return;
	}
	if(rem0){
		cur[pos]=0;
		dfs(pos+1,rem0-1,rem1);
	}
	if(rem1){
		cur[pos]=1;
		dfs(pos+1,rem0,rem1-1);
	}
}

bool check2(){
	v.clear();
	for(int x:s){
		v.pb(x);
	}
	cout<<"=========="<<endl;
	for(int x:v){
		cout<<x<<" ";
	} cout<<endl;
	bool ok=0;
	rep(i,0,(int)v.size()-6){
		ok|=check(i);
	}
	return ok;
}

inline void SOLVE(int Case){
	dfs(0,3,3);
	cin>>n>>q;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,q){
		cin>>p[i].l;
		cin>>p[i].r;
		p[i].id=i;
	}
	sort(p+1,p+q+1,[](Queue a,Queue b){
		if(a.l/Z==b.l/Z){
			if((a.l/Z)%2) return a.r>b.r;
			else return a.r<b.r;
		}
		return a.l/Z<b.l/Z;
	});
	int l=p[1].l,r=p[1].l-1;
	rep(i,1,q){
		while(l>p[i].l) add(--l);
		while(r<p[i].r) add(++r);
		while(l<p[i].l) remove(l++);
		while(r>p[i].r) remove(r--);
		ans[p[i].id]=check2();
	}
	rep(i,1,q){
		if(ans[i]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
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

