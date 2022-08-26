/*Author: AustinJiang
题目: 安全距离 
时间复杂度: O(n*log(MaxD))
算法: 二分*/
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
const int M=1e5+10;

int n,m;
PI s[M];

bool cmp(PI a,PI b){
	return a.fir<b.fir;
}

bool check(int d){
	int pos=-INF,cnt=0;
	for(int i=1;i<=m;i++)
		while(max(pos+d,s[i].fir)<=s[i].sec){
			pos=max(pos+d,s[i].fir);
			cnt++;
			if(cnt>=n) return true;
		}
	return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>s[i].fir>>s[i].sec;
	sort(s+1,s+m+1,cmp);
	int l=1,r=s[m].sec,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

