/*Author：AustinJiang
题目：Portals
时间复杂度：O()
算法： 并查集，乘法计数 
来源：
描述：一个图，Q次查询，求满足要求的点对数量，即a和b之间的某条路径的最大边权不超过L 
*/
#include<bits/stdc++.h>
#define int long long
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
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;

int n,m,Q,tot,f[N],size[N],ans[N],dep[N];

struct edge{
	int u,v,w;
} e[N];

struct query{
	int x,id;
} q[N];

bool cmp1(edge a,edge b){
	return a.w<b.w;
}

bool cmp2(query a,query b){
	return a.x<b.x;
}

int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}

void merge(int x,int y){
	if(dep[x]<dep[y]){
		f[x]=y;
		size[y]+=size[x];
	}
	else if(dep[x]>dep[y]){
		f[y]=x;
		size[x]+=size[y];
	}
	else{
		f[x]=y;
		dep[y]++;
		size[y]+=size[x];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)
		f[i]=i,size[i]=1,dep[i]=1;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=Q;i++)
		cin>>q[i].x,q[i].id=i;
	sort(e+1,e+m+1,cmp1);
	sort(q+1,q+Q+1,cmp2);
	for(int i=1,j=0;i<=Q;i++){
		while(j<m&&e[j+1].w<=q[i].x){
			j++;
			int fx=find(e[j].u);
			int fy=find(e[j].v);
			if(fx!=fy){
				tot+=size[fx]*size[fy];
				merge(fx,fy);
			}
		}
		ans[q[i].id]=tot;
	}
	for(int i=1;i<=Q;i++)
		cout<<ans[i]<<endl;
	return 0;
}

