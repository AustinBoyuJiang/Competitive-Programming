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
const int N=2e5+10;

int n,m,ans=INF,a[N],dp[N];
deque<int> q;

void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main(){
	IOS();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!q.empty()&&dp[q.back()]>=dp[i-1])
			q.pop_back();
		q.push_back(i-1);
		while(q.front()+m-1<i-1)
			q.pop_front();
		dp[i]=dp[q.front()]+a[i];
	}
	for(int i=max(1,n-m+1);i<=n;i++)
		ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
