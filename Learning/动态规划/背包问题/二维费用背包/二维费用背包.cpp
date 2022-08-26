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
const int N=200;

int n,C,W,v[N],c[N],w[N],dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>C>>W;
	for(int i=1;i<=n;i++) cin>>v[i]>>c[i]>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=C;j>=c[i];j--){
			for(int k=W;k>=w[i];k--)
				dp[j][k]=max(dp[j][k],dp[j-c[i]][k-w[i]]+v[i]);
		}
	}
	cout<<dp[C][W]<<endl; 
	return 0;
}

