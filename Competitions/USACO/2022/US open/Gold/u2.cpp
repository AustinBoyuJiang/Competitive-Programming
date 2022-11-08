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
const int N=5010;
const int MOD=1e9+7;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,dp[N][N];
string A,B,a,b;

void solve(){
	cin>>n>>A>>B;
	a="",b="";
	for(auto x:A){
		if(x=='1') continue;
		if(x=='0') a="";
		a+=x;
	}
	for(auto x:B){
		if(x=='1') continue;
		if(x=='0') b="";
		b+=x;
	}
	for(int i=0;i<=a.size();i++)
		dp[i][0]=1;
	for(int i=0;i<=b.size();i++)
		dp[0][i]=1;
	for(int i=1;i<=a.size();i++){
		for(int j=1;j<=b.size();j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
			if((a[i-1]=='+')==(b[j-1]=='+')) dp[i][j]=(dp[i][j]-dp[i-1][j-1]+MOD)%MOD;
		}
	}
	cout<<dp[a.size()][b.size()]<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

