#include<bits/stdc++.h>
#define int long long
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
const int N=18;

//dp[i][j]表示当前在i点，以已经经过了点j集合的最小值 
int n,tot,e[N][N],dp[N][1<<N];

int dfs(int u,int status){
	if(dp[u][status]>INF){
		if(status==tot) dp[u][status]=e[u][0];
		else{
			for(int v=0;v<=n;v++){
				if(status&1<<v) continue;
				dp[u][status]=min(dp[u][status],dfs(v,status|1<<v)+e[u][v]);
			}
		}
	}
	return dp[u][status];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	tot=(1<<n+1)-1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			cin>>e[i][j];
	memset(dp,63,sizeof(dp));
	cout<<dfs(0,1)<<endl;
	return 0;
}

