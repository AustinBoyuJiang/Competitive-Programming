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
const int N=110;

int n,m,a,b,ans,e[N][N];

void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main(){
	IOS();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		e[a][b]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(e[i][k]&&e[k][j]) e[i][j]=1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(e[i][j]||e[j][i]) cnt++;
		if(cnt==n-1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

