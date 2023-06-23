/*Author：AustinJiang
题目：逆序对 
时间复杂度：O(q*log(n))
算法：主席树，离散化，前缀和 */
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

int n,q,cnt,tot,a[N],f[N],id[N],root[N],sum[N];
set<int> num;

struct node{
	int lc,rc,sum;
} st[N*40];

int find(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=l+r>>1;
		if(x==f[mid]) return mid;
		if(x>f[mid]) l=mid+1;
		if(x<f[mid]) r=mid-1;
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

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt].sum;
	int mid=l+r>>1;
	if(y<=mid) return query(st[rt].lc,l,mid,x,y);
	else if(x>mid) return query(st[rt].rc,mid+1,r,x,y);
	else return query(st[rt].lc,l,mid,x,mid)+query(st[rt].rc,mid+1,r,mid+1,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
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
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+(id[i]<cnt?query(root[i-1],1,cnt,id[i]+1,cnt):0);
	for(int i=1;i<=q;i++){
		int l,r,ans;
		cin>>l>>r;
		ans=sum[r]-sum[l-1];
		for(int j=l;j<=r;j++)
			if(id[j]<cnt) ans-=query(root[l-1],1,cnt,id[j]+1,cnt);
		cout<<ans<<endl;
	}
	return 0;
}
