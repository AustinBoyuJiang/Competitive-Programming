/*Author：AustinJiang
题目：普通平衡树 
时间复杂度：O(n*log(n))
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

int n;
VI a;

signed main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int opt,x;
		cin>>opt>>x;
		if(opt==1) a.insert(lower_bound(a.begin(),a.end(),x),x);
		if(opt==2) a.erase(lower_bound(a.begin(),a.end(),x));
		if(opt==3) cout<<lower_bound(a.begin(),a.end(),x)-a.begin()+1<<endl;
		if(opt==4) cout<<a[x-1]<<endl;
		if(opt==5) cout<<a[lower_bound(a.begin(),a.end(),x)-a.begin()-1]<<endl;
		if(opt==6) cout<<*upper_bound(a.begin(),a.end(),x)<<endl;
	} 
	return 0;
}

