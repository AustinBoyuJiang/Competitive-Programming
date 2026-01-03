/*
 * Author: Austin Jiang
 * Date: 8/28/2022 5:44:47 PM
 * Problem:
 * Description:
*/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
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
const int M = 1e5+10;
int T=1,n,m,q,s,t,dist[2][N],vis[N],sum[M];
VPI e[2][N];

struct EDGE{
	int u,v,w,c,sp;
	
	bool operator< (const EDGE &other){
		return sp<other.sp;
	}
} edge[M];

inline void dijkstra(int st,int k){
	fill(dist[k]+1,dist[k]+n+1,INF);
	fill(vis+1,vis+n+1,0);
	dist[k][st]=0;
	PQ<PI,VPI,greater<PI>> q;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().sec;
		q.pop();
		if(vis[u]) continue;
		vis[u]=0;
		for(auto i:e[k][u]){
			int v=i.fir,w=i.sec;
			if(dist[k][u]+w<dist[k][v]){
				dist[k][v]=dist[k][u]+w;
				q.push({dist[k][v],v});
			}
		}
	}
}

void solve(int Case){
	cin>>n>>m>>s>>t;
	rep(i,1,m){
		int u,v,w,c;
		cin>>u>>v>>w>>c;
		edge[i]={u,v,w,c};
		e[0][u].pb({v,w});
		e[1][v].pb({u,w});
	}
	dijkstra(s,0);
	dijkstra(t,1);
	rep(i,1,m){
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		edge[i].sp=dist[0][u]+dist[1][v]+w;
	}
	sort(edge+1,edge+m+1);
	rep(i,1,m) sum[i]=sum[i-1]+edge[i].c;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		int l=0,r=m,pos;
		while(l<=r){
			int mid=l+r>>1;
			if(edge[mid].sp<=x){
				pos=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<sum[pos]<<endl;
	}
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
