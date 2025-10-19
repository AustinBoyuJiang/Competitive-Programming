/*
 * Author: Austin Jiang
 * Date: 12/5/2022 9:08:03 AM
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
	template<typename T> inline T pow(T a,T b){T ans=1;while(b){if(b&1) ans*=a,ans%=MOD;a*=a,a%=MOD;b>>=1;}return ans;}
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
	int add(int x,int y,int v){update(x,v),update(y+1,-v);}
	int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
};

/* ========================================| Main Program |======================================== */

const int N = 1e6+10;
int n,k,a[N],fst[N],lst[N];
long dp[N][2];

struct segment_tree{
	long dpv[N<<2],mx[N<<2];
	int lazy[N<<2];
	
	inline void push_up(int rt){
		dpv[rt]=max(dpv[rt<<1],dpv[rt<<1|1]);
		mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
	}
	
	inline void push_down(int rt,int l,int mid,int r){
		if(lazy[rt]){
			lazy[rt<<1]=max(lazy[rt<<1],lazy[rt]);
			lazy[rt<<1|1]=max(lazy[rt<<1|1],lazy[rt]);
			mx[rt<<1]=max(mx[rt<<1],dpv[rt<<1]+lazy[rt]);
			mx[rt<<1|1]=max(mx[rt<<1|1],dpv[rt<<1|1]+lazy[rt]);
			lazy[rt]=0;
		}
	}
	
	inline void update(int rt,int l,int r,int x,long y){
		if(l==r){
			mx[rt]+=y-dpv[rt];
			dpv[rt]=y;
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(x<=mid) update(rt<<1,l,mid,x,y);
		else update(rt<<1|1,mid+1,r,x,y);
		push_up(rt);
	}
	
	inline void update(int rt,int l,int r,int x,int y,int v){
		if(x>y) return;
		if(l==x&&r==y){
			mx[rt]=max(mx[rt],dpv[rt]+v);
			lazy[rt]=max(lazy[rt],v);
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(rt<<1,l,mid,x,y,v);
		else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
		else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
		push_up(rt);
	}
	
	inline long query(int rt,int l,int r,int x,int y){
		if(x>y) return 0;
		if(l==x&&r==y) return mx[rt];
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) return query(rt<<1,l,mid,x,y);
		else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
		else return max(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y));
	}
} st[2];

inline void solve(int Case){
	read(n),read(k);
	rep(i,1,n){
		read(a[i]);
		int lb=(i+k-1)/k,ub=(i-n%k+k-1)/k+1; //The ith attraction最早和最晚能到达的天 
		rep(d,0,min(ub-lb,1)){
			st[0].update(1,0,n,0,i-1,a[i]);
			st[1].update(1,0,n,0,i-1,a[i]);
			int a=max(i-k,fst[lb+d-1]);
			int b=max(lst[lb+d-2],a-1);
			int c=min(i-1,lst[lb+d-1]);
			dp[i][d]=max(st[1].query(1,0,n,a,b),st[0].query(1,0,n,b+1,c));
			st[d].update(1,0,n,i,dp[i][d]);
		}
		if(!fst[lb]) fst[lb]=i;
		if(!fst[ub]) fst[ub]=i;
		lst[lb]=i;
		lst[ub]=i;
	}
	write(dp[n][0]);
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int CASE=1;
	//cin>>CASE;
	rep(Case,1,CASE) solve(Case);
    //exit(0);
	//system("fc stdout.txt out.txt");
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

