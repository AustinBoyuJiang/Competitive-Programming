/*Author：AustinJiang
题目：线段树之区间更新 
时间复杂度：O(q*log(n))
算法：树状数组，差分 */
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

int lowbit(int x){
	return x&-x;
}

int n,q;

struct fenwick{
	int d[(int)1e6+10][2];
	void update(int x,int v){for(int i=x;i<=1e6;i+=lowbit(i))d[i][0]+=v,d[i][1]+=v*x;}
	int query(int x,int k){int ans=0;for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];return ans;}
	int add(int x,int y,int v){update(x,v),update(y+1,-v);}
	int ask(int x,int y){return (y+1)*query(y,0)-query(y,1)-x*query(x-1,0)+query(x-1,1);}
} fw;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		fw.add(i,i,x);
	}
	for(int i=1;i<=q;i++){
		char opt;
		int a,b,c;
		cin>>opt>>a>>b;
		if(opt=='C') cin>>c,fw.add(a,b,c);
		else cout<<fw.ask(a,b)<<endl;
	}
	return 0;
}

