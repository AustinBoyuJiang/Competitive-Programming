/*Author: AustinJiang
题目: 家庭作业
时间复杂度: O(n*log(t))
算法: 贪心，并查集*/
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
const int T=7e5+10;

int n,t,cnt,ans,flag[T],f[T];
PI s[N];

bool cmp(PI a,PI b){
	if(a.sec==b.sec) return a.fir<b.fir;
	return a.sec>b.sec;
}

int find(int x){
	if(!flag[x]) return x;
	return f[x]=find(f[x]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].fir>>s[i].sec;
		t=max(t,s[i].fir);
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=t;i++)
		f[i]=i-1;
	for(int i=1;i<=n;i++){
		int pos=find(s[i].fir);
		if(!pos) continue;
		flag[pos]=1;
		ans+=s[i].sec;
		//f[s[i].fir]=f[pos];
	}
	cout<<ans<<endl;
	return 0;
}

