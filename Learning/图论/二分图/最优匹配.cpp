/*Author：AustinJiang
题目：最优匹配
时间复杂度：O(n^3)
算法：二分图，最优匹配，KM算法 */
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
const int N=310;

int n,d,ans,e[N][N],cx[N],cy[N],visx[N],visy[N],match[N];

bool find(int u){
	visx[u]=1;
	for(int v=1;v<=n;v++){
		if(visy[v]) continue;
		int t=cx[u]+cy[v]-e[u][v];
		if(t==0){
			visy[v]=1;
			if(!match[v]||find(match[v])){
				match[v]=u;
				return 1;
			}
		}
		if(t>0) d=min(d,t);
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>e[i][j];
			cx[i]=max(cx[i],e[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		while(1){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			d=INF;
			if(find(i)) break;
			for(int j=1;j<=n;j++){
				if(visx[j]) cx[j]-=d;
				if(visy[j]) cy[j]+=d;
			}
			for(int i=1;i<=n;i++){
				cout<<cx[i]<<' ';
			}
			cout<<endl;
			for(int i=1;i<=n;i++){
				cout<<cy[i]<<' ';
			}
			cout<<endl;
		}
		cout<<"----------"<<endl;		
	}
	for(int i=1;i<=n;i++)
		ans+=e[match[i]][i];
	cout<<ans<<endl;
	return 0;
}

