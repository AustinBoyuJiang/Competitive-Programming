/*Author��AustinJiang
��Ŀ�����ٵ�ҩ�� 
ʱ�临�Ӷȣ�O(n^2)
�㷨������ͼ */
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
const int N=510;

int n,k,ans,vis[N],match[N];
VI e[N];

bool find(int u){
	for(auto v:e[u]){
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||find(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		e[x].pb(y);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

