#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

#define lc (rt << 1)
#define rc (rt << 1 | 1)

#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}

const int INF = 0x3f3f3f3f;

const int N = 2e5+10;

struct Segtree_max_single{
	
	int st[N<<2];
	
	void build(int rt,int l,int r,int arr[]){
		if(l==r){
			st[rt]=arr[l];
			return;
		}
		int mid=l+r>>1;
		build(lc,l,mid,arr);
		build(rc,mid+1,r,arr);
		st[rt]=max(st[lc],st[rc]);
	}
	
	void update(int rt,int l,int r,int x,int y){
		if(l==r){
			st[rt]=y;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(lc,l,mid,x,y);
		else update(rc,mid+1,r,x,y);
		st[rt]=max(st[lc],st[rc]);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return max(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
	}
} st1;

struct Segtree_min_single{
	
	int st[N<<2];
	
	void build(int rt,int l,int r,int arr[]){
		if(l==r){
			st[rt]=arr[l];
			return;
		}
		int mid=l+r>>1;
		build(lc,l,mid,arr);
		build(rc,mid+1,r,arr);
		st[rt]=min(st[lc],st[rc]);
	}
	
	void update(int rt,int l,int r,int x,int y){
		if(l==r){
			st[rt]=y;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) update(lc,l,mid,x,y);
		else update(rc,mid+1,r,x,y);
		st[rt]=min(st[lc],st[rc]);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&r==y) return st[rt];
		int mid=l+r>>1;
		if(y<=mid) return query(lc,l,mid,x,y);
		else if(x>mid) return query(rc,mid+1,r,x,y);
		else return min(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
	}
} st2;

int n,m,q,sum,mx,mn,a[N],b[N];
multiset<int> s[N];
PI p[N];

void upd(int j){
	if(s[j].empty()){
		a[j]=INF;
		b[j]=0;
		return;
	}
	auto itr=s[j].rbegin();
	a[j]=*itr;
	b[j]=0;
	if(s[j].size()>1){
		itr++;
		b[j]=*itr;
	}
}

int get(){
	int ans=0,mx=0,mn=INF;
	rep(j,1,m){
		auto itr=s[j].rbegin();
		ans+=*itr;
		chkmin(mn,*itr);
		if(s[j].size()<=1) continue;
		itr++;
		chkmax(mx,*itr);
	}
	if(mx>mn){
		ans+=mx-mn;
	}
	return ans;
}

signed main(){
	cin>>n>>m>>q;
//	n=2e5,m=2e5,q=2e5;
	rep(i,1,n){
		cin>>p[i].fir>>p[i].sec;
//		p[i]={i,100};
		s[p[i].fir].insert(p[i].sec);
	}
	rep(i,1,m){
		upd(i);
		sum+=a[i];
	}
	st1.build(1,1,m,b);
	st2.build(1,1,m,a);
	mx=st1.query(1,1,m,1,m);
	mn=st2.query(1,1,m,1,m);
	cout<<(mx>mn?sum+mx-mn:sum)<<endl;
	rep(i,1,q){
		int opt,x,y;
		cin>>opt>>x>>y;
//		opt=1,x=i,y=i;
		if(opt==1&&p[x].fir==y||opt==2&&p[x].sec==y){
			cout<<(mx>mn?sum+mx-mn:sum)<<endl;
			continue;
		}
		s[p[x].fir].erase(s[p[x].fir].find(p[x].sec));
		sum-=a[p[x].fir];
		upd(p[x].fir);
		sum+=a[p[x].fir];
		st1.update(1,1,m,p[x].fir,b[p[x].fir]);
		st2.update(1,1,m,p[x].fir,a[p[x].fir]);
		
		if(opt==1) p[x].fir=y;
		else p[x].sec=y;
		
		s[p[x].fir].insert(p[x].sec);
		sum-=a[p[x].fir];
		upd(p[x].fir);
		sum+=a[p[x].fir];
		st1.update(1,1,m,p[x].fir,b[p[x].fir]);
		st2.update(1,1,m,p[x].fir,a[p[x].fir]);
		
		mx=st1.query(1,1,m,1,m);
		mn=st2.query(1,1,m,1,m);
		cout<<(mx>mn?sum+mx-mn:sum)<<endl;
	}
}
