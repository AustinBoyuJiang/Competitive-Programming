/*
 * Author: Austin Jiang
 * Date: 10/19/2024 10:45:46 AM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
#define MULTICASES
//#define LOCAL
#define READLOCAL
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
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
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

const int N = 1e6+10;

int n,flag[10][10];
char a[10][10],b[10][10];

void clear(){
	rep(i,1,6){
		rep(j,1,7){
			flag[i][j]=0;
		}
	}
}

bool check(char k){
	rep(i,1,6){
		rep(j,1,7){
			if(flag[i][j]) b[i][j]=a[i][j];
			else b[i][j]=' ';
		}
	}
	rep(i,1,6){
		rep(j,1,4){
			if(b[i][j]==k&&a[i][j+1]==k&&a[i][j+2]==k&&a[i][j+3]==k){
				return 1;
			}
		}
	}
	rep(i,1,3){
		rep(j,1,7){
			if(b[i][j]==k&&a[i+1][j]==k&&a[i+2][j]==k&&a[i+3][j]==k){
				return 1;
			}
		}
	}
	rep(i,1,3){
		rep(j,1,4){
			if(b[i][j]==k&&a[i+1][j+1]==k&&a[i+2][j+2]==k&&a[i+3][j+3]==k){
				return 1;
			}
			if(b[i+3][j]==k&&a[i+2][j+1]==k&&a[i+1][j+2]==k&&a[i][j+3]==k){
				return 1;
			}
		}
	}
	return 0;
}

inline void SOLVE(int Case){
	rep(i,1,6){
		rep(j,1,7){
			cin>>a[i][j];
		}
	}
	int c=0,f=0;
	rep(i,1,6){
		rep(j,1,4){
			if(a[i][j]=='C'&&a[i][j+1]=='C'&&a[i][j+2]=='C'&&a[i][j+3]=='C'){
				clear();
				rep(x,i+1,6) rep(y,j,j+3){
					flag[x][y]=1;
				}
				if(!check('F')){
					c=1;
				}
			}
			if(a[i][j]=='F'&&a[i][j+1]=='F'&&a[i][j+2]=='F'&&a[i][j+3]=='F'){
				clear();
				rep(x,i+1,6) rep(y,j,j+3){
					flag[x][y]=1;
				}
				if(!check('C')){
					f=1;
				}
			}
		}
	}
	rep(i,1,3){
		rep(j,1,7){
			if(a[i][j]=='C'&&a[i+1][j]=='C'&&a[i+2][j]=='C'&&a[i+3][j]=='C'){
				clear();
				rep(x,i+4,6) rep(y,j,j){
					flag[x][y]=1;
				}
				if(!check('F')){
					c=1;
				}
			}
			if(a[i][j]=='F'&&a[i+1][j]=='F'&&a[i+2][j]=='F'&&a[i+3][j]=='F'){
				clear();
				rep(x,i+4,6) rep(y,j,j){
					flag[x][y]=1;
				}
				if(!check('C')){
					f=1;
				}
			}
		}
	}
	rep(i,1,3){
		rep(j,1,4){
			if(a[i][j]=='C'&&a[i+1][j+1]=='C'&&a[i+2][j+2]=='C'&&a[i+3][j+3]=='C'){
				clear();
				rep(x,i+1,6) flag[x][j]=1;
				rep(x,i+2,6) flag[x][j+1]=1;
				rep(x,i+3,6) flag[x][j+2]=1;
				rep(x,i+4,6) flag[x][j+3]=1;
				if(!check('F')){
					c=1;
				}
			}
			if(a[i][j]=='F'&&a[i+1][j+1]=='F'&&a[i+2][j+2]=='F'&&a[i+3][j+3]=='F'){
				clear();
				rep(x,i+1,6) flag[x][j]=1;
				rep(x,i+2,6) flag[x][j+1]=1;
				rep(x,i+3,6) flag[x][j+2]=1;
				rep(x,i+4,6) flag[x][j+3]=1;
				if(!check('C')){
					f=1;
				}
			}
		}
	}
	rep(i,1,3){
		rep(j,1,4){
			if(a[i+3][j]=='C'&&a[i+2][j+1]=='C'&&a[i+1][j+2]=='C'&&a[i][j+3]=='C'){
				clear();
				rep(x,i+4,6) flag[x][j]=1;
				rep(x,i+3,6) flag[x][j+1]=1;
				rep(x,i+2,6) flag[x][j+2]=1;
				rep(x,i+1,6) flag[x][j+3]=1;
				if(!check('F')){
					c=1;
				}
			}
			if(a[i+3][j]=='F'&&a[i+2][j+1]=='F'&&a[i+1][j+2]=='F'&&a[i][j+3]=='F'){
				clear();
				rep(x,i+4,6) flag[x][j]=1;
				rep(x,i+3,6) flag[x][j+1]=1;
				rep(x,i+2,6) flag[x][j+2]=1;
				rep(x,i+1,6) flag[x][j+3]=1;
				if(!check('C')){
					f=1;
				}
			}
		}
	}
	cout<<"Case #"<<Case<<": ";
	if(f&&c){
		cout<<"?"<<endl;
	}
	else if(f){
		cout<<"F"<<endl;
	}
	else if(c){
		cout<<"C"<<endl;
	}
	else{
		cout<<"0"<<endl;
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

