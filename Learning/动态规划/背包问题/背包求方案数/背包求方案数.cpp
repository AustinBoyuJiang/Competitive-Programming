/*Author: AustinJiang
��Ŀ: �����󷽰���
ʱ�临�Ӷ�: O(n*v)
�㷨: �������⣬��̬�滮*/
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
const int N=110;
const int V=1010;

//dp[i]��ʾ���Ϊi�ķ�����
int n,v,c[N],dp[V];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>v;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=v;j>=c[i];j--)
			dp[j]+=dp[j-c[i]];
	cout<<dp[v]<<endl;
	return 0;
}

