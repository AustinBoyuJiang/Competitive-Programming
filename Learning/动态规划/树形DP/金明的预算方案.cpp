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
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=LLONG_MAX;
const int N=1e2;
const int M=4e4;

int n,m,c[N],w[N],fa[N],dp[N][M];
vector<int> e[N];

void dfs(int u){
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		for(int j=0;j<=m-c[v];++j)
			dp[v][j]=dp[u][j]+c[v]*w[v];
		dfs(v);
		for(int j=c[v];j<=m;++j)
			dp[u][j]=max(dp[u][j],dp[v][j-c[v]]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>w[i]>>fa[i];
		e[fa[i]].pb(i);
	}
	dfs(0);
	cout<<dp[0][m]<<endl;
	return 0;
}


