/*Author：AustinJiang
题目：HILO
时间复杂度：O(n*log(n))
算法：线段树，二分 
来源：USACO 2022 december gold */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
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

int n,a[N],pos[N],pre[N],nxt[N],sum[N<<2],lazy[N<<2];
vector<int> num;

int find(int x){
	return lower_bound(num.begin(),num.end(),x)-num.begin();
}

void push_down(int rt,int l,int mid,int r){
	if(lazy[rt]!=-1){
		sum[rt<<1]=lazy[rt]*(mid-l+1);
		sum[rt<<1|1]=lazy[rt]*(r-mid);
		lazy[rt<<1]=lazy[rt];
		lazy[rt<<1|1]=lazy[rt];
		lazy[rt]=-1;
	}
}

void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		sum[rt]=v*(y-x+1);
		lazy[rt]=v;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		pre[a[i]]=(find(a[i])<i-1?pos[num[find(a[i])]]:-1)>(find(a[i])-1>=0?pos[num[find(a[i])-1]]:-1);
		num.insert(num.begin()+find(a[i]),a[i]);
	}
	memset(lazy,-1,sizeof(lazy));
	cout<<0<<endl;
	for(int i=1;i<=n;i++){
		if(pre[i]) update(1,1,n,pos[i],pos[i],1);
		if(pos[i]+1<=n) update(1,1,n,pos[i]+1,n,0);
		cout<<query(1,1,n,1,pos[i])<<endl;
	}
	return 0;
}

