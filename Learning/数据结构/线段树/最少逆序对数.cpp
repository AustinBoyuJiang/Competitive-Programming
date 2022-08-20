#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,a[E];
long long ans,cnt,sum[E<<2];

void update(int rt,int l,int r,int a){
	if(l==r){
		sum[rt]++;
		return;
	}
	int mid=(l+r)/2;
	if(a<=mid) update(rt*2,l,mid,a);
	else update(rt*2+1,mid+1,r,a);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

long long query(int rt,int l,int r,int a,int b){
	if(l==a&&r==b) return sum[rt];
	int mid=(l+r)/2;
	if(b<=mid) return query(rt*2,l,mid,a,b);
	else if(a>mid) return query(rt*2+1,mid+1,r,a,b);
	else return query(rt*2,l,mid,a,mid)+query(rt*2+1,mid+1,r,mid+1,b);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]++;
		update(1,1,E,a[i]);
		cnt+=query(1,1,E,a[i]+1,E);
	}
	ans=cnt;
	for(int i=1;i<n;i++){
		cnt+=query(1,1,E,a[i]+1,E)-query(1,1,E,1,a[i]-1);
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
}
