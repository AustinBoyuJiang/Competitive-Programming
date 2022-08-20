//Author: AustinJiang
//题目: 绿色通道 
//时间复杂度: O(n*log(t))
//算法: 二分,单调队列,动态规划 
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=INT_MAX;
const int N=5e4+10;
 
//dp[i]表示以i题结尾，最多隔k道题的时间消耗最小值 
int n,t,l,r,ans,a[N],dp[N];

bool check(int k){
	deque<int> q;
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&q.front()<i-k-1)
			q.pop_front();
		while(!q.empty()&&dp[q.back()]>=dp[i-1])
			q.pop_back();
		q.push_back(i-1);
		dp[i]=dp[q.front()]+a[i];
		if(i>=n-k&&dp[i]<=t) return true;
	}
	return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	l=0,r=t;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

