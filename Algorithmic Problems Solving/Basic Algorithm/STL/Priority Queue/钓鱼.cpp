/*Author：AustinJiang
题目：钓鱼 
时间复杂度：O(n*h*log(h))
算法：优先队列 */
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
const int N=110;

int n,h,ans,f[N],d[N],t[N];

int solve(int pos){
	int time=h-t[pos];
	if(time<=0) return 0;
	int res=0;
	PQ<PI,VPI,less<PI>> q;
	for(int i=1;i<=pos;i++)
		q.push(mp(f[i],i));
	while(time--&&!q.empty()){
		PI top=q.top();
		q.pop();
		res+=top.fir;
		int fish=top.fir-d[top.sec];
		if(fish>=0) q.push(mp(fish,top.sec));
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	h*=12;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=2;i<=n;i++){
		cin>>t[i];
		t[i]+=t[i-1];
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}

