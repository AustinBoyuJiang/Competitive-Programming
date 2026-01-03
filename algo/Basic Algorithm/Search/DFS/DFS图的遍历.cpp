/*Author：AustinJiang
题目：DFS图的遍历
时间复杂度：O(2^(n+m))
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
const int N=20;

int n,m,ans,Map[N][N];

void dfs(int x,int y){
	if(x>n||y>m) return;
	if(x==n&&y==m) ans++;
	if(Map[x+1][y]) dfs(x+1,y);
	if(Map[x][y+1]) dfs(x,y+1);
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
	cout<<ans<<endl;
	return 0;
}

