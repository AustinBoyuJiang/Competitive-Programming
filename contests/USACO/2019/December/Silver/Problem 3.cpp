#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,m,x,y;
char ltp;
string tp;
vector<int> Map[E];

struct node{
	int bi,fa;
	char tp;
} cow[E];

int find(int x){
	if(x==cow[x].bi) return x;
	return cow[x].bi=find(cow[x].bi);
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	cow[fx].bi=cow[fy].bi;
}

void dfs(int u,int fa){
	cow[u].fa=fa;
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		if(cow[u].tp==cow[v].tp) merge(u,v);
		dfs(v,u);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>tp;
	for(int i=1;i<=n;i++){
		cow[i].bi=i;
		cow[i].tp=tp[i-1];
	}
	for(int i=1;i<n;i++){
		cin>>x>>y;
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		cin>>x>>y>>ltp;
		if(find(x)!=find(y)) printf("1");
		else if(cow[find(x)].tp==ltp) printf("1");
		else printf("0");
	}
}
