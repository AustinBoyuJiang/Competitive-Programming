/*Author: AustinJiang
题目: The Golden Porcupine
时间复杂度: O(t)
算法: 差分*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=INT_MAX;
const int N=1e5+10;
const int T=1e5+10;

ll n,t,l,r,a,b,c,ad[T],bd[T],cd[T],bld[T],al2d[T],alld[T];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>l>>r>>a>>b>>c;
		ad[l]+=a,ad[r+1]-=a;
		bd[l]+=b,bd[r+1]-=b;
		cd[l]+=c,cd[r+1]-=c;
		bld[l]+=b*l,bld[r+1]-=b*l;
		al2d[l]+=a*l*2,al2d[r+1]-=a*l*2;
		alld[l]+=a*l*l,alld[r+1]-=a*l*l;
	}
	for(int i=1;i<=t;i++){
		ad[i]+=ad[i-1];
		bd[i]+=bd[i-1];
		cd[i]+=cd[i-1];
		bld[i]+=bld[i-1];
		al2d[i]+=al2d[i-1];
		alld[i]+=alld[i-1];
		cout<<ad[i]*i*i+alld[i]-al2d[i]*i+bd[i]*i-bld[i]+cd[i]<<' ';
	}
	return 0;
}
