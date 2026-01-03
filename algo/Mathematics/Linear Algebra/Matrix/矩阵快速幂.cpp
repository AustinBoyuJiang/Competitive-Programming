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
#define for(i,n) for(int i=1;i<=n;i++)
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=LLONG_MAX;
const int N=20;
const int MOD=4399;

int n,k,ans,a[N][N],b[N][N];

void muti(int a[N][N],int b[N][N]){
	int tmp[N][N];
	memset(tmp,0,sizeof(tmp));
	for(i,n) for(j,n) for(k,n)
		tmp[i][j]+=a[i][k]*b[k][j],tmp[i][j]%=MOD;
	for(i,n) for(j,n)
		a[i][j]=tmp[i][j];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(i,n) for(j,n)
		cin>>a[i][j];
	for(i,n)
		b[i][i]=1;
	while(k){
		if(k%2) muti(b,a);
		muti(a,a);
		k/=2;
	}
	for(i,n)
		ans+=b[i][i],ans%=MOD;
	cout<<ans<<endl;
	return 0;
}

