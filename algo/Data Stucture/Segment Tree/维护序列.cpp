#include<bits/stdc++.h>
using namespace std;
const int E=4e5+10;
int n,p,m,k,x,y,v;
long long sum[E];

struct node{
	long long muti=1,plus=0;
}lazy[E];

void push_up(int rt){
	sum[rt]=(sum[rt*2]+sum[rt*2+1])%p;
}

void push_down(int rt,int l,int mid,int r){
	sum[rt*2]*=lazy[rt].muti;
	sum[rt*2]+=lazy[rt].plus*(mid-l+1);
	sum[rt*2]%=p;
	sum[rt*2+1]*=lazy[rt].muti;
	sum[rt*2+1]+=lazy[rt].plus*(r-mid);
	sum[rt*2+1]%=p;
	lazy[rt*2].plus*=lazy[rt].muti;
	lazy[rt*2].plus+=lazy[rt].plus;
	lazy[rt*2].plus%=p;
	lazy[rt*2+1].plus*=lazy[rt].muti;
	lazy[rt*2+1].plus+=lazy[rt].plus;
	lazy[rt*2+1].plus%=p;
	lazy[rt*2].muti*=lazy[rt].muti;
	lazy[rt*2].muti%=p;
	lazy[rt*2+1].muti*=lazy[rt].muti;
	lazy[rt*2+1].muti%=p;
	lazy[rt].muti=1;
	lazy[rt].plus=0;
}

void build(int rt,int l,int r){
	if(l==r){
		cin>>sum[rt];
		sum[rt]%=p;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

void update1(int rt,int l,int r,int x, int y, int v){
	if(l==x&&r==y){
		sum[rt]*=v;
		sum[rt]%=p;
		lazy[rt].muti*=v;
		lazy[rt].muti%=p;
		lazy[rt].plus*=v;
		lazy[rt].plus%=p;
		return;
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) update1(rt*2,l,mid,x,y,v);
	else if(x>mid) update1(rt*2+1,mid+1,r,x,y,v);
	else{
		update1(rt*2,l,mid,x,mid,v);
		update1(rt*2+1,mid+1,r,mid+1,y,v);
	}
	push_up(rt);
}

void update2(int rt,int l,int r,int x, int y, int v){
	if(l==x&&r==y){
		sum[rt]+=v*(r-l+1);
		lazy[rt].plus+=v;
		lazy[rt].plus%=p;
		return;
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid) update2(rt*2,l,mid,x,y,v);
	else if(x>mid) update2(rt*2+1,mid+1,r,x,y,v);
	else{
		update2(rt*2,l,mid,x,mid,v);
		update2(rt*2+1,mid+1,r,mid+1,y,v);
	}
	push_up(rt);
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
	cin>>n>>p;
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>k;
		if(k==1){
			cin>>x>>y>>v; 
			update1(1,1,n,x,y,v);
		}
		else if(k==2){
			cin>>x>>y>>v;
			update2(1,1,n,x,y,v);
		}
		else{
			cin>>x>>y;
			cout<<query(1,1,n,x,y)%p<<endl;
		}
	}
}
