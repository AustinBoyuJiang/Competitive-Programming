/*
 * Author: Austin Jiang
 * Date: 8/30/2023 11:54:45 PM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
#define MULTICASES
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

/* Common functions and data structures */

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
	template<class T> inline void disc(Vec<T> &v,int st=0) /*discretize*/ {Vec<T> num=v;sort(all(num));
	for(T &x:v) x=lb(all(num),x)-num.begin()+st;}
} using namespace Comfun;

/* ========================================| Main Program |======================================== */

const int N = 510;

int n,m,row[N],col[N],ans[N][N];
PI a[N][N],b[N][N],lstrow[N],lstcol[N];

void Set(PI pos,int x){
	int i=pos.fir;
	int j=pos.sec;
	if(ans[i][j]!=-1) return;
	ans[i][j]=x;
}

inline void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,n){
		row[i]=0;
		lstcol[i]={0,0};
	}
	rep(i,1,m){
		col[i]=0;
		lstrow[i]={0,0};
	}
	rep(i,1,n){
		rep(j,1,m){
			ans[i][j]=-1;
			char x;
			cin>>x;
			b[i][j]=make_pair(0,0);
			if(x=='.'){
				a[i][j]=make_pair(0,0);
				continue;
			}
			if(x=='L'){
				a[i][j]={i,j+1}; 
				if(lstrow[j]==make_pair(0,0)){
					lstrow[j]=make_pair(i,j);
				}
				else{
					b[i][j]=lstrow[j];
					b[lstrow[j].fir][lstrow[j].sec]={i,j};
					lstrow[j]=make_pair(0,0);
				}
			}
			else if(x=='R') a[i][j]={i,j-1};
			else if(x=='U'){
				a[i][j]={i+1,j};
				if(lstcol[i]==make_pair(0,0)){
					lstcol[i]=make_pair(i,j);
				}
				else{
					b[i][j]=lstcol[i];
					b[lstcol[i].fir][lstcol[i].sec]={i,j};
					lstcol[i]=make_pair(0,0);
				}
			}
			else if(x=='D') a[i][j]={i-1,j};
			row[i]++;
			col[j]++;
		}
	}
	rep(i,1,n){
		if(row[i]%2==1){
			cout<<-1<<endl;
			return;
		}
	}
	rep(i,1,m){
		if(col[i]%2==1){
			cout<<-1<<endl;
			return;
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			if(a[i][j]==make_pair(0,0)) continue;
			if(ans[i][j]!=-1) continue;
			ans[i][j]=0;
			Set(a[i][j],ans[i][j]^1);
			if(b[i][j]!=make_pair(0,0)){
				Set(b[i][j],ans[i][j]^1);
			}
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			cout<<(ans[i][j]==-1?'.':(ans[i][j]?'B':'W'));
		} cout<<endl;
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

