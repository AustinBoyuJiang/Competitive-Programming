/*Author：AustinJiang
询问次数：n*2
来源：CF1407C */
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
const int N=1e4+10;

int n,x=1,y=2,a,b,ans[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		cout<<"? "<<x<<" "<<y<<endl;
		cout.flush();
		cin>>a;
		cout<<"? "<<y<<" "<<x<<endl;
		cout.flush();
		cin>>b;
		if(a>b) ans[x]=a,x=y,y=y+1;
		else ans[y]=b,y=y+1;
	}
	ans[x]=n;
	cout<<"!";
	for(int i=1;i<=n;i++)
		cout<<" "<<ans[i];
	return 0;
}

