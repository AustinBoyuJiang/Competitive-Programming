/*
 * Author: Austin Jiang
 * Date: 12/3/2023 7:32:55 AM
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

const int N = 1e6+10;

int n,m,sumx[N],sumy[N],res[N];
Vec<pair<PI,int>> s[N];

struct query{
	int x,y,l,r;
	int p1,p2,p3;
} q[N];

void ask(int k,int sx,int sy,int id){
//	cout<<k<<" "<<sx<<" "<<sy<<endl;
	s[k].pb({{sx,sy},id});
}

inline void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,n){
		char x;
		cin>>x;
		sumx[i]=sumx[i-1];
		sumy[i]=sumy[i-1];
		if(x=='U') sumy[i]++;
		if(x=='D') sumy[i]--;
		if(x=='L') sumx[i]--;
		if(x=='R') sumx[i]++;
	}
	int tot=0;
	rep(i,1,m){
		int x,y,l,r;
		cin>>q[i].x>>q[i].y>>q[i].l>>q[i].r;
		q[i].p1=++tot;
		q[i].p2=++tot;
		q[i].p3=++tot;
		ask(q[i].l-1,q[i].x,q[i].y,q[i].p1);
//		cout<<sumx[q[i].r]+sumx[q[i].l-1]<<" "<<sumy[q[i].r]+sumy[q[i].l-1]<<endl;
		ask(q[i].r,sumx[q[i].r]+sumx[q[i].l-1]-q[i].x,sumy[q[i].r]+sumy[q[i].l-1]-q[i].y,q[i].p2);
		ask(n,q[i].x,q[i].y,q[i].p3);
	}
	set<pair<PI,int>> num;
	rep(i,0,n){
		num.insert({{sumx[i],sumy[i]},n-i});
//		if(i==10){
//			cout<<sumx[i]<<","<<sumy[i]<<endl;
//		}
		for(pair<PI,int> ss:s[i]){
			pair<PI,int> fd=*num.lb({ss.fir,-1});
			if(ss.sec==12){
//				cout<<i<<",,,"<<endl;
//				cout<<fd.fir.fir<<"+"<<fd.fir.sec<<endl;
//				cout<<ss.fir.fir<<"-"<<ss.fir.sec<<endl;
			}
			if(fd.fir==ss.fir) res[ss.sec]=n-fd.sec;
			else res[ss.sec]=-1;
		}
	}
	rep(i,1,m){
		if(res[q[i].p1]>=0){
//			if(i==4) cout<<111<<endl;
			cout<<"YES"<<endl;
			continue;
		}
//		cout<<res[q[i].p2]<<endl;
		if(res[q[i].p2]>=q[i].l-1){
//			if(i==4) cout<<"222"<<endl;
			cout<<"YES"<<endl;
			continue;
		}
//		cout<<sumx[5]<<" "<<sumy[5]<<endl;
//		cout<<sumx[1]<<" "<<sumy[1]<<endl;
		if(res[q[i].p3]>=q[i].r){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
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

