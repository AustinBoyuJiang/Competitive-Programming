/*Author：AustinJiang
题目：最小费用流 
时间复杂度：O(n*m^2)
算法：EK算法，SPFA算法，最大流，最短路 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
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
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=5010;
const int M=3e4+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,pre[N],inq[N],flow[N],dist[N];
int tot=-1,to[M],val[M],cost[M],nxt[M],head[N];

void add(int u,int v,int c,int w){
	to[++tot]=v;
	val[tot]=c;
	cost[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}

PI bfs(){
	memset(flow,0,sizeof(flow));
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;
	q.push(1);
	flow[1]=INF;
	dist[1]=0;
	inq[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];~i;i=nxt[i]){
			int v=to[i];
			if(dist[v]>dist[u]+cost[i]&&val[i]){
				pre[v]=i^1;
				flow[v]=min(flow[u],val[i]);
				dist[v]=dist[u]+cost[i];
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return mp(flow[n],dist[n]);
}

PI maxFlow(){
	int ans1=0,ans2=0;
	PI flow;
	while((flow=bfs()).fir){
		for(int i=n;i!=1;i=to[pre[i]]){
			val[pre[i]]+=flow.fir;
			val[pre[i]^1]-=flow.fir;
		}
		ans1+=flow.fir;
		ans2+=flow.fir*flow.sec;
	}
	return mp(ans1,ans2);
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
	PI ans=maxFlow();
	cout<<ans.fir<<" "<<ans.sec<<endl;
	return 0;
}

