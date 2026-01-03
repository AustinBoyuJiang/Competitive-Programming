/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
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
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=110;
const int H=1010;
const int MOD=1e9+7;

int n,ans,mn=INF,h[N],dp[N][H],sum[N][H];

void solve(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		sum[i][0]=dp[i-1][0];
		for(int j=1;j<=h[i];j++){
			sum[i][j]=dp[i-1][j]+sum[i][j-1];
			sum[i][j]%=MOD;
		}
		for(int j=0;j<=h[i];j++)
			dp[i][j]=sum[i][h[i]-j];
	}
	ans+=dp[n][0];
	ans%=MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		mn=min(mn,h[i]);
	}
	if(n&1){
		for(int i=0;i<=mn;i++){
			solve();
			for(int i=1;i<=n;i++)
				h[i]--;
		}
	}
	else solve();
	cout<<ans<<endl;
	return 0;
}

