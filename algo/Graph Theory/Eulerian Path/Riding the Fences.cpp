/*Author: AustinJiang
题目: Riding the Fences
时间复杂度: O(n+m)
算法: 欧拉回路，Hierholzer算法*/
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
const int F=1050;

int n,f,s,cnt,flag[N],ans[F],Map[N][N];

void dfs(int u){
	for(int v=1;v<=n;v++){
		if(!Map[u][v]) continue;
		Map[u][v]--;
		Map[v][u]--;
		dfs(v);
	}
	ans[++cnt]=u;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>f;
	for(int i=1;i<=f;i++){
		int u,v;
		cin>>u>>v;
		Map[u][v]++;
		Map[v][u]++;
		flag[u]++;
		flag[v]++;
		n=max(n,max(u,v));
	}
	while(!flag[s]) s++;
	for(int i=1;i<=n;i++){
		if(flag[i]&1){
			s=i;
			break; 
		}
	}
	dfs(s);
	for(int i=cnt;i>=1;i--)
		cout<<ans[i]<<endl;
	return 0;
}
