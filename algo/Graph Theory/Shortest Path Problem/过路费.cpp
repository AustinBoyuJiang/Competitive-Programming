/*Author: AustinJiang
题目: 过路费 
时间复杂度: O(n^3)
算法: 最短路，Floyd法*/
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
const int N=300;

int n,m,K,C[N],dist[N][N],ans[N][N];
PI c[N];

signed main(){
	cin>>n>>m>>K;
	memset(dist,0x3f,sizeof(dist));
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		cin>>c[i].fir;
		c[i].sec=i;
		C[i]=c[i].fir;
		dist[i][i]=0;
		ans[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		dist[a][b]=min(dist[a][b],w);
		dist[b][a]=min(dist[b][a],w);
	}
	sort(c+1,c+n+1);
	for(int k=1;k<=n;k++){
		int pos=c[k].sec;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][pos]+dist[pos][j]);
				ans[i][j]=min(ans[i][j],dist[i][j]+max(C[pos],max(C[i],C[j])));
			}
	}
	for(int i=1;i<=K;i++){
		int s,t;
		cin>>s>>t;
		cout<<ans[s][t]<<endl;
	}
}
