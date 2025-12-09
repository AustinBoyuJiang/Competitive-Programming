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

void SOLVE(int Case){
	string s;
	cin>>s;
	n=s.size();
	int ans=0;
	int cnt[2]={0,0};
	int i=0;
	while(i<n){
		int j=i;
		while(j<n){
			if(s[j]!='I' && s[j+1]=='I'){
				j+=2;
				continue;
			}
			if(s[j]=='I'){
				break;
			}
			else break;
		}
		cnt[0]=cnt[1]=0;
		rep(k,i,j){
			if(s[k]=='M') cnt[0]++;
			if(s[k]=='T') cnt[1]++;
			k+=1;
		}
		ans+=min(cnt[0],cnt[1]/2);
		i=j+1;
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