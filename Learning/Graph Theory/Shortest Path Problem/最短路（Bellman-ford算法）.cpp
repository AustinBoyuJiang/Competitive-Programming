/*Author: AustinJiang
��Ŀ: ���· 
ʱ�临�Ӷ�: O(n*m)
�㷨: ���·��Bellman-ford�㷨*/
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
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e3+10;
const int M=2e4+10;

int n,m,cnt,flag1,dist[N];

struct edge{
	int u,v,w;
}e[M];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
		e[++cnt]={v,u,w};
	}
	for(int i=1;i<=n;i++){
		flag1=false;//�жϸ�Ȩ�� 
		bool flag2=false;//�жϵ�ǰ�����û�и��£����û��˵���Ѿ������·�����˳�ѭ�� 
		for(int j=1;j<=cnt;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				flag1=flag2=true;
			}
		}
		if(!flag2) break;
	}
	if(flag1) cout<<"Nagetive circle"<<endl;
	else cout<<dist[n]<<endl;
	return 0;
}

