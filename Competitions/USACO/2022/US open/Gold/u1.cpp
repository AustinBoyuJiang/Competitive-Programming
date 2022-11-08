/*Author：AustinJiang
题目：Apple Catching
时间复杂度：O(n*log(n))
算法：贪心，双指针, 二分 
来源：USACO 2022 USopen Gold */
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
const int N=2e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,cnt1,cnt2,ans;
VI pos;

struct node{
	int n,l,r;
} c[N],a[N];

bool cmp(node a,node b){
	return a.r<b.r;
}

int find(int x){
	int l=0,r=pos.size()-1,ans=pos.size();
	while(l<=r){
		int mid=l+r>>1;
		if(c[pos[mid]].l<x) l=mid+1;
		else r=mid-1,ans=mid;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int q,t,x,n;
		cin>>q>>t>>x>>n;
		if(q==1){
			c[++cnt1].n=n;
			c[cnt1].l=x-t;
			c[cnt1].r=x+t;
		}
		else{
			a[++cnt2].n=n;
			a[cnt2].l=x-t;
			a[cnt2].r=x+t;
		}
	}
	sort(c+1,c+cnt1+1,cmp);
	sort(a+1,a+cnt2+1,cmp);
	for(int i=1,j=0;i<=cnt2;i++){
		while(j<cnt1&&c[j+1].r<=a[i].r){
			int x=find(c[++j].l);
			pos.insert(pos.begin()+x,j);
		}
		int x=find(a[i].l);
		while(a[i].n&&x<pos.size()){
			int v=min(c[pos[x]].n,a[i].n);
			c[pos[x]].n-=v,a[i].n-=v,ans+=v;
			if(c[pos[x]].n==0) pos.erase(pos.begin()+x);
		}
	}
	cout<<ans<<endl;
	return 0;
}

