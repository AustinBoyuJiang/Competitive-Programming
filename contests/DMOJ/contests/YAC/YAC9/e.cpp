/*
 * Author: Austin Jiang
 * Date: 1/17/2025 11:53:40 PM
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
//#define FASTIO
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

const int N = 110;

int n;
VPI s,t;
Vec<pair<PI,PI>> ans;

bool check(VPI a,VPI b){
	if(a.size()!=b.size()) return 0;
	sort(all(a));
	sort(all(b));
	rep(i,0,(int)a.size()-1){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}

PI diff1(VPI a,VPI b,VPI c){
	set<PI> s,ss;
	for(PI edge:b){
		s.insert(edge);
	}
	for(PI edge:c){
		ss.insert(edge);
	}
	for(PI edge:a){
		if(s.find(edge)==s.end()&&ss.find(edge)==ss.end()){
			return edge;
		}
	}
	for(PI edge:a){
		if(s.find(edge)==s.end()){
			return edge;
		}
	}
	return a[random(0,(int)a.size()-1)];
}

PI diff2(VPI a,VPI b){
	set<PI> s;
	for(PI edge:b){
		s.insert(edge);
	}
	for(PI edge:a){
		if(s.find(edge)==s.end()){
			return edge;
		}
	}
	return {0,0};
}

int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	if(find(x)==find(y)) return;
	f[find(x)]=find(y);
}

VI e[N];
bool add_path(int u,int fa,int tar,VPI &arr){
	if(u==tar) return 1;
	for(int v:e[u]){
		if(v==fa) continue;
		int res=add_path(v,u,tar,arr);
		if(res){
			arr.pb({min(u,v),max(u,v)});
			return 1;
		}
	}
	return 0;
}

VPI get(VPI g){
	VPI cyc;
	rep(i,1,n){
		e[i].clear();
		f[i]=i;
	}
	int p,q;
	for(PI edge:g){
		int u,v;
		tie(u,v)=edge;
		if(find(u)==find(v)){
			tie(p,q)=edge;
			cyc.pb(edge);
			continue;
		}
		merge(u,v);
		e[u].pb(v);
		e[v].pb(u);
	}
	add_path(p,0,q,cyc);
	return cyc;
}

inline void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		int u,v;
		cin>>u>>v;
		s.pb({min(u,v),max(u,v)});
	}
	rep(i,1,n){
		int u,v;
		cin>>u>>v;
		t.pb({min(u,v),max(u,v)});
	}
//	VPI cyc1=get(s);
//	for(PI edge:cyc1){
//		cout<<edge.fir<<"-"<<edge.sec<<endl;
//	}
//	VPI cyc2=get(t);
//	for(PI edge:cyc2){
//		cout<<edge.fir<<" "<<edge.sec<<endl;
//	}
//	PI ee=diff(cyc1,cyc2);
//	cout<<ee.fir<<" "<<ee.sec<<endl;
//	return;
	while(!check(s,t)){
//	rep(i,1,3){
		VPI cyc1=get(s);
		VPI cyc2=get(t);
		int a,b,c,d;
		tie(a,b)=diff1(cyc1,cyc2,t);
		tie(c,d)=diff1(t,s,cyc2);
		rep(i,0,(int)s.size()-1){
			if(s[i]==make_pair(min(a,b),max(a,b))){
				s.erase(s.begin()+i);
				break;
			}
		}
		s.pb({min(c,d),max(c,d)});
		ans.pb({{a,b},{c,d}});
//		pair<PI,PI> opt={{a,b},{c,d}};
//		cout<<opt.fir.fir<<" "<<opt.fir.sec<<" "<<opt.sec.fir<<" "<<opt.sec.sec<<endl;
	}
	cout<<ans.size()<<endl;
	for(auto opt:ans){
		cout<<opt.fir.fir<<" "<<opt.fir.sec<<" "<<opt.sec.fir<<" "<<opt.sec.sec<<endl;
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

