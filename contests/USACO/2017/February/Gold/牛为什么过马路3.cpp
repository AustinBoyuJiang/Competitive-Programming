/*Author：AustinJiang
题目：牛为什么过马路3
时间复杂度：O(n*2*log(n*2))
算法：线段树 
来源：USACO2017FEB Gold */
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
const int N=1e5+10;

int n,ans,a[N],pre[N],f[N],sum[N<<2];

void update(int rt,int l,int r,int x,int v){
	if(l==r){
		sum[rt]=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt*2,l,mid,x,v);
	else update(rt*2+1,mid+1,r,x,v);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else return query(rt*2,l,mid,x,mid)+query(rt*2+1,mid+1,r,mid+1,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>a[i];
		pre[i]=f[a[i]];
		f[a[i]]=i;
		if(!pre[i]) update(1,1,n*2,i,1);
		if(pre[i]){
			update(1,1,n*2,pre[i],0);
			ans+=query(1,1,n*2,pre[i],i);
		}
	}
	cout<<ans<<endl;
	return 0;
}

