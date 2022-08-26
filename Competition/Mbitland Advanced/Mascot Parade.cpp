/*Author：AustinJiang
题目：Mascot Parade
时间复杂度：O(n*log(n)^2)
算法：主席树，李超线段树 
来源：mbitland_advanced p3
思路：可持久化李超线段树 
*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
const int Y=1e9;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,q,ans,tot,root[N];

struct segent{
	int k,b;
} sg[N];

struct node{
	int lc,rc,id;
} st[N<<2];

int calc(int id,int x){
	return sg[id].b+sg[id].k*x;
}

int cmp(int a,int b,int x){
	if(a==0||b==0) return a+b;
	if(calc(a,x)<calc(b,x)) return a;
	else return b;
}

void update(int &rt,int rtk,int l,int r,int id){
	st[rt=++tot]=st[rtk];
	int mid=l+r>>1;
	int a=cmp(st[rt].id,id,mid),b=st[rt].id+id-a; st[rt].id=a;
	if(cmp(a,b,l)==b) update(st[rt].lc,st[rtk].lc,l,mid,b);
	if(cmp(a,b,r)==b) update(st[rt].rc,st[rtk].rc,mid+1,r,b);
}

int query(int rt,int l,int r,int x){
	if(l==r) return st[rt].id;
	int mid=l+r>>1;
	if(x<=mid) return cmp(st[rt].id,query(st[rt].lc,l,mid,x),x); 
	else return cmp(st[rt].id,query(st[rt].rc,mid+1,r,x),x);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>sg[i].b;
	for(int i=1;i<=n;i++)
		cin>>sg[i].k;
	for(int i=n;i>=1;i--){
		sg[i].b+=n-i;
		update(root[i],root[i+1],0,Y,i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		x=(ans+x)%n+1;
		y=(ans+y)%Y+1;
		ans=calc(query(root[x],0,Y,y),y)-n+x;
		cout<<ans<<endl;
	}
	return 0;
}

