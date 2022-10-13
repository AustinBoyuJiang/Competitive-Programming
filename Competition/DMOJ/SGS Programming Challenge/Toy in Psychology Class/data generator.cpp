//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define fir first
#define sec second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
#define random(a,b) rng()%(b-a+1)+a
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

const int TEST = 15;
const int Hi = 1e6;
const int Si = 100;
const int Di = 1e6;
int NS[TEST]={   1,  50, 200, 200, 200, 200,1000,1000,1000,1000, 200,1000,1000,1000,1000};
int MS[TEST]={   1,  20,  50,  50,  50,  50, 100, 100, 100, 100,  50, 100, 100, 100, 100};
int KS[TEST]={   0,   0,   0,   0,   0,  50, 100, 100, 100, 100,  50, 100, 100, 100, 100};
int CS[TEST]={   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1};
/*
5&6: a ton of duplicate edges
7: H: lots of 1 followed by lots of 1e6
8: most S[i] is 0, but some is 100
*/

const int N = 1e3+10;
const int V = N*2;
const int E = V*V*2;

int n,m,k,h[N],s[N],c[N],a[N],b[N],d[N];
int ans,S,T,dist[V],inq[V],vis[V];
int tot,hd[V],head[V];

struct Edge{
	int to,flow,cost,nxt;
} e[E];

void addd(int u,int v,int w,int c){
	e[++tot].to=v;
	e[tot].flow=w;
	e[tot].cost=c;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void add(int u,int v,int w,int c){
	addd(u,v,w,c);
	addd(v,u,0,-c);
}

bool SPFA(){
	for(int i=S;i<=T;i++){
		dist[i]=-INF;
		hd[i]=head[i];
	}
	queue<int> q;
	q.push(S);
	dist[S]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];~i;i=e[i].nxt){
			int v=e[i].to,w=e[i].flow,c=e[i].cost;
			if(w&&dist[u]+c>dist[v]){
				dist[v]=dist[u]+c;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dist[T]!=-INF;
}

int DFS(int u,int flow){
	if(u==T){
		ans+=flow*dist[T];
		return flow;
	}
	int ans=0;
	vis[u]=1;
	for(int &i=hd[u];~i;i=e[i].nxt){
		int v=e[i].to,&w=e[i].flow,c=e[i].cost;
		if(!vis[v]&&w&&dist[v]==dist[u]+c){
			int res=DFS(v,min(w,flow));
			w-=res,e[i^1].flow+=res;
			ans+=res,flow-=res;
			if(!res) dist[v]=-INF;
			if(!flow) break;
		}
	}
	vis[u]=0;
	return ans;
}

int Dinic(){
	while(SPFA())
		DFS(S,INF);
	return ans;
}

int solve(){
	memset(head,-1,sizeof(head));
	tot=-1,ans=0;
	S=0,T=m*2+2;
	add(S,T-1,n,0);
	for(int i=1;i<=m;i++){
		add(T-1,i,s[i],0);
		add(i+m,T,INF,0);
		for(int j=1;j<=n;j++)
			add(i,i+m,1,h[i]/j);
	}
	for(int i=1;i<=k;i++){
		if(c[i]) add(a[i]+m,b[i],INF,-d[i]);
		else add(a[i],b[i],INF,-d[i]);
	}
	return Dinic();
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void generate(int Test){
	n=NS[Test],m=MS[Test],k=KS[Test];
	int pos=random(0,m);
	rep(i,1,m){
		if(Test==7) h[i]=i<=pos?Hi:1;
		else h[i]=random(1,Hi);
		if(Test==8) s[i]=random(1,5)==1?100:0;
		else s[i]=random(1,Si);
	}
	VI f(m+1); VPI edge;
	rep(i,1,m) f[i]=i;
	rep(i,1,m) swap(f[i],f[random(1,i)]);
	rep(i,2,m){
		if(random(1,7)!=1){
			int cnt=random(1,3)==1?random(1,Test==6?20:1):1;
			while(cnt--) edge.pb({f[i],f[i-1]});
		}
	}
	chkmin(k,(int)edge.size());
	rep(i,1,k){
//		c[i]=random(0,CS[Test]);
		a[i]=edge[Test==5?0:i-1].fir;
		b[i]=edge[Test==5?0:i-1].sec;
		d[i]=random(0,1)?random(1,Di/10):random(1,Di);
	}
	cout<<n<<" "<<m<<" "<<k<<endl;
	rep(i,1,m) cout<<h[i]<<" "<<s[i]<<endl;
	rep(i,1,k) cout<<a[i]<<" "<<b[i]<<" "<<d[i]<<endl;
}

signed main(int argc, char **argv){
    //int size(512<<20);  //512M
    //__asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	//cin.tie(nullptr)->sync_with_stdio(false);
//	generate(atoi(argv[1]));
//	crr<<solve()<<endl;
	int id=0;
	rep(i,0,9){
		rep(j,1,3){
			id++;
			char infile[100],outfile[100];
    		sprintf(infile,"data/sgsopc1p5.%d.in",id);
    		sprintf(outfile,"data/sgsopc1p5.%d.out",id);
			freopen(infile,"w",stdout);
			generate(i);
			freopen(outfile,"w",stdout);
			cout<<solve()<<endl;
		}
	}
    //exit(0);
	//system("fc stdout.txt out.txt");
	return 0;
}

