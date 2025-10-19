/*
 * Author: Austin Jiang
 * Date: 12/1/2023 11:50:42 AM
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
	inline int mex(VI s){sort(all(s));int j=0;rep(i,0,s[s.size()-1]+1){
	while(j<s.size()&&s[j]<i) j++;if(s[j]!=i) return i;}}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false;return true;}
	template<class T> inline void disc(Vec<T> &v,int st=0){set<int> num;Vec<T> pos;
	for(T x:v)num.insert(x);for(T x:num)pos.pb(x);for(T &x:v) x=lb(all(pos),x)-pos.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 2e5+1;
const int LG = 18;

int n,q,sp[N],id[2],l[N],r[N],to[N][LG],fr[N][LG],dep[N],sum[N][LG],invsum[N][LG],laysum[N];
char a[N<<1];
VI e[N],lay[N];

struct Segtree_sum{
	int st[N<<3],lazy[N<<3];
	
	inline void push_down(int rt,int l,int mid,int r){
		if(lazy[rt]){
			chkmax(lazy[lc],lazy[rt]);
			chkmax(lazy[rc],lazy[rt]);
			chkmax(st[lc],lazy[rt]);
			chkmax(st[rc],lazy[rt]);
			lazy[rt]=0;
		}
	}
	
	inline void update(int rt,int l,int r,int x,int y,int val){
		if(l==x&&r==y){
			st[rt]=val;
			lazy[rt]=val;
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(lc,l,mid,x,y,val);
		else if(x>mid) update(rc,mid+1,r,x,y,val);
		else update(lc,l,mid,x,mid,val),update(rc,mid+1,r,mid+1,y,val);
		st[rt]=max(st[lc],st[rc]);
	}
	
	inline int query(int rt,int l,int r,int x){
		if(l==r) return st[rt];
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(x<=mid) return query(lc,l,mid,x);
		else return query(rc,mid+1,r,x);
	}
	
	inline void upd(int l,int r,int val){update(1,1,n*2,l,r,val);}
	inline int get(int x){return query(1,1,n*2,x);}
} st;

inline void dfs(int u){
	dep[u]=dep[to[u][0]]+1;
	lay[dep[u]].pb(u);
	laysum[dep[u]]+=sp[u];
	for(int v:e[u]){
		dfs(v);
	}
}

inline void SOLVE(int Case){
	cin>>n>>q;
	rep(i,1,n*2){
		cin>>a[i];
		if(a[i]=='L'){
			id[0]++;
			l[id[0]]=i;
		}
		else{
			id[1]++;
			r[id[1]]=i;
			st.upd(l[id[1]],r[id[1]],id[1]);
		}
	}
	per(i,n-1,1){
		to[i][0]=st.get(r[i]);
		fr[to[i][0]][0]=i;
		rep(j,1,LG-1){
			to[i][j]=to[to[i][j-1]][j-1];
		}
	}
	rep(i,1,n){
		char x;
		cin>>x;
		sp[i]=x-'0';
		e[to[i][0]].pb(i);
	}
	dfs(n);
	per(i,n,1) if(!fr[i][0]&&dep[i]==dep[i+1])
		fr[i][0]=fr[i+1][0];
	rep(i,1,n){
		rep(j,1,LG-1) fr[i][j]=fr[fr[i][j-1]][j-1];
		laysum[i]+=laysum[i-1];
		if(lay[i].empty()) continue;
		sum[lay[i][0]][0]=sp[lay[i][0]];
		invsum[lay[i][0]][0]=0;
		for(int j=1;j<lay[i].size();j++){
			sum[lay[i][j]][0]=sum[lay[i][j-1]][0]+sp[lay[i][j]];
			invsum[lay[i][j]][0]=sum[lay[i][j-1]][0];
		}
	}
	per(i,n,1)rep(j,1,LG-1)
		sum[i][j]=sum[i][j-1]+sum[to[i][j-1]][j-1];
	rep(i,1,n) rep(j,1,LG-1)
		invsum[i][j]=invsum[i][j-1]+invsum[fr[i][j-1]][j-1];
	rep(i,1,q){
		int s,t;
		cin>>s>>t;
		int d=s;
		per(i,LG-1,0){
			if(to[d][i]==0) continue;
			if(dep[to[d][i]]<dep[t]) continue;
			d=to[d][i];
		}
		int res=sp[s]+sp[t];
		int x=s,y=t;
		per(i,LG-1,0){
			if(to[x][i]==0) continue;
			if(d<t&&dep[to[x][i]]<dep[t]) continue;
			if(d>=t&&dep[to[x][i]]<=dep[t]) continue;
			res+=sum[to[x][0]][i];
			x=to[x][i];
		}
		per(i,LG-1,0){
			if(fr[y][i]==0) continue;
			if(d<t&&dep[fr[y][i]]>dep[s]) continue;
			if(d>=t&&dep[fr[y][i]]>=dep[s]) continue;
			res-=invsum[fr[y][0]][i];
			y=fr[y][i];
		}
		if(d<t) res+=laysum[dep[y]]-laysum[dep[t]];
		cout<<dep[s]-dep[t]+(d<t)<<" "<<res<<endl;
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

