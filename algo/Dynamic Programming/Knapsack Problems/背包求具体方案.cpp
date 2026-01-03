/*Author: AustinJiang
题目: 背包求具体方案
时间复杂度: O(n*v)
算法: 背包问题，动态规划*/
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
const int V=1e3+10;

//dp[i][j]表示第i个物品体积为j的最大值
int n,v,c[N],w[N],dp[N][V];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>v;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>w[i];
	for(int i=n;i>=1;i--)
		for(int j=0;j<=v;j++){
			dp[i][j]=dp[i+1][j];
			if(j>=c[i]) dp[i][j]=max(dp[i][j],dp[i+1][j-c[i]]+w[i]);
		}
	for(int i=1;i<=n;i++)
		if(v>=c[i]&&dp[i][v]==dp[i+1][v-c[i]]+w[i]){
			v-=c[i];
			cout<<i<<' ';
		}
	return 0;
}

