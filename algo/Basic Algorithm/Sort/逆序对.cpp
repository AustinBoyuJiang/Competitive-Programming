/*Author：AustinJiang
题目：逆序对 
时间复杂度：O(n*log(n))
算法：归并排序 */
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
int n,a[N],res[N];
ll ans;

void merge(int l1,int r1,int l2,int r2){
	int tot=0,L=l1;
	while(l1<=r1&&l2<=r2){
		if(a[l1]>a[l2]){
			res[++tot]=a[l1++];
			ans+=r2-l2+1;
    	}
    	else res[++tot]=a[l2++];
  	}
	while(l1<=r1) res[++tot]=a[l1++];
  	while(l2<=r2) res[++tot]=a[l2++];
  	tot=0;
  	for(int i=L;i<=r2;i++)
    	a[i]=res[++tot];
} 

void sort(int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	sort(l,mid);
	sort(mid+1,r);
	merge(l,mid,mid+1,r);
}

signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(1,n); 
	cout<<ans<<endl;
	return 0;
}
