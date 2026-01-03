/*Author：AustinJiang
题目：高精度加法 
时间复杂度：O(n)
算法：高精度*/
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
const int N=1e6+10;

int n,A[N],B[N],ans[N];
string a,b;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	n=a.size()+b.size();
	for(int i=0;i<a.size();i++)
		A[i]=a[a.size()-i-1]-'0';
	for(int i=0;i<b.size();i++)
		B[i]=b[b.size()-i-1]-'0';
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			ans[i+j]+=A[i]*B[j];
	for(int i=0;i<n;i++){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	while(n>1&&!ans[n-1]) n--;
	for(int i=n-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}

