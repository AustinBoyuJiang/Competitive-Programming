/*Author：AustinJiang
题目：可持久化并查集
时间复杂度：O(m*log(n)*log(n))
算法：可持久化，线段树，并查集 */
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
const int N=2e4+10;

int n,m,cnt,tot,root[N];

struct node{
	int lc,rc,fa,dep;
} st[N*20];

void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r){
		st[rt].fa=l;
		st[rt].dep=1;
		return;
	}
	int mid=l+r>>1;
	build(st[rt].lc,l,mid);
	build(st[rt].rc,mid+1,r);
}

void update1(int &rt,int rtk,int l,int r,int pos,int x){
	st[rt=++tot]=st[rtk];
	if(l==r){
		st[rt].fa=x;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update1(st[rt].lc,st[rtk].lc,l,mid,pos,x);
	else update1(st[rt].rc,st[rtk].rc,mid+1,r,pos,x);
}

void update2(int &rt,int rtk,int l,int r,int pos,int x){
	st[rt=++tot]=st[rtk];
	if(l==r){
		st[rt].dep=x;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update2(st[rt].lc,st[rtk].lc,l,mid,pos,x);
	else update2(st[rt].rc,st[rtk].rc,mid+1,r,pos,x);
}

int query1(int rt,int l,int r,int pos){
	if(l==r) return st[rt].fa;
	int mid=l+r>>1;
	if(pos<=mid) return query1(st[rt].lc,l,mid,pos);
	else return query1(st[rt].rc,mid+1,r,pos);
}

int query2(int rt,int l,int r,int pos){
	if(l==r) return st[rt].dep;
	int mid=l+r>>1;
	if(pos<=mid) return query2(st[rt].lc,l,mid,pos);
	else return query2(st[rt].rc,mid+1,r,pos);
}

int find(int x){
	if(query1(root[cnt-1],1,n,x)==x) return x;
	else return find(query1(root[cnt-1],1,n,x));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	build(root[0],1,n);
	for(cnt=1;cnt<=m;cnt++){
		int opt,a,b;
		cin>>opt;
		if(opt==1){
			cin>>a>>b;
			int fx=find(a),fy=find(b);
			int depx=query2(root[cnt-1],1,n,fx);
			int depy=query2(root[cnt-1],1,n,fy);
			if(depx<depy) update1(root[cnt],root[cnt-1],1,n,fx,fy);
			else if(depx>depy) update1(root[cnt],root[cnt-1],1,n,fy,fx);
			else{
				update1(root[cnt],root[cnt-1],1,n,fy,fx);
				update2(root[cnt],root[cnt],1,n,fx,depx+1);
			}
		}
		if(opt==2){
			cin>>a;
			root[cnt]=root[a];
		}
		if(opt==3){
			cin>>a>>b;
			cout<<((int)find(a)==find(b))<<endl;
			root[cnt]=root[cnt-1];
		}
	}
	return 0;
}

