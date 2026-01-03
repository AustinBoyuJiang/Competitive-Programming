/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=110;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,a[N],sum[N],dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=0;
		sum[i]=sum[i-1]+a[i];
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			for(int k=l;k<r;k++){
				dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[r]-sum[l-1]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}

