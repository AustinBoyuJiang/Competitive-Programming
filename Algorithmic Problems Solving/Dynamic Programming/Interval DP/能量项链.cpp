/*Author：AustinJiang
题目：能量项链 
时间复杂度：O(n^3)
算法：动态规划 
来源：NOIP提高组T1
思路：dp[i][j]表示合并区间(i,j)释放的最大能量 
*/
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
const int N=210;

int n,ans,a[N],dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n*2;i++)
		if(i<=n) cin>>a[i];
		else a[i]=a[i-n];
	for(int l=2;l<=n;l++){//长度 
		for(int i=1;i+l-1<=n*2;i++){//左端点 
			int j=i+l-1;//右端点 
			for(int k=i;k<j;k++)//断点 
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl; 
	return 0;
}

