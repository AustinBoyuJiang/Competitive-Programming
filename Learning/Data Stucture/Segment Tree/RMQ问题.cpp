#include<bits/stdc++.h>
using namespace std;
const int E=4e5+10;
int n,m,x,y,st[E];

void build(int rt,int l,int r){
	if(l==r){
		scanf("%d",&st[rt]);
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	st[rt]=max(st[rt*2],st[rt*2+1]);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else return max(query(rt*2,l,mid,x,mid),query(rt*2+1,mid+1,r,mid+1,y));
}

int main(){
	scanf("%d %d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",query(1,1,n,x,y));
	}
}
