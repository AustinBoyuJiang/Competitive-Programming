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

const int N = 160;

int n,a[N][N],b[N][N];

void SOLVE(int Case){
	cin>>n;
	memset(a,0,sizeof(a));
	rep(i,1,n){
		rep(j,1,n){
			char x;
			cin>>x;
			a[i+n][j+n]=x-'0';
		}
	}
	int ans=INF;
	rep(dx,-n,n) rep(dy,-n,n){
		memset(b,0,sizeof(b));
		rep(i,1,n){
			rep(j,1,n){
				int ni=j+n+dx;
				int nj=n-i+1+n+dy;
				b[ni][nj]=a[i+n][j+n];
			}
		}
		int sum=0;
		rep(i,0,n*3){
			rep(j,0,n*3){
				sum+=abs(a[i][j]-b[i][j]);
			}
		}
		chkmin(ans,sum/2);
	}
	cout<<ans<<nl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}