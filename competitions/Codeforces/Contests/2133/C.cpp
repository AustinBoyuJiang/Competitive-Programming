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

const int N = 610;

int n;
VI dep[N];

void SOLVE(int Case){
	cin>>n;
	rep(i,1,n){
		dep[i].clear();
	}
	int len=1;
	rep(i,1,n){
		cout<<"! "<<i<<" "<<n<<" ";
		rep(j,1,n){
			cout<<j<<" \n"[j==n];
		}
		cout.flush();
		int d;
		cin>>d;
		dep[d].pb(i);
		chkmax(len,d);
	}
	int s=dep[len][0];
	VI path={s};
	per(i,len-1,1){
		for(int u:dep[i]){
			cout<<"! "<<s<<" "<<(int)path.size()+1<<" ";
			for(int x:path){
				cout<<x<<" ";
			}
			cout<<u<<nl;
			cout.flush();
			int d;
			cin>>d;
			if(d==(int)path.size()+1){
				path.pb(u);
				break;
			}
		}
	}
	cout<<"! "<<len;
	for(int x:path){
		cout<<" "<<x;
	}
	cout<<nl;
	cout.flush();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}