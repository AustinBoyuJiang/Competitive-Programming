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
#define IOS ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int INF=LLONG_MAX;
const int N=1e3+10;

int n,a[N];
priority_queue<int,vector<int>,greater<int> > qg;
priority_queue<int,vector<int>,less<int> > ql;


signed main(){
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qg.push(a[i]);
		ql.push(a[i]);
	}
	while(qg.size()-1){
		int a=qg.top(); qg.pop();
		int b=qg.top(); qg.pop();
		qg.push(a*b+1);
	}
	while(ql.size()-1){
		int a=ql.top(); ql.pop();
		int b=ql.top(); ql.pop();
		ql.push(a*b+1);
	}
	cout<<qg.top()-ql.top()<<endl;
	return 0;
}

