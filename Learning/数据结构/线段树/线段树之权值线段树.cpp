#include<bits/stdc++.h>
using namespace std;
int n,a;
long sum[400010];

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

long get_sum(int rt,int l,int r,int a){
	if(l==a){
		return sum[rt];
	}
	int mid=(l+r)/2;
	if(a>mid){
		return get_sum(rt*2+1,mid+1,r,a);
	}
	else{
		return get_sum(rt*2,l,mid,a)+get_sum(rt*2+1,mid+1,r,mid+1);
	}
}

int main(){
	long count;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		update(1,1,100000,a,1);
		count+=get_sum(1,1,100000,a+1);
	}
	cout<<count<<endl;
}
