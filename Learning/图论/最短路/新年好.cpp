/*Author: AustinJiang
题目: 新年好
时间复杂度: O(6*n*log(n)+!5)
算法: 最短路，Dijkstra算法，DFS*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int M=1e5+10;

int n,m,ans=INF,start[6],vis[6],dist[6][N];
VPI e[M];

void dijkstra(int x,int pos){
	int vis[N];
	PQ<PI,VPI,greater<PI> > q;
	memset(dist[x],0x3f,sizeof(dist[x]));
	memset(vis,0,sizeof(vis));
	q.push(mp(0,pos));
	dist[x][pos]=0;
	while(!q.empty()){
		int u=q.top().sec;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.sec;
			int w=i.fir;
			if(dist[x][u]+w<dist[x][v]){
				dist[x][v]=dist[x][u]+w;
				q.push(mp(dist[x][v],v));
			}
		}
	}
}

int dfs(int pos,int dis,int dep){
	if(dep==5) return dis;
	int ans=INF;
	for(int i=0;i<=5;i++){
		if(!vis[i]){
			vis[i]=1;
			ans=min(ans,dfs(i,dis+dist[pos][start[i]],dep+1));
			vis[i]=0;
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	start[0]=1;
	for(int i=1;i<=5;i++)
		cin>>start[i];
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(w,v));
		e[v].pb(mp(w,u));
	}
	for(int i=0;i<=5;i++)
		dijkstra(i,start[i]);
	vis[0]=1;
	cout<<dfs(0,0,0)<<endl;
	return 0;
}

