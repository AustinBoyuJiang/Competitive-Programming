#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;

int n,p[N],d[N],w[N*2],ans[N];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i]>>d[i];
	for(int i=1;i<=n;i++) w[i]=w[i+n]=p[i]-d[i];
	for(int i=1;i<=n*2;i++) w[i]+=w[i-1];
	for(int i=n*2;i>=1;i--){
		while(!q.empty()&&q.front()-i>=n) q.pop_front();
		while(!q.empty()&&w[q.back()]>=w[i]) q.pop_back();
		q.push_back(i);
		if(w[q.front()]-w[i-1]>=0) ans[i]=true;
	}
	q.clear();
	d[0]=d[n];
	for(int i=1;i<=n;i++) w[i]=w[i+n]=p[i]-d[i-1];
	for(int i=n*2;i>=1;i--) w[i]+=w[i+1];
	for(int i=1;i<=n;i++){
		while(!q.empty()&&i-q.front()>=n) q.pop_front();
		while(!q.empty()&&w[q.back()]>=w[i]) q.pop_back();
		q.push_back(i);
		if(w[q.front()]-w[i+1]>=0) ans[i]=true;
	}
	for(int i=1;i<=n;i++) cout<<(ans[i]?"TAK":"NIE")<<endl;
	return 0;
}

