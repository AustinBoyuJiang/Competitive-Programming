/*Author: AustinJiang
题目: 多源最短路
时间复杂度: O(n*n*n)
算法: 最短路，Floyd算法*/
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
#define PQ priority_queue
using namespace std;
const int INF=INT_MAX;
const int N=110;

//dp[i][j]表示从i到j的最短距离
int n,m,q;
ll a,b,c,dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		dp[a][b]=min(dp[a][b],c);
	}
	for(int k=1;k<=n;k++)//经过前k个点 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		if(dp[a][b]>INF) cout<<"Nothing to say!"<<endl;
		else cout<<dp[a][b]<<endl;
	}
	return 0;
}

