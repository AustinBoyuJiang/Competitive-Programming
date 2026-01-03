/*Author：AustinJiang
题目：最小费用流 
时间复杂度：O(n*m^2)
算法：EK算法，SPFA算法，最大流，最短路 */
#pragma GCC optimize(2)
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
const int N=410;
const int M=3e4+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,ans1,ans2,vis[N],inq[N],dist[N];
int tot=-1,to[M],val[M],cost[M],nxt[M],head[N],h[N];

inline void add(int u,int v,int c,int w){
	to[++tot]=v;
	val[tot]=c;
	cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}

inline int SPFA(){
	memcpy(h,head,sizeof(h));
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	queue<int> q;
	q.push(1);
	inq[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];~i;i=nxt[i]){
			int v=to[i];
			if(val[i]&&dist[v]>dist[u]+cost[i]){
				dist[v]=dist[u]+cost[i];
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dist[n];
}

inline int dfs(int u,int flow){
	if(u==n){
		ans2+=flow*dist[n];
		return flow;
	}
	vis[u]=1;
	int ans=0;
	for(int &i=h[u];~i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]&&val[i]&&dist[v]==dist[u]+cost[i]){
			int res=dfs(v,min(flow,val[i]));
			val[i]-=res,val[i^1]+=res;
			flow-=res,ans+=res;
			if(!res) dist[v]=-1;
			if(!flow) break;
		}
	}
	vis[u]=0;
	return ans;
}

inline void Dinic(){
	while(SPFA()!=INF)
		ans1+=dfs(1,INF);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v,c,w;
		cin>>u>>v>>c>>w;
		add(u,v,c,w);
		add(v,u,0,-w);
	}
	Dinic();
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}

