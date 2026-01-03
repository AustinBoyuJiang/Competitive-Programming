/*
 * Author: Austin Jiang
 * Date: 2/18/2024 2:20:20 PM
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

struct Segtree_max_interval{
	struct node{
		int mx,sum,ans,num;
	} st[N<<2];
	
	int lazy[N<<2],clean[N<<2];
	
	void clear(int rt){
		clean[rt]=1;
		st[rt].mx=0;
		st[rt].sum=0;
		st[rt].ans=0;
		st[rt].num=0;
		lazy[rt]=0;
	}
	
	void check(int rt,int l,int r,int val){
		st[rt].mx+=val;
		st[rt].sum+=val*(r-l+1);
		st[rt].ans+=(r-l+1)-st[rt].num;
		st[rt].ans*=qpow(3ll,val);
		st[rt].ans%=MOD;
		st[rt].num=r-l+1;
		lazy[rt]+=val;
	}
	
	void push_down(int rt,int l,int mid,int r){
		if(clean[rt]){
			clear(lc);
			clear(rc);
			clean[rt]=0;
		}
		if(!lazy[rt]) return;
		check(lc,l,mid,lazy[rt]);
		check(rc,mid+1,r,lazy[rt]);
		lazy[rt]=0;
	}
	
	void update(int rt,int l,int r,int x,int y,int val){
		if(l==x&&r==y){
			check(rt,l,r,val);
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(lc,l,mid,x,y,val);
		else if(x>mid) update(rc,mid+1,r,x,y,val);
		else update(lc,l,mid,x,mid,val),update(rc,mid+1,r,mid+1,y,val);
		st[rt].mx=max(st[lc].mx,st[rc].mx);
		st[rt].sum=st[lc].sum+st[rc].sum;
		st[rt].num=st[lc].num+st[rc].num;
		st[rt].ans=(st[lc].ans+st[rc].ans)%MOD;
	}
	
	void clear(int rt,int l,int r,int x,int y){
		if(l==x&&r==y){
			clear(rt);
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) clear(lc,l,mid,x,y);
		else if(x>mid) clear(rc,mid+1,r,x,y);
		else clear(lc,l,mid,x,mid),clear(rc,mid+1,r,mid+1,y);
		st[rt].mx=max(st[lc].mx,st[rc].mx);
		st[rt].sum=st[lc].sum+st[rt].sum;
		st[rt].num=st[lc].num+st[rc].num;
		st[rt].ans=st[lc].ans+st[rc].ans;
	}
	
	node merge(node a,node b){
		chkmax(a.mx,b.mx);
		a.sum+=b.sum;
		a.ans+=b.ans;
		a.num+=b.num;
		return a;
	}
	
	node query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return st[rt];
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return merge(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
	}
	
	void add(int l,int r,int val){
		if(!val) return;
		if(r<l) return;
		update(1,1,1e6,l,r,val);
	}
	
	void clear(int l,int r){
		if(r<l) return;
		clear(1,1,1e6,l,r);
	}
	
	node ask(int l,int r){
		if(r<l) return {0,0,0,0};
		return query(1,1,1e6,l,r);
	}
} cnt;

int n;
PI q[N],p[N];

bool check(int l,int r,int x){
	x+=cnt.ask(l,r).sum;
	int mid=l+x%(r-l+1)-1;
	if(cnt.ask(l,mid).mx>(x+(r-l+1)-1)/(r-l+1)) return 0;
	if(cnt.ask(mid+1,r).mx>x/(r-l+1)) return 0;
	return 1;
}

inline void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>q[i].fir>>q[i].sec;
	}
	rep(i,1,n){
		p[i]=q[i];
		sort(p+1,p+i+1);
		cnt.clear(1);
		int tot=0;
		rep(j,1,i){
			if(p[j].sec<=tot) continue;
			int left=p[j].sec-tot;
			int l=1,r=p[j].fir,pos=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid,p[j].fir,left)){
					pos=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			left+=cnt.ask(pos,p[j].fir).sum;
			cnt.clear(pos,p[j].fir);
			cnt.add(pos,p[j].fir,left/(p[j].fir-pos+1));
			cnt.add(pos,pos+left%(p[j].fir-pos+1)-1,1);
			tot=p[j].sec;
		}
		cout<<cnt.ask(1,p[i].fir).ans*inv(3ll)%MOD<<endl;
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

