/*Author: AustinJiang
题目: 连通块问题 
时间复杂度: O(n*m)
算法: BFS*/
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

string str;
int n,m,ans,dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool vis[N][N],Map[N][N];
deque<PI> q;

bool ok(int x,int y){
	if(x<1||y<1||x>n||y>m) return false;
	if(vis[x][y]) return false;
	if(!Map[x][y]) return false;
	return true;
}

void bfs(int i,int j){
	q.clear();
	q.pb(mp(i,j));
	while(!q.empty()){
		PI u=q.front();q.pop_front();
		int x=u.fir,y=u.sec;
		vis[x][y]=1;
		for(int i=0;i<8;i++){
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if(ok(nx,ny)) q.pb(mp(nx,ny));
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str;
		for(int j=1;j<=m;j++)
			Map[i][j]=str[j-1]=='W';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j]&&Map[i][j]){
				ans++;
				bfs(i,j);
			}
	cout<<ans<<endl;
	return 0;
}

