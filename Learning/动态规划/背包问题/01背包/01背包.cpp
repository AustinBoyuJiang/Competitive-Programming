#include<bits/stdc++.h>
#define int long long
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
const int INF=LLONG_MAX;
const int N=1e3+10;
const int V=1e3+10;

int n,v,c[N],w[N],dp[V];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>v;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=v;j>=c[i];j--)
			dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
	cout<<dp[v]<<endl; 
	return 0;
}

