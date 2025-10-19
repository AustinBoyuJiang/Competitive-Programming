/*
 * Author: Austin Jiang
 * Date: 10/10/2023 11:37:45 PM
 * Problem: Early Exam Evacuation
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

const int N = 1e5+10;
const int M = N*6;

int n,m,A,B,ans=INF,pos[N][5],val[M][2],sum[M][2];
PI ord[M];

struct Segtree{
	int st[N<<2],lazy[N<<2];
	
	void push_down(int rt,int l,int mid,int r){
		if(lazy[rt]){
			lazy[lc]+=lazy[rt];
			lazy[rc]+=lazy[rt];
			st[lc]+=lazy[rt]*(mid-l+1);
			st[rc]+=lazy[rt]*(r-mid);
			lazy[rt]=0;
		}
	}
	
	void update(int rt,int l,int r,int x,int y,int val){
		if(l==x&&r==y){
			st[rt]+=val*(r-l+1);
			lazy[rt]+=val;
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(lc,l,mid,x,y,val);
		else if(x>mid) update(rc,mid+1,r,x,y,val);
		else update(lc,l,mid,x,mid,val),update(rc,mid+1,r,mid+1,y,val);
		st[rt]=st[lc]+st[rc];
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return st[rt];
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return query(lc,l,mid,x,mid)+query(rc,mid+1,r,mid+1,y);
	}
	
	void add(int l,int r,int val){update(1,1,n,l,r,val);}
	void add(int x,int val){add(x,x,val);}
	int ask(int l,int r){return query(1,1,n,l,r);}
} c,d;

inline void SOLVE(int Case){
	cin>>n>>m>>A>>B;
	c.add(1,n,1);
	d.add(1,n,1);
	rep(i,1,m){
		int row;
		char col;
		cin>>row>>col;
		int cnt=0;
		if(col=='A') cnt=1-pos[row][1];
		if(col=='F') cnt=1-pos[row][4];
		if(col=='C') c.add(row,-1);
		if(col=='D') d.add(row,-1);
		val[i][0]=cnt+c.ask(1,row)+d.ask(1,row);
		val[i][1]=cnt+c.ask(row,n)+d.ask(row,n);
		ord[i]={val[i][0]-val[i][1],i};
		pos[row][col-'A']=1;
	}
	sort(ord+1,ord+m+1);
	rep(i,1,m){
		sum[i][0]=val[ord[i].sec][0];
		sum[i][1]=val[ord[i].sec][1];
	}
	rep(i,2,m){
		sum[i][0]+=sum[i-1][0];
		sum[i][1]+=sum[i-1][1];
	}
	rep(i,0,m){
		int res=B*(i*(i-1)/2+(m-i)*(m-i-1)/2);
		res+=A*(sum[i][0]+sum[m][1]-sum[i][1]);
		ans=min(ans,res);
	}
	cout<<ans<<endl;
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

