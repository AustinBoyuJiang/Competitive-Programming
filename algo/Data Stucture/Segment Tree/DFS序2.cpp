#include<bits/stdc++.h>
using namespace std;
const int E=1e6+10;
int n,m,r,k,x,v,cnt,id[E];
long long sum[4*E],lazy[4*E];
vector<int> Map[E];

struct node{
	int val,pos,son;
}s[E];

void dfs(int u, int fa){
	id[++cnt]=u;
	s[u].pos=cnt;
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		dfs(v,u);
		s[u].son+=s[v].son+1;
	}
}

void push_down(int rt,int l,int mid,int r){
	sum[rt*2]+=lazy[rt]*(long)(mid-l+1);
	sum[rt*2+1]+=lazy[rt]*(long)(r-mid);
	lazy[rt*2]+=lazy[rt];
	lazy[rt*2+1]+=lazy[rt];
	lazy[rt]=0;
}

void build(int rt,int l,int r){
	if(l==r){
		sum[rt]=s[id[++cnt]].val;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		sum[rt]+=v*(long)(r-l+1);
		lazy[rt]+=v;
		return;
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt*2,l,mid,x,y,v);
	else if(x>mid) update(rt*2+1,mid+1,r,x,y,v);
	else{
		update(rt*2,l,mid,x,mid,v);
		update(rt*2+1,mid+1,r,mid+1,y,v);
	}
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

long long query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		return sum[rt];
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else return query(rt*2,l,mid,x,mid)+query(rt*2+1,mid+1,r,mid+1,y);
}

int main(){
	scanf("%d %d %d",&n,&m,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].val);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	dfs(r,0);
	cnt=0;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		if(k==1){
			scanf("%d %d",&x,&v);
			update(1,1,n,s[x].pos,s[x].pos+s[x].son,v);
		}
		else{
			scanf("%d",&x);
			printf("%lld\n",query(1,1,n,s[x].pos,s[x].pos+s[x].son));
		}
	}
}
