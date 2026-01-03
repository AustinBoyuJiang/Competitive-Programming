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

const int N = 1e5+10;

int T,n,t;
char ans[N];

struct node{
	int p,bb,be,eb,ee;
} a[N],dp[N];

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>t;
		rep(i,1,n){
			cin>>a[i].p>>a[i].bb>>a[i].be>>a[i].eb>>a[i].ee;
		}
		dp[1].bb=INF;
		dp[1].be=a[1].p;
		dp[1].eb=a[1].p;
		dp[1].ee=INF;
		rep(i,2,n){
			dp[i].bb=a[i].p+min(dp[i-1].bb+a[i-1].be,dp[i-1].be+a[i-1].ee);
			dp[i].be=a[i].p+min(dp[i-1].bb+a[i-1].bb,dp[i-1].be+a[i-1].eb);
			dp[i].eb=a[i].p+min(dp[i-1].eb+a[i-1].be,dp[i-1].ee+a[i-1].ee);
			dp[i].ee=a[i].p+min(dp[i-1].eb+a[i-1].bb,dp[i-1].ee+a[i-1].eb);
		}
		int mn=min({dp[n].bb+a[n].bb,dp[n].be+a[n].eb,dp[n].eb+a[n].be,dp[n].ee+a[n].ee});
		if(mn>t){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		else{
			bool tr,nxt;
			if(mn==dp[n].bb+a[n].bb){
				mn=dp[n].bb;
				ans[1]='F';
				tr=0;
				nxt=0;
			}
			else if(mn==dp[n].be+a[n].eb){
				mn=dp[n].be;
				ans[1]='F';
				tr=0;
				nxt=1;
			}
			else if(mn==dp[n].eb+a[n].be){
				mn=dp[n].eb;
				ans[1]='B';
				tr=1;
				nxt=0;
			}
			else if(mn==dp[n].ee+a[n].ee){
				mn=dp[n].ee;
				ans[1]='B';
				tr=1;
				nxt=1;
			}
			if(tr==0){
				per(i,n,2){
					if(nxt==0){
						ans[i]='B';
						if(dp[i-1].bb+a[i-1].be<dp[i-1].be+a[i-1].ee){
							nxt=0;
						}
						else{
							nxt=1;
						}
					}
					else{
						ans[i]='F';
						if(dp[i-1].bb+a[i-1].bb<dp[i-1].be+a[i-1].eb){
							nxt=0;
						}
						else{
							nxt=1;
						}
					}
				}
			}
			else{
				per(i,n,2){
					if(nxt==0){
						ans[i]='B';
						if(dp[i-1].eb+a[i-1].be<dp[i-1].ee+a[i-1].ee){
							nxt=0;
						}
						else{
							nxt=1;
						}
					}
					else{
						ans[i]='F';
						if(dp[i-1].eb+a[i-1].bb<dp[i-1].ee+a[i-1].eb){
							nxt=0;
						}
						else{
							nxt=1;
						}
					}
				}
			}
			rep(i,1,n){
				cout<<ans[i];
			} cout<<endl;
		}
	}
	return 0;
}

