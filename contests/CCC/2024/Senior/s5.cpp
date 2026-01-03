#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int MOD = 1e9+7;

int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=MOD;
		}
		a*=a;
		a%=MOD;
		b>>=1;
	}
	return ans;
}

int inv(int x){
	return qpow(x,MOD-2);
}

const int N = 2e5+10;

int n,a[N],b[N],sa[N],sb[N];
set<double> vis;

signed main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		sa[i]=sa[i-1]+a[i];
	}
	rep(i,1,n){
		cin>>b[i];
		sb[i]=sb[i-1]+b[i];
	}
	int ans=1;
	rep(i,1,n){
		int suma=sa[i],sumb=sb[i];
		vis.insert(suma*inv(i)%MOD);
		vis.insert(sumb*inv(i)%MOD);
		if(vis.size()==ans+1){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

