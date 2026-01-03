/*Author：AustinJiang
题目：分配问题
时间复杂度：O()
算法：
来源：
思路：
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
const int N=110;
const int V=N*2;
const int E=N*N*2;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,S,T,ans,c[N][N],dist[V],inq[V],vis[V];
int tot,head[V],h[V];

struct edge{
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

bool SPFA1(){
	for(int i=S;i<=T;i++){
		h[i]=head[i];
		dist[i]=INF;
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

bool SPFA2(){
	for(int i=S;i<=T;i++){
		h[i]=head[i];
		dist[i]=-INF;
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
		ans+=dist[T]*flow;
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
			if(!res) dist[v]=INF;
			if(!flow) break;
		}
	}
	vis[u]=0;
	return ans;
}

void Dinic2(){
	while(SPFA2())
		DFS(S,INF);
}

void Dinic1(){
	while(SPFA1())
		DFS(S,INF);
}

int solve(int k){
	ans=0,tot=-1;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			add(i,n+j,1,c[i][j]);
	for(int i=1;i<=n;i++){
		add(S,i,1,0);
		add(n+i,T,1,0);
	}
	if(k==1) Dinic1();
	else Dinic2();
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	S=0,T=n*2+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	cout<<solve(1)<<endl;
	cout<<solve(2)<<endl;
	return 0;
}

