/*
 * Author: Austin Jiang
 * Date: 1/12/2024 11:43:09 PM
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

struct flow_network{
	static const int V = 10;
	static const int E = 100;
	
	int S,T,inq[V],dist[V],vis[V];
	int tot=-1,head[V],h[V];
	
	flow_network(){
		memset(head,-1,sizeof(head));
	}
	
	struct edge{
		int to,flow,cost,nxt;
	} e[E<<1];
	
	void addd(int u,int v,int w,int c){
		e[++tot].to=v;
		e[tot].flow=w;
		e[tot].cost=c;
		e[tot].nxt=head[u];
		head[u]=tot;
	}
	
	int add(int u,int v,int w=INF,int c=0){
		addd(u,v,w,c);
		addd(v,u,0,-c);
		return tot;
	}
	
	bool SPFA(){
		for(int i=S;i<=T;i++){
			h[i]=head[i];
			dist[i]=INF;
		}
		queue<int> q;
		q.push(S);
		dist[S]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			inq[u]=0;
			for(int i=h[u];~i;i=e[i].nxt){
				int v=e[i].to,w=e[i].flow,c=e[i].cost;
				if(w&&dist[u]+c<dist[v]){
					dist[v]=dist[u]+c;
					if(!inq[v]){
						q.push(v);
						inq[v]=1;
					}
				}
			}
		}
		return dist[T]!=INF;
	}
	
	int DFS(int u,int flow){
		if(u==T) return flow;
		vis[u]=1;
		int ans=0;
		for(int &i=h[u];~i;i=e[i].nxt){
			int v=e[i].to,&w=e[i].flow,c=e[i].cost;
			if(!vis[v]&&w&&dist[v]==dist[u]+c){
				int res=DFS(v,min(w,flow));
				w-=res,e[i^1].flow+=res;
				flow-=res,ans+=res;
				if(!res) dist[v]=-1;
				if(!flow) break;
			}
		}
		vis[u]=0;
		return ans;
	}
	
	PI Dinic(){
		PI ans={0,0};
		while(SPFA()){
			int res=DFS(S,INF);
			ans.fir+=res;
			ans.sec+=res*dist[T];
		}
		return ans;
	}
} fn;

inline void SOLVE(int Case){
	int &S=fn.S=0;
	int &T=fn.T=9;
	rep(i,1,8){
		int x;
		cin>>x;
		fn.add(S,i,x);
	}
	rep(i,1,8){
		int x;
		cin>>x;
		fn.add(i,T,x);
	}
	fn.add(1,3);
	fn.add(1,5);
	fn.add(1,7);
	fn.add(3,7);
	fn.add(5,7);
	fn.add(1,2);
	fn.add(1,4);
	fn.add(2,4);
	fn.add(3,4);
	fn.add(1,6);
	fn.add(2,6);
	fn.add(5,6);
	rep(v,1,7){
		fn.add(v,8);
	}
	int ans=fn.Dinic().fir;
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

