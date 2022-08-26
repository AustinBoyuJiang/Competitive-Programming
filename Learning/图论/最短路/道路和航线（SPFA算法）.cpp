/*Author: AustinJiang
题目: 道路与航线 
时间复杂度: O(t*(r+p))
算法: 最短路，SPFA算法*/
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
const int T=2.5e4+10;

int t,r,p,s,avg,cnt[T],vis[T],dist[T];
VPI e[T];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>r>>p>>s;
	for(int i=1;i<=r;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	for(int i=1;i<=p;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
	}
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push_back(s);
	while(!q.empty()) {
		int u=q.front(); q.pop_front();
		vis[u]=0;
		for(auto i:e[u]) {
			int v=i.fir;
			if(dist[u]+i.sec<dist[v]) {
				dist[v]=dist[u]+i.sec;
				if(!vis[v]){
					vis[v]=1;
					avg=(avg*q.size()+dist[v])/(q.size()+1);
					if(dist[v]<dist[q.front()]||dist[v]<=avg) q.push_front(v);
					else q.pb(v);
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		if(dist[i]==INF) cout<<"NO PATH"<<endl;
		else cout<<dist[i]<<endl;
	}
	return 0;
}

