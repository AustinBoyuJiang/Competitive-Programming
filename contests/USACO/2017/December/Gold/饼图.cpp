/*
 * Author: Austin Jiang
 * Date: 11/7/2022 1:13:12 PM
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

const int N = 1e5+10;
int n,d,tot,ans[N],root[2],id[2][N<<2],dist[N<<3],vis[N<<3];
VPI e[N<<3];
deque<PI> q;

struct pie{
	int x,y,pos;
} p[2][N];

struct node{
	int lc,rc;
} st[N<<3];

int lbx(int x){	int l=1,r=n,res=n+1; while(l<=r){ int mid=l+r>>1; if(p[1][mid].x>=x) r=mid-1,res=mid; else l=mid+1;} return res;}
int ubx(int x){ int l=1,r=n,res=0; while(l<=r){ int mid=l+r>>1; if(p[1][mid].x<=x) l=mid+1,res=mid; else r=mid-1;} return res;}
int lby(int y){ int l=1,r=n,res=n+1; while(l<=r){ int mid=l+r>>1; if(p[0][mid].y>=y) r=mid-1,res=mid; else l=mid+1;} return res;}
int uby(int y){	int l=1,r=n,res=0; while(l<=r){ int mid=l+r>>1; if(p[0][mid].y<=y) l=mid+1,res=mid; else r=mid-1;} return res;}

void build(int k,int &rt,int l,int r){
	rt=++tot;
	if(l==r){
		id[k][l]=rt;
		return;
	}
	int mid=l+r>>1;
	build(k,st[rt].lc,l,mid);
	build(k,st[rt].rc,mid+1,r);
	e[rt].pb({st[rt].lc,0});
	e[rt].pb({st[rt].rc,0});
}

void add(int u,int v,int l,int r,int x,int y){
	if(x>y) return;
	if(l==x&&r==y){
		e[u].pb({v,1});
		return;
	}
	int mid=l+r>>1;
	if(y<=mid) add(u,st[v].lc,l,mid,x,y);
	else if(x>mid) add(u,st[v].rc,mid+1,r,x,y);
	else add(u,st[v].lc,l,mid,x,mid),add(u,st[v].rc,mid+1,r,mid+1,y);
}

void solve(int Case){
	cin>>n>>d;
	rep(k,0,1) rep(i,1,n){
		cin>>p[k][i].x>>p[k][i].y;
		p[k][i].pos=i;
	}
	sort(p[0]+1,p[0]+n+1,[](pie a,pie b){return a.y<b.y;});
	sort(p[1]+1,p[1]+n+1,[](pie a,pie b){return a.x<b.x;});
	build(0,root[0],1,n);
	build(1,root[1],1,n);
	rep(i,1,n){
		add(id[0][i],root[1],1,n,lbx(p[0][i].x-d),ubx(p[0][i].x));
		add(id[1][i],root[0],1,n,lby(p[1][i].y-d),uby(p[1][i].y));
		if(p[0][i].y==0) e[0].pb({id[0][i],1});
		if(p[1][i].x==0) e[0].pb({id[1][i],1});
	}
	memset(dist,0x3f,sizeof(dist));
	dist[0]=0;
	q.pb({0,0});
	while(!q.empty()){
		int u=q.front().fir;
		q.pop_front();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto r:e[u]){
			int v=r.fir,w=r.sec;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(w) q.pb({v,dist[v]});
				else q.push_front({v,dist[v]});
			}
		}
	}
	rep(i,1,n) ans[p[0][i].pos]=dist[id[0][i]];
	rep(i,1,n) cout<<(ans[i]==INF?-1:ans[i])<<endl;
}

/* ======================================| Main Program End |====================================== */

signed main(){
	srand(time(0));
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	cin.tie(nullptr)->sync_with_stdio(false);
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
