#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e3+10;
const int V=N*2;
const int E=V*V*2;

int n,m,k,ans;
int S,T,dist[V],inq[V],vis[V];
int tot=-1,h[V],head[V];

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
		h[i]=head[i];
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
	for(int &i=h[u];~i;i=e[i].nxt){
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

void Dinic(){
	while(SPFA())
		DFS(S,INF);
}

signed main(){
	memset(head,-1,sizeof(head));
	scanf("%d %d %d",&n,&m,&k);
	S=0,T=m*2+2;
	add(S,T-1,n,0);
	for(int i=1;i<=m;i++){
		int h,s;
		scanf("%d %d",&h,&s);
		add(T-1,i,s,0);
		add(i+m,T,INF,0);
		for(int j=1;j<=n;j++)
			add(i,i+m,1,h/j);
	}
	for(int i=1;i<=k;i++){
		int c=0,a,b,d;
		scanf("%d %d %d",&a,&b,&d);
		if(c) add(a+m,b,INF,-d);
		add(a,b,INF,-d);
	}
	Dinic();
	printf("%d\n",ans);
	return 0;
}

