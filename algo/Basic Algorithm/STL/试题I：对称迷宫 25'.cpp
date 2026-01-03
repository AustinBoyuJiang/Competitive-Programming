/*Author：AustinJiang
题目：试题I：对称迷宫 25' 
时间复杂度：O(2^n)
算法：DFS，STL
来源：竞码编程-蓝桥杯模拟赛1（大学生组&青少年组）*/
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
const int N=20;
const int MOD=1e9+7;

int n,Map[N][N],f[N<<1];
set<int> flag;

void dfs(int x,int y,int k){
	if(x+y-1<=n) k=(k*26+Map[x][y])%MOD;
	f[x+y-1]=Map[x][y];
	if(x+y-1>n&&f[n*2-(x+y-1)]!=f[x+y-1]) return;
	if(x+y-1==n&&flag.count(k)) return;
	if(x==n&&y==n){
		flag.insert(k);
		return;
	}
	if(x<n) dfs(x+1,y,k);
	if(y<n) dfs(x,y+1,k);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;
			cin>>x;
			Map[i][j]=x-'A';
		}
	}
	dfs(1,1,0);
	cout<<flag.size()<<endl;
	return 0;
}

