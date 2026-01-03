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
const int N=1e5+10;

int n,a[N][3],dp[N][3][3][2];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	dp[1][0][0][0]=dp[1][0][0][1]=a[1][0];
	dp[1][1][1][0]=dp[1][1][1][1]=a[1][1];
	dp[1][2][2][0]=dp[1][2][2][1]=a[1][2];
	for(int i=2;i<=n;i++){
		for(int j=0;j<3;j++){
			for(int s=0;s<3;s++){
				for(int d=0;d<=1;d++){
					if(i&1^d) for(int k=0;k<j;k++) dp[i][j][s][d]=max(dp[i][j][s][d],dp[i-1][k][s][d]+a[i][j]);
					else for(int k=j+1;k<3;k++) dp[i][j][s][d]=max(dp[i][j][s][d],dp[i-1][k][s][d]+a[i][j]);
				}
			}
		}
	}
	cout<<max(max(max(dp[n][0][1][0],dp[n][0][2][0]),dp[n][1][2][0]),
	max(max(dp[n][2][0][1],dp[n][2][1][1]),dp[n][1][0][1]))<<endl;
	return 0;
}

