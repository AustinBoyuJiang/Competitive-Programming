/*Author：AustinJiang
题目：K-th number
时间复杂度：O(n*log(n)^2)
算法：整体二分 
来源：
思路：
*/
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

int n,m,a[N],f[N],num[N],pos[N],ans[N],sum[N<<2];

struct QUERY{
	int x,y,k;
} q[N];

void update(int rt,int l,int r,int x,int v){
	if(l==r){
		sum[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x,v);
	else update(rt<<1|1,mid+1,r,x,v);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

void add(int x,int v){
	update(1,1,n,x,v);
}

int get(int x,int y){
	return query(1,1,n,x,y);
}

void solve(int l,int r,VI b){
	if(l==r){
		for(auto x:b)
			ans[x]=l;
		return;
	}
	int mid=l+r>>1;
	for(int i=l;i<=mid;i++)
		add(pos[i],1);
	VI bl,br;
	for(auto x:b){
		int tmp=get(q[x].x,q[x].y);
		if(tmp>=q[x].k) bl.pb(x);
		else br.pb(x),q[x].k-=tmp;
	}
	for(int i=l;i<=mid;i++)
		add(pos[i],-1);
	solve(l,mid,bl);
	solve(mid+1,r,br);
}

int find(int x){
	int l=1,r=n;
	while(l<=n){
		int mid=l+r>>1;
		if(num[mid]<x) l=mid+1;
		else if(num[mid]>x) r=mid-1;
		else return mid;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=a[i];
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		f[i]=find(a[i]);
		pos[f[i]]=i;
	}
	VI b;
	for(int i=1;i<=m;i++){
		cin>>q[i].x>>q[i].y>>q[i].k;
		b.pb(i);
	}
	solve(1,n,b);
	for(int i=1;i<=m;i++)
		cout<<num[ans[i]]<<endl;
	return 0;
}

