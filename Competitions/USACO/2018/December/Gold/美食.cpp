/*Author��AustinJiang
��Ŀ����ʳ
ʱ�临�Ӷȣ�O(n*log(n))
�㷨�����·��Dijkstra�㷨 
��Դ��USACO2018DEC Gold
˼·�����������·������ڶ��αȵ�һ�θ����ˣ�����ԳԵ��ʲ��� 
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

