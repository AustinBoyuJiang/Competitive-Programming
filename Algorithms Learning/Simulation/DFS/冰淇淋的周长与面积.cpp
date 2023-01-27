/*Author: AustinJiang
题目: 冰淇淋的周长与面积
时间复杂度: O(n*n)
算法: DFS*/
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

int n,vis[N][N],Map[N][N];
int dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
string line;
PI ans;

PI dfs(int x,int y){
	if(x<1||x>n||y<1||y>n) return mp(0,1);
	if(!Map[x][y]) return mp(0,1);
	if(vis[x][y]) return mp(0,0);
	int area=1,len=0;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		PI res=dfs(x+dic[i][0],y+dic[i][1]);
		area+=res.fir;
		len+=res.sec;
	}
	return mp(area,len);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>line;
		for(int j=1;j<=n;j++)
			Map[i][j]=(line[j-1]=='#');
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			PI res=dfs(i,j);
			if(res.fir>ans.fir||(res.fir==ans.fir&&res.sec<ans.sec)) ans=res;
		}
	cout<<ans.fir<<' '<<ans.sec<<endl;
	return 0;
}
