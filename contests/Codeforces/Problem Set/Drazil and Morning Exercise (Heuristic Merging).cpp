/*
 * Author: Austin Jiang
 * Date: 6/8/2023 11:35:59 AM
 * Problem: Drazil and Morning Exercise
 * Source:
 * Description: O(n*log(n)^2)
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
//#define FASTIO
#define OPTIMIZE
//#define INTTOLL

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
using PI = pair<ll,int>;
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
	template<class T> inline T qpow(T a,T b){T ans=1;while(b){if(b&1)ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0) /*discretize*/ {Vec<T> num=v;sort(all(num));
	for(T &x:v) x=lb(all(num),x)-num.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 1e5+10;

int n,q,ans,hd1,hd2,root,res[N],fa[N],siz[N],hson[N];
ll lim,val[N],dist[3][N];
set<PI> *pt[N],*ptt[N];
VPI e[N];

inline void diameter(int u,int fa,int w,int &head,int k){
	dist[k][u]=dist[k][fa]+w;
	if(k<2&&dist[k][u]>dist[k][head]) head=u;
	for(PI edge:e[u]){
		int v=edge.fir;
		if(v==fa) continue;
		diameter(v,u,edge.sec,head,k);
	}
}

inline void init(int u,int father){
	fa[u]=father;
	siz[u]=1;
	for(PI edge:e[u]){
		int v=edge.fir;
		if(v==father) continue;
		init(v,u);
		siz[u]+=siz[v];
		if(!hson[u]||siz[v]>siz[hson[u]]){
			hson[u]=v;
		}
	}
}

inline void merge(int x,int y){
	res[x]+=res[y];
	while(!(*pt[y]).empty()){
		auto it=(*pt[y]).begin();
		(*pt[x]).insert(*it);
		(*pt[y]).erase(it);
	}
}

inline void dfs(int u){
	if(hson[u]){
		dfs(hson[u]);
		pt[u]=pt[hson[u]];
		res[u]=res[hson[u]]+1;
	}
	else{
		(*pt[u]).insert({-val[u],u});
		res[u]=1;
	}
	for(PI edge:e[u]){
		int v=edge.fir;
		if(v==fa[u]||v==hson[u]) continue;
		dfs(v);
		merge(u,v);
	}
	while(!(*pt[u]).empty()){
		auto it=(*pt[u]).begin();
		PI node=*it;
		if(-node.fir-val[u]>lim){
			(*pt[u]).erase(it);
			(*pt[u]).insert({-val[fa[node.sec]],fa[node.sec]});
			res[u]--;
		}
		else break;
	}
	chkmax(ans,res[u]);
}

inline void SOLVE(int Case){
	read(n);
	rep(i,1,n-1){
		int u=read(),v=read(),w=read();
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
	diameter(1,0,0,hd1,0);
	diameter(hd1,0,0,hd2,1);
	diameter(hd2,0,0,hd2,2);
	rep(i,1,n){
		val[i]=max(dist[1][i],dist[2][i]);
		if(!root||val[i]<val[root]) root=i;
		ptt[i]=new set<PI>();
	}
	read(q);
	init(root,0);
	rep(i,1,q){
		lim=readLL();
		rep(j,1,n){
			(*ptt[j]).clear();
			pt[j]=ptt[j];
		}
		ans=0;
		dfs(root);
		write(ans,endl);
	}
}

/* =====================================| End of Main Program |===================================== */

signed main(){
	#ifdef SETMEM
    int size(256<<20);  //512MB
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

