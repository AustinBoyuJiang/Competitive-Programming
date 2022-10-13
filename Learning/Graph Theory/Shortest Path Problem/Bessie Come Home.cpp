/*Author：AustinJiang
题目：Bessie Come Home
时间复杂度：O(52*log(52))
算法：最短路，Dijkstra算法 
来源：USACO Tranning */
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
const int N=100;

int n,ans,dist[N],vis[N];
PQ<PI,VPI,greater<PI>> q;
VPI e[N];

int id(char x){
	int res;
	if(x<='Z') res=x-65;
	else res=x-97+26;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		int len;
		cin>>a>>b>>len;
		e[id(a)].pb(mp(id(b),len));
		e[id(b)].pb(mp(id(a),len));
	}
	memset(dist,0x3f,sizeof(dist));
	q.push(mp(0,25));
	dist[25]=0;
	while(!q.empty()){
		int u=q.top().sec; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.fir;
			if(dist[u]+i.sec<dist[v]){
				dist[v]=dist[u]+i.sec;
				q.push(mp(dist[v],v));
			}
		}
	}
	for(int i=0;i<25;i++)
		if(dist[i]<dist[ans]) ans=i;
	cout<<(char)(ans+65)<<' '<<dist[ans]<<endl;
	return 0;
}

