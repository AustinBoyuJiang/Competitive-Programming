/*Author：AustinJiang
题目：DZY Loves Fibonacci Numbers
时间复杂度：O(m*log(n))
算法：线段树
来源：CodeForces 446 problem C */
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
const int N=3e5+10;
const int MOD=1e9+9;

int n,m,f[N],val[N],sum[N<<2];
PI lazy[N<<2];

int fibo(int a,int b,int t){
	if(t==1) return a;
	return ((f[t-2]*a)%MOD+(f[t-1]*b)%MOD)%MOD;
}

void push_up(int rt){
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%MOD;
}

void push_down(int rt,int l,int mid,int r){
	if(lazy[rt].fir){
		int a=lazy[rt].fir;
		int b=lazy[rt].sec;
		int aa=fibo(lazy[rt].fir,lazy[rt].sec,mid-l+2);
		int bb=fibo(lazy[rt].fir,lazy[rt].sec,mid-l+3);
		lazy[rt<<1].fir=(lazy[rt<<1].fir+a)%MOD;
		lazy[rt<<1].sec=(lazy[rt<<1].sec+b)%MOD;
		lazy[rt<<1|1].fir=(lazy[rt<<1|1].fir+aa)%MOD;
		lazy[rt<<1|1].sec=(lazy[rt<<1|1].sec+bb)%MOD;
		sum[rt<<1]=(sum[rt<<1]+fibo(a,b,mid-l+3)-b+MOD)%MOD;
		sum[rt<<1|1]=(sum[rt<<1|1]+fibo(aa,bb,r-mid+2)-bb+MOD)%MOD;
		lazy[rt]=mp(0,0);
	}
}

void build(int rt,int l,int r){
	if(l==r){
		sum[rt]=val[l];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y,int fl,int fr){
	if(l==x&&r==y){
		sum[rt]=(sum[rt]+fibo(f[fl],f[fl+1],r-l+3)-f[fl+1]+MOD)%MOD;
		lazy[rt].fir=(lazy[rt].fir+f[fl]+MOD)%MOD;
		lazy[rt].sec=(lazy[rt].sec+f[fl+1]+MOD)%MOD;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,fl,fr);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,fl,fr);
	else update(rt<<1,l,mid,x,mid,fl,fl+mid-x),update(rt<<1|1,mid+1,r,mid+1,y,fl+mid-x+1,r);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return (query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y))%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	build(1,1,n);
	f[1]=1,f[2]=1;
	for(int i=3;i<=n+2;i++)
		f[i]=(f[i-1]+f[i-2])%MOD;
	for(int i=1;i<=m;i++){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt==1) update(1,1,n,l,r,1,r-l+1);
		else cout<<query(1,1,n,l,r)<<endl;
	}
	return 0;
}

