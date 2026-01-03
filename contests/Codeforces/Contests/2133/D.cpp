#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
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

const int N = 2e5+10;

int n,a[N],dp[N][2],dam[N],dis[N];

void SOLVE(int Case){
	cin>>n;
	int sum=0;
	rep(i,1,n){
		cin>>a[i];
		sum+=a[i];
	}
	dam[n]=0;
	rep(i,1,n-1){
		dam[i]=min(i,a[i+1]);
		dis[i]=0;
		if(dam[i]==a[i+1]){
			dis[i]++;
			int u=i+1;
			while(u<n&&a[u+1]==1){
				u++;
				dam[i]++;
				dis[i]++;
			}
			if(u<n) dam[i]++;
		}
	}
	rep(i,1,n){
		cout<<dam[i]<<" ";
	} cout<<endl;
	rep(i,1,n){
		cout<<dis[i]<<" ";
	} cout<<endl;
	dp[1][0]=0;
	dp[1][1]=dam[1];
	rep(i,2,n){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=dam[i];
		rep(j,1,i-1){
			if(i-j>dis[j]){
				if(i-j-dis[j]==1){
					chkmax(dp[i][1],dp[j][1]+dam[i]-1);
				}
				else{
					chkmax(dp[i][1],dp[j][1]+dam[i]);
				}
			}
		}
	}
	rep(i,1,n){
		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<sum-dp[n][0]<<endl;
	cout<<"---------"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}