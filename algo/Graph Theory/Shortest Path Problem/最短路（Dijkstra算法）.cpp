/*Author: AustinJiang
题目: 最短路 
时间复杂度: O(n*log(n))
算法: 最短路，Dijkstra算法，优先队列优化*/
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
const int INF=INT_MAX;
const int N=1e5+10;

int n,m,vis[N],dist[N];
vector<PI > Map[N];
PQ<PI,VPI,greater<PI> > q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Map[u].pb(mp(w,v));
	}
	memset(dist,63,sizeof(dist));
	dist[1]=0;
	q.push(mp(0,1));
	while(!q.empty()){
		int u=q.top().sec; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<Map[u].size();i++){
			int v=Map[u][i].sec;
			if(dist[u]+Map[u][i].fir<dist[v]){
				dist[v]=dist[u]+Map[u][i].fir;
				q.push(mp(dist[v],v));
			}
		}
	}
	cout<<dist[n]<<endl;
	return 0;
}

