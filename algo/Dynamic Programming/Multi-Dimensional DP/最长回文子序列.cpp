/*Author: AustinJiang
题目: 回文子序列
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

//dp[l][r]表示(l,r)区间的最长回文子序列
int n,dp[N][N];
string s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(s[l-1]==s[r-1])
				dp[l][r]=max(dp[l+1][r],max(dp[l][r-1],dp[l+1][r-1]+2));
			else
				dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
		}
	cout<<dp[1][n]<<endl;
	return 0;
}

