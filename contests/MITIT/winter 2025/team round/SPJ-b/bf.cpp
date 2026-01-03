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

int a,b,c,n;
char s[20];

void dfs(int a,int b,int c,int p){
	if(p>2&&s[p-1]==s[p-2]) return;
	if(p==n+1){
		rep(i,1,n-1){
			if(s[i]==s[i+1]) return;
		}
		rep(i,1,n-2){
			if(s[i]=='M'&&s[i+1]=='I'&&s[i+2]=='T'){
				return;
			}
			if(s[i]=='T'&&s[i+1]=='I'&&s[i+2]=='M'){
				return;
			}
		}
		rep(i,1,n){
			cout<<s[i];
		} cout<<endl;
		return;
	}
	if(a){
		s[p]='M';
		dfs(a-1,b,c,p+1);
	}
	if(b){
		s[p]='I';
		dfs(a,b-1,c,p+1);
	}
	if(c){
		s[p]='T';
		dfs(a,b,c-1,p+1);
	}
}

void SOLVE(int Case){
	cin>>a>>b>>c;
	n=a+b+c;
	dfs(a,b,c,1);
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