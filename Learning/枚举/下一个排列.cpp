/*Author：AustinJiang
题目：下一个排列
时间复杂度：O(n) */
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
const int N=3e3+10;

int n,a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		if(a[i-1]<a[i]){
			if(i>1)
			for(int j=n;j>=i;j--)
				if(a[j]>a[i-1]){
					swap(a[i-1],a[j]);
					break; 
				}
			reverse(a+i,a+n+1);
			break;
		}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
