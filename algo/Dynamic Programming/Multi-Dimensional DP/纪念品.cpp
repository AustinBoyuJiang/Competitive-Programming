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
#define IOS ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int INF=LLONG_MAX;
const int N=150;
const int T=150;
const int M=1e4+10;

//dp[i]表示当天成本为i赚到的最大值 (状态压缩)
int n,m,t,val[T][N],dp[M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
			cin>>val[i][j];
	for(int i=1;i<t;i++){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++)
			if(val[i+1][j]>val[i][j]) 
				for(int k=val[i][j];k<=m;k++)
					dp[k]=max(dp[k],dp[k-val[i][j]]-val[i][j]+val[i+1][j]);
		m+=dp[m];
	}
	cout<<m<<endl;
	return 0;
}
