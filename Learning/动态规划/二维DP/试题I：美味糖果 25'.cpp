/*Author：AustinJiang
题目：试题I：美味糖果 25'
时间复杂度：O(n*m)
算法：动态规划，前缀和 
来源：竞码编程-蓝桥杯模拟赛2（大学生组&青少年组） 
思路：dp[i][j]表示前i种选了j包的方案数
dp[i][j]=dp[i-1][j]~dp[i-1][j-a[i]]*/
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
const int K=1e5+10;
const int MOD=998244353;

int n,m,now,a[N],sum[2][K];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m+1;i++)
		sum[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			int tmp=(sum[i-1&1][j+1]-sum[i-1&1][max(0,j-a[i])]+MOD)%MOD;
			sum[i&1][j+1]=(tmp+sum[i&1][j])%MOD;
		}
	}
	cout<<sum[n&1][m+1]<<endl;
	return 0;
}

