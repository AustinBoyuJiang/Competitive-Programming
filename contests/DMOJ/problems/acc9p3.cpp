#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int dir[8][2] = {
    {1,0},{0,1},{0,-1},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
};
const int MOD = 998244353;

template<class T> bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1e5+10;

int n,m,dist[2][N][12],vis[N][12];
VPI e[N];

void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb({v,w});
		e[v].pb({u,w});
	}
	memset(dist,0x3f,sizeof(dist));
	rep(i,0,1){
		int st=i==0?1:n;
		memset(vis,0,sizeof(vis));
		PQG<pair<int,PI>> q;
		dist[i][st][0]=0;
		q.push({0,{st,0}});
		while(!q.empty()){
			auto [u,ud]=q.top().sec;
			q.pop();
			if(vis[u][ud]) continue;
			vis[u][ud]=true;
			for(auto [v,w]:e[u]){
				int vd=(ud+w)%12;
				if(dist[i][u][ud]+w<dist[i][v][vd]){
					dist[i][v][vd]=dist[i][u][ud]+w;
					q.push({dist[i][v][vd],{v,vd}});
				}
			}
		}
	}
	rep(i,1,n){
		int ans=INF;
		rep(j,0,11){
			chkmin(ans,max(dist[0][i][j],dist[1][i][j]));
		}
		if(ans==INF){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
}

signed main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	srand(time(0));
	int T=1;
	// cin>>T;
	rep(i,1,T){
		SOLVE(i);
	}
	return 0;
}