/*
 * Author: Austin Jiang
 * Date: 8/6/2022 5:02:13 PM
 * Problem: Link with Running
 * Description: dijk and tarjan
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int N = 1e5+10;
int T=1,n,m,tot,cnt,dist[N],cost[N],vis[N],dfn[N],low[N],flag[N],col[N],val[N],in[N];
vector<pair<int,PI>> e[N];
VPI ee[N];
stack<int> stk;

void dfs(int u){
	dfn[u]=low[u]=++tot;
	flag[u]=1;
	stk.push(u);
	for(auto i:e[u]){
		int v=i.fir;
		if(dist[v]!=dist[u]+i.sec.fir) continue;
		if(!dfn[v]) dfs(v);
		if(flag[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]!=low[u]) return;
	col[u]=++cnt;
	while(stk.top()!=u){
		col[stk.top()]=cnt;
		flag[stk.top()]=0;
		stk.pop();
	}
	flag[u]=0;
	stk.pop();
}

void solve(int Case){
	cin>>n>>m;
	rep(i,1,n){
		e[i].clear();
		ee[i].clear();
	}
	rep(i,1,m){
		int u,v,w,p;
		cin>>u>>v>>w>>p;
		e[u].pb(mp(v,mp(w,p)));
	}
	fill(dist+1,dist+n+1,LLINF);
	fill(vis+1,vis+n+1,0);
	PQ<PI,VPI,greater<PI>> qe;
	dist[1]=0;
	qe.push(mp(0,1));
	while(!qe.empty()){
		int u=qe.top().sec;
		qe.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.fir;
			if(dist[u]+i.sec.fir<dist[v]){
				dist[v]=dist[u]+i.sec.fir;
				qe.push(mp(dist[v],v));
			}
		}
	}
	fill(dfn+1,dfn+n+1,0);
	fill(low+1,low+n+1,0);
	fill(flag+1,flag+n+1,0);
	tot=cnt=0;
	rep(i,1,n) if(!dfn[i]) dfs(i);
	fill(val+1,val+n+1,0);
	fill(in+1,in+n+1,0);
	rep(u,1,n){
		for(auto i:e[u]){
			int v=i.fir;
			if(dist[v]!=dist[u]+i.sec.fir) continue;
			if(col[u]==col[v]) val[col[u]]+=i.sec.sec;
			else{
				ee[col[u]].pb(mp(col[v],i.sec.sec));
				in[col[v]]++;
			}
		}
	}
	rep(u,1,cnt){
		if(u==col[1]||in[u]) continue;
		for(auto i:ee[u]){
			int v=i.fir;
			in[v]--;
		}
	}
	fill(cost+1,cost+cnt+1,-INF);
	cost[col[1]]=val[col[1]];
	queue<int> qp;
	qp.push(col[1]);
	while(!qp.empty()){
		int u=qp.front();
		qp.pop();
		for(auto i:ee[u]){
			int v=i.fir;
			chkmax(cost[v],cost[u]+i.sec+val[v]);
			if(!--in[v]) qp.push(v);
		}
	}
	cout<<dist[n]<<" "<<cost[col[n]]<<endl;
}

signed main(){
    int size(512<<20);  // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
//	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>T;
	rep(Case,1,T) solve(Case);
    exit(0);
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

