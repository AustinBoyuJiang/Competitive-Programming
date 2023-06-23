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
#define QG priority_queue<int,vector<int>,greater<int> >
#define QL priority_queue<int,vector<int>,less<int> >
using namespace std;
const int INF=LLONG_MAX;
const int N=1e5+10;
const int M=1e5+10;

int a,b,m,ans=1;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>m; 
	while(b){
		if(b%2) ans*=a,ans%=m;
		a*=a,a%=m;
		b/=2;
	}
	cout<<ans<<endl;
	return 0;
}

