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

const int INF = 0x3f3f3f3f;
const int MOD = 1e6+3;

const int N = 1e6+10;

int q,n,tot,ans,del[N];
PI a[N];

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>q;
	rep(i,1,q){
		char opt;
		int x,y;
		cin>>opt;
		if(opt=='A'){
			cin>>x>>y;
//			x=(x+ans)%MOD;
//			y=(y+ans)%MOD;
			a[++tot]={x,y};
		}
		else{
			cin>>x;
//			x=(x+ans)%MOD;
			del[x]=1;
		}
		VPI v;
		rep(j,1,tot){
			if(del[j]) continue;
			v.pb({a[j]});
		}
		n=v.size();
		sort(v.begin(),v.end());
		ans=0;
		for(PI p:v){
			ans=max(ans+1,p.fir)+p.sec-1;
		}
		cout<<ans<<endl;
	}
}

