/*Author：AustinJiang
题目：生日快乐 
时间复杂度：O(4^p)
算法：DFS
来源：SCOI2009 */
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
const int N=1e5+10;

double x,y;
int p;

double dfs(double x,double y,int p){
	if(x<y) swap(x,y);
	if(p==1) return x/y;
	double ans=INF;
	for(int i=1;i<p;i++){
		double tmp1=max(dfs(x/p*i,y,i),dfs(x-x/p*i,y,p-i));
		double tmp2=max(dfs(x,y/p*i,i),dfs(x,y-y/p*i,p-i));
		ans=min(ans,min(tmp1,tmp2));
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>y>>p;
	printf("%.6f\n",dfs(x,y,p));
	return 0;
}

