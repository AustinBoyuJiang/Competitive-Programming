/*
 * Author: Austin Jiang
 * Date: 2/25/2023 12:44:18 AM
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

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using PPI = pair<PI,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using VEC = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace FastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<class T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<class T> inline void write(T x,char let) {write(x),putchar(let);}
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

/* Commonly used constants variables, functions, and data structures */
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#ifndef int
const int INF = 0x3f3f3f3f;
#else
const ll INF = LLINF;
#endif
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
const unordered_set<char> vowel = {'a','e','i','o','u'};

namespace Comfun{
	template<class T> inline T lowbit(T x){return x&-x;}
	template<class T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<class T> inline T qpow(T a,T b){
	T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<class T> inline T inv(T x){return qpow(x,MOD-2);}
	template<class T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace Comfun;

template<class T> struct Fenwick{
	int n; VEC<array<T,2>> d;
	Fenwick(int n){d.resize(this->n=n);}
	inline T query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	inline T ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
	inline void update(int x,int v){for(int i=x;i<=n;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	inline void add(int x,int y,int v){update(x,v),update(y+1,-v);}
	inline void add(int x,int v){add(x,x,v);}
};

/* ========================================| Main Program |======================================== */

const int N = 2e5+10;

int n;
ll l,r;
char a[N];
string b[N];

struct node{
	char ch;
	ll siz;
	node *lc,*rc;
	
	void find(ll l,ll r){
		chkmax(l,1ll);
		chkmin(r,this->siz);
		if(l>r) return;
		if(this->ch!=' '){
			cout<<ch;
			return;
		}
		this->lc->find(l,r);
		this->rc->find(l-this->lc->siz,r-this->lc->siz);
	}
} *lst[30];

void SOLVE(int Case){
	cin>>l>>r>>n;
	rep(i,1,n) cin>>a[i]>>b[i];
	rep(i,1,26) lst[i]=new node{'a'+i-1,1,nullptr,nullptr};
	per(i,n,1){
		node *u=nullptr;
		for(char x:b[i]){
			if(u==nullptr) u=lst[x-'a'+1];
			else u=new node{' ',min(LLINF,u->siz+lst[x-'a'+1]->siz),u,lst[x-'a'+1]};
		}
		lst[a[i]-'a'+1]=u;
	}
	lst[1]->find(l,r);
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
		cout<<"Case #"<<i<<": "<<endl;
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
    * Debug: (c) duipai
*/

