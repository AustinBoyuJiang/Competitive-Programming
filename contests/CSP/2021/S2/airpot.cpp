/*Author：AustinJiang
题目：廊桥分配
时间复杂度：O()
算法：
来源：CSP 2021 S2
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

int n,m[2],ans,sum[2][N];

struct plane{
	int st,ed;
} t[2][N];

bool cmp(plane a,plane b){
	return a.st<b.st;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m[0]>>m[1];
	for(int j=0;j<2;j++){
		for(int i=1;i<=m[j];i++)
			cin>>t[j][i].st>>t[j][i].ed;
		sort(t[j]+1,t[j]+m[j]+1,cmp);
	}
	for(int j=0;j<2;j++){
		int cnt=0,now;
		PQ<int,VI,greater<int>> id;
		PQ<PI,VPI,greater<PI>> q;
		for(int i=1;i<=m[j];i++){
			while(!q.empty()&&q.top().fir<t[j][i].st){
				id.push(q.top().sec);
				q.pop();
			}
			if(id.size()) now=id.top(),id.pop();
			else now=++cnt;
			sum[j][now]++;
			q.push(mp(t[j][i].ed,now));
		}
	}
	for(int i=1;i<=n;i++){
		sum[0][i]+=sum[0][i-1];
		sum[1][i]+=sum[1][i-1];
	}
	for(int i=0;i<=n;i++)
		ans=max(ans,sum[0][i]+sum[1][n-i]);
	cout<<ans<<endl;
	return 0;
}

