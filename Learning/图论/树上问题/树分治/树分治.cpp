/*
 * Author: Austin Jiang
 * Date: 9/3/2022 6:08:05 PM
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

namespace comfun{
	template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
	template<typename T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
	template<typename T> inline T lowbit(T x){return x&-x;}
	template<typename T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<typename T> inline T chkmin(T &a,T b){return a=min(a,b);}
	template<typename T> inline bool is_prime(T x){if(x==1) return false; for(T i=2;i*i<=x;i++) if(x%i==0) return false; return true;}
} using namespace comfun;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 4e4+10;
int T=1,n,k,ans,root,mn,vis[N];
VPI e[N];

struct segment_tree{//可用STL代替 
	int sum[N<<2],flag[N<<2];
	VI num;
	
	void push_down(int rt,int l,int mid,int r){
		if(flag[rt]){
			sum[rt<<1]=0;
			sum[rt<<1|1]=0;
			flag[rt<<1]=1;
			flag[rt<<1|1]=1;
			flag[rt]=0;
		}
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(y<x) return 0;
		if(l==x&&r==y) return sum[rt];
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) return query(rt<<1,l,mid,x,y);
		else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
		return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
	}
	
	void update(int rt,int l,int r,int x){
		sum[rt]++;
		if(l==r) return;
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(x<=mid) update(rt<<1,l,mid,x);
		else update(rt<<1|1,mid+1,r,x);
	}
	
	void clear(){
		sum[1]=0;
		flag[1]=1;
		num.clear();
	}
	
	void insert(int x){
		update(1,0,N,x);
		num.pb(x);
	}
	
	int count(int x){
		return query(1,0,N,0,x);
	}
}dist,tmp;

int findRoot(int u,int fa){
	int siz=1;
	int mx=0;
	for(auto i:e[u]){
		int v=i.fir;
		if(vis[v]||v==fa) continue;
		int res=findRoot(v,u);
		chkmax(mx,res);
		siz+=res;
	}
	chkmax(mx,n-siz);
	if(mx<mn){
		mn=mx;
		root=u;
	}
	return siz;
}

int getRoot(int u){
	mn=INF;
	findRoot(u,u);
	return root;
}

void calc(int u,int fa,int dis){
	tmp.insert(dis);
	ans+=dist.count(k-dis);
	for(auto i:e[u]){
		int v=i.fir;
		int w=i.sec;
		if(v==fa||vis[v]) continue;
		calc(v,u,dis+w);
	}
}

void dfs(int u){
	vis[u]=1;
	dist.clear();
	dist.insert(0);
	for(auto i:e[u]){
		int v=i.fir;
		int w=i.sec;
		if(vis[v]) continue;
		calc(v,v,w);
		for(auto x:tmp.num) dist.insert(x);
		tmp.clear();
	}
	for(auto i:e[u]){
		int v=i.fir;
		if(vis[v]) continue;
		dfs(getRoot(v));
	}
}

void solve(int Case){
	read(n);
	rep(i,1,n-1){
		int u=read();
		int v=read();
		int w=read();
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
	read(k);
	dfs(getRoot(1));
	cout<<ans<<endl;
}

signed main(){
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//srand(time(0));
	//cin.tie(nullptr)->sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	rep(Case,1,T) solve(Case);
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
    * Debug: (c) 对拍
*/

