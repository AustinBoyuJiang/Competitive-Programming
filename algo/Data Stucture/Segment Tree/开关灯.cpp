#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,m,k,x,y,sum[E*4];
bool lazy[E*4];

void push_down(int rt,int l,int mid,int r){
	if(lazy[rt]){
		sum[rt*2]=mid-l+1-sum[rt*2];
		sum[rt*2+1]=r-mid-sum[rt*2+1];
		lazy[rt*2]^=lazy[rt];
		lazy[rt*2+1]^=lazy[rt];
		lazy[rt]=0;
	}
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		return sum[rt];
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid){
		return query(rt*2,l,mid,x,y);
	}
	else if(x>mid){
		return query(rt*2+1,mid+1,r,x,y); 
	}
	else{
		return query(rt*2,l,mid,x,mid)+query(rt*2+1,mid+1,r,mid+1,y);
	}
}

void update(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		sum[rt]=r-l+1-sum[rt];
		lazy[rt]=!lazy[rt];
		return; 
	}
	int mid=(l+r)/2;
	push_down(rt,l,mid,r);
	if(y<=mid){
		update(rt*2,l,mid,x,y);
	}
	else if(x>mid){
		update(rt*2+1,mid+1,r,x,y);
	}
	else{
		update(rt*2,l,mid,x,mid);
		update(rt*2+1,mid+1,r,mid+1,y);
	}
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>k>>x>>y;
		if(k==0){
			update(1,1,n,x,y);
		}
		else{
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
} 
