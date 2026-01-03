/*Author：AustinJiang
题目：麻将
时间复杂度：O(n^3)
算法：枚举 */
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
const int N=500;

int n,m,cnt[N],tmp[N];
VI ans;

inline bool check(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+2;j++)
			tmp[j]=cnt[j];
		tmp[x]++;
		if(tmp[i]<2) continue;
		tmp[i]-=2;
		for(int j=1;j<=n;j++){
			if(!tmp[j]) continue;
			if(tmp[j]<0) break;
			tmp[j]%=3;
			tmp[j+1]-=tmp[j];
			tmp[j+2]-=tmp[j];
			tmp[j]=0;
		}
		int flag=1;
		for(int j=1;j<=n+2;j++)
			if(tmp[j]<0) flag=0;
		if(flag) return 1;
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=3*m+1;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=n;i++)
		if(check(i)) ans.pb(i);
	if(ans.empty()) cout<<"NO"<<endl;
	else for(auto i:ans) cout<<i<<' ';
	return 0;
}


