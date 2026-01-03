/*Author：AustinJiang
题目：换教室 
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
const int N=2010;
const int V=310;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,v,e,p[N][2],dist[V][V];
double ans=INF,k[N],dp[N][N][2];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>v>>e;
	for(int i=1;i<=n;i++)
		cin>>p[i][0];
	for(int i=1;i<=n;i++)
		cin>>p[i][1];
	for(int i=1;i<=n;i++)
		cin>>k[i];
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dist[u][v]=dist[v][u]=min(dist[u][v],w);
	}
	for(int i=1;i<=v;i++)
		dist[i][i]=0;
	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0]=dp[i][j][1]=INF;
		}
	}
	dp[1][0][0]=0;
	dp[1][1][1]=0;
	for(int i=2;i<=n;i++)
		dp[i][0][0]=dp[i-1][0][0]+dist[p[i-1][0]][p[i][0]];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j][0]=min(dp[i-1][j][0] + dist[p[i-1][0]][p[i][0]],
						    dp[i-1][j][1] + k[i-1] * dist[p[i-1][1]][p[i][0]] + (1-k[i-1]) * dist[p[i-1][0]][p[i][0]]);
			dp[i][j][1]=min(k[i] * (dp[i-1][j-1][0] + dist[p[i-1][0]][p[i][1]]) +
						    (1-k[i]) * (dp[i-1][j-1][0] + dist[p[i-1][0]][p[i][0]]),
							k[i] * (dp[i-1][j-1][1] + k[i-1] * dist[p[i-1][1]][p[i][1]] + (1-k[i-1]) * dist[p[i-1][0]][p[i][1]]) +
						    (1-k[i]) * (dp[i-1][j-1][1] + (1-k[i-1]) * dist[p[i-1][0]][p[i][0]] + k[i-1]*dist[p[i-1][1]][p[i][0]]));
		}
	}
	for(int i=0;i<=min(n,m);i++)
		ans=min(ans,min(dp[n][i][0],dp[n][i][1]));
	printf("%.2lf",ans);
	return 0;
}

