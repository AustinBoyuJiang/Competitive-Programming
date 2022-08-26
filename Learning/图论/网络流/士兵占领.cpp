/*Author：AustinJiang
题目：士兵占领 
时间复杂度：O((n+m)^3)
算法：网络流，EK算法 */
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
const int N=210;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,k,pre[N],flow[N],Map[N][N];

int bfs(){
	memset(pre,-1,sizeof(pre));
	memset(flow,0,sizeof(flow));
	queue<int> q;
	q.push(0);
	flow[0]=INF;
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==n+m+1) break;
		for(int v=0;v<=n+m+1;v++){
			if(v!=0&&Map[u][v]&&pre[v]==-1){
				pre[v]=u;
				flow[v]=min(flow[u],Map[u][v]);
				q.push(v);
			}
		}
	}
	return flow[n+m+1];
} 

int maxFlow(){
	int ans=0,flow;
	while(flow=bfs()){
		for(int i=n+m+1;i;i=pre[i]){
			Map[i][pre[i]]+=flow;
			Map[pre[i]][i]-=flow;
		}
		ans+=flow;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>Map[0][i];
	for(int i=n+1;i<=n+m;i++)
		cin>>Map[i][n+m+1];
	for(int i=1;i<=n;i++)
		for(int j=n+1;j<=n+m;j++)
			Map[i][j]=INF;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		Map[x][y]=0;
	}
	cout<<maxFlow()<<endl;
	return 0;
}

