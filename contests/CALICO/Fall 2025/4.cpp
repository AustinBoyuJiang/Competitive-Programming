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
const int K = 4e5+10;

int n,m,k,tot;
unordered_map<int,set<int>> hx,hy,dx,dy;

struct node{
	char t;
	int x,y;
} p[K];


void SOLVE(int Case){
	cin>>n>>m;
	cin>>k;
	hx.clear();
	hy.clear();
	dx.clear();
	dy.clear();
	int ans=0,tot=0;
	rep(i,1,k){
		char t;
		int x,y;
		cin>>t>>x>>y;
		if(t=='Q'){
			p[++tot]={'R',x,y};
			p[++tot]={'B',x,y};
		}
		else{
			p[++tot]={t,x,y};
		}
		hx[x].insert(y);
		hy[y].insert(x);
		dx[x+y].insert(x-y);
		dy[x-y].insert(x+y);
	}
	rep(i,1,tot){
		char t=p[i].t;
		int x=p[i].x,y=p[i].y;
		int res1=0,res2=0;
		if(t=='R'){
			if(hx[x].ub(y)!=hx[x].end()){
				res1++;
			}
			if(hy[y].ub(x)!=hy[y].end()){
				res1++;
			}
			if(hx[x].lb(y)!=hx[x].begin()){
				res1++;
			}
			if(hy[y].lb(x)!=hy[y].begin()){
				// cout<<(*hx[x].ub(y))<<endl;
				res1++;
			}
		}
		if(t=='B'){
			if(dx[x+y].ub(x-y)!=dx[x+y].end()){
				res2++;
			}
			if(dy[x-y].ub(x+y)!=dy[x-y].end()){
				res2++;
			}
			if(dx[x+y].lb(x-y)!=dx[x+y].begin()){
				res2++;
			}
			if(dy[x-y].lb(x+y)!=dy[x-y].begin()){
				res2++;
			}
		}
		//cout<<t<<" "<<x<<" "<<y<<" "<<res1<<" "<<res2<<endl;
		ans+=res1+res2;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}