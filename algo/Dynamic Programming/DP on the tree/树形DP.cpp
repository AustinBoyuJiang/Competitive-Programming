#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=6e3+10;
int n,val[MAXN],flag[MAXN],dp[MAXN][2];
vector<int> Map[MAXN];

void dfs(int u,int fa){
	dp[u][1]=val[u];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		dfs(v,u);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>val[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		Map[y].push_back(x);
		flag[x]=1;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			dfs(i,0);
			cout<<max(dp[i][0],dp[i][1])<<endl; 
		}
	}
}

