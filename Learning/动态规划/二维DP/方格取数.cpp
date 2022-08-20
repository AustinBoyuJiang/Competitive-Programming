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
const int N=1e3+10;
const int M=1e3+10; 

int n,m,a[N][M],x[N],y[N],dp[N][M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			dp[i][j]=-INF; 
		}
	dp[1][1]=a[1][1];
	for(int i=2;i<=n;i++)
		dp[i][1]=dp[i-1][1]+a[i][1];
	for(int j=2;j<=m;j++){
		x[1]=dp[1][j-1]+a[1][j];
		for(int i=2;i<=n;i++)
			x[i]=max(dp[i][j-1],x[i-1])+a[i][j];
		y[n]=dp[n][j-1]+a[n][j];
		for(int i=n-1;i>=1;i--)
			y[i]=max(dp[i][j-1],y[i+1])+a[i][j];
		for(int i=1;i<=n;i++)
			dp[i][j]=max(x[i],y[i]);
	}
	cout<<dp[n][m]<<endl;
	return 0;
}

