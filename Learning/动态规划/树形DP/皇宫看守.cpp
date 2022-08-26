#include<bits/stdc++.h>
#define int long long
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define for(i,n) for(int i=1;i<=n;i++)
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=LLONG_MAX;
const int N=2e4;

int n,r,flag[N];
VI Map[N];

struct node{
	int fa,u,v=INF;
}dp[N];

void dfs(int u){
	dp[u].v=INF;
	for(i,Map[u].size()){
		int v=Map[u][i-1];
		dfs(v);
		dp[u].fa+=min(dp[v].u,dp[v].v);
		dp[u].u+=min(dp[v].fa,min(dp[v].u,dp[v].v));
	}
	for(i,Map[u].size()){
		int v=Map[u][i-1];
		dp[u].v=min(dp[u].v,dp[u].fa-min(dp[v].v,dp[v].u)+dp[v].u);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(i,n){
		int u,m,v;
		cin>>u;
		cin>>dp[u].u>>m;
		for(j,m){
			cin>>v;
			Map[u].pb(v);
			flag[v]=true;
		}
	}
	for(i,n){
		if(flag[i]) continue;
		dfs(i);
		cout<<min(dp[i].u,dp[i].v)<<endl;
	}
	return 0;
}


