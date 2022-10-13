/*Author: AustinJiang
题目: 海贼王
时间复杂度: O(n)
算法: DFS，动态规划，树形DP*/
#include<bits/stdc++.h>
#define int long long
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
const int N=2e5+10;

int n,ans,a[N],sum[N],dp[N];
VI e[N];

ll get_sum(int u,int fa){
	sum[u]=a[u];
	for(auto v:e[u]){
		if(v==fa) continue;
		sum[u]+=get_sum(v,u);
	}
	return sum[u];
}

ll init(int u,int fa,int dist){
	int res=a[u]*dist;
	for(auto v:e[u]){
		if(v==fa) continue;
		res+=init(v,u,dist+1);
	}
	return res;
}

void dfs(int u,int fa){
	if(u!=1) dp[u]=dp[fa]+(sum[1]-sum[u])-sum[u];
	ans=max(ans,dp[u]);
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dp[1]=init(1,0,0);
	get_sum(1,0);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

