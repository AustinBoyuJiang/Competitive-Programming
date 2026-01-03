#include<bits/stdc++.h>
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=INT_MAX;
const int N=1e5+10;

//dp[i]表示以奶牛i结尾，每隔k+1头奶牛至少选一个的最小值
int n,k,e[N];
ll sum,ans,dp[N];
deque<ll> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>e[i];
		sum+=e[i];
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&dp[q.back()]>=dp[i-1])
			q.pop_back();
		q.push_back(i-1);
		while(q.front()<max(0,i-k-1))
			q.pop_front();
		dp[i]=dp[q.front()]+e[i];
		if(i>=n-k) ans=max(ans,sum-dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}

