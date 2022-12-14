/*Author：AustinJiang
题目：美食
时间复杂度：O(n*log(n))
算法：最短路，Dijkstra算法 
来源：USACO2018DEC Gold
思路：跑两次最短路，如果第二次比第一次更短了，则可以吃到甘草捆 
*/
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

int n,m,k,vis[N],dist[N];
PQ<PI,VPI,greater<PI>> q;
VPI e[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,t;
		cin>>a>>b>>t;
		e[a].pb(mp(b,t));
		e[b].pb(mp(a,t));
	}
	memset(dist,0x3f,sizeof(dist));
	dist[n]=0;
	q.push(mp(0,n));
	while(!q.empty()){
		int u=q.top().sec; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.fir,w=i.sec;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				q.push(mp(dist[v],v));
			}
		}
	}
	for(int i=1;i<=k;i++){
		int pos,x;
		cin>>pos>>x;
		dist[pos]-=x;
		q.push(mp(dist[pos],pos));
	}
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.top().sec; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.fir,w=i.sec;
			if(dist[u]+w<=dist[v]){
				dist[v]=dist[u]+w;
				q.push(mp(dist[v],v));
			}
		}
	}
	for(int i=1;i<n;i++)
		cout<<vis[i]<<endl;
	return 0;
}

