#include<bits/stdc++.h>
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
const int INF=INT_MAX;
const int N=510;
const int T=4e6+10;

//dp[i]表示以第i分钟结尾，之前学生的等待时间之和的最小值 
int n,m,t,dis,ans=INF,cnt[T],sum[T],dp[T];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t;
		dis=max(dis,t);
		cnt[t]++;
		sum[t]+=t;
	}
	for(int i=1;i<dis+m;i++){
		cnt[i]+=cnt[i-1];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<dis+m;i++){
		if(i>=m&&cnt[i]==cnt[i-m]){
            dp[i]=dp[i-m];
            continue;
        }
		dp[i]=cnt[i]*i-sum[i];
		for(int j=max(0,i-m*2+1);j<=i-m;j++)
			dp[i]=min(dp[i],dp[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]));
	}
	for(int i=dis;i<dis+m;i++)
        ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}

