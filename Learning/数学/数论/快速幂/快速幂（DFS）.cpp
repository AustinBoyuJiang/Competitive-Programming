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

int a,b,m;

int dfs(int n){
	if(n==0) return 1;
	if(n==1) return a;
	int x=dfs(n/2);
	return ((x*x)%m*dfs(n%2))%m;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>m;
	cout<<dfs(b)<<endl;
	return 0;
}

