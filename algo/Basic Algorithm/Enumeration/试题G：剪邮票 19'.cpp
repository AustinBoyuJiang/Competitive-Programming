/*Author：AustinJiang
题目：试题G:剪邮票 19'
时间复杂度：O(12^6)
算法：枚举，DFS 
来源：第七届蓝桥杯大赛个人赛省赛（软件类）C/C++ 大学A组 */
#include<bits/stdc++.h>
using namespace std;

int ans,cnt,f[6],vis[3][4],Map[3][4];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

inline bool OK(int x,int y){
	if(x<0||x>=3||y<0||y>=4) return 0;
	if(vis[x][y]||!Map[x][y]) return 0;
	return 1;
}

inline dfs2(int x,int y){
	vis[x][y]=1;
	cnt++;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(OK(nx,ny)) dfs2(nx,ny);
	}
}

inline bool check(){
	memset(vis,0,sizeof(vis));
	memset(Map,0,sizeof(Map));
	for(int i=1;i<=5;i++)
		Map[(f[i]-1)/4][(f[i]-1)%4]=1;
	cnt=0;
	dfs2((f[1]-1)/4,(f[1]-1)%4);
	return cnt==5;
}

inline void dfs1(int x,int pos){
	f[pos]=x;
	if(pos==5&&check()) ans++;
	for(int i=x+1;i<=12;i++)
		if(pos<5) dfs1(i,pos+1);
}

signed main(){
	dfs1(0,0);
	cout<<ans<<endl;
	return 0;
}

