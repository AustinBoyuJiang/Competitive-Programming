/*Author��AustinJiang
��Ŀ��ר��ţ��
ʱ�临�Ӷȣ�O(m)
�㷨����� 
��Դ��USACO */
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

int n,m,ans,t[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		t[a]+=1;
		t[b+1]-=1;
		m=max(m,b);
	}
	for(int i=1;i<=m;i++){
		t[i]+=t[i-1];
		ans=max(ans,t[i]);
	}
	cout<<ans<<endl;
	return 0;
}

