/*Author: AustinJiang
题目: DAG图最短路 
时间复杂度: O(n)
算法: 拓扑序*/
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
const int N=1e6+10;

int n,m,cnt[N],dist[N];
VPI e[N];
queue<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		cnt[v]++; 
	}
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto i:e[u]){
			int v=i.fir;
			dist[v]=min(dist[v],dist[u]+i.sec);
			if(!--cnt[v]) q.push(v);
		}
	}
	cout<<dist[n]<<endl;
	return 0;
}

