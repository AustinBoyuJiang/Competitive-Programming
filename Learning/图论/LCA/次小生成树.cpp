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
const int N=1e5+10;
const int M=3e5+10;

int n,m,sum,ans,bin[N],dep[N],f[N][21],Max[N][21],cmax[N][21];
vector<pair<int,int> > Map[N];

struct eg{
	int u,v,w;
	bool flag;
}e[M];

bool cmp(eg a,eg b){
	return a.w<b.w;
}

int find(int x){
	if(x==bin[x]) return x;
	return bin[x]=find(bin[x]);
}

bool merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)return false;
	bin[fx]=fy;
	return true;
}

void getMax(int u,int i){
	Max[u][i]=max(Max[u][i-1],Max[f[u][i-1]][i-1]);
	cmax[u][i]=max(cmax[u][i-1],cmax[f[u][i-1]][i-1]);
	if(Max[u][i-1]<Max[u][i]) cmax[u][i]=max(cmax[u][i],Max[u][i-1]);
	if(Max[f[u][i-1]][i-1]<Max[u][i]) cmax[u][i]=max(cmax[u][i],Max[f[u][i-1]][i-1]);
}

void dfs(int u,int fa,int w){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	Max[u][0]=w;
	for(int i=1;i<=20;i++){
		f[u][i]=f[f[u][i-1]][i-1];
		getMax(u,i);
	}
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i].fir;
		if(v==fa) continue;
		dfs(v,u,Map[u][i].sec);
	}
}

void getMax2(int &max2,int &cmax2,int u,int i){
	int tmp = max2;
	max2=max(max2,Max[u][i]);
	cmax2=max(cmax2,cmax[u][i]);
	if(tmp<max2) cmax2=max(cmax2,tmp);
	if(Max[u][i]<max2) cmax2=max(cmax2,Max[u][i]);
}

int LCA(int x,int y,int w){
	int max2=0,cmax2=0;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			getMax2(max2,cmax2,x,i);
			x=f[x][i];
		}
		if(x==y) return max2==w?cmax2:max2;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			getMax2(max2,cmax2,x,i);
			getMax2(max2,cmax2,y,i);
			x=f[x][i];
			y=f[y][i];
		}
	}
	getMax2(max2,cmax2,x,0);
	getMax2(max2,cmax2,y,0);
	return max2==w?cmax2:max2;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) bin[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		if(merge(u,v)){
			sum+=w;
			Map[u].pb(mp(v,w));
			Map[v].pb(mp(u,w));
			e[i].flag=true;
		}
	}
	dfs(1,0,0);
	ans=INF;
	for(int i=1;i<=m;i++){
		if(e[i].flag) continue;
        int u=e[i].u;
        int v=e[i].v;
        int w=e[i].w;
		ans=min(ans,sum-LCA(u,v,w)+w);
	}
	cout<<ans<<endl;
	return 0;
}

