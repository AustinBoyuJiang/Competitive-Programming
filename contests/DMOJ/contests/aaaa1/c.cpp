#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1e6+10;

int n,a[N],ans[N];

struct node{
	int l,mx,r;
} st[N*4];

node merge(node a,node b){
	node res={a.l,a.mx+b.mx,b.r};
	if(a.r&&b.l){
		res.mx--;
	}
	return res;
}

void build(int rt,int l,int r){
	if(l==r){
		st[rt]={1,1,1};
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	st[rt]=merge(st[rt*2],st[rt*2+1]);
}

void update(int rt,int l,int r,int x){
	if(l==r){
		st[rt]={0,0,0};
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) update(rt*2,l,mid,x);
	else update(rt*2+1,mid+1,r,x);
	st[rt]=merge(st[rt*2],st[rt*2+1]);
}

void SOLVE1(int Case){
	cin>>n;
	VPI p;
	rep(i,1,n){
		cin>>a[i];
		p.pb({a[i],i});
	}
	sort(all(p));
	build(1,0,n+1);
	update(1,0,n+1,0);
	update(1,0,n+1,n+1);
	int i=-1;
	rep(s,1,n){
		while(i+1<n&&p[i+1].F<s){
			i++;
			update(1,0,n+1,p[i].S);
		}
		cout<<st[1].mx<<" ";
	}
	cout<<endl;
}

void SOLVE2(int Case){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	int i=1,j=2;
	per(s,n,1){
		if(a[s]>a[s+1]){
			rep(k,1,a[s]-a[s+1]){
				if(i>n){
					cout<<"-1"<<endl;
					return;
				}
				ans[i]=s;
				i+=2;
			}
		}
		else{
			rep(k,1,a[s+1]-a[s]){
				ans[j]=s;
				j+=2;
				if(j>i){
					cout<<"-1"<<endl;
					return;
				}
			}
		}
	}
	rep(i,1,n){
		cout<<ans[i]<<" ";
	} cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	cin>>T;
	if(T==1) SOLVE1(1);
	else SOLVE2(1);
	return 0;
}