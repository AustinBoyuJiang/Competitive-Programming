/*Author: AustinJiang
题目: 太鼓达人
时间复杂度: O(2^k)
算法: 欧拉回路，位运算*/
#include<bits/stdc++.h>
using namespace std;
int k,m,cnt,vis[2050],ans[2050];

void dfs(int x){
	if(vis[x]) return; vis[x]=1;
	dfs(x<<1&(1<<k)-1);
	dfs(x<<1&(1<<k)-1|1);
	ans[cnt++]=x&1;
}

int main(){
	cin>>k;
	m=1<<k;
	dfs(0);
	cout<<m<<' ';
	for(int i=m-1;i>=0;i--)
		cout<<ans[(i+k-1)%m];
}

