/*Author：AustinJiang
题目：逆序对 
时间复杂度：O(q*sqrt(n)*log(n))
算法：莫队 */
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
const int N=1e5+10;

int n,m,tot,block,a[N],f[N],sum[N<<2];
ll res,ans[N];
set<int> num;

struct QUERY{
	int l,r,id;
} q[N];

inline int read(){
    register int x=0;
    register char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar())
        (x*=10)+=ch^48;
    return x;
}

int pr[20];
inline void put(register ll x){
    if (!x) putchar('0');
    else{
        register int len=0;
        while(x) pr[++len]=x%10,x/=10;
        while(len) putchar(48^pr[len--]);
    }
    putchar('\n');
}

bool cmp(QUERY a,QUERY b){
	if(a.l/block!=b.l/block) return a.l/block<b.l/block;
	return a.r<b.r;
}

int find(int x){
	int l=1,r=tot;
	while(l<=r){
		int mid=l+r>>1;
		if(f[mid]<x) l=mid+1;
		else if(f[mid]>x) r=mid-1;
		else return mid;
	}
}

void push_up(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		sum[rt]+=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x,y);
	else update(rt<<1|1,mid+1,r,x,y);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(y<x) return 0;
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

signed main(){
	n=read(),m=read();
	block=sqrt(n);
	for(int i=1;i<=n;i++){
		a[i]=read();
		num.insert(a[i]);
	}
	for(auto x:num)
		f[++tot]=x;
	for(int i=1;i<=n;i++)
		a[i]=find(a[i]);
	for(int i=1;i<=m;i++){
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		int x=q[i].l,y=q[i].r,id=q[i].id;
		while(l>x) update(1,1,tot,a[--l],1),res+=query(1,1,tot,1,a[l]-1);
		while(r<y) update(1,1,tot,a[++r],1),res+=query(1,1,tot,a[r]+1,tot);
		while(l<x) res-=query(1,1,tot,1,a[l]-1),update(1,1,tot,a[l++],-1);
		while(r>y) res-=query(1,1,tot,a[r]+1,tot),update(1,1,tot,a[r--],-1);
		ans[id]=res;
	}
	for(int i=1;i<=m;i++)
		put(ans[i]);
	return 0;
}

