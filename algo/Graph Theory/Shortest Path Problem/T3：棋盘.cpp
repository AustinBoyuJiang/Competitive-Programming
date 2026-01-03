/*Author：AustinJiang
题目：T3：棋盘
时间复杂度：O(n*log(n))
算法：最短路 
来源：NOIP2017 */
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
const int M=110;

int n,m,Map[M][M],dist[M*M],vis[M*M];
int dir1[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dir2[8][2]={{2,0},{-2,0},{0,2},{0,-2},{1,1},{1,-1},{-1,1},{-1,-1}};
VPI e[M*M];
PQ<PI,VPI,greater<PI>> q;

int ID(int x,int y){
	return x*m-m+y;
}

int OK(int x,int y){
	if(x<1||x>m||y<1||y>m) return 0;
	if(Map[x][y]==-1) return 0;
	return -1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	memset(Map,-1,sizeof(Map));
	for(int i=1;i<=n;i++){
		int x,y,c;
		cin>>x>>y>>c;
		Map[x][y]=c;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(!OK(i,j)) continue;
			for(int k=0;k<4;k++){
				int x=i+dir1[k][0],y=j+dir1[k][1];
				if(!OK(x,y)) continue;
				e[ID(i,j)].pb(mp(ID(x,y),Map[i][j]!=Map[x][y]));
			}
			for(int k=0;k<8;k++){
				int x=i+dir2[k][0],y=j+dir2[k][1];
				if(!OK(x,y)) continue;
				e[ID(i,j)].pb(mp(ID(x,y),2+(Map[i][j]!=Map[x][y])));
			}
		}
	}
	e[ID(m-1,m)].pb(mp(ID(m,m),2));
	e[ID(m,m-1)].pb(mp(ID(m,m),2));
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
	if(dist[ID(m,m)]==INF) cout<<-1<<endl;
	else cout<<dist[ID(m,m)]<<endl;
	return 0;
}

