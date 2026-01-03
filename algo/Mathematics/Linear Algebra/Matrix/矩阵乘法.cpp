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

int n,m,p,a[N][N],b[N][N],c[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	cin>>p;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=p;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p;j++)
			for(int k=1;k<=m;k++)
				c[i][j]+=a[i][k]*b[k][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<p;j++)
			cout<<c[i][j]<<' ';
		cout<<c[i][p]<<endl;
	}
	return 0;
}

