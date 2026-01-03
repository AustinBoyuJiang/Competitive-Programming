/*Author：AustinJiang
题目：线段树之单点更新
时间复杂度：O(m*log(n))
算法：树状数组 */
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
const int N=1e5+10;

int n,m,sum[N];

int lowbit(int x){
	return x&-x;
}

void update(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)) sum[i]+=y;
}

int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i)) ans+=sum[i];
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int k,a,b;
		cin>>k>>a>>b;
		if(k==0) update(a,b);
		else cout<<query(b)-query(a-1)<<endl;
	}
	return 0;
}

