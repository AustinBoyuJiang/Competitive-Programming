#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,cnt;
int a[E],b[E],c[E];
long long sum[4*E];
map<int,int>d;

void discretization(){
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+(b[i]>b[i-1]);
		d[b[i]]=c[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=d[a[i]];
	}
}

void update(int rt,int l,int r,int a,int b){
	if(l==r){
		sum[rt]+=b;
		return;
	}
	int mid=(l+r)/2;
	if(a<=mid){
		update(rt*2,l,mid,a,b);
	}
	else{
		update(rt*2+1,mid+1,r,a,b);
	}
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

long long get_sum(int rt,int l,int r,int a,int b){
	if(l==a&&r==b){
		return sum[rt];
	}
	int mid=(l+r)/2;
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
	int left[E],right[E]; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	discretization();
	for(int i=1;i<=n;i++){
		update(1,1,E,a[i],1);
		left[i]=get_sum(1,1,E,a[i]+1,E);
	}
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--){
		update(1,1,E,a[i],1);
		right[i]=get_sum(1,1,E,a[i]+1,E);
		cnt+=max(left[i],right[i])>min(left[i],right[i])*2;
	}
	cout<<cnt<<endl; 
}
