/*Author: AustinJiang
题目 差分约束:
时间复杂度: O(n*h)
算法: 暴力枚举*/
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
const int N=3e4+10;
const int H=5e3+10;

int n,h,ans,a[N];

struct house{
	int b,e,t;
}s[H];

bool cmp(house a,house b){
	return a.b<b.b;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	for(int i=1;i<=h;i++)
		cin>>s[i].b>>s[i].e>>s[i].t;
	sort(s+1,s+h+1,cmp);
	for(int i=h;i>=1;i--){
		for(int pos=s[i].b;pos<=s[i].e;pos++)
			if(a[pos]) s[i].t--;
		if(s[i].t<=0) continue;
		for(int pos=s[i].b;pos<=s[i].e;pos++)
			if(!a[pos]){
				ans++;
				a[pos]=1;
				s[i].t--;
				if(s[i].t<=0) break;
			}
	}
	cout<<ans<<endl;
	return 0;
}

