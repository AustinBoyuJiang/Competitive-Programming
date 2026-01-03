/*Author：AustinJiang
题目：骑士游历
时间复杂度：O(n^2)
算法：BFS
来源：
思路：
*/
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

struct node{
	int x,y,step;
};

int sx,sy,ex,ey,vis[N][N],dir[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
string s,e;
queue<node> q;

bool ok(int x,int y){
	if(x<1||x>8||y<1||y>8) return 0;
	if(vis[x][y]) return 0;
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>e;
	sx=s[0]-'a'+1;
	sy=s[1]-'0';
	ex=e[0]-'a'+1;
	ey=e[1]-'0';
	q.push((node){sx,sy,0});
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		int step=q.front().step;
		q.pop();
		vis[x][y]=1;
		if(x==ex&&y==ey){
			cout<<step<<endl;;
			return 0;
		}
		for(int i=0;i<8;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(ok(nx,ny)) q.push((node){nx,ny,step+1});
		}
	}
	return 0;
}

