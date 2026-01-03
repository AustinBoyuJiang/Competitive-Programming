/*Author：AustinJiang
题目：Gym
询问次数：25
算法：二分 */
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

signed main(){
	int l=1,r=1e6,mid,ans;
	string opt;
	while(l<=r){
		mid=l+r>>1;
		cout<<mid<<endl;
		cout.flush();
		cin>>opt;
		if(opt=="<") r=mid-1;
		else ans=mid,l=mid+1;
	}
	cout<<"!"<<ans<<endl;
	cout.flush(); 
	return 0;
}

