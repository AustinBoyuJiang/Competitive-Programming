/*Author：AustinJiang
题目：MinOr Tree
时间复杂度：O(t*n*log(n))
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
const int N=2e5+10;

int t,n,m,f[N];

struct edge{
	int u,v,w;
} e[N];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	f[find(x)]=find(y);
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	int ans=(1<<30)-1;
	for(int i=29;i>=0;i--){
		ans^=1<<i;
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int j=1;j<=m;j++)
			if((ans&e[j].w)==e[j].w)
				merge(e[j].u,e[j].v);
		int res=1,fn=find(n);
		for(int j=1;j<n;j++)
			if(find(j)!=fn){
				res=0;
				break;
			}
		if(!res) ans^=1<<i;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

