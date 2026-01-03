#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int N = 1e3+10;
const int M = 110;

int n,sum,a[N],b[N];

bool check(int siz){
	int lim=sum/siz;
	int cnt=0;
	rep(i,1,n){
		cnt+=a[i];
		
	}
}

signed main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		sum+=a[i];
	}
	rep(i,1,n){
		cin>>b[i];
		sum+=b[i];
	}
	check(2);
	cout<<dp[1][11][0][1]<<endl;
	return 0;
	per(i,n*2,1){
		if(sum%i) continue;
		if(check(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}

