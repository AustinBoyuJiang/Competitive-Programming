/*Author：AustinJiang
题目：高精度减法 
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
const int N=1e5+10;

int n,A[N],B[N],ans[N];
string a,b,tmp;

bool cmp(string a,string b){
	if(a.size()>b.size()) return 1;
	if(a.size()<b.size()) return 0;
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	n=max(a.size(),b.size());
	if(!cmp(a,b)) tmp=a,a=b,b=tmp,cout<<'-';
	for(int i=0;i<a.size();i++)
		A[i]=a[a.size()-i-1]-'0';
	for(int i=0;i<b.size();i++)
		B[i]=b[b.size()-i-1]-'0';
	for(int i=0;i<n;i++){
		if(A[i]<B[i]) A[i]+=10,A[i+1]--;
		ans[i]=A[i]-B[i];
	}
	while(n>1&&!ans[n-1]) n--;
	for(int i=n-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}

