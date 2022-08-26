/*
 * Author: Austin Jiang
 * Date: 8/8/2022 12:40:27 AM
 * Problem: 次短路计数
 * Description:
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

const int N = 5e4+10;
int T=1,n,m,dist[N][2],cnt[N][2],vis[N][2];
VPI e[N];

struct node{
	int dis,to,tp;
};

bool operator > (const node &a,const node &b){
	return a.dis>b.dis;
}

PQ<node,vector<node>,greater<node>> q;

int dijkstra(){
	memset(dist,0x3f,sizeof(dist));
	dist[1][0]=0;
	cnt[1][0]=1;
	q.push({0,1,0});
	while(!q.empty()){
		int u=q.top().to;
		int k=q.top().tp;
		q.pop();
		if(vis[u][k]) continue;
		vis[u][k]=1;
		for(auto i:e[u]){
			int v=i.fir,w=i.sec;
			if(dist[u][k]+w<dist[v][0]){
				dist[v][1]=dist[v][0];
				cnt[v][1]=cnt[v][0];
				q.push({dist[v][1],v,1});
				
				dist[v][0]=dist[u][k]+w;
				cnt[v][0]=cnt[u][k];
				q.push({dist[v][0],v,0});
			}
			else if(dist[u][k]+w==dist[v][0]){
				cnt[v][0]+=cnt[u][k];
			}
			else if(dist[u][k]+w<dist[v][1]){
				dist[v][1]=dist[u][k]+w;
				cnt[v][1]=cnt[u][k];
				q.push({dist[v][1],v,1});
			}
			else if(dist[u][k]+w==dist[v][1]){
				cnt[v][1]+=cnt[u][k];
			}
		}
	}
	return cnt[n][0]+(dist[n][0]+1==dist[n][1]?cnt[n][1]:0);
}

void solve(int Case){
	cin>>n>>m;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
	}
	cout<<dijkstra()<<endl;
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

