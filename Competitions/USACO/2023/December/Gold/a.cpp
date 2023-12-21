#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using PPI = pair<PI,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace Comfun{
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
} using namespace Comfun;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

const int N=800;

int n,ans,a[N][N],dp[N][N];

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	rep(i,1,n){
		dp[i][i]=1;
		rep(j,i+1,n){
			char x;
			cin>>x;
			a[i][j]=x-'0';
		}
	}
	per(i,n,1){
		rep(j,i+1,n){
			if(a[i][j]!=dp[i][j]%2){
				ans++;
				rep(k,1,n){
					dp[i][k]+=dp[j][k];
					dp[i][k]%=2;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
