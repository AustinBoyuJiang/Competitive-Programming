#include<bits/stdc++.h>
using namespace std;
int n,q,a,b,c;
char k;
long long sum[400010],lazy[400010];


void build(int rt,int l,int r){
	if(l==r){
		cin>>sum[rt];
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}


void push_down(int rt,int l,int r,int mid){
	lazy[rt*2]+=lazy[rt];
	lazy[rt*2+1]+=lazy[rt];
	sum[rt*2]+=lazy[rt]*(mid-l+1);
	sum[rt*2+1]+=lazy[rt]*(r-mid);
	lazy[rt]=0;
}

void update(int rt,int l,int r,int a,int b,int c){
	if(l==a&&r==b){
		sum[rt]+=c*(r-l+1);
		lazy[rt]+=c;
		return;
	}
	int mid=(l+r)/2;
	push_down(rt,l,r,mid);
	if(b<=mid){
		update(rt*2,l,mid,a,b,c);
	}
	else if(a>mid){
		update(rt*2+1,mid+1,r,a,b,c);
	}
	else{
		update(rt*2,l,mid,a,mid,c);
		update(rt*2+1,mid+1,r,mid+1,b,c);
	}
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

long long get_sum(int rt,int l,int r,int a,int b){
	if(l==a&&r==b){
		return sum[rt];
	}
	int mid=(l+r)/2;
	push_down(rt,l,r,mid);
	if(b<=mid){
		return get_sum(rt*2,l,mid,a,b);
	}
	else if(a>mid){
		return get_sum(rt*2+1,mid+1,r,a,b);
	}
	else{
		return get_sum(rt*2,l,mid,a,mid)+get_sum(rt*2+1,mid+1,r,mid+1,b);
	}
}

int main(){
	cin>>n>>q;
	build(1,1,n);
	for(int i=0;i<q;i++){
		cin>>k;
		if(k=='C'){
			cin>>a>>b>>c;
			update(1,1,n,a,b,c);
		}
		else{
			cin>>a>>b;
			cout<<get_sum(1,1,n,a,b)<<endl;
		}
	}
}
