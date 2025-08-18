#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const int INF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6+10;

int t,n,k;
unordered_map<int,int> cnt,cnt2;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		cnt.clear();
		cnt2.clear();
		VI p;
		int x=k;
		for(int i=2;i*i<=k;i++){
			if(x%i==0){
				p.pb(i);
			}
			while(x%i==0){
				x/=i;
				cnt[i]++;
			}
		}
		if(x>1){
			p.pb(x);
			cnt[x]++;
		}
//		for(int x:p){
//			cout<<x<<","<<cnt[x]<<endl;
//		}
//		continue; 
		for(int x:p){
			__int128 y=x;
			while(y<=n){
				cnt2[x]+=n/y;
				y*=x;
			}
		}
		int ans=INF;
		for(PI p:cnt){
			ans=min(ans,cnt2[p.fir]/p.sec);
		}
		cout<<ans<<endl;
	}

}

