/*Author：AustinJiang
题目：普通莫队
时间复杂度：O(m*sqrt(n))
算法：莫队 */
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
const int N=3e4+10;

int n,m,tot,block,a[N],ans[N],cnt[N];

struct node{
	int id,l,r;
} q[N];

bool cmp(node a,node b){
	if((a.l-1)/block==(b.l-1)/block) return a.r<b.r;
	return (a.l-1)/block<(b.l-1)/block;
}

void in(int x){
	if(!cnt[a[x]]) tot++;
	cnt[a[x]]++;
}

void out(int x){
	cnt[a[x]]--;
	if(!cnt[a[x]]) tot--;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	block=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		int x=q[i].l,y=q[i].r;
		while(x<l) in(--l);
		while(x>l) out(l++);
		while(y<r) out(r--);
		while(y>r) in(++r);
		ans[q[i].id]=tot;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}

