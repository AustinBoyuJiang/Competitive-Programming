/*Author：AustinJiang
题目：Couriers
时间复杂度：O(n*log(n))
算法：主席树 
来源：POI2014 */
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
const int N=5e5+10;

int n,m,cnt,tot,a[N],f[N],id[N],root[N];
set<int> num;

struct node{
	int lc,rc,sum;
} st[N*21];

int find(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=l+r>>1;
		if(x==f[mid]) return mid;
		if(x<f[mid]) r=mid-1;
		if(x>f[mid]) l=mid+1;
	}
}

void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return;
	int mid=l+r>>1;
	build(st[rt].lc,l,mid);
	build(st[rt].rc,mid+1,r);
}

void update(int &rt,int rtk,int l,int r,int x){
	st[rt=++tot]=st[rtk];
	st[rt].sum++;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) update(st[rt].lc,st[rtk].lc,l,mid,x);
	else update(st[rt].rc,st[rtk].rc,mid+1,r,x);
}

int query(int rt,int rtk,int l,int r,int x){
	if(l==r) return l;
	int mid=l+r>>1;
	if((st[st[rtk].lc].sum-st[st[rt].lc].sum)*2>x) return query(st[rt].lc,st[rtk].lc,l,mid,x);
	if((st[st[rtk].rc].sum-st[st[rt].rc].sum)*2>x) return query(st[rt].rc,st[rtk].rc,mid+1,r,x);
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num.insert(a[i]);
	}
	for(auto i:num)
		f[++cnt]=i;
	sort(f+1,f+cnt+1);
	for(int i=1;i<=n;i++)
		id[i]=find(a[i]);
	build(root[0],1,cnt);
	for(int i=1;i<=n;i++)
		update(root[i],root[i-1],1,cnt,id[i]);
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		cout<<f[query(root[l-1],root[r],1,cnt,r-l+1)]<<endl;
	}
	return 0;
}

