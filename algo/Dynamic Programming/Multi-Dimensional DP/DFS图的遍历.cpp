/*Author：AustinJiang
题目：DFS图的遍历
时间复杂度：O(n*m)
算法：动态规划 */
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

int n,m,Map[N][N],dp[N][N];

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
	dp[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			dp[i][j]=Map[i-1][j]*dp[i-1][j]+Map[i][j-1]*dp[i][j-1];
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}

