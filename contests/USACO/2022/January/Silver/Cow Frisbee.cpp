/*Author：AustinJiang
题目：Cow Frisbee
时间复杂度：O(n*log(n))
算法：线段树,单调栈 
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
const int N=3e5+10;

int n,ans,a[N],upr[N];
stack<int> stk;

struct segment_tree{
	int sum[N<<2],lazy[N<<2];
	
	void push_up(int rt){
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
	
	void push_down(int rt,int l,int mid,int r){
		if(lazy[rt]==-1) return;
		sum[rt<<1]=(mid-l+1)*lazy[rt];
		sum[rt<<1|1]=(r-mid)*lazy[rt];
		lazy[rt<<1]=lazy[rt];
		lazy[rt<<1|1]=lazy[rt];
		lazy[rt]=-1;
	}
	
	void update(int rt,int l,int r,int x,int y,int v){
		if(l==x&&r==y){
			sum[rt]=(r-l+1)*v;
			lazy[rt]=v;
			return;
		}
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) update(rt<<1,l,mid,x,y,v);
		else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
		else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
		push_up(rt);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return sum[rt];
		int mid=l+r>>1;
		push_down(rt,l,mid,r);
		if(y<=mid) return query(rt<<1,l,mid,x,y);
		else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
		else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
	}
	
} pos,cnt;

int find(int x){
	for(int i=x-1;i>=1;i--)
		if(a[i]>a[x]) return a[i];
	return n;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		while(!stk.empty()&&a[i]>a[stk.top()]){
			upr[stk.top()]=a[i];
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		upr[stk.top()]=n;
		stk.pop();
	}
	for(int i=1;i<=n;i++){
		ans+=(i+1)*cnt.query(1,1,n,1,upr[i])-pos.query(1,1,n,1,upr[i]);
		pos.update(1,1,n,1,a[i],0);
		cnt.update(1,1,n,1,a[i],0);
		pos.update(1,1,n,a[i],a[i],i);
		cnt.update(1,1,n,a[i],a[i],1);
	}
	cout<<ans<<endl;
	return 0;
}

