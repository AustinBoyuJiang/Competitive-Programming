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

namespace rnd {
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    inline int randint(int l, int r) {
        return uniform_int_distribution<int>(l, r)(rng);
    }

    inline long long randll(long long l, long long r) {
        return uniform_int_distribution<long long>(l, r)(rng);
    }

    inline double randdouble(double l, double r) {
        return uniform_real_distribution<double>(l, r)(rng);
    }
} using namespace rnd;

const int N = 1e6+10;
const int M = 500;

int n;

void SOLVE(int Case){
	n=10000;
	int tot=0;
	int tot2=0;
	rep(i,1,n){
		double p;
		p=randdouble(0.005,1);
		double a=0,b=1;
		int cnt=0;
		bool ok=0;
		while(a+0.0001<0.5){
			double na=p*b+(1-p)*a;
			double nb=(1-p)*b+p*a;
			a=na;
			b=nb;
			//cout<<"REACT"<<endl;
			if(randdouble(0,1)<p) ok^=1;
			//cout<<a<<" "<<b<<endl;
			cnt++;
			if(cnt>=500) break;
		}
		tot2+=cnt;
		tot+=ok;
		//cout<<cnt<<endl;
		//cout<<"NEXT"<<endl;
	}
	cout<<tot*1.0/n<<endl;
	cout<<tot2<<endl;
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