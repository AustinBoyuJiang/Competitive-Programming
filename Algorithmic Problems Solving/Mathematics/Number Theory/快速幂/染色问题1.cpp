/*Author：AustinJiang
题目：染色问题1
时间复杂度：O(log(m))
算法：快速幂，数学
来源：jmcoding
思路：m*(m-1)^(n-1)种染色法 */
#include<bits/stdc++.h>
#define int long long
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
const int MOD=1e9+7;

int n,m,ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ans=m;
	n--,m--;
	while(n){
		if(n&1) ans*=m,ans%=MOD;
		m*=m,m%=MOD;
		n>>=1;
	}
	cout<<ans<<endl;
	return 0;
}

