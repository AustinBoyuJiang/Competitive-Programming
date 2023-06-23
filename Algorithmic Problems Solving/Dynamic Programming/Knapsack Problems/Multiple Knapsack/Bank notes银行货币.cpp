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
const int N=200;
const int V=2e4+10;

int n,v,c[N],m[N],dp[V];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++)
		cin>>m[i];
	cin>>v;
	dp[0]=0;
	memset(dp,63,sizeof(dp));
	for(int i=0;i<n;i++){
		if(c[i]*m[i]>=v){
			for(int j=c[i];j<=v;j++)
				dp[j]=min(dp[j],dp[j-c[i]]+1);
			continue;
		}
		int cnt=1;
		while(cnt<=m[i]){
			for(int j=v;j>=c[i]*cnt;j--)
				dp[j]=min(dp[j],dp[j-c[i]*cnt]+cnt);
			m[i]-=cnt;
			cnt*=2;
		}
		if(!m[i]) continue;
		for(int j=v;j>=c[i]*m[i];j--)
			dp[j]=min(dp[j],dp[j-c[i]*m[i]]+m[i]);
	}
	cout<<dp[v]<<endl; 
	return 0;
}

