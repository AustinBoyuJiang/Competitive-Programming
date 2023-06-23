/*Author：AustinJiang
题目：麻球繁衍 
时间复杂度：O()
算法：
来源：
思路：dp[i][j]表示第i天有j个毛球的概率 
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
const int N=1010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,m;
double p[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
		cin>>p[i];
	dp[1]=p[0];
	for(int i=2;i<=m;i++){
		double sum=1;
		for(int j=0;j<=n;j++){
			dp[i]+=p[j]*sum;
			sum*=dp[i-1];
		}
	}
	printf("%.7lf",pow(dp[m],k));
	return 0;
}

