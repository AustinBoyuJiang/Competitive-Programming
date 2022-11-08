/*Author：AustinJiang
题目：Segment
时间复杂度：O(n*log(n)^2)
算法：线段树，标记永久化，李超线段树 */
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int M=4e4;
const int MOD1=39989;
const int MOD2=1e9;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,tot,lastans,st[M<<2];

struct segment{
	double k,b; //斜率和截距 
} sg[N];

double calc(int id,int x){
	return sg[id].b+sg[id].k*x; //返回线段在x的高度 
}

int getMax(int a,int b,int x){
	if(b<a) swap(a,b);
	if(a==0) return b;
	if(calc(a,x)>=calc(b,x)) return a;
	return b;
}

int add(int x0,int y0,int x1,int y1){
	tot++;
	if(x0==x1) sg[tot].k=0,sg[tot].b=max(y0,y1);
	else sg[tot].k=(double)(y1-y0)/(x1-x0),sg[tot].b=y0-x0*sg[tot].k;
	return tot;
}

void update(int rt,int l,int r,int x,int y,int id){
	int mid=l+r>>1;
	if(l==x&&r==y){
		int a=getMax(st[rt],id,mid),b=st[rt]+id-a; st[rt]=a;
		if(getMax(a,b,l)==b) update(rt<<1,l,mid,x,mid,b);
		if(getMax(a,b,r)==b) update(rt<<1|1,mid+1,r,mid+1,y,b);
		return;
	}
	if(y<=mid) update(rt<<1,l,mid,x,y,id);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,id);
	else update(rt<<1,l,mid,x,mid,id),update(rt<<1|1,mid+1,r,mid+1,y,id);
}

int query(int rt,int l,int r,int x){
	if(l==r) return st[rt];
	int mid=l+r>>1;
	if(x<=mid) return getMax(query(rt<<1,l,mid,x),st[rt],x);
	else return getMax(query(rt<<1|1,mid+1,r,x),st[rt],x);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt,x0,y0,x1,y1;
		cin>>opt;
		if(opt==0){
			cin>>x0;
			x0=(x0+lastans-1)%MOD1+1;
			cout<<(lastans=query(1,1,MOD1,x0))<<endl;
		}
		else{
			cin>>x0>>y0>>x1>>y1;
			x0=(x0+lastans-1)%MOD1+1;
			y0=(y0+lastans-1)%MOD2+1;
			x1=(x1+lastans-1)%MOD1+1;
			y1=(y1+lastans-1)%MOD2+1;
			if(x0>x1) swap(x0,x1),swap(y0,y1);
			update(1,1,MOD1,x0,x1,add(x0,y0,x1,y1));
		}
	}
	return 0;
}

