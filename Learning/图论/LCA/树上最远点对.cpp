#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,q,x,y,w,f[E][17],dep[E],dis[E];
vector<pair<int,int> > Map[E];

struct node{
	int dis,l,r;
} st[E*4];

void dfs(int u,int fa,int w){
	dep[u]=dep[fa]+1;
	dis[u]=dis[fa]+w;
	f[u][0]=fa;
	for(int i=1;i<=16;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i].first;
		if(v==fa) continue;
		dfs(v,u,Map[u][i].second);
	}
}

int LCA(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=16;i>=0;i--){
		if(dep[x]<=dep[f[y][i]]) y=f[y][i];
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

int get_dis(int x,int y){
	return dis[x]+dis[y]-dis[LCA(x,y)]*2;
}

void push_up(node &ans,node lson,node rson){
	int dis;
	if(lson.dis>rson.dis) ans=lson;
	else ans=rson;
	dis=get_dis(lson.l,rson.l);
	if(dis>ans.dis) ans=(node){dis,lson.l,rson.l};
	dis=get_dis(lson.l,rson.r);
	if(dis>ans.dis) ans=(node){dis,lson.l,rson.r};
	dis=get_dis(lson.r,rson.l);
	if(dis>ans.dis) ans=(node){dis,lson.r,rson.l};
	dis=get_dis(lson.r,rson.r);
	if(dis>ans.dis) ans=(node){dis,lson.r,rson.r};
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]=(node){0,l,r};
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(st[rt],st[rt*2],st[rt*2+1]);
}

node query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y)return st[rt];
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else{
		node ans;
		node lson=query(rt*2,l,mid,x,mid);
		node rson=query(rt*2+1,mid+1,r,mid+1,y);
		push_up(ans,lson,rson);
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y>>w;
		Map[x].push_back(make_pair(y,w));
		Map[y].push_back(make_pair(x,w));
	}
	dfs(1,0,0);
	build(1,1,n);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<query(1,1,n,x,y).dis<<endl;
	}
}
