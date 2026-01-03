/*Author: AustinJiang
题目: 合唱队 
时间复杂度: O(n^2)
算法: 动态规划*/
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
const int MOD=19650827;

//dp[l][r][0]表示区间(l,r)中插入到右边的方案数 
//dp[l][r][1]表示区间(l,r)中插入到左边的方案数 
int n,a[N],dp[N][N][2];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i][0]=1;
	}
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			dp[l][r][0]=((a[l]<a[l+1]?dp[l+1][r][0]:0)+(a[l]<a[r]?dp[l+1][r][1]:0))%MOD; 
			dp[l][r][1]=((a[r]>a[r-1]?dp[l][r-1][1]:0)+(a[r]>a[l]?dp[l][r-1][0]:0))%MOD;
		}
	cout<<(dp[1][n][0]+dp[1][n][1])%MOD<<endl;
	return 0;
}

