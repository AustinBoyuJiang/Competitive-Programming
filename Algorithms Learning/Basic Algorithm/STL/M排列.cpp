/*Author：AustinJiang
题目：M排列
时间复杂度：O(n*m)
算法：STL */
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

int n,m,a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<m;i++) next_permutation(a + 1, a + 1 + n);
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}

