/*Author：AustinJiang
题目：Travel Budget
时间复杂度：O()
算法：线段树，标记永久啊，李超线段树 
来源：Yet Another Contest 2 P6 */
#include<bits/stdc++.h>
#define int long long
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
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,st[N<<2];

struct segment{
	int k,b;
} sg[N];

struct town{
	int p,s,c,d;
} t[N];

bool cmp(town a,town b){
	return a.p<b.p;
}

int find(int id){
	int l=1,r=n,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(t[id].p+t[id].s<t[mid].p) r=mid-1;
		else l=mid+1,res=mid;
	}
	return res;
}

void add(int id,int val){
	sg[id].k=t[id].c;
	sg[id].b=t[id].d-t[id].p*t[id].c+val;
}

int calc(int id,int x){
	if(!id) return INF;
	return sg[id].b+sg[id].k*x;
}

int getMin(int a,int b,int x){
	if(calc(a,x)<calc(b,x)) return a;
	else return b;
}

void update(int rt,int l,int r,int x,int y,int id){
	int mid=l+r>>1;
	if(l==x&&r==y){
		int a=getMin(st[rt],id,t[mid].p); int b=st[rt]+id-a; st[rt]=a;
		if(getMin(a,b,t[l].p)==b) update(rt<<1,l,mid,x,mid,b);
		if(getMin(a,b,t[r].p)==b) update(rt<<1|1,mid+1,r,mid+1,y,b);
		return;
	}
	if(y<=mid) update(rt<<1,l,mid,x,y,id);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,id);
	else update(rt<<1,l,mid,x,mid,id),update(rt<<1|1,mid+1,r,mid+1,y,id);
}

int query(int rt,int l,int r,int x){
	if(l==r) return calc(st[rt],t[x].p);
	int mid=l+r>>1;
	if(x<=mid) return min(query(rt<<1,l,mid,x),calc(st[rt],t[x].p));
	else return min(query(rt<<1|1,mid+1,r,x),calc(st[rt],t[x].p));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i].p>>t[i].s>>t[i].c>>t[i].d;
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<n;i++){
		add(i,i==1?0:query(1,1,n,i));
		if(find(i)>i) update(1,1,n,i+1,find(i),i);
	}
	cout<<query(1,1,n,n)<<endl;
	return 0;
}

