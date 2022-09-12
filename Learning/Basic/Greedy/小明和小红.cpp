/*Author：AustinJiang
题目：小明和小红 
时间复杂度：O(n*log(n))
算法：差分，贪心 */
#pragma GCC optimize(2)
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
const int N=5e5+10;

int n,m,ans[N];

struct node{
	int sum,id;
} c[N];

bool cmp(node a,node b){
	if(a.sum==b.sum) return a.id<b.id;
	return a.sum<b.sum;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		c[l].sum++;
		c[r+1].sum--;
	}
	for(int i=1;i<=n;i++){
		c[i].sum+=c[i-1].sum;
		c[i].id=i;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		ans[c[i].id]=i;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}

