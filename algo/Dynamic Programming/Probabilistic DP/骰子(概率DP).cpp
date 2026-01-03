/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int long long
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
const int N=30;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,ans1,ans2,dp[N][N*6];

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=6;i++)
		dp[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=i;j<=i*6;j++)
			for(int k=1;k<=6;k++)
				if(j-k>0) dp[i][j]+=dp[i-1][j-k];
	for(int i=m;i<=n*6;i++)
		ans1+=dp[n][i];
	for(int i=n;i<=n*6;i++)
		ans2+=dp[n][i];
	int x=gcd(ans1,ans2);
	if(ans1==0) cout<<0<<endl;
	else if(ans1==ans2) cout<<1<<endl;
	else cout<<ans1/x<<"/"<<ans2/x<<endl;
	return 0;
}

