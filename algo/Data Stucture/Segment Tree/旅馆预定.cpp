#include<bits/stdc++.h>
using namespace std;
const int E=2e5+10;
int n,m,k,x,y,lx[E]={1},mx[E],rx[E],lazy[E];

void push_up(int rt,int l,int mid,int r){
	mx[rt]=max(mx[rt*2],mx[rt*2+1]);
	mx[rt]=max(mx[rt],rx[rt*2]+lx[rt*2+1]);
	lx[rt]=lx[rt*2]+lx[rt*2+1]*(lx[rt*2]==mid-l+1);
	rx[rt]=rx[rt*2+1]+rx[rt*2]*(rx[rt*2+1]==r-mid);
}

void push_down(int rt,int l,int mid,int r){
	if(lazy[rt]){
		lx[rt*2]=mx[rt*2]=rx[rt*2]=(lazy[rt]-1)*(mid-l+1);
		lx[rt*2+1]=mx[rt*2+1]=rx[rt*2+1]=(lazy[rt]-1)*(r-mid);
		lazy[rt*2]=lazy[rt];
		lazy[rt*2+1]=lazy[rt];
		lazy[rt]=0;
	}
}

void build(int rt,int l,int r){
	if(l==r){
		lx[rt]=mx[rt]=rx[rt]=1;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt,l,mid,r);
}

int query(int rt,int l,int r,int x){
	if(r-l+1==x){
		return l;
	}
	int pos,mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(mx[rt*2]>=x){
		return query(rt*2,l,mid,x);
	}
	else if(rx[rt*2]+lx[rt*2+1]>=x){
		return mid-rx[rt*2]+1;
	}
	else{
		return query(rt*2+1,mid+1,r,x);
	}
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		lx[rt]=mx[rt]=rx[rt]=v*(r-l+1);
		lazy[rt]=v+1;
		return;
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid){
		update(rt*2,l,mid,x,y,v);
	}
	else if(x>mid){
		update(rt*2+1,mid+1,r,x,y,v);
	}
	else{
		update(rt*2,l,mid,x,mid,v);
		update(rt*2+1,mid+1,r,mid+1,y,v);
	}
	push_up(rt,l,mid,r);
}

int main(){
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>k;
		if(k==1){
			cin>>x;
			if(mx[1]<x){
				cout<<0<<endl;
			}
			else{
				int pos=query(1,1,n,x);
				update(1,1,n,pos,pos+x-1,0);
				cout<<pos<<endl;
			}
		}
		else{
			cin>>x>>y;
			update(1,1,n,x,x+y-1,1);
		}
	}
}

