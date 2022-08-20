/*Author：AustinJiang
题目：牛为什么过马路1
时间复杂度：O(n^2*log(n^2))
算法：最短路 
来源：USACO 2017 Gold Problem1 */
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

int n,t,val[N],vis[N],dist[N];
PQ<PI,VPI,greater<PI>> q;
VPI e[N];

int ID(int x,int y){
	return (x-1)*n+y;
}

bool OK(int x,int y){
	if(x<1||y<1||x>n||y>n) return 0;
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>val[ID(i,j)];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int u=ID(i,j);
			if(OK(i+1,j)) e[u].pb(mp(ID(i+1,j),t*3+val[ID(i+1,j)]));
			if(OK(i,j+1)) e[u].pb(mp(ID(i,j+1),t*3+val[ID(i,j+1)]));
			if(OK(i-1,j)) e[u].pb(mp(ID(i-1,j),t*3+val[ID(i-1,j)]));
			if(OK(i,j-1)) e[u].pb(mp(ID(i,j-1),t*3+val[ID(i,j-1)]));
			for(int x=-3;x<=3;x++){
				int y=3-abs(x);
				if(OK(i+x,j+y)) e[u].pb(mp(ID(i+x,j+y),t*3+val[ID(i+x,j+y)]));
				if(y&&OK(i+x,j-y)) e[u].pb(mp(ID(i+x,j-y),t*3+val[ID(i+x,j-y)]));
			}
		}
	e[ID(n-1,n)].pb(mp(ID(n,n),t));
	e[ID(n,n-1)].pb(mp(ID(n,n),t));
	e[ID(n-2,n)].pb(mp(ID(n,n),t*2));
	e[ID(n,n-2)].pb(mp(ID(n,n),t*2));
	e[ID(n-1,n-1)].pb(mp(ID(n,n),t*2));
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	q.push(mp(0,1));
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
	cout<<dist[ID(n,n)]<<endl;
	return 0;
}

