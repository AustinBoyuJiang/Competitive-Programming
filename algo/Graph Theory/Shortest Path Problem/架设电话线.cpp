/*Author: AustinJiang
题目: 架设电话线 
时间复杂度: O(n*log(MaxW))
算法: 二分，最短路，Dijkstra算法*/
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

int n,p,k,l=0,r,ans=-1,dist[N],vis[N];
VPI e[N];

bool check(int x){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	deque<int> q;
	dist[1]=0;
	q.pb(1);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		if(vis[u]) continue;
		vis[u]=1;
		for(PI i:e[u]){
			int v=i.fir;
			int w=i.sec>x;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				if(w) q.pb(v);
				else q.push_front(v);
			}
		}
	}
	return dist[n]<=k;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p>>k;
	for(int i=1;i<=p;i++){
		int u,v,w;
		cin>>u>>v>>w;
		r=max(r,w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

