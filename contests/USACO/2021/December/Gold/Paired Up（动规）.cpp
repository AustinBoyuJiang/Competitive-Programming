/*Author：AustinJiang
题目：Paired Up
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
#define INF 0x3f3f3f3f*(t==1?1:-1)
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,k,dp[N][2];
PI a[N];

int mnx(int a,int b){
	if(t==1) return min(a,b);
	else return max(a,b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].fir>>a[i].sec;
	sort(a+1,a+n+1);
	dp[0][0]=dp[0][1]=0;
	dp[1][0]=a[1].sec; dp[1][1]=INF;
	for(int i=2;i<=n;i++){
		int x=INF,y=INF;
		if(a[i].fir-k<=a[i-1].fir)
			x=mnx(dp[i-2][0],dp[i-2][1]);
		if(a[i].fir-k<=a[i-2].fir){
			int pos=lower_bound(a+1,a+n+1,mp(a[i-1].fir-k,-0x3f3f3f3f))-a;
			if((i-pos)%2==0)
				y=mnx(dp[pos-1][0],dp[pos-1][1])+a[i-1].sec;
			else
				y=dp[pos][1]+a[i-1].sec;
		}
		dp[i][1]=mnx(x,y);
		
		if(a[i].fir-k>a[i-1].fir)
			dp[i][0]=mnx(dp[i-1][0],dp[i-1][1])+a[i].sec;
		else{
			int pos=lower_bound(a+1,a+n+1,mp(a[i].fir-k,-0x3f3f3f3f))-a;
			if((i-pos)%2==0)
				dp[i][0]=mnx(dp[pos-1][0],dp[pos-1][1])+a[i].sec;
			else
				dp[i][0]=dp[pos][1]+a[i].sec;
		}
	}
	cout<<mnx(dp[n][0],dp[n][1])<<endl;
	return 0;
}

