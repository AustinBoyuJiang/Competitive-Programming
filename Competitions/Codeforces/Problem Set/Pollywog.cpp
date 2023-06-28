/*
 * Author: Austin Jiang
 * Date: 6/24/2023 6:55:28 PM
 * Problem: Pollywog
 * Source:
 * Description:
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
//#define FASTIO
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

/* ========================================| Main Program |======================================== */

const int N = 30;

int x,k,n,q,m,c[N];
map<int,int> w;
set<int> p;
Vec<VI> empty;
VI state;

int lowbit(int x){
	return x&(-x);
}

void init(int s,int cnt,int pos){
	if(cnt>x) return; 
	if(k-pos+cnt<x) return;
	if(pos==k) return state.pb(s);
	init(s<<1,cnt,pos+1);
	init((s<<1)|1,cnt+1,pos+1);
}

int cost(int pos,int i,int j){
	int s1=state[i],s2=state[j];
	int pos1=log2(lowbit(s1));
	int pos2=log2(s2);
	if(((s2^(1<<pos2))<<1)^s1^(1<<pos1)) return INF;
	return c[pos2-pos1+1]+w[pos2+pos+1];
}

Vec<VI> matrix(int pos){
	Vec<VI> res;
	res.resize(m);
	rep(i,0,m-1){
		res[i].resize(m);
		rep(j,0,m-1){
			res[i][j]=cost(pos,i,j);
		}
	}
	return res;
}

Vec<VI> operator *(const Vec<VI>& a,const Vec<VI>& b){
    Vec<VI> res(m);
    rep(i,0,m-1) res[i].resize(m,INF);
    rep(i,0,m-1) rep(j,0,m-1) rep(k,0,m-1){
    	res[i][j]=min(res[i][j],a[i][k]+b[k][j]);
	}
	return res;
}

template<class T>
T qpow(T a,int b){
	T ans=empty;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}

void print(Vec<VI> a){
	rep(i,0,m-1){
		rep(j,0,m-1){
			cout<<a[i][j]<<" ";
		} cout<<endl;
	}
	cout<<endl;
}

void print(int x){
	per(i,k-1,0){
		cout<<(x>>i)%2;
	} cout<<endl;
}

void SOLVE(int Case){
	read(x),read(k),read(n),read(q);
	rep(i,1,k){
		read(c[i]);
	}
	rep(i,1,q){
		int pos=read();
		read(w[pos]);
		rep(j,pos-k,min(n-k,pos)){
			p.insert(j);
		}
	}
	init(0,0,0);
	m=state.size();
	empty.resize(m);
	rep(i,0,m-1){
		empty[i].resize(m,INF);
		empty[i][i]=0;
	}
	Vec<VI> res=empty,a=matrix(1);
	
	rep(i,1,n-k){
		res=res*matrix(i);
	}
//	int lst=0;
//	for(int pos:p){
//		cout<<pos<<endl;
//		rep(i,lst+1,pos-1){
//			res=res*a;
//		}
////		res=res*qpow(a,pos-lst-1);
//		res=res*matrix(pos);
//		lst=pos;
//	}
////	res=res*qpow(a,n-k-lst);
//	rep(i,lst+1,n-k){
//		res=res*a;
//	}

	int ans=INF;
	rep(i,0,m-1){
		ans=min(ans,res[i][m-1]);
	}
	write(ans,endl);
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

