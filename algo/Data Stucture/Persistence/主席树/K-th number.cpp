/*Author：AustinJiang
题目：K-th number
时间复杂度：O(m*log(n)
算法：主席树，可持久化，离散化 */
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

int n,m,cnt,tot,a[N],f[N],id[N],root[N];
set<int> num;

struct node{
	int lc,rc,sum;
} st[N*21];

int find(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=l+r>>1;
		if(f[mid]==x) return mid;
		if(f[mid]<x) l=mid+1;
		if(f[mid]>x) r=mid-1;
	}
}

void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return;
	int mid=l+r>>1;
	build(st[rt].lc,l,mid);
	build(st[rt].rc,mid+1,r);
}

void update(int &x,int y,int l,int r,int pos){
	st[x=++tot]=st[y];
	st[x].sum++;
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) update(st[x].lc,st[y].lc,l,mid,pos);
	else update(st[x].rc,st[y].rc,mid+1,r,pos);
}

int query(int x,int y,int l,int r,int k){
	if(l==r) return l;
	int mid=l+r>>1;
	int sum=st[st[y].lc].sum-st[st[x].lc].sum;
	if(k<=sum) return query(st[x].lc,st[y].lc,l,mid,k);
	else return query(st[x].rc,st[y].rc,mid+1,r,k-sum);
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
	build(root[0],1,n);
	for(int i=1;i<=n;i++)
		update(root[i],root[i-1],1,n,id[i]);
	for(int i=1;i<=m;i++){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<f[query(root[l-1],root[r],1,n,k)]<<endl;
	}
	return 0;
}

