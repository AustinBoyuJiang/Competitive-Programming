/*Author£ºAustinJiang
Ñ¯ÎÊ´ÎÊý£ºn*3 */
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

int n,x,ans1,ans2,mn[N],mx[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"? "<<i*2-1<<" "<<i*2<<endl;
		cout.flush();
		cin>>x;
		if(x==i) mx[i]=i*2-1,mn[i]=i*2;
		else mx[i]=i*2,mn[i]=i*2-1;
	}
	ans1=mx[1];
	ans2=mn[1];
	for(int i=2;i<=n;i++){
		cout<<"? "<<ans1<<" "<<mx[i]<<endl;
		cout.flush();
		cin>>ans1;
	}
	for(int i=2;i<=n;i++){
		cout<<"? "<<ans2<<" "<<mn[i]<<endl;
		cout.flush();
		cin>>x;
		ans2=ans2+mn[i]-x;
	}
	cout<<"! "<<ans1<<" "<<ans2<<endl;
	return 0;
}

