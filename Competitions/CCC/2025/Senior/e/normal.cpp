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

const int INF = 0x3f3f3f3f;
const int MOD = 1e6+3;

const int N = 1e6+10;

int q,n,tot,ans,cnt[N];
PI 	c[N];

struct node{
	int a,b,mx;
} st[N<<2];

node merge(node a,node b){
	node res;
	res.a=a.a;
	if(b.mx==0){
		return a;
	}
	if(a.mx==0){
		return b;
	}
	if(b.a>a.mx){
		res.mx=b.mx;
	}
	else{
		res.mx=b.mx+(a.mx-b.a+1);
	}
	if(a.mx&&b.mx&&res.mx==106){
		cout<<"here"<<endl;
		cout<<":::"<<a.a<<" "<<a.mx<<" "<<b.a<<" "<<b.mx<<endl;
	}
	return res;
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]={l,0,0};
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	st[rt]=merge(st[lc],st[rc]);
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		st[rt].b=y;
		st[rt].mx=(st[rt].b==0?0:st[rt].a+st[rt].b-1);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(lc,l,mid,x,y);
	else update(rc,mid+1,r,x,y);
	st[rt]=merge(st[lc],st[rc]);
}

node query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(lc,l,mid,x,y);
	else if(x>mid) return query(rc,mid+1,r,x,y);
	else return merge(query(lc,l,mid,x,mid),query(rc,mid+1,r,mid+1,y));
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>q;
	build(1,1,1e6);
	rep(i,1,q){
		char opt;
		int x,y;
		cin>>opt;
		if(opt=='A'){
			cin>>x>>y;
//			x=(x+ans)%MOD;
//			y=(y+ans)%MOD;
			c[++tot]={x,y};
			cnt[x]+=y;
			update(1,1,1e6,x,cnt[x]);
		}
		else{
			cin>>x;
//			x=(x+ans)%MOD;
			cnt[c[x].fir]-=c[x].sec;
			update(1,1,1e6,c[x].fir,cnt[c[x].fir]);
		}
		ans=query(1,1,1e6,1,1e6).mx;
		cout<<ans<<endl;
	}
/*
3
A 46 6
A 59 3
A 28 63
*/
	cout<<merge(query(1,1,1e6,28,46),query(1,1,1e6,59,59)).mx<<endl;
	cout<<st[4].mx<<endl;
}

