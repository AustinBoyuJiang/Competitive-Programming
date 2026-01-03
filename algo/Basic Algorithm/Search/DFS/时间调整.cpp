/*Author：AustinJiang
题目：时间调整
时间复杂度：O(4^10*16*5)
算法：DFS
思路：每个按钮最多按三次，多按没有意义，所以枚举出所有按钮组合*/
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
const int N=16;
const int S=10;

int n,ans=INF,a[N],tmp[N],cnt[S];
VI sw[S];

void init(){
	sw[0].pb(0),sw[0].pb(1),sw[0].pb(2);
	sw[1].pb(3),sw[1].pb(7),sw[1].pb(9),sw[1].pb(11);
	sw[2].pb(4),sw[2].pb(10),sw[2].pb(14),sw[2].pb(15);
	sw[3].pb(0),sw[3].pb(4),sw[3].pb(5),sw[3].pb(6),sw[3].pb(7);
	sw[4].pb(6),sw[4].pb(7),sw[4].pb(8),sw[4].pb(10),sw[4].pb(12);
	sw[5].pb(0),sw[5].pb(2),sw[5].pb(14),sw[5].pb(15);
	sw[6].pb(3),sw[6].pb(14),sw[6].pb(15);
	sw[7].pb(4),sw[7].pb(5),sw[7].pb(7),sw[7].pb(14),sw[7].pb(15);
	sw[8].pb(1),sw[8].pb(2),sw[8].pb(3),sw[8].pb(4),sw[8].pb(5);
	sw[9].pb(3),sw[9].pb(4),sw[9].pb(5),sw[9].pb(9),sw[9].pb(13);
}

bool check(){
	for(int i=0;i<16;i++)
		if(tmp[i]!=0) return 0;
	return 1;
}

void dfs(int id,int step){
	if(id>9){
		memcpy(tmp,a,sizeof(a));
		for(int i=0;i<10;i++){
			for(auto j:sw[i]){
				tmp[j]+=cnt[i];
				tmp[j]%=4;
			}
		}
		if(check()) ans=min(ans,step);
		return;
	}
	for(int i=0;i<4;i++){
		cnt[id]=i;
		dfs(id+1,step+i);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<16;i++){
		cin>>a[i];
		a[i]/=3;
		a[i]%=4;
	}
	init();
	dfs(0,0);
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}

