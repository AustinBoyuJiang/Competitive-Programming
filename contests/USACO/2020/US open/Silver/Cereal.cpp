/*Author：AustinJiang
题目：Cereal
时间复杂度：O(n)
来源：USACO 2020 US Open Contest, Silver */
#pragma GCC optimize(2)
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

int n,m,cnt,a[N],b[N],ans[N],pos[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=n;i>=1;i--){
		int x=i,y=a[i];
		while(1){
			if(!pos[y]){
				cnt++;
				pos[y]=x;
				break;
			}
			else if(pos[y]<x){
				break;
			}
			else{
				swap(x,pos[y]);
				if(b[x]==y) break;
				y=b[x];		
			}
		}
		ans[i]=cnt;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}

