/*Author: AustinJiang
题目: 最长上升子序列 
时间复杂度: O(n*log(n))
算法: 动态规划，二分*/
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
const int N=1e5+10;

//dp[i]表示长度为i的最长上升子序列的结尾 
int n,ans,a[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0; 
	for(int i=1;i<=n;i++){
		int l=1,r=ans+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]>dp[mid-1]) l=mid+1;
			else r=mid-1;
		}
		dp[l-1]=min(dp[l-1],a[i]);
		ans=max(ans,l-1);
	}
	cout<<ans<<endl;
	return 0;
}

