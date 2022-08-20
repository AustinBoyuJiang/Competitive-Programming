/*Author：AustinJiang
题目：过河 
时间复杂度：O(t*m)
算法：动态规划 
来源：NOIP2005提高组T2 */
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
const int N=2e4+10;

int n,l,s,t,m,ans,pos[N],vis[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l>>s>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>pos[i];
	sort(pos+1,pos+m+1);
	pos[++m]=l;
	for(int i=1;i<=m;i++){
		if(pos[i]-pos[i-1]>t) n+=(pos[i]-pos[i-1])%t+t;
		else n+=pos[i]-pos[i-1];
		vis[n]=1;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	ans=INF;
	for(int i=1;i<=n*2;i++){
		for(int j=s;j<=t;j++)
			if(i>=j) dp[i]=min(dp[i],dp[i-j]+vis[i-j]);
		if(i>=n) ans=min(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

