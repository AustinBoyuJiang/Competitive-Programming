/*Author: AustinJiang
题目: 糖果 
时间复杂度: O(n*k)
算法: 最短路，SPFA算法，差分约束*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;

int n,k,cnt[N],vis[N];
ll ans,dist[N];
VPI e[N];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		int x,a,b;
		cin>>x>>a>>b;
		if(x==1) e[a].pb(mp(b,0)),e[b].pb(mp(a,0));
		if(x==2) e[a].pb(mp(b,1));
		if(x==3) e[b].pb(mp(a,0));
		if(x==4) e[b].pb(mp(a,1));
		if(x==5) e[a].pb(mp(b,0));
	}
	for(int i=1;i<=n;i++)
		e[0].pb(mp(i,1));
	dist[0]=0;
	q.pb(0);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		cnt[u]++;
		if(cnt[u]>n){
			ans=-1;
			break;
		}
		for(auto i:e[u]){
			int v=i.fir;
			if(dist[u]+i.sec>dist[v]){
				dist[v]=dist[u]+i.sec;
				if(!vis[v]){
					vis[v]=1;
					if(dist[v]>dist[q.front()]) q.push_front(v);
					else q.pb(v);
				}
			}
		}
	}
	if(ans==-1) cout<<ans<<endl;
	else{
		for(int i=1;i<=n;i++)
			ans+=dist[i];
		cout<<ans<<endl;
	}
	return 0;
}

