#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=1e3+10;
const int MAXM=1e5+10;
int n,m,k,u,v,w,cnt,Map1[MAXN][MAXM],f[MAXN],pt[MAXN][21],Max[MAXN][21],dep[MAXN];
vector<pair<int,int> > Map2[MAXN];

struct edge{
	int u,v,w;
} e[MAXM];

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

bool merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return false;
	f[fx]=fy;
	return true;
}

void dfs(int u,int fa,int w){
	if(pt[u][0]!=0) return;
	dep[u]=dep[fa]+1;
	pt[u][0]=fa;
	Max[u][0]=w;
	for(int i=1;i<=20;i++){
		pt[u][i]=pt[pt[u][i-1]][i-1];
		Max[u][i]=max(Max[u][i-1],Max[pt[u][i-1]][i-1]);
	}
	for(int i=0;i<Map2[u].size();i++){
		int v=Map2[u][i].first;
		if(v==fa) continue;
		dfs(v,u,Map2[u][i].second);
	}
}

int LCA(int x,int y){
	if(find(x)!=find(y)) return -1;
	if(dep[x]<dep[y]) swap(x,y);
	int ans=0;
	for(int i=20;i>=0;i--){
		if(dep[pt[x][i]]>=dep[y]){
			ans=max(ans,Max[x][i]);
			x=pt[x][i];
		}
		if(x==y) return ans;
	}
	for(int i=20;i>=0;i--){
		if(pt[x][i]!=pt[y][i]){
			ans=max(ans,Max[x][i]);
			ans=max(ans,Max[y][i]);
			x=pt[x][i];
			y=pt[y][i];
		}
	}
	ans=max(ans,Max[x][0]);
	ans=max(ans,Max[y][0]);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) Map1[i][j]=10000010;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		Map1[min(u,v)][max(u,v)]=min(Map1[min(u,v)][max(u,v)],w);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(Map1[i][j]!=10000010){
				e[++cnt].u=i;
				e[cnt].v=j;
				e[cnt].w=Map1[i][j];
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			Map2[e[i].u].push_back(make_pair(e[i].v,e[i].w));
			Map2[e[i].v].push_back(make_pair(e[i].u,e[i].w));
		}
	}
	for(int i=1;i<=n;i++) dfs(i,0,0);
	for(int i=1;i<=k;i++){
		cin>>u>>v;
		cout<<LCA(u,v)<<endl;
	}
}

