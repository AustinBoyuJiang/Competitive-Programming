/*Author: AustinJiang
题目: 王者荣耀之皇黄忠 
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
const int N=3e5+10;

int n,m,ans1,ans2,a[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,-0x3f,sizeof(dp));
	dp[0]=INF;
	for(int i=1;i<m;i++){
		if(a[i]<=a[m]) continue;
		int l=1,r=ans1+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]<dp[mid-1]) l=mid+1;
			else r=mid-1;
		}
		dp[l-1]=max(dp[l-1],a[i]);
		ans1=max(ans1,l-1);
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0]=INF;
	for(int i=m+1;i<=n;i++){
		if(a[i]>=a[m]) continue;
		int l=1,r=ans2+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]<dp[mid-1]) l=mid+1;
			else r=mid-1;
		}
		dp[l-1]=max(dp[l-1],a[i]);
		ans2=max(ans2,l-1);
	}
	cout<<ans1+ans2+1<<endl;
	return 0;
}
