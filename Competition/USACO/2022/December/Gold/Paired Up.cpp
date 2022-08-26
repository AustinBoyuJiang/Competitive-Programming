/*Author：AustinJiang
题目：Paired Up
时间复杂度：O(n*log(n))
算法：动态规划 
来源：USACO 2022 Gold */
#pragma GCC optimize(2)
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

int t,n,k,ans;
VPI cow;

int min_cost(){
	int n=cow.size();
	if(!n||!(n&1)) return 0;
	int res=INF;
	for(int i=0;i<n;i++){
		if(!(i&1)||cow[i+1].fir-cow[i-1].fir<=k)
			res=min(res,cow[i].sec);
	}
	return res;
}

int max_cost(){
	int n=cow.size();
	if(!n) return 0;
	VPI dp(n+1);
	dp[n]={0,-INF};
	for(int i=n-1;i>=0;i--){
		dp[i]=dp[i+1];
		int pos=upper_bound(cow.begin(),cow.end(),mp(cow[i].fir+k,INF))-cow.begin();
		if(i==n-1||cow[i+1].fir-cow[i-1].fir<=k||!(n-i&1))
			dp[i].fir=max(dp[i].fir,dp[pos].sec+cow[i].sec);
		if(i==n-1||cow[i+1].fir-cow[i-1].fir<=k||n-i&1)
			dp[i].sec=max(dp[i].sec,dp[pos].fir+cow[i].sec);
	}
	if(n&1) return dp[0].sec;
	else return dp[0].fir;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>n>>k;
	int lst=0;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(x-lst>k){
			if(t==1) ans+=min_cost();
			else ans+=max_cost();
			cow.clear();
		}
		cow.pb(mp(x,y));
		lst=x;
	}
	if(t==1) ans+=min_cost();
	else ans+=max_cost();
	cout<<ans<<endl;
	return 0;
}

