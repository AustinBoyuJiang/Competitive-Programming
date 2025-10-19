/*Author：AustinJiang
题目：牛为什么过马路3 
时间复杂度：O(n^n)
算法：DFS，连通块，并查集 
来源：USACO 2017 February Silver */
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
const int N=110;

int n,k,r,ans,x[N*N],y[N*N],f[N*N],vis[N][N],flag[N][N][4];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int ID(int x,int y){
	return (x-1)*n+y;
}

bool OK(int x,int y){
	if(x<1||x>n||y<1||y>n) return 0;
	if(vis[x][y]) return 0;
	return 1;
}

int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	f[fx]=fy;
}

void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		if(flag[x][y][i]) continue;
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(!OK(nx,ny)) continue;
		merge(ID(x,y),ID(nx,ny));
		dfs(nx,ny);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>r;
	for(int i=1;i<=r;i++){
		int x1,y1,x2,y2,tmp;
		cin>>x1>>y1>>x2>>y2;
		tmp=x1;
		x1=min(x1,x2);
		x2=max(tmp,x2);
		tmp=y1;
		y1=min(y1,y2);
		y2=max(tmp,y2);
		if(x1<x2) flag[x1][y1][0]=1;
		if(y1<y2) flag[x1][y1][1]=1;
		if(x2>x1) flag[x2][y2][2]=1;
		if(y2>y1) flag[x2][y2][3]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[ID(i,j)]=ID(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!vis[i][j]) dfs(i,j);
	for(int i=1;i<=k;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			if(find(ID(x[i],y[i]))!=find(ID(x[j],y[j]))) ans++;
	cout<<ans<<endl;
	return 0;
}

