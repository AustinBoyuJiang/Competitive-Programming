/*Author：AustinJiang
题目：CDQ分治(陌上花开_三维偏序)
时间复杂度：O(n*log(n)^2)
算法：CDQ分治，线段树 */
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

int n,m,tot,ans[N],sum[N<<2];

struct flower{
	int a,b,c,cnt=1,low;
} p[N],f[N],tmp[N];

bool cmp(flower a,flower b){
	if(a.a!=b.a) return a.a<b.a;
	if(a.b!=b.b) return a.b<b.b;
	return a.c<b.c;
}

bool check(flower a,flower b){
	if(a.a!=b.a) return 0;
	if(a.b!=b.b) return 0;
	return a.c==b.c;
}

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

void solve(int l,int r){
	if(l==r) return;
	int mid=l+r>>1;
	solve(l,mid);
	solve(mid+1,r);
	int x=l,y=mid+1,k=0;
	while(x<=mid||y<=r){
		if(y>r||f[x].b<=f[y].b&&x<=mid) update(1,1,m,f[x].c,f[x].cnt),tmp[++k]=f[x++];
		else f[y].low+=query(1,1,m,1,f[y].c),tmp[++k]=f[y++];
	}
	for(int i=l;i<=mid;i++) update(1,1,m,f[i].c,-f[i].cnt);
	for(int i=1;i<=k;i++) f[l+i-1]=tmp[i];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].b>>p[i].c;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(check(p[i],p[i+1])) p[i+1].cnt+=p[i].cnt;
		else f[++tot]=p[i];
	}
	solve(1,tot);
	for(int i=1;i<=tot;i++)
		ans[f[i].low+f[i].cnt-1]+=f[i].cnt;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
