/*Author：AustinJiang
题目：Interval GCD
时间复杂度：O(m*log(n))
算法：线段树，差分 
思路：gcd(a,b)=gcd(a,b-a)
st1维护正常的值，st2维护差值的gcd*/
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
const int N=5e5+10;

int n,m,a[N],st1[N<<2],st2[N<<2],lazy[N<<2];

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

void push_up1(int rt){
	st1[rt]=st1[rt<<1]+st1[rt<<1|1];
}

void push_down(int rt,int l,int mid,int r){
	lazy[rt<<1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	st1[rt<<1]+=lazy[rt]*(mid-l+1);
	st1[rt<<1|1]+=lazy[rt]*(r-mid);
	lazy[rt]=0;
}

void build1(int rt,int l,int r){
	if(l==r){
		st1[rt]=a[l];
		return;
	}
	int mid=l+r>>1;
	build1(rt<<1,l,mid);
	build1(rt<<1|1,mid+1,r);
	push_up1(rt);
}

void update1(int rt,int l,int r,int x,int y,int v){
	if(l==x&&r==y){
		st1[rt]+=v*(r-l+1);
		lazy[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(y<=mid) update1(rt<<1,l,mid,x,y,v);
	else if(x>mid) update1(rt<<1|1,mid+1,r,x,y,v);
	else update1(rt<<1,l,mid,x,mid,v),update1(rt<<1|1,mid+1,r,mid+1,y,v);
	push_up1(rt);
}

int query1(int rt,int l,int r,int x){
	if(l==r) return st1[rt];
	int mid=l+r>>1;
	push_down(rt,l,mid,r);
	if(x<=mid) return query1(rt<<1,l,mid,x);
	else return query1(rt<<1|1,mid+1,r,x);
}

void push_up2(int rt){
	st2[rt]=gcd(st2[rt<<1],st2[rt<<1|1]);
}

void build2(int rt,int l,int r){
	if(l==r){
		st2[rt]=a[l]-a[l-1];
		return;
	}
	int mid=l+r>>1;
	build2(rt<<1,l,mid);
	build2(rt<<1|1,mid+1,r);
	push_up2(rt);
}

void update2(int rt,int l,int r,int x,int v){
	if(l==r){
		st2[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update2(rt<<1,l,mid,x,v);
	else update2(rt<<1|1,mid+1,r,x,v);
	push_up2(rt);
}

int query2(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st2[rt];
	int mid=l+r>>1;
	if(y<=mid) return query2(rt<<1,l,mid,x,y);
	else if(x>mid) return query2(rt<<1|1,mid+1,r,x,y);
	else return gcd(query2(rt<<1,l,mid,x,mid),query2(rt<<1|1,mid+1,r,mid+1,y));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build1(1,1,n);
	build2(1,1,n);
	for(int i=1;i<=m;i++){
		char opt;
		int l,r,d;
		cin>>opt;
		if(opt=='C'){
			cin>>l>>r>>d;
			update1(1,1,n,l,r,d);
			update2(1,1,n,l,d);
			if(r+1<=n) update2(1,1,n,r+1,-d);
		}
		else{
			cin>>l>>r;
			if(l==r) cout<<query1(1,1,n,l)<<endl;
			else cout<<gcd(query1(1,1,n,l),abs(query2(1,1,n,l+1,r)))<<endl;
		}
	}
	return 0;
}

