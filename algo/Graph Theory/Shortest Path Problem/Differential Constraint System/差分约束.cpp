/*Author: AustinJiang
题目: 差分约束 
时间复杂度: O(n*h)
算法: 最短路，差分约束，SPFA算法*/
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
const int N=3e4+10;

int n,h,vis[N],dist[N];
VPI Map[N];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	for(int i=1;i<=h;i++){
		int b,e,t;
		cin>>b>>e>>t;
		Map[b-1].pb(mp(e,t));
	}
	for(int i=0;i<n;i++){
		Map[i].pb(mp(i+1,0));
		Map[i+1].pb(mp(i,-1));
	}
	memset(dist,-0x3f,sizeof(dist));
	dist[0]=0;
	q.pb(0);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		for(auto i:Map[u]){
			int v=i.fir;
			if(dist[u]+i.sec>dist[v]){
				dist[v]=dist[u]+i.sec;
				if(!vis[v]){
					vis[v]=1;
					q.pb(v);
				}
			}
		}
	}
	cout<<dist[n]<<endl;
	return 0;
}

