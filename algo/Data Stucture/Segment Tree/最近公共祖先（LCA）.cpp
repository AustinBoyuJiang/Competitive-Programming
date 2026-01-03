#include<bits/stdc++.h>
using namespace std;
const int E=1e3+10;
int n,q,x,y,cnt1,cnt2,depth[E],pos[E],id[2*E],st[8*E];
vector<int> Map[E];

void dfs(int u,int fa){
	depth[u]=depth[fa]+1;
	id[++cnt1]=u;
	pos[u]=cnt1;
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		dfs(v,u);
		id[++cnt1]=u;
	}
}

void push_up(int rt){
	if(depth[st[rt*2]]<depth[st[rt*2+1]]) st[rt]=st[rt*2];
	else st[rt]=st[rt*2+1];
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]=id[++cnt2];
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		return st[rt];
	}
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else{
		int ansL=query(rt*2,l,mid,x,mid);
		int ansR=query(rt*2+1,mid+1,r,mid+1,y);
		if(depth[ansL]<depth[ansR]) return ansL;
		else return ansR;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	dfs(1,0);
	build(1,1,cnt1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",query(1,1,cnt1,min(pos[x],pos[y]),max(pos[x],pos[y])));
	}
}
