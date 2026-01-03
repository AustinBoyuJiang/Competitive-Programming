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
#define for(i,n) for(int i=0;i<n;i++)
#define PI pair<int, int>
#define VI vector<int>
#define IOS ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int INF=LLONG_MAX;
const int E=2;

//f[n]=f[n-1]+f[n-2]
int n,mod,ans[E][E];
int a[E][E]={{1,0},{1,0}};
int b[E][E]={{1,1},{1,0}};

void muti(int a[E][E],int b[E][E]){
	int ans[E][E];
	memset(ans,0,sizeof(ans));
	for(i,E) for(j,E) for(k,E)
		ans[i][j]+=a[i][k]*b[k][j],ans[i][j]%=mod;
	for(i,E) for(j,E)
		a[i][j]=ans[i][j];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mod;
	n-=2;
	for(i,E)
		ans[i][i]=1;
	while(n){
		if(n%2) muti(ans,b);
		muti(b,b);
		n/=2;
	}
	muti(ans,a);
	cout<<ans[0][0]<<endl;
	return 0;
}

