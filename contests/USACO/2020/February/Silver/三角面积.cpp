/*Author：AustinJiang
题目：三角面积
时间复杂度：O(n^2)
算法：STL，枚举 
来源：USACO 2020 February Contest, Silver Problem 2. Triangles */
#include<bits/stdc++.h>
#define int long long
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
const int N=5e3+10;
const int MOD=1e9+7;

int n,ans,x[N],y[N];
map<PI,bool> pos;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		pos[mp(x[i],y[i])]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(pos[mp(x[i],y[j])]){
				ans+=abs(x[i]-x[j])*abs(y[i]-y[j]);
				ans%=MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

