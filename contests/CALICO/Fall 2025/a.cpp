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

int to_int(string s){
	int ans=0;
	for(char x:s){
		ans*=10;
		ans+=x-'0';
	}
	return ans;
}

bool check(int a,int b,int c){
	if(a<2026) return true;
	if(a>2026) return false;
	if(b<11) return true;
	if(b>11) return false;
	if(c<19) return true;
	return false;
}

int n;

void SOLVE(int Case){
	cin>>n;
	string name,y,m,d;
	cin.ignore();
	rep(i,1,n){
		getline(cin,name);
		cin>>y>>m>>d;
		cin.ignore();
		int a,b,c;
		a=to_int(y);
		b=to_int(m);
		c=to_int(d);
		if(check(a,b,c)){
			cout<<"we got "<<name<<" before gta6"<<endl;
		}
		else{
			cout<<"we got gta6 before "<<name<<endl;
		}
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