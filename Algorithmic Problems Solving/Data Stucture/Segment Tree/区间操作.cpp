#include<bits/stdc++.h>
using namespace std;
const int E=2e6+10;
int n,m,q,x,y,k,flag[E];
long long sum[E];

void push_up(int rt){
	sum[rt]=sum[rt*2]+sum[rt*2+1];
	flag[rt]=flag[rt*2]&flag[rt*2+1];
}

void build(int rt,int l,int r){
	if(l==r){
		scanf("%d",&sum[rt]);
		if(sum[rt]<1){
			flag[rt]=1;
		}
		else{
			flag[rt]=0;
		}
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

void update1(int rt,int l,int r,int x,int y,int k){
	if(flag[rt]){
		return;
	}
	if(l==r){
		sum[rt]/=k;
		if(sum[rt]<1){
			flag[rt]=1;
		}
		else{
			flag[rt]=0;
		}
		return;
	}
	int mid=(l+r)/2;
	if(y<=mid){
		update1(rt*2,l,mid,x,y,k);
	}
	else if(x>mid){
		update1(rt*2+1,mid+1,r,x,y,k);
	}
	else{
		update1(rt*2,l,mid,x,mid,k);
		update1(rt*2+1,mid+1,r,mid+1,y,k);
	}
	push_up(rt);
}

void update2(int rt,int l,int r,int x,int y){
	if(l==r){
		sum[rt]=y;
		if(sum[rt]<1){
			flag[rt]=1;
		}
		else{
			flag[rt]=0;
		}
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid){
		update2(rt*2,l,mid,x,y);
	}
	else{
		update2(rt*2+1,mid+1,r,x,y);
	}
	push_up(rt);
}

long long query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		return sum[rt];
	}
	int mid=(l+r)/2;
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

int main(){
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>q;
		if(q==0){
			scanf("%d%d%d",&x,&y,&k);
			x+=1;
			y+=1;
			update1(1,1,n,x,y,k);
		}
		else if(q==1){
			scanf("%d%d",&x,&y);
			x+=1;
			update2(1,1,n,x,y);
		}
		else{
			scanf("%d%d",&x,&y);
			x+=1;
			y+=1;
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
}
