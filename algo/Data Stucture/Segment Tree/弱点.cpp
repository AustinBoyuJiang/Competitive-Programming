#include<bits/stdc++.h>
using namespace std;
const int E=1e6+10;
long long n,cnt,a[E],l[E],r[E],sum[4*E],lazy[4*E];

void push_down(int rt,int l,int mid,int r){
	lazy[rt*2]+=lazy[rt];
	lazy[rt*2+1]+=lazy[rt];
	sum[rt*2]+=lazy[rt]*(mid-l+1);
	sum[rt*2+1]+=lazy[rt]*(r-mid);
	lazy[rt]=0;
}

void update(int rt,int l,int r,int a){
	if(l==r){
		sum[rt]+=1;
		return;
	}
	int mid=(l+r)/2;
	if(a<=mid){
		update(rt*2,l,mid,a);
	}
	else{
		update(rt*2+1,mid+1,r,a);
	}
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

long long query(int rt,int l,int r,int x,int y){
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

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=1;
		l[i]=query(1,1,E,a[i]+1,E);
		update(1,1,E,a[i]);
	}
	memset(sum,0,sizeof(sum));
	memset(lazy,0,sizeof(lazy));
	for(int i=n;i>=1;i--){
		r[i]=query(1,1,E,1,a[i]-1);
		cnt+=l[i]*r[i];
		update(1,1,E,a[i]);
	}
	cout<<cnt<<endl;
}
