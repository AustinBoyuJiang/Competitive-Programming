#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int E=1e5+10;
int n,q,x,y,cnt,f[E][17],dep[E],st[E*4];
vector<int> Map[E];

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=16;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=16;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=16;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]=++cnt;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	st[rt]=LCA(st[rt*2],st[rt*2+1]);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else{
		int lson=query(rt*2,l,mid,x,mid);
		int rson=query(rt*2+1,mid+1,r,mid+1,y);
		return LCA(lson,rson);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	dfs(1,0);
	build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<query(1,1,n,x,y)<<endl;
	}
}

