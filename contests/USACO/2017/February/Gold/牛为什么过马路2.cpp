/*Author：AustinJiang
题目：牛为什么过马路2
时间复杂度：O(n^2)
算法：动态规划 
来源：USACO 2017 February Gold*/
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

int n,a[N],b[N],dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			if(abs(a[i]-b[j])<=4) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			else dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}

