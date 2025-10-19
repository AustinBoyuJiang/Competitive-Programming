/*
 * Author: Austin Jiang
 * Date: 12/12/2022 1:09:55 AM
 * Problem:
 * Description:
*/

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define fir first
#define sec second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define PQ priority_queue
#define random(a,b) rand()%(b-a+1)+a
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;

namespace fast_io{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline ll readLL() {ll x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {write(x),putchar(let);}
} using namespace fast_io;

/* Common constants, functions, and data structures */
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

namespace comfun{
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline T qpow(T a,T b){T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
	template<typename T> inline T inv(T x){return pow(x,MOD-2);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

struct fenwick{
	int sum[(int)1e6+10];
	void add(int x,int y){ for(int i=x;i<=1e6;i+=lowbit(i)) sum[i]+=y;}
	int ask(int x,int y){ int res=0; for(int i=y;i>0;i-=lowbit(i)) res+=sum[i];
	for(int i=x-1;i>0;i-=lowbit(i)) res-=sum[i]; return res;}
};

struct fenwick_interval{
	int d[(int)1e6+10][2];
	void update(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	int query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	void add(int x,int y,int v){update(x,v),update(y+1,-v);}
	int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
};

/* ========================================| Main Program |======================================== */

const int N = 1e4+10;
int n,m,st,Map[N],dist[N],vis[N];
char a[N];
VPI e[N];

int id(int x,int y){
	return (y-1)*m+x;
}

bool check(int x,int y){
	if(x<1||x>m) return 0;
	if(y<1||y>n) return 0;
	return Map[id(x,y)];
}

void add(int ux,int uy,int vx,int vy,int w=1){
	if(!check(ux,uy)) return;
	if(!check(vx,vy)) return;
	e[id(ux,uy)].pb({id(vx,vy),w});
}

void solve(int Case){
	cin>>n>>m;
	rep(y,1,n) rep(x,1,m){
		cin>>a[id(x,y)];
		if(a[id(x,y)]!='W'&&a[id(x,y)]!='C') Map[id(x,y)]=1;
		if(a[id(x,y)]=='S') st=id(x,y);
	}
	rep(y,1,n) rep(x,1,m){
		if(a[id(x,y)]!='C') continue;
		rep(i,x+1,m){
			if(a[id(i,y)]=='W') break;
			else if(a[id(i,y)]=='.'||a[id(i,y)]=='S') Map[id(i,y)]=0;
		}
		per(i,x-1,1){
			if(a[id(i,y)]=='W') break;
			else if(a[id(i,y)]=='.'||a[id(i,y)]=='S') Map[id(i,y)]=0;
		}
		rep(i,y+1,n){
			if(a[id(x,i)]=='W') break;
			else if(a[id(x,i)]=='.'||a[id(x,i)]=='S') Map[id(x,i)]=0;
		}
		per(i,y-1,1){
			if(a[id(x,i)]=='W') break;
			else if(a[id(x,i)]=='.'||a[id(x,i)]=='S') Map[id(x,i)]=0;
		}
	}
	rep(y,1,n) rep(x,1,m){
		if(Map[id(x,y)]&&(a[id(x,y)]=='.'||a[id(x,y)]=='S')){
			add(x,y,x+1,y);
			add(x,y,x-1,y);
			add(x,y,x,y+1);
			add(x,y,x,y-1);
		}
		if(a[id(x,y)]=='L'){
			add(x,y,x-1,y,0);
		}
		if(a[id(x,y)]=='R'){
			add(x,y,x+1,y,0);
		}
		if(a[id(x,y)]=='U'){
			add(x,y,x,y-1,0);
		}
		if(a[id(x,y)]=='D'){
			add(x,y,x,y+1,0);
		}
	}
	memset(dist,-1,sizeof(dist));
	dist[st]=0;
	deque<int> q;
	q.pb(st);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		for(auto i:e[u]){
			int v=i.fir;
			int w=i.sec;
			if(dist[v]==-1||dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(w) q.pb(v);
				else q.push_front(v);
			}
		}
	}
	rep(i,1,n*m){
		if(a[i]=='.'){
			cout<<dist[i]<<endl;
		}
	}
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	cin.tie(nullptr)->sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
//	freopen("stdout.txt","w",stdout);
	int CASE=1;
//	cin>>CASE;
	rep(Case,1,CASE) solve(Case);
//  exit(0);
//	system("fc stdout.txt out.txt");
	return 0;
}

/* stuff you should look for
	* read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow, check edge case
    * Debug: (b) create your own test case
    * Debug: (c) duipai
*/
