#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const int INF = 0x3f3f3f3f;

const int N = 1e6+10;

int n,m;
VPI e[N];

void dfs(int u,int fa,int cost,int tmp){
	if(u==n){
		cout<<cost<<endl;
		return;
	}
	for(PI edge:e[u]){
		int v=edge.fir;
		int w=edge.sec;
		if(v==fa) continue;
		dfs(v,u,cost+abs(tmp-w),w);
	}
}

signed main(){
	cin>>n>>m;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
	dfs(1,0,0,0);
}

