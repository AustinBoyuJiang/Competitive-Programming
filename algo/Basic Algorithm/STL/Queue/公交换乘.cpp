#include<bits/stdc++.h>
#define int long long
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=LLONG_MAX;
const int N=1e5+10;

int n,k,p,t,ans;
queue<PI> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int dcnt=0;
		cin>>k>>p>>t;
		if(k==0){
			q.push(mp(t+45,p));
		}
		else{
			queue<PI> tmp;
			while(!q.empty()){
				PI tp=q.front();
				q.pop();
				if(t<=tp.fir){
					if(tp.sec>=p){
						dcnt=p;
						break;
					}
					else{
						tmp.push(tp);
					}
				}
			}
			while(!q.empty()){
				tmp.push(q.front());
				q.pop();
			}
			while(!tmp.empty()){
				q.push(tmp.front());
				tmp.pop();
			}
		}
		ans+=p-dcnt;
	}
	cout<<ans<<endl;
	return 0;
}

