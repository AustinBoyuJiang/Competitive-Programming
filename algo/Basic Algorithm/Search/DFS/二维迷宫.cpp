/*Author：AustinJiang
题目：二维迷宫
时间复杂度：O(n*m)
算法：DFS */
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

int n,m,ans,Map[N][N],vis[N][N],dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool ok(int x,int y){
	if(ans) return 0;
	if(vis[x][y]) return 0;
	if(!Map[x][y]) return 0;
	return 1;
}

void dfs(int x,int y){
	if(x==n&&y==m) ans=1;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(ok(nx,ny)) dfs(nx,ny);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string line;
		cin>>line;
		for(int j=1;j<=m;j++)
			Map[i][j]=line[j-1]=='.';
	}
	dfs(1,1);
	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

