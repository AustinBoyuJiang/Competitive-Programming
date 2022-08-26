#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,m,k,x,y,v,sum[E * 4][21];
bool lazy[E * 4][21];

int decimal(int digit[]){
	int v=0;
	for(int i=1;i<=20;i++){
		v+=digit[i]*pow(2,i-1);
	}
	return v;
}

void binary(int digit[], int v){
	int cnt=0;
	while(v>0){
		digit[++cnt]=v%2;
		v/=2;
	}
}

void push_up(int rt){
	for(int i=1;i<=20;i++){
		sum[rt][i]=sum[rt*2][i]+sum[rt*2+1][i];
	}
}

void push_down(int rt,int l,int mid,int r){
	for(int i=1;i<=20;i++){
		if(lazy[rt][i]){
			sum[rt*2][i]=mid-l+1-sum[rt*2][i];
			sum[rt*2+1][i]=r-mid-sum[rt*2+1][i];
			lazy[rt*2][i]^=lazy[rt][i];
			lazy[rt*2+1][i]^=lazy[rt][i];
			lazy[rt][i]=0;
		}
	}
}

void build(int rt,int l,int r){
	if(l==r){
		int v,cnt=0;
		cin>>v;
		binary(sum[rt], v);
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		return decimal(sum[rt]);
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

void update(int rt,int l,int r,int x,int y,int v[]){
	if(l==x&&r==y){
		for(int i=1;i<=20;i++){
			if(v[i]){
				sum[rt][i]=r-l+1-sum[rt][i];
				lazy[rt][i]=!lazy[rt][i];
			}
		}
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
	push_up(rt);
}

int main(){
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>k;
		if(k==1){
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<endl;
		}
		else{
			cin>>x>>y>>v;
			int binNum[30];
			memset(binNum, 0, sizeof(binNum));
			binary(binNum, v);
			update(1,1,n,x,y,binNum);
		}
	}
} 
