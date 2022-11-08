/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=5e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,a[N],b[N],pos[N],ans[N],sum[N<<2];
stack<int> stk;

struct QUERY{
	int l,r,id;
} q[N];

bool cmp(QUERY a,QUERY b){
	return a.r<b.r;
}

void update(int rt,int l,int r,int x){
	if(l==r){
		sum[rt]++;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x);
	else update(rt<<1|1,mid+1,r,x); 
	sum[rt]++;
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&(a[i]==a[stk.top()]||b[i]>=b[stk.top()])) stk.pop();
		if(stk.empty()) pos[i]=0;
		else pos[i]=stk.top();
		stk.push(i);
	}
	for(int i=1;i<=m;i++){
		q[i].id=i;
		cin>>q[i].l>>q[i].r;
	}
	sort(q+1,q+m+1,cmp);
	int j=0;
	for(int i=1;i<=m;i++){
		while(j<q[i].r) update(1,0,n,pos[++j]);
		ans[q[i].id]=query(1,0,n,0,q[i].l-1)-q[i].l+1;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}

