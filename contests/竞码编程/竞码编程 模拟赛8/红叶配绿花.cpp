/*Author：AustinJiang
题目：红叶配绿花
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=1e5+10;

int n,m,k,f[N];

struct edge{
	int u,v,w,col;
} e[N];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int u,int v){
	f[find(u)]=find(v);
}

bool cmp(edge a,edge b){
	if(a.w!=b.w) return a.w<b.w;
	else return a.col<b.col;
}

PI check(int x){
	for(int i=1;i<=m;i++)
		if(!e[i].col) e[i].w+=x;
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<n;i++)
		f[i]=i;
	int sum=0,cnt=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		merge(e[i].u,e[i].v);
		sum+=e[i].w;
		cnt+=!e[i].col;
	}
	for(int i=1;i<=m;i++)
		if(!e[i].col) e[i].w-=x;
	return mp(sum,cnt);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	int x=0;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w>>e[i].col;
	int l=-105,r=105,ans;
	while(l<=r){
		int mid=l+r>>1;
		PI res=check(mid);
		if(res.sec>=k) l=mid+1,ans=res.fir-k*mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

