/*Author：AustinJiang
题目：方格取数 
时间复杂度：O((n*m)^3)
算法：网络流，Dinic算法 */
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
const int INF=0x3f3f3f3f;
const int N=5010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,sum,pre[N],flow[N],a[N][N],Map[N][N];

int ID(int i,int j){
	return (i-1)*m+j;
}

bool OK(int x,int y,int k){
	if(x+dir[k][0]<1||x+dir[k][0]>n) return 0;
	if(y+dir[k][1]<1||y+dir[k][1]>m) return 0;
	return 1;
}

int bfs(){
	memset(pre,-1,sizeof(pre));
	memset(flow,0,sizeof(flow));
	queue<int> q;
	q.push(0);
	flow[0]=INF;
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==n*m+1) break;
		for(int v=0;v<=n*m+1;v++){
			if(v!=0&&Map[u][v]&&pre[v]==-1){
				pre[v]=u;
				flow[v]=min(flow[u],Map[u][v]);
				q.push(v);
			}
		}
	}
	return flow[n*m+1];
}

int maxFlow(){
	int ans=0,flow;
	while(flow=bfs()){
		for(int i=n*m+1;i;i=pre[i]){
			Map[pre[i]][i]-=flow;
			Map[i][pre[i]]+=flow;
		}
		ans+=flow;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			sum+=a[i][j];
			if(i+j&1) Map[ID(i,j)][n*m+1]+=a[i][j];
			else{
				Map[0][ID(i,j)]+=a[i][j];
				for(int k=0;k<4;k++)
					if(OK(i,j,k)) Map[ID(i,j)][ID(i+dir[k][0],j+dir[k][1])]+=INF;
			}
		}
	}
	cout<<sum-maxFlow()<<endl;
	return 0;
}

