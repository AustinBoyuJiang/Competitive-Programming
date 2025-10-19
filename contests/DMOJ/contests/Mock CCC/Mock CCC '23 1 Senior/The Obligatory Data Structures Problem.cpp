#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

namespace fastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<typename T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<typename T> inline void write(T x,char let) {write(x),putchar(let);}
} using namespace fastIO;

const int N = 1e5+10;
const int MOD = 998244353;

int n,m,last,a[N],b[N];
long ans;

int st[N<<2],lazy[N<<2];
vector<int> num[N<<2];

int A, B, C = ~(1<<31), M = (1<<16)-1;
inline int rnd(int last) {
  A = (36969 + (last >> 3)) * (A & M) + (A >> 16);
  B = (18000 + (last >> 3)) * (B & M) + (B >> 16);
  return (C & ((A << 16) + B)) % 1000000000;
}

inline int count(int rt,int x){
	int l=0,r=num[rt].size()-1;
	while(l<=r){
		int mid=l+r>>1;
		if(num[rt][mid]<=x) l=mid+1;
		else r=mid-1;
	} return l;
}

inline void build(int rt,int l,int r){
	rep(i,l,r) num[rt].emplace_back(b[i]);
	sort(num[rt].begin(),num[rt].end());
	if(l==r){
		st[rt]=a[l]>=b[l];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	st[rt]=st[rt<<1]+st[rt<<1|1];
}

inline void push_down(int rt,int l,int mid,int r){
	if(!lazy[rt]) return;
	st[rt<<1]=count(rt<<1,lazy[rt]);
	st[rt<<1|1]=st[rt]-st[rt<<1];
	lazy[rt<<1]=lazy[rt];
	lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=0;
}

inline void update(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		lazy[rt]=v;
		st[rt]=count(rt,v);
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	st[rt]=st[rt<<1]+st[rt<<1|1];
}

inline int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

signed main(){
	read(n),read(m),read(A),read(B);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	build(1,1,n);
	rep(i,1,m){
		int l=rnd(last)%n+1;
		int r=rnd(last)%n+1;
		int x=rnd(last)+1;
		if(l>r) swap(l,r);
		cout<<l<<" "<<r<<" "<<x<<endl;
		if(l+r+x&1) update(1,1,n,l,r,x);
		else{
			int res=query(1,1,n,l,r);
			(ans+=(long)i*res)%=MOD;
			last=res;
			cout<<res<<endl;
		}
	}
	write(ans,endl);
}
