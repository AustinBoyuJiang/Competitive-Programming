/*Author��AustinJiang
��Ŀ���̶��ܵĹ��� 
ʱ�临�Ӷȣ�O()
�㷨��
��Դ��
˼·��
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,k[N],in[N];
double dp[N];
VPI e[N];
queue<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[v].pb(mp(u,w));
		k[u]++,in[u]++;
	}
	q.push(n);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(auto nxt:e[u]){
			int v=nxt.fir;
			dp[v]+=1.0/k[v]*(dp[u]+nxt.sec);
			if(!--in[v]) q.push(v);
		}
	}
	printf("%.2lf",dp[1]);
	return 0;
}

