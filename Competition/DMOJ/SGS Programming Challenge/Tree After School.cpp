/*
 * Author: Austin Jiang
 * Date: 8/31/2022 8:46:07 PM
 * Problem: Tree After School
 * Description: LCA, DFS
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
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

const int INF = 2000000000;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 1e5+10;
const int D = 17;
int T=1,n,q,k,cnt,tot,lev[N],dep[N],f[N][D];
VI e[N];

inline int pow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans*=a;
			if(ans>=INF) return INF;
		}
		a*=a;
		chkmin(a,INF);
		b>>=1;
	}
	return ans;
}

inline void dfs(int u,int fa){
	int id=++tot;
	f[id][0]=fa;
	rep(i,1,D-1) f[id][i]=f[f[id][i-1]][i-1];
	dep[id]=dep[fa]+1;
	if(!e[u].size()) lev[++cnt]=id;
	for(auto v:e[u]) dfs(v,id);
}

inline int getSize(int x){//how many nodes are there when k=x
	return min(INF,(pow(cnt,x+1)-1)/(cnt-1)*(n-1)+1);
}

inline int findLev(int x,int siz){//find x will be going through which leaf node
	int l=1,r=cnt,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(lev[mid]+(siz-1)*mid>=x){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	per(i,D-1,0){
		if(dep[y]<=dep[f[x][i]]) x=f[x][i];
		if(x==y) return x;
	}
	per(i,D-1,0){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

inline int getDist(int x,int y){//the distance from x to y on the original tree
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

inline int query(int x,int depth){
	int siz=getSize(depth-1);
	int vx=siz==INF?1:findLev(x,siz);
	x-=(vx-1)*(siz-1);
	if(x<=lev[vx]) return dep[x]-1;
	return dep[lev[vx]]-1+query(x-lev[vx]+1,depth-1);
}

inline int query(int x,int y,int depth){
	//special judge
	if(cnt==1) return abs(x-y);
	if(depth>30){
		int tmp=(dep[lev[1]]-1)*(depth-30);
		return query(x-tmp,y-tmp,30);
	}
	if(x<=1&&y<=1) return abs(x-y);
	if(x<=1) return query(y,depth)-x+1;
	if(y<=1) return query(x,depth)-y+1;
	
	int siz=getSize(depth-1);
	int vx=siz==INF?1:findLev(x,siz);
	int vy=siz==INF?1:findLev(y,siz);
	x-=(vx-1)*(siz-1);
	y-=(vy-1)*(siz-1);
	
	if(x<=lev[vx]&&y<=lev[vy]) return getDist(x,y);
	if(x<=lev[vx]) return getDist(x,lev[vy])+query(y-lev[vy]+1,depth-1);
	if(y<=lev[vy]) return getDist(y,lev[vx])+query(x-lev[vx]+1,depth-1);
	if(vx==vy) return query(x-lev[vx]+1,y-lev[vy]+1,depth-1);
	return getDist(lev[vx],lev[vy])+query(x-lev[vx]+1,depth-1)+query(y-lev[vy]+1,depth-1);
}

inline void solve(int Case){
	read(n);
	rep(i,1,n-1) e[read()].pb(i);
	dfs(0,0);
	read(k),read(q);
	while(q--) cout<<query(read(),read(),k)<<endl;
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
    * Debug: (c) ╤тед
*/

