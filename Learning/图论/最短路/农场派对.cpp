/*Author: AustinJiang
题目: 农场派对 
时间复杂度: O(n*log(n))
算法: 最短路，Dijkstra算法*/
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
const int N=1e3+10;

int n,m,x,ans,vis[N],de[N],ds[N];
VPI e[N],s[N];

void dijkstra(VPI e[N],int dist[N]){
	PQ<PI,VPI,greater<PI>> q;
	memset(dist,0x3f,sizeof(de));
	memset(vis,0,sizeof(vis));
	q.push(mp(0,x));
	dist[x]=0;
	while(!q.empty()){
		int u=q.top().sec;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.sec;
			if(dist[u]+i.fir<dist[v]){
				dist[v]=dist[u]+i.fir;
				q.push(mp(dist[v],v));
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++){
		int a,b,t;
		cin>>a>>b>>t;
		e[a].pb(mp(t,b));
		s[b].pb(mp(t,a));
	}
	dijkstra(e,de);
	dijkstra(s,ds);
	for(int i=1;i<=n;i++)
		ans=max(ans,de[i]+ds[i]);
	cout<<ans<<endl;
	return 0;
}

