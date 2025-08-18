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
const int N=110;
const int H=2010;

int n,h,ans,f[N],d[N],t[N],t2[N],dp[N][H];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,-63,sizeof(dp));
	memset(dp[0],0,sizeof(dp[0]));
	cin>>n>>h;
	h*=60/5;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=2;i<=n;i++){
		cin>>t[i];
		t2[i]=t2[i-1]+t[i];
	}
	for(int i=1;i<=n;i++){		
		for(int j=t2[i];j<=h;j++){
			dp[i][j]=dp[i-1][j-t[i]];
			int k=1,fish=f[i],fishs=fish;
			while(fish>0&&j-t[i]-k>=0){
				dp[i][j]=max(dp[i][j],dp[i-1][j-t[i]-k]+fishs);
				k++;
				fish-=d[i];
				fishs+=fish;
				ans=max(ans,dp[i][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}





