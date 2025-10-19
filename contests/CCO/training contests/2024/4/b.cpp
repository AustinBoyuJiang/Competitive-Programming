/*
 * Author: Austin Jiang
 * Date: 4/19/2024 8:27:17 PM
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

const int N = 2e5+10;

int n,q,st,ed,dep[N],flag[N],pos[N],id[N];
Vec<array<int,4>> tps;
VI e[N],rt[N];
bool xall0=1;

struct query{
	int x,y,z;
} que[N];

int dfs(int u,int fa,int depth,int root=0){
	dep[u]=depth;
	if(root) rt[root][depth]=u;
	int res=dep[u];
	for(int v:e[u]){
		if(v==fa) continue;
		if(flag[v]) continue;
		res=max(res,dfs(v,u,depth+1,root));
	}
	return res;
}

int furthest(int st){
	dfs(st,0,0);
	int res=st;
	rep(i,1,n){
		if(dep[i]>dep[res]){
			res=i;
		}
	}
	return res;
}

void flag_path(int u,int fa){
	for(int v:e[u]){
		if(v==fa) continue;
		flag_path(v,u);
		flag[u]|=flag[v];
	}
}

bool solve(int a,int b,int c,int k){
	for(auto tp:tps){
		if(a<=tp[0]&&b<=tp[1]&&c<=tp[2]){
			int u=tp[3];
			int A=id[pos[u]-a];
			int B=id[pos[u]+b];
			int C=rt[u][c];
			if(k==0) cout<<A<<" "<<B<<" "<<C<<endl;
			if(k==1) cout<<A<<" "<<C<<" "<<B<<endl;
			if(k==2) cout<<B<<" "<<A<<" "<<C<<endl;
			if(k==3) cout<<C<<" "<<A<<" "<<B<<endl;
			if(k==4) cout<<B<<" "<<C<<" "<<A<<endl;
			if(k==5) cout<<C<<" "<<B<<" "<<A<<endl;
			return 1;
		}
		if(xall0) break;
	}
	return 0;
}

bool solve1(int a,int b,int c,int k){
	int l=0,r=(int)tps.size()-1,res=(int)tps.size();
	while(l<=r){
		int mid=l+r>>1;
		if(a<=tps[mid][0]){
			r=mid-1;
			res=mid;
		}
		else{
			l=mid+1;
		}
	}
	l=res,r=(int)tps.size()-1;
	int res2=(int)tps.size();
	while(l<=r){
		int mid=l+r>>1;
		if(b<=tps[mid][1]){
			res2=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	rep(i,res,res2){
		auto tp=tps[i];
		if(a<=tp[0]&&b<=tp[1]&&c<=tp[2]){
			int u=tp[3];
			int A=id[pos[u]-a];
			int B=id[pos[u]+b];
			int C=rt[u][c];
			if(k==0) cout<<A<<" "<<B<<" "<<C<<endl;
			if(k==1) cout<<A<<" "<<C<<" "<<B<<endl;
			if(k==2) cout<<B<<" "<<A<<" "<<C<<endl;
			if(k==3) cout<<C<<" "<<A<<" "<<B<<endl;
			if(k==4) cout<<B<<" "<<C<<" "<<A<<endl;
			if(k==5) cout<<C<<" "<<B<<" "<<A<<endl;
			return 1;
		}
	}
	return 0;
}

inline void SOLVE(int Case){
	cin>>n;
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	st=furthest(1);
	ed=furthest(st);
	flag[ed]=1;
	flag_path(st,0);
	int u=st,fa=0,left=0,right=dep[ed];
	bool linear=1;
	while(true){
		pos[u]=left;
		id[left]=u;
		int far=dfs(u,0,0);
		if(far) linear=0;
		VI ord={left,right,far};
//		sort(all(ord));
		tps.pb({ord[0],ord[1],ord[2],u});
		rt[u].resize(far+1);
		dfs(u,0,0,u);
		if(u==ed) break;
		for(int v:e[u]){
			if(v==fa) continue;
			if(!flag[v]) continue;
			fa=u;
			u=v;
			break;
		}
		left++;
		right--;
	}
	cin>>q;
	rep(i,1,q){
		cin>>que[i].x>>que[i].y>>que[i].z;
		if(que[i].x) xall0=0;
	}
	if(linear) sort(all(tps));
	rep(i,1,q){
		int x=que[i].x;
		int y=que[i].y;
		int z=que[i].z;
		int a=(x+y-z)/2;
		int b=(x+z-y)/2;
		int c=(y+z-x)/2;
		assert(a+b==x);
		assert(b+c==z);
		assert(a+c==y);
		if(linear){
			if(a==0){
				solve1(b,c,a,3)||
				solve1(c,b,a,5);
			}
			else if(b==0){
				solve1(a,c,b,1)||
				solve1(c,a,b,4);
			}
			else{
				solve1(a,b,c,0)||
				solve1(b,a,c,2);
			}
		}
		else{
			solve(a,b,c,0)||
			solve(a,c,b,1)||
			solve(b,a,c,2)||
			solve(b,c,a,3)||
			solve(c,a,b,4)||
			solve(c,b,a,5);
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

