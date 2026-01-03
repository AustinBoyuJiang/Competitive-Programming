/*Author: AustinJiang
题目: 最短路 
时间复杂度: O(n*m)
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
const int N=1e3+10;
const int M=2e4+10;

int n,m,flag,cnt[N],vis[N],dist[N];
VPI e[N];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	q.push_back(1);
	while(!q.empty()) {
		int u=q.front(); q.pop_front();
		vis[u]=0; cnt[u]++;
		if(cnt[u]>n){//判断负权环 
			flag=1;
			break;
		}
		for(int i=0;i<e[u].size();i++) {
			int v=e[u][i].fir;
			if(dist[u]+e[u][i].sec<dist[v]) {
				dist[v]=dist[u]+e[u][i].sec;
				if(!vis[v]){
					vis[v]=1;
					if(dist[v]<dist[q.front()]) q.push_front(v);
					else q.pb(v);
				}
			}
		}
	}
	if(flag) cout<<"Nagetive circle"<<endl;
	else cout<<dist[n]<<endl;	
	return 0;
}

