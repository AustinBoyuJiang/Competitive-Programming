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

int n;
double tot=0;
vector<array<int,5>> ans;

int f(int l,int r){
	tot+=1.0L/(r-l+1);
	if(tot>0.95) return -1;
	cout<<"? "<<l<<" "<<r<<endl;
	cout.flush();
	int x;
	cin>>x;
	ans.pb({l,l,r,r,x});
	return x;
}

void SOLVE(int Case){
	cin>>n;
	queue<array<int,5>> q;
	q.push({1,n,f(1,n),1,n});
	while(!q.empty()&&tot<0.95){
		auto [l,r,res,ll,rr]=q.front();
		q.pop();
		int mid=(l+r)/2;
		int res2=f(l,mid);
		if(res2==-1) break;
		if(res==res2){
			ans.pb({ll,l,mid,rr,res});
			q.push({l,mid,res,ll,rr});
		}
		else{
			ans.pb({ll,mid+1,r,rr,res});
			q.push({mid+1,r,ll,rr,res});
			q.push({l,mid,l,mid,res2});
		}
	}
	cout<<"! "<<ans.size()<<endl;
	for(auto v:ans){
		rep(i,0,4){
			cout<<v[i]<<" ";
		} cout<<endl;
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	// cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}