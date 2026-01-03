/*
 * Author: Austin Jiang
 * Date: 1/18/2023 12:12:52 PM
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

/* STL Data Structures */
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
template <typename T> using VEC = vector<T>;
template <typename T> using US = unordered_set<T>;
template <typename T> using MS = multiset<T>;
template <typename T1, typename T2> using UM = unordered_map<T1,T2>;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace fastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {write(x),putchar(let);}
} using namespace fastIO;

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
const US<char> vowel = {'a','e','i','o','u'};

namespace comfun{
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline T qpow(T a,T b){
	T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<typename T> inline T inv(T x){return qpow(x,MOD-2);}
	template<typename T> inline bool is_prime(T x){
	if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

struct fenwick{
	int sum[(int)1e6+10];
	inline void add(int x,int y){ for(int i=x;i<=1e6;i+=lowbit(i)) sum[i]+=y;}
	inline int ask(int x,int y){ int res=0; for(int i=y;i>0;i-=lowbit(i)) res+=sum[i];
	for(int i=x-1;i>0;i-=lowbit(i)) res-=sum[i]; return res;}
};

struct interval_fenwick{
	int d[(int)1e6+10][2];
	inline void update(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	inline int query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	inline void add(int x,int y,int v){update(x,v),update(y+1,-v);}
	inline int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
};

/* ========================================| Main Program |======================================== */

const int N = 16;
const int G = sqrt(N);
const int R = N*N*N;
const int C = N*N*4;

int cnt,a[N+1][N+1],ans[N+1][N+1];

struct DLX{	
	#define IT(i,A,x) for(int i=A[x];i!=x;i=A[i])
	static const int MS = 1e5+10;
	int n,m,tot,ans,stk[MS];
	int L[MS],R[MS],U[MS],D[MS];
	int col[MS],row[MS],fst[MS],siz[MS];
	
	void build(int n,int m){
		this->n=n;
		this->m=m;
		rep(i,0,m){
			L[i]=i-1;
			R[i]=i+1;
			U[i]=D[i]=i;
		}
		L[0]=m,R[m]=0,tot=m;
		memset(fst,0,sizeof(fst));
		memset(siz,0,sizeof(siz));
	}
	
	void insert(int r,int c){
		row[++tot]=r,siz[col[tot]=c]++;
		D[tot]=D[c],U[D[c]]=tot;
		U[tot]=c,D[c]=tot;
		if(!fst[r]) fst[r]=L[tot]=R[tot]=tot;
		else{
			R[tot]=R[fst[r]],L[R[fst[r]]]=tot;
			L[tot]=fst[r],R[fst[r]]=tot;
		}
	}
	
	void remove(int c){
		L[R[c]]=L[c];
		R[L[c]]=R[c];
		IT(i,D,c) IT(j,R,i){
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			siz[col[j]]--;
		}
	}
	
	void recover(int c){
		IT(i,U,c) IT(j,L,i){
			U[D[j]]=D[U[j]]=j;
			siz[col[j]]++;
		}
		L[R[c]]=R[L[c]]=c;
	}
	
	bool dance(int dep){
		int c=R[0];
		if(c==0){
			ans=dep;
			return 1;
		}
		IT(i,R,0) if(siz[i]<siz[c]) c=i;
		remove(c);
		IT(i,D,c){
			stk[dep]=row[i];
			IT(j,R,i) remove(col[j]);
			if(dance(dep+1)) return 1;
			IT(j,L,i) recover(col[j]);
		}
		recover(c);
		return 0;
	}
} dlx;

struct node{
	int r,c,w;
} row[N*N*N];
	
int columnID(int a,int b,int c){
	return (c-1)*N*N+(a-1)*N+b;
}

void add_row(int r,int c,int w){
	row[++cnt]={r,c,w};
	dlx.insert(cnt,columnID(r,c,1));
	dlx.insert(cnt,columnID(r,w,2));
	dlx.insert(cnt,columnID(c,w,3));
	dlx.insert(cnt,columnID(((r+G-1)/G-1)*G+(c+G-1)/G,w,4));
}

void SOLVE(int Case){
	dlx.build(R,C);
	rep(i,1,N) rep(j,1,N){
		char x;
		cin>>x;
		if(x=='-') a[i][j]=0;
		else a[i][j]=x-'A'+1;
		if(a[i][j]) add_row(i,j,a[i][j]);
		else rep(k,1,N) add_row(i,j,k);
	}
	dlx.dance(1);
	rep(i,1,dlx.ans){
		int r=row[dlx.stk[i]].r;
		int c=row[dlx.stk[i]].c;
		int w=row[dlx.stk[i]].w;
		ans[r][c]=w;
	}
	rep(r,1,N){
		rep(c,1,N) cout<<(char)('A'+ans[r][c]-1);
		cout<<endl;
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

