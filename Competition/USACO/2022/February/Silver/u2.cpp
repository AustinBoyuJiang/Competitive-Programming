/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
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
const int INF=0x3f3f3f3f;
const int N=50;

int n,xg,yg,x[N],y[N],ans[N];

struct result{
	unordered_map<int,int> cnt;
};

map<PI,result> flag;

struct QUEUE{
	int x,y,step,cnt;
};

inline void bfs1(int t){
	queue<QUEUE> q;
	q.push({0,0,0,0});
	while(!q.empty()){
		QUEUE now=q.front();
		q.pop();
		if(now.step==t){
			flag[mp(now.x,now.y)].cnt[now.cnt]++;
		}
		if(now.step<t){
			q.push({now.x,now.y,now.step+1,now.cnt});
			q.push({now.x+x[now.step+1],now.y+y[now.step+1],now.step+1,now.cnt+1});
		}
	}
}

inline void bfs2(int t){
	queue<QUEUE> q;
	q.push({xg,yg,n,0});
	while(!q.empty()){
		QUEUE now=q.front();
		q.pop();
		if(now.step==t){
			for(auto i:flag[mp(now.x,now.y)].cnt){
				ans[now.cnt+i.fir]+=i.sec;
			}
		}
		if(now.step>t){
			q.push({now.x,now.y,now.step-1,now.cnt});
			q.push({now.x-x[now.step],now.y-y[now.step],now.step-1,now.cnt+1});
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>xg>>yg;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	bfs1(n/2+(n&1));
	bfs2(n/2+(n&1));
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

