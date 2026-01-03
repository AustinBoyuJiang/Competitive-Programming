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
const int N=20;
const int TOT=2e3;

int n,m,tot,ans,a[N][N],dp[N][TOT];
VI s;

inline int get_sum(int row,int num){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[row][i]*(num&1);
		num>>=1;
	}
	return sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=0;i<1<<n;i++){
		if(i&i<<1) continue; 
		s.pb(i); 
	}
	tot=s.size();
	for(int i=1;i<=n+1;i++)
		for(int j=0;j<tot;j++)
			for(int k=0;k<tot;k++){
				if(s[j]&s[k]) continue;
				dp[i][j]=max(dp[i][j],dp[i-1][k]+get_sum(i,s[j])); 
			}
	cout<<dp[n+1][0]<<endl;
	return 0;
}

