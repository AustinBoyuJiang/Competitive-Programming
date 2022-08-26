/*Author：AustinJiang
题目：United Cows of Farmer John
时间复杂度：O(n*log(n))
算法：线段树 
来源：USACO 2021 US Open, Gold */
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
const int INF=0x3f3f3f3f;
const int N=2e5+10;

int n,ans,pre[N],last[N],sum[N<<2];

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		sum[rt]=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt*2,l,mid,x,y);
	else update(rt*2+1,mid+1,r,x,y);
	sum[rt]=sum[rt*2]+sum[rt*2+1]; 
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	return query(rt*2,l,mid,x,mid)+query(rt*2+1,mid+1,r,mid+1,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pre[i]=last[x];
		last[x]=i;
	}
	for(int i=1;i<=n;i++){
		update(1,1,n,i,1);
		if(pre[i]) update(1,1,n,pre[i],0);
		if(pre[i]<i-1) ans+=query(1,1,n,pre[i]+1,i-1);
	}
	cout<<ans<<endl;
	return 0;
}

