/*Author: AustinJiang
题目: 股票交易 
时间复杂度: O(t*MaxP)
算法: 单调队列，动态规划*/
#include<bits/stdc++.h>
using namespace std;
const int INF=INT_MAX;
const int T=2e3+10;
const int P=2e3+10;

//dp[i][j]表示第i天手里有j张股票的最大收益 
int t,maxp,w,ans,ap[T],bp[T],as[T],bs[T],dp[T][P];
deque<int> buy,sell;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>maxp>>w;
	for(int i=1;i<=t;i++)
		cin>>ap[i]>>bp[i]>>as[i]>>bs[i];
	memset(dp,-63,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=t;i++){
		int l=max(0,i-w-1);
		buy.clear(),sell.clear();
		for(int j=0;j<=maxp;j++){
			dp[i][j]=dp[i-1][j];
			while(!buy.empty()&&buy.front()<j-as[i]) buy.pop_front();
			while(!buy.empty()&&dp[l][buy.back()]+buy.back()*ap[i]<=dp[l][j]+j*ap[i]) buy.pop_back();
			buy.push_back(j);
			dp[i][j]=max(dp[i][j],dp[l][buy.front()]+buy.front()*ap[i]-j*ap[i]);
		}
		for(int j=maxp;j>=0;j--){
			while(!sell.empty()&&sell.front()>j+bs[i]) sell.pop_front();
			while(!sell.empty()&&dp[l][sell.back()]+sell.back()*bp[i]<=dp[l][j]+(j)*bp[i]) sell.pop_back();
			sell.push_back(j);
			dp[i][j]=max(dp[i][j],dp[l][sell.front()]+sell.front()*bp[i]-j*bp[i]);
			ans=max(ans,dp[t][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

