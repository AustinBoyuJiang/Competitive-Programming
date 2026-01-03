/*Author：AustinJiang
题目：最大流 
时间复杂度：O(n*m^2)
算法：EK算法，网络流 */
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

int n,m,s,t,pre[N],flow[N],Map[N][N];

int BFS(){
	memset(pre,-1,sizeof(pre));
	memset(flow,0,sizeof(flow));
	queue<int> q;
	q.push(s);
	flow[s]=INF;
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(u==t) break;
		for(int v=1;v<=n;v++){
			if(v!=s&&pre[v]==-1&&Map[u][v]){
				pre[v]=u;
				flow[v]=min(flow[u],Map[u][v]);
				q.push(v);
			}
		}
	}
	return flow[t];
}

int maxFlow(){
	int flow,res=0;
	while(flow=BFS()){
		for(int i=t;i!=s;i=pre[i]){
			Map[i][pre[i]]+=flow;
			Map[pre[i]][i]-=flow;
		}
		res+=flow;
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Map[u][v]+=w;
	}
	cout<<maxFlow()<<endl;
	return 0;
}

