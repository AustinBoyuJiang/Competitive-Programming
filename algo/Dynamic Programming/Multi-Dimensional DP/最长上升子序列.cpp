/*Author: AustinJiang
题目: 最长上升子序列 
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

//dp[i]表示以i结尾的最长上升子序列 
int n,ans,a[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)
			if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]); 
	}
	cout<<ans<<endl;
	return 0;
}

