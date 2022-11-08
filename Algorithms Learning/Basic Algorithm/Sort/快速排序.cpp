/*Author：AustinJiang
题目：排序算法 
时间复杂度：O(n*log(n))
算法：快速排序 */
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
const int N=1e5+10;

int n,a[N],tmp[N];

void sort(int l,int r){
	if(l>=r) return;
	int tot=l,mid;
	for(int i=l;i<=r;i++)
		tmp[i]=a[i]; 
	for(int i=l;i<r;i++)
		if(tmp[i]>=tmp[r]) a[tot++]=tmp[i];
	a[mid=tot]=tmp[r];
	for(int i=l;i<r;i++)
		if(tmp[i]<tmp[r]) a[++tot]=tmp[i];
	sort(l,mid-1);
	sort(mid+1,r);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}

