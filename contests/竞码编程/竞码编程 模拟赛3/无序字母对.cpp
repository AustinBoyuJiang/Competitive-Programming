/*Author：AustinJiang
题目：无序字母对
时间复杂度：O(n)
算法：欧拉回路 */
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
const int N=1e4;

int n,cnt,tot,k,vis[N],du[N],ans[N];
VPI e[N];

void dfs(int u){
	ans[++k]=u;
	for(auto i:e[u]){
		int v=i.fir;
		if(vis[i.sec]) continue;
		vis[i.sec]=1;
		dfs(v);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		cin>>x>>y;
		int a=x-'A';
		int b=y-'A';
		e[a].pb(mp(b,i));
		e[b].pb(mp(a,i));
		du[a]++;
		du[b]++;
	}
	int cnt=0;
	for(int i=0;i<=N;i++){
		if(du[i]&1) cnt++;
		sort(e[i].begin(),e[i].end());
	}
	if(cnt!=0&&cnt!=2){
		cout<<"No Solution"<<endl;
		return 0;
	}
	if(!cnt){
		for(int i=0;i<=N;i++)
			if(du[i]){
				dfs(i);
				break;
			}
	}
	else{
		for(int i=0;i<=N;i++)
			if(du[i]&1){
				dfs(i);
				break;
			}
	}
	if(k==n+1){
		for(int i=1;i<=k;i++){
			cout<<(char)(ans[i]+'A');
		}
	}
	else cout<<"No Solution"<<endl;
	return 0;
}

