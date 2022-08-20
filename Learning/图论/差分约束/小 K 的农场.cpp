/*Author: AustinJiang
题目: 小 K 的农场 
时间复杂度: O(n*m)
算法: 差分约束，最短路，SPFA算法*/
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
const int N=1e4+10;

int n,m,vis[N],dist[N];
VPI e[N];
deque<int> q;

bool SPFA(int u){
	vis[u]=1;
	for(auto i:e[u]){
		int v=i.fir;
		if(dist[u]+i.sec<dist[v]){
			dist[v]=dist[u]+i.sec;
			if(vis[v]) return 0;
			if(!SPFA(v)) return 0;
		}
	}
	vis[u]=0;
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int o,a,b,c;
	for(int i=1;i<=m;i++){
		cin>>o;
		if(o==1){
			cin>>a>>b>>c;
			e[a].pb(mp(b,-c));
		}
		else if(o==2){
			cin>>a>>b>>c;
			e[b].pb(mp(a,c));
		}
		else{
			cin>>a>>b;
			e[a].pb(mp(b,0));
			e[b].pb(mp(a,0));
		}		
	}
	for(int i=1;i<=n;i++)
		e[0].pb(mp(i,0));
	memset(dist,0x3f,sizeof(dist));
	dist[0]=0;
	if(SPFA(0)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

