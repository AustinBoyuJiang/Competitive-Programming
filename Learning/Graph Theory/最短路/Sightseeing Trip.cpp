/*Author: AustinJiang
题目: Sightseeing Trip
时间复杂度: O(n^4)
算法: 最短路，Floyd算法*/
#include<bits/stdc++.h>
#define int long long
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
const int N=110;

//e[i][j]表示i到j的边
//pos[i][j]表示i到j的最短路经过的点k
//dist[i][j]表示i到j的最短路 
int n,m,cnt,ans=INF,path[N],e[N][N],pos[N][N],dist[N][N];

void dfs(int i,int j){
	if(!pos[i][j]) return;
	int k=pos[i][j];
	dfs(i,k);
	path[++cnt]=k;
	dfs(k,j);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(e,0x3f,sizeof(e));
	for(int i=1;i<=n;i++)
		e[i][i]=0;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[x][y]=e[y][x]=min(e[x][y],z);
	}
	memcpy(dist,e,sizeof(dist));
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				if((ll)e[i][k]+e[j][k]+dist[i][j]<ans){
					ans=e[i][k]+e[j][k]+dist[i][j];
					cnt=0;
					path[++cnt]=k;
					path[++cnt]=i;
					dfs(i,j);
					path[++cnt]=j;
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dist[i][k]+dist[j][k]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[j][k];
					pos[i][j]=k;
				}
	}
	if(ans==INF) cout<<"No solution"<<endl;
	else for(int i=1;i<=cnt;i++) cout<<path[i]<<' ';
	return 0;
}

