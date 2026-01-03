/*Author：AustinJiang
题目：Comfortable Cows
时间复杂度：O(n^2)
算法：DFS
来源：USACO 2021 February Contest, Silver */
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
const int E=3e3+10;

int n,ans,Map[E][E],cnt[E][E],dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct node{
	int x,y; 
} st[N];

bool check(int x,int y){
	return Map[x][y]&&cnt[x][y]==3;
}

void add(int x,int y,bool k){
	if(k==0&&Map[x][y]){
		ans--;
		return;
	}
	ans+=k;
	Map[x][y]=1;
	for(int i=0;i<4;i++)
		cnt[x+dir[i][0]][y+dir[i][1]]++;
}

void dfs(int x,int y){
	int nx,ny;
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(!Map[dx][dy]) add(nx=dx,ny=dy,1);
	}
	if(check(nx,ny)) dfs(nx,ny);
	for(int i=0;i<4;i++){
		int dx=nx+dir[i][0];
		int dy=ny+dir[i][1];
		if(check(dx,dy)) dfs(dx,dy);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].x>>st[i].y;
		st[i].x+=1005,st[i].y+=1005;
		add(st[i].x,st[i].y,0);
		if(check(st[i].x,st[i].y)) dfs(st[i].x,st[i].y);
		for(int j=0;j<4;j++){
			int dx=st[i].x+dir[j][0];
			int dy=st[i].y+dir[j][1];
			if(check(dx,dy)) dfs(dx,dy);
		}
		cout<<ans<<endl;
	}
	return 0;
}

