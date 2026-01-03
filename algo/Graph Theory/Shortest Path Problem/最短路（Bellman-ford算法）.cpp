/*Author: AustinJiang
题目: 最短路 
时间复杂度: O(n*m)
算法: 最短路，Bellman-ford算法*/
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
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e3+10;
const int M=2e4+10;

int n,m,cnt,flag1,dist[N];

struct edge{
	int u,v,w;
}e[M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
		e[++cnt]={v,u,w};
	}
	for(int i=1;i<=n;i++){
		flag1=false;//判断负权环 
		bool flag2=false;//判断当前这次有没有更新，如果没有说明已经是最短路，则退出循环 
		for(int j=1;j<=cnt;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				flag1=flag2=true;
			}
		}
		if(!flag2) break;
	}
	if(flag1) cout<<"Nagetive circle"<<endl;
	else cout<<dist[n]<<endl;
	return 0;
}

