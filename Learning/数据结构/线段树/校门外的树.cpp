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
const int N=5e4+10;

int n,m;

struct segment_tree{
	int sum[N<<2];
	
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
	
} add,sub;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int opt,l,r;
		cin>>opt>>l>>r;
		if(opt==1){
			add.update(1,1,n,l);
			sub.update(1,1,n,r);
		}
		else{
			int res=add.query(1,1,n,1,r);
			res-=sub.query(1,1,n,1,l-1);
			cout<<res<<endl;
		}
	}
	return 0;
}

