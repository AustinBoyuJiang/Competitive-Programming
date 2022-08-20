/*Author：AustinJiang
题目：数独游戏 
时间复杂度：O(9^9)
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
const int N=10;

int a[N][N],r[N][N],c[N][N],g[N][N];

int get_grid(int x,int y){
	return (x-1)/3*3+(y-1)/3+1;
}

bool check(int x,int y,int v){
	if(a[x][y]) return 0;
	if(r[x][v]) return 0;
	if(c[y][v]) return 0;
	if(g[get_grid(x,y)][v]) return 0;
	return 1;
}

void dfs(int x,int y){
	if(x>9){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		exit(0);
	}
	if(!a[x][y]){
		for(int i=1;i<=9;i++){
			if(!check(x,y,i)) continue;
			a[x][y]=i,r[x][i]=c[y][i]=g[get_grid(x,y)][i]=1;
			if(y<9) dfs(x,y+1);
			else dfs(x+1,1);
			a[x][y]=0,r[x][i]=c[y][i]=g[get_grid(x,y)][i]=0;
		}
	}
	else{
		if(y<9) dfs(x,y+1);
		else dfs(x+1,1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=9;i++){
		string line;
		cin>>line;
		for(int j=1;j<=9;j++){
			a[i][j]=line[j-1]-'0';
			if(a[i][j]){
				r[i][a[i][j]]=1;
				c[j][a[i][j]]=1;
				g[get_grid(i,j)][a[i][j]]=1;
			}
		}
	}
	dfs(1,1);
	return 0;
}

