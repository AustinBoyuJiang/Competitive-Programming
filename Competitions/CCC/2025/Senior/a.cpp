#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int N = 1e6+10;

int a,b,c,d;

signed main(){
	cin>>a>>b>>c>>d;
	int mx=max({min(a,c),min(b,d)});
	cout<<(a+b+c+d-mx)*2<<endl;
}
