/*
 * Author: Austin Jiang
 * Date: 4/27/2025 2:08:20 AM
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

const int N = 1e5+10;

int n,q,a[N],sum[N];

struct segment_tree{
	
	struct node{
		int mx,cnt,sum=0,lazy_cnt=0,val=-INF;
	} st[N<<2];
	
	node merge(node a,node b){
		node res;
		if(a.mx>b.mx){
			res.mx=a.mx;
			res.cnt=a.cnt;
		}
		else{
			res.mx=b.mx;
			res.cnt=b.cnt;
		}
		return res;
	}
	
	void push_up(int rt){
		node res=merge(st[rt<<1],st[rt<<1|1]);
		st[rt].mx=res.mx;
		st[rt].cnt=res.cnt;
	}
	
	void build(int rt,int l,int r){
		if(l==r){
			st[rt].mx=sum[l];
			st[rt].cnt=0;
			return;
		}
		int mid=l+r>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		push_up(rt);
	}
	
	void push_down(int rt,int l,int mid,int r){
		st[rt<<1].mx-=st[rt].sum;
		st[rt<<1|1].mx-=st[rt].sum;
		st[rt<<1].sum+=st[rt].sum;
		st[rt<<1|1].sum+=st[rt].sum;
		st[rt].sum=0;
		st[rt<<1].mx-=st[rt<<1].val*st[rt<<1].cnt;
		st[rt<<1|1].mx-=st[rt<<1|1].val*st[rt<<1|1].cnt;
		st[rt<<1].mx+=st[rt].val*st[rt].cnt;
		st[rt<<1|1].mx+=st[rt].val*st[rt].cnt;
		st[rt<<1].val=st[rt].val;
		st[rt<<1].cnt+=st[rt].lazy_cnt;
		st[rt<<1].lazy_cnt+=st[rt].lazy_cnt;
		st[rt<<1|1].val=st[rt].val;
		st[rt<<1|1].cnt+=st[rt].lazy_cnt;
		st[rt<<1|1].lazy_cnt+=st[rt].lazy_cnt;
		st[rt].lazy_cnt=0;
	}
	
	void update(int rt,int l,int r,int x,int y,int val){
		if(l==x&&r==y){
			st[rt].mx-=val;
			st[rt].mx+=st[rt].val;
			st[rt].sum+=val;
			st[rt].cnt++;
			st[rt].lazy_cnt++;
//			if(l<r){
//				push_down(rt,l,l+r>>1,r);
//				push_up(rt);
//			}
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(rt<<1,l,mid,x,y,val);
		else if(x>mid) update(rt<<1|1,mid+1,r,x,y,val);
		else{
			update(rt<<1,l,mid,x,mid,val);
			update(rt<<1|1,mid+1,r,mid+1,y,val);
		}
		push_up(rt);
	}
} t;

inline void SOLVE(int Case){
	cin>>n>>q;
	VPI val;
	rep(i,1,n){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		val.pb({a[i],i});
	}
	t.build(1,0,n);
	rep(i,1,7){
		cout<<i<<" "<<t.st[i].mx<<" "<<t.st[i].sum<<" "<<t.st[i].cnt<<" "<<t.st[i].val<<endl;
	}
	sort(all(val));
	int j=-1;
	rep(i,1,q){
		int opt;
		cin>>opt;
		if(opt==0){
			int x;
			cin>>x;
			chkmax(t.st[1].val,x);
			while(j+1<n&&val[j+1].fir<=x){
				j++;
				int pos=val[j].sec;
				t.update(1,0,n,pos,n,a[pos]);
			}
			rep(i,1,7){
				cout<<i<<" "<<t.st[i].mx<<" "<<t.st[i].sum<<" "<<t.st[i].cnt<<" "<<t.st[i].val<<endl;
			}
			cout<<"----------"<<endl;
		}
		else{
			cout<<t.st[1].mx<<endl;
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

