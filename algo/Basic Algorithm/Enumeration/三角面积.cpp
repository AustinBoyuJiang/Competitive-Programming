/*Author：AustinJiang
题目：三角面积
时间复杂度：O(n*log(n))
算法：枚举 
来源：USACO 2020 February Contest, Silver */
#pragma GCC optimize(2)
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
const int N=1e5+10;
const int MOD=1e9+7;

int n,ans,sum[N],sumx[N],sumy[N];

struct node{
	int x,y,id;
} p[N];

bool cmp1(node a,node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

bool cmp2(node a,node b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmp1);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<n&&p[j].x==p[j+1].x) j++;
		sum[i-1]=0;
		for(int k=i;k<=j;k++) sum[k]=sum[k-1]+p[k].y;
		for(int k=i;k<=j;k++) sumy[p[k].id]=sum[j]-sum[k]-(j-k)*p[k].y+(k-i)*p[k].y-sum[k-1];
		i=j;
	}
	sort(p+1,p+n+1,cmp2);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<n&&p[j].y==p[j+1].y) j++;
		sum[i-1]=0;
		for(int k=i;k<=j;k++) sum[k]=sum[k-1]+p[k].x;
		for(int k=i;k<=j;k++) sumx[p[k].id]=sum[j]-sum[k]-(j-k)*p[k].x+(k-i)*p[k].x-sum[k-1];
		i=j;
	}
	for(int i=1;i<=n;i++){
		ans+=sumx[i]*sumy[i];
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}

