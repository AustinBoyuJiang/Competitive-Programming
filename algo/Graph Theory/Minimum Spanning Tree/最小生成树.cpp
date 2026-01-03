#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,m,fx,fy,f[E*2];
long long ans;

struct edge{
	int u,v,w;
} e[E*5];

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		fx=find(e[i].u);
		fy=find(e[i].v);
		if(fx!=fy){
			f[fx]=fy;
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
}
