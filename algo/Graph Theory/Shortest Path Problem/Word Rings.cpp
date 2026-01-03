/*Author: AustinJiang
题目: Word Rings
时间复杂度: O(t*26^2*n*log(1000))
算法: 二分，最短路，SPFA算法*/
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
const int N=700;

int n,cnt[N],vis[N];
double dist[N];
VPI e[N];

bool SPFA(int u,double x){
	vis[u]=1;
	for(auto i:e[u]){
		int v=i.fir;
		if(dist[u]+i.sec-x>dist[v]){
			dist[v]=dist[u]+i.sec-x;
			if(vis[v]) return 0;
			if(!SPFA(v,x)) return 0;
		}
	}
	vis[u]=0;
	return 1;
}

bool check(double x){
	memset(vis,0,sizeof(vis));
	memset(dist,-0x3f,sizeof(dist));
	dist[0]=0;
	for(int i=0;i<676;i++)
		if(!SPFA(i,x)) return 1;
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n,n){
		for(int i=0;i<676;i++)
			e[i].clear();
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			int len=str.size();
			int start=(str[0]-'a')*26+str[1]-'a';
			int end=(str[len-2]-'a')*26+str[len-1]-'a';
			e[start].pb(mp(end,len));
		}
		double l=0,r=1000;
		while(l<=r){
			double mid=(l+r)/2;
			if(check(mid)) l=mid+0.001;
			else r=mid-0.001;
		}
		if(l==0) printf("No solution\n");
		else printf("%.2lf\n",r);
	}
	return 0;
}

