/*
 * Author: Austin Jiang
 * Date: 8/8/2022 2:50:56 PM
 * Problem: K短路 
 * Description: A*算估价价算法
 	fx=gx+hx
	gx为起点到x的距离
	hx为x到终点的距离 
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
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

const int N = 1010;
int T=1,n,m,k,h[N],vis[N],cnt[N],ans[N];
VPI e[N],ee[N];
PQ<PI,VPI,greater<PI>> qq;

struct node{
	int dis,u;
};


bool operator > (const node &a,const node &b){
	return a.dis+h[a.u]>b.dis+h[b.u];
}

PQ<node,vector<node>,greater<node>> q;

void solve(int Case){
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		ee[v].pb(mp(u,w));
	}
	fill(h+1,h+n+1,INF);
	h[n]=0;
	qq.push(mp(0,n));
	while(!qq.empty()){
		int u=qq.top().sec;
		qq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:ee[u]){
			int v=i.fir,w=i.sec;
			if(h[u]+w<h[v]){
				h[v]=h[u]+w;
				qq.push(mp(h[v],v));
			}
		}
	}
	fill(ans+1,ans+n+1,-1);
	q.push({0,1});
	while(!q.empty()){
		int u=q.top().u;
		int gu=q.top().dis;
		q.pop();
		cnt[u]++;
		if(cnt[u]>k) continue;
		else if(u==n) ans[cnt[u]]=gu;
		for(auto i:e[u]){
			int v=i.fir,w=i.sec;
			q.push({gu+w,v});
		}
	}
	rep(i,1,k) cout<<ans[i]<<endl; 
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	srand(time(0));
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	rep(Case,1,T) solve(Case);
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

