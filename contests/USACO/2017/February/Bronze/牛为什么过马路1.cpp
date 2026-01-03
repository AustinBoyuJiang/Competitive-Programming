/*Author：AustinJiang
题目：牛为什么过马路1
时间复杂度：O(n)
算法：模拟 
来源：USACO 2017 February Bronze */
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
const int N=11;

int n,ans,pos[11];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	memset(pos,-1,sizeof(pos));
	for(int i=1;i<=n;i++){
		int id,x;
		cin>>id>>x;
		if(pos[id]!=-1&&pos[id]!=x) ans++;
		pos[id]=x;
	}
	cout<<ans<<endl;
	return 0;
}

