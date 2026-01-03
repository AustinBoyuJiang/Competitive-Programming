/*Author: AustinJiang
题目: 布局 Layout
时间复杂度: O(n*m)
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
const int N=1e3+10;

int n,ml,md,flag,cnt[N],vis[N],dist[N];
VPI e[N];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>ml>>md;
	for(int i=1;i<=ml;i++){
		int a,b,d;
		cin>>a>>b>>d;
		e[a].pb(mp(b,d));
	}
	for(int i=1;i<=md;i++){
		int a,b,d;
		cin>>a>>b>>d;
		e[b].pb(mp(a,-d));
	}
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	q.pb(1);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		cnt[u]++;
		if(cnt[u]>n){
			flag=1;
			break;
		}
		for(auto i:e[u]){
			int v=i.fir;
			if(dist[u]+i.sec<dist[v]){
				dist[v]=dist[u]+i.sec;
				if(!vis[v]){
					vis[v]=1;
					q.pb(v);
				}
			}
		}
	}
	if(flag) cout<<-1<<endl;
	else if(dist[n]==INF) cout<<-2<<endl;
	else cout<<dist[n]<<endl;
	return 0;
}

