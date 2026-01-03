/*Author：AustinJiang
题目：离散化
时间复杂度：O(n*log(n))
算法：离散化 */
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

int n,cnt,a[N],b[N];
set<int> s;

int find(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=(l+r)/2;
		if(b[mid]==x) return mid;
		if(b[mid]<x) l=mid+1;
		if(b[mid]>x) r=mid-1;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]); 
	}
	for(auto i:s)
		b[++cnt]=i;
	sort(b+1,b+cnt+1);
	for(int i=1;i<=n;i++)
		cout<<find(a[i])<<' ';
	return 0;
}

