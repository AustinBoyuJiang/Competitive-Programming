/*Author：AustinJiang
题目：线段树套线段树
时间复杂度：O(q*log(n)*log(m))
算法：树套树，线段树 */
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
const int N=1e3+10;

int n,m,q;

struct col{
	int mx[N<<2],lazy[N<<2];
	
	void update(int rt,int l,int r,int x,int y,int v){
		mx[rt]=max(mx[rt],v);
		if(l==x&&r==y){
			lazy[rt]=max(lazy[rt],v);
			return;
		}
		int mid=l+r>>1;
		if(y<=mid) update(rt<<1,l,mid,x,y,v);
		else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
		else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
	}
	
	int query(int rt,int l,int r,int x,int y){
		if(l==x&&r==y) return mx[rt];
		int mid=l+r>>1;
		if(y<=mid) return max(lazy[rt],query(rt<<1,l,mid,x,y));
		else if(x>mid) return max(lazy[rt],query(rt<<1|1,mid+1,r,x,y));
		else return max(lazy[rt],max(query(rt<<1,l,mid,x,mid),query(rt<<1|1,mid+1,r,mid+1,y)));
	}
};

struct row{
	col mx[N<<2],lazy[N<<2];
	
	void update(int rt,int l,int r,int x1,int y1,int x2,int y2,int v){
		mx[rt].update(1,1,m,x2,y2,v);
		if(l==x1&&r==y1){
			lazy[rt].update(1,1,m,x2,y2,v);
			return;
		}
		int mid=l+r>>1;
		if(y1<=mid) update(rt<<1,l,mid,x1,y1,x2,y2,v);
		else if(x1>mid) update(rt<<1|1,mid+1,r,x1,y1,x2,y2,v);
		else update(rt<<1,l,mid,x1,mid,x2,y2,v),update(rt<<1|1,mid+1,r,mid+1,y1,x2,y2,v);
	}
	
	int query(int rt,int l,int r,int x1,int y1,int x2,int y2){
		if(l==x1&&r==y1) return mx[rt].query(1,1,m,x2,y2);
		int mid=l+r>>1;
		if(y1<=mid) return max(lazy[rt].query(1,1,m,x2,y2),query(rt<<1,l,mid,x1,y1,x2,y2));
		else if(x1>mid) return max(lazy[rt].query(1,1,m,x2,y2),query(rt<<1|1,mid+1,r,x1,y1,x2,y2));
		else return max(lazy[rt].query(1,1,m,x2,y2),max(query(rt<<1,l,mid,x1,mid,x2,y2),query(rt<<1|1,mid+1,r,mid+1,y1,x2,y2)));
	}
} t;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++){
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		t.update(1,1,n,x+1,x+a,y+1,y+b,t.query(1,1,n,x+1,x+a,y+1,y+b)+c);
	}
	cout<<t.query(1,1,n,1,n,1,m)<<endl;
	return 0;
}

