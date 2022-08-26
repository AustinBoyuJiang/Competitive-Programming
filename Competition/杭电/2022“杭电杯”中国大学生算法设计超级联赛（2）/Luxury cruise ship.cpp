/*
 * Author: Austin Jiang
 * Date: 7/20/2022 10:00:06 PM
 * Problem:
 * Description:
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
#define random(a,b) rand()%(b-a+1)+a
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 8e4;
int T=1,n;
ll dp[N];

void solve(int Case){
	cin>>n;
	ll ans=n/(365*31*7)*31*7;
	n%=365*31*7;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	rep(i,1,n){
		if(i>=7) dp[i]=min(dp[i],dp[i-7]+1);
		if(i>=31) dp[i]=min(dp[i],dp[i-31]+1);
		if(i>=365) dp[i]=min(dp[i],dp[i-365]+1);
	}
	if(dp[n]==LLINF) cout<<-1<<endl;
	else cout<<ans+dp[n]<<endl;
}

signed main(){
	cin>>T;
	rep(Case,1,T) solve(Case);
	return 0;
}

/* stuff you should look for
    * read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow, check edge case
    * Debug: (b) create your own test case
    * Debug: (c) ╤тед
*/

