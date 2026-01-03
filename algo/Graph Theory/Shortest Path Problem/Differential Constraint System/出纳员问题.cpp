/*Author: AustinJiang
题目: 出纳员问题 
时间复杂度: O(T*log(n)*24*n)
算法: 差分约束，二分

Solution:
r[i]表示第i小时需要的人数 
t[i]表示第i小时申请的数量
e[i]表示第1到i小时雇佣的人数 
r[i]<=e[i]-e[i-1]<=t[i] 每小时雇佣的人数大于等于需要的人数且小于等于申请的人数 
e[i]-e[i-8]>=r[i] (if i>=8) 八小时内雇佣的人数必须大于当前需要的人数 
e[i-8+24]-e[i]<=tot-r[i] (if i<8) 反向建图 
e[24]-e[i]>=tot 全天雇佣的人数大于tot 
二分枚举tot表示全天需要雇佣多少出纳员*/
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
const int D=25;

int T,n,r[D],t[D],cnt[D],vis[D],dist[D];
VPI e[D];
deque<int> q;

bool check(int tot){
	memset(dist,0x3f,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	q.clear();
	for(int i=0;i<=24;i++)
		e[i].clear();
	for(int i=1;i<=24;i++){
		e[i].pb(mp(i-1,r[i]));
		e[i-1].pb(mp(i,t[i]));
		if(i>=8) e[i].pb(mp(i-8,-r[i]));
		else e[i].pb(mp(i+16,tot-r[i]));
	}
	e[24].pb(mp(0,-tot));
	dist[0]=0;
	q.pb(0);
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		vis[u]=0;
		if(++cnt[u]>24) return 0;
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
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		memset(t,0,sizeof(t));
		for(int i=1;i<=24;i++)//0点从1开始 
			cin>>r[i];
		cin>>n;
		for(int i=1,x;i<=n;i++)
			cin>>x,t[x+1]++;
		int l=0,r=n,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		if(ans!=-1) cout<<ans<<endl;
		else cout<<"No Solution"<<endl;
	}
	return 0;
}

