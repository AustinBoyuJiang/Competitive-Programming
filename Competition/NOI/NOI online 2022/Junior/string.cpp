/*Author：AustinJiang
题目：string
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
const int N=510;
const int MOD=1e9+7;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,f[N];
ll dp[N][N][2];

void solve(){
	int n=0,m,l,k=0;
	ll ans=0;
	string t,a,b;
	memset(f,0,sizeof(f));
	memset(dp,0,sizeof(dp));
	cin>>l>>m>>t>>b;
	int cnt=0;
	for(auto x:t){
		if(x=='-'){
			cnt++;
			f[n-cnt+1]=cnt;
			k++;
		}
		else{
			cnt=0;
			a+=x,n++;
		}
	}
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(f+1,f+n+1);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(f[i]==1) dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1];//缺少组合数 
			if(f[i]>1) dp[i][j][0]+=dp[i-1][j][0];
			if(j>0&&a[i-1]==b[j-1]) dp[i][j][1]+=dp[i-1][j-1][0]+dp[i-1][j-1][1];
			dp[i][j][0]%=MOD;
			dp[i][j][1]%=MOD;
		}
	}
	for(int i=0;i<=k;i++){
		ans+=dp[n-i][m][0]+dp[n-i][m][1];
		ans%=MOD;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

