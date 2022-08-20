/*Author：AustinJiang
题目：Chips Challenge
时间复杂度：O()
算法：
来源：
思路：最大费用可行流 
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=50;
const int V=N*2;
const int E=N*N*2;
const int M=1e3;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,A,B,S,T,r[N],c[N];
char Map[N][N];
int flow,cost,dep[V],dist[V],inq[V],vis[V];
int etot,head[V],h[V];

struct edge{
	int to,flow,cost,nxt;
} e[E];

void addd(int u,int v,int w,int c){
	e[++etot].to=v;
	e[etot].flow=w;
	e[etot].cost=c;
	e[etot].nxt=head[u];
	head[u]=etot;
}

void add(int u,int v,int w,int c){
	addd(u,v,w,c);
	addd(v,u,0,-c);
}

bool SPFA(){
	memset(dist,0x3f,sizeof(dist));
	memcpy(h,head,sizeof(h));
	queue<int> q;
	q.push(S);
	dist[S]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];~i;i=e[i].nxt){
			int v=e[i].to,w=e[i].flow,c=e[i].cost;
			if(w&&dist[u]+c<dist[v]){
				dist[v]=dist[u]+c;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dist[T]!=INF;
}

int DFS(int u,int flow){
	if(u==T){
		cost+=flow*dist[T];
		return flow;
	}
	vis[u]=1;
	int ans=0;
	for(int &i=h[u];~i;i=e[i].nxt){
		int v=e[i].to,&w=e[i].flow,c=e[i].cost;
		if(!vis[v]&&w&&dist[v]==dist[u]+c){
			int res=DFS(v,min(w,flow));
			w-=res,e[i^1].flow+=res;
			ans+=res,flow-=res;
			if(!res) dist[v]=INF;
			if(!flow) break;
		}
	}
	vis[u]=0;
	return ans;
}

void graph(int lim){
	S=0,T=2*n+1,etot=-1;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(Map[i][j]=='.') add(i,n+j,1,1);
	for(int i=1;i<=n;i++){
		add(i,n+i,lim,0);
		add(S,i,r[i],0);
		add(n+i,T,c[i],0);
	}
}

void Dinic(int lim){
	graph(lim);
	flow=cost=0;
	while(SPFA())
		flow+=DFS(S,INF);
}

void solve(int Case){
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	int tot=0,hav=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>Map[i][j];
			if(Map[i][j]!='/'){
				r[i]++;
				c[j]++;
				tot++;
			}
			if(Map[i][j]=='C') hav++;
		}
	}	
	int ans=-1;
	for(int i=0;i<=n;i++){
		Dinic(i);
		int num=tot-cost;
		if(flow==tot&&i*B<=num*A)
			ans=num-hav;
	}
	if(ans>=0) printf("Case %d: %d\n",Case,ans);
	else printf("Case %d: impossible\n",Case);
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	int Case=0;
	while(cin>>n>>A>>B,n)
		solve(++Case);
	return 0;
}

