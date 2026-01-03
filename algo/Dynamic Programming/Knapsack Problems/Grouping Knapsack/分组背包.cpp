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
const int N=1e2+10;
const int M=1e3+10;

int n,V,a,K,w[N],c[N],dp[M];
VI gp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>V;
	for(int i=1;i<=n;i++){
		cin>>a>>w[i]>>c[i];
		K=max(K,a);
		gp[a].pb(i);
	}
	for(int k=1;k<=K;k++){
		for(int v=V;v>0;v--){
			for(int j=0;j<gp[k].size();j++){
				int i=gp[k][j];
				if(v<c[i]) continue;
				dp[v]=max(dp[v],dp[v-c[i]]+w[i]);
			}
		}
	}
	cout<<dp[V]<<endl;
	return 0;
}


