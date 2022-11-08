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
using namespace std;
const int E=7;
const int MOD=2147493647ll;

//f[n]=f[n-1]+2*f[n-2]+n^4
int n,a[E][E],ans[E][E];
int b[E][E]={
{1,2,1,4,6,4,1},
{1,0,0,0,0,0,0},
{0,0,1,4,6,4,1},
{0,0,0,1,3,3,1},
{0,0,0,0,1,2,1},
{0,0,0,0,0,1,1},
{0,0,0,0,0,0,1}};

void IOS(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void muti(int a[E][E],int b[E][E]){
	int ans[E][E];
	memset(ans,0,sizeof(ans));
	for(i,E) for(j,E) for(k,E)
		ans[i][j]+=a[i][k]*b[k][j],ans[i][j]%=MOD;
	for(i,E) for(j,E)
		a[i][j]=ans[i][j];
}

signed main(){
	IOS();
	cin>>n>>a[1][0]>>a[0][0];
	if(n==1){
		cout<<a[1][0]<<endl;
		return 0;
	}
	n-=2;
	for(i,5)
		a[i+2][0]=1<<4-i;
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

