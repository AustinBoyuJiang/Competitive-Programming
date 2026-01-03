/*Author: AustinJiang
题目: 找工作 
时间复杂度: O(c*(p+f))
算法: 最短路，SPFA算法*/
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
const int C=250;

int d,p,c,f,s,ans,cnt[C],vis[C],dist[C];
VPI e[C];
deque<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>d>>p>>c>>f>>s;
	for(int i=1;i<=p;i++){
		int a,b;
		cin>>a>>b;
		e[a].pb(mp(b,d));
	}
	for(int i=1;i<=f;i++){
		int j,k,t;
		cin>>j>>k>>t;
		e[j].pb(mp(k,d-t));
	}
	memset(dist,-0x3f,sizeof(dist));
	dist[s]=d;
	q.pb(s);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		cnt[u]++;
		if(cnt[u]>c){
			ans=-1;
			break;
		}
		for(auto i:e[u]){
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
	if(ans!=-1)
		for(int i=1;i<=c;i++)
			ans=max(ans,dist[i]);
	cout<<ans<<endl;
	return 0;
}


