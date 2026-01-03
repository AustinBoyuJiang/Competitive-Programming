#include<bits/stdc++.h>
using namespace std;
const int E=2e6+10;
int n,m,k,x,y;

struct node{
	long long sum,mx,lx,rx;
}st[E];

void push_up(int rt,int l,int mid,int r){
	st[rt].sum=st[rt*2].sum+st[rt*2+1].sum;
	st[rt].mx=max(st[rt*2].rx+st[rt*2+1].lx,max(st[rt*2].mx,st[rt*2+1].mx));
	st[rt].lx=max(st[rt*2].lx,st[rt*2].sum+st[rt*2+1].lx);
	st[rt].rx=max(st[rt*2+1].rx,st[rt*2+1].sum+st[rt*2].rx);
}

void build(int rt,int l,int r){
	if(l==r){
		cin>>st[rt].sum;
		st[rt].mx=st[rt].lx=st[rt].rx=st[rt].sum;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt,l,mid,r);
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		st[rt].mx=st[rt].lx=st[rt].rx=st[rt].sum=y;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) update(rt*2,l,mid,x,y);
	else update(rt*2+1,mid+1,r,x,y);
	push_up(rt,l,mid,r);
}

node query(int rt,int l,int r,int x,int y){
	node ans,ansR,ansL;
	if(l==x&&r==y){
		return st[rt];
	}
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else{
		ansL=query(rt*2,l,mid,x,mid);
		ansR=query(rt*2+1,mid+1,r,mid+1,y);
		ans.mx=max(ansL.rx+ansR.lx,max(ansL.mx,ansR.mx));
		ans.lx=max(ansL.lx,ansL.sum+ansR.lx);
		ans.rx=max(ansR.rx,ansR.sum+ansL.rx);
		return ans;
	}
}

int main(){
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>k>>x>>y;
		if(k==1) cout<<query(1,1,n,min(x,y),max(x,y)).mx<<endl;
		else update(1,1,n,x,y);
	}
}
