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
using namespace std;
const int INF=LLONG_MAX;
const int N=1e4+10;
const int M=1e5+10;
const int P=1e3+10;
const int PI=2e2+10;
int n,m,q,cnt,pv[N],bin[N],Map[N][N],f[N][21],dep[N];
vector<pair<int,int> > mst1[P],mst2[P][PI];

struct province{
	int id,fac;
} e[P];

int find(int x){
	if(bin[x]==x) return x;
	return bin[x]=find(bin[x]);
}

bool merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) false;
	bin[fx]=fy;
	return true;
}

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<mst1[u].size();i++){
		int v=mst1[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Map[u][v]=w;
	}
	for(int i=1;i<=n;i++) bin[i]=i;
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if(!Map[u][v]) continue;
			if(Map[u][v]&&Map[v][u]) merge(u,v);
			else{
				int fx=find(u);
				e[++cnt].id=fx;
				pv[fx]=cnt;
				mst1[u].pb(mp(v,Map[u][v]));
				mst1[v].pb(mp(u,Map[u][v]));
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if(Map[u][v]&&Map[v][u]){
				mst2[cnt][u].pb(mp(v,Map[u][v]));
			}
		}
	}
	dfs(1,0);
	return 0;
}


