#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int N=1e5+10;
int n,m,k,a,b,sum[4*N];

void build(int rt,int l,int r){
	if(l==r){
		sum[rt]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void update(int rt,int l,int r,int a,int b){
	if(l==r){
		sum[rt]+=b;
		return;
	}
	int mid=(l+r)>>1;
	if(a<=mid) update(rt<<1,l,mid,a,b);
	else update(rt<<1|1,mid+1,r,a,b);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int query(int rt,int l,int r,int a,int b){
	if(l==a&&r==b) return sum[rt];
	int mid=(l+r)>>1;
	if(b<=mid) return query(rt<<1,l,mid,a,b);
	else if(a>mid) return query(rt<<1|1,mid+1,r,a,b);
	else return query(rt<<1,l,mid,a,mid)+query(rt<<1|1,mid+1,r,mid+1,b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	build(1,1,n);
	for(int i=0;i<m;i++){
		cin>>k>>a>>b;
		if(k==0) update(1,1,n,a,b);
		else cout<<query(1,1,n,a,b)<<endl;
	}
} 
