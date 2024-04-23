#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int N = 1e6+10;

int n,ans,a[N];

signed main(){
	cin>>n;
	rep(i,0,n-1){
		cin>>a[i];
	}
	rep(i,0,n-1){
		if(a[i]==a[(i+n/2)%n]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

