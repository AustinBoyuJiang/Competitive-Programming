/*Author：AustinJiang
题目：最大生成木森林 
时间复杂度：O(n*k+m*log(k))
算法：二分，并查集 */
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
const int M=3e5+10;
const int K=1e4+10;

int n,m,k,f[K][N],ans[M];

struct edge{
	int id,u,v,w;
} e[M];

bool cmp(edge a,edge b){
	return a.w>b.w;
}

int find(int k,int x){
	if(x==f[k][x]) return x;
	return f[k][x]=find(k,f[k][x]);
}

void merge(int k,int x,int y){
	f[k][find(k,x)]=find(k,y);
}

bool check(int k,int x,int y){
	return find(k,x)!=find(k,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=j;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		int l=1,r=k,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,u,v)) res=mid,r=mid-1;
			else l=mid+1;
		}
		merge(res,u,v);
		ans[e[i].id]=res;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}

