/*Author��AustinJiang
��Ŀ���ǹ����� 
ʱ�临�Ӷȣ�O(n*log(n))
�㷨��̰�ģ�ǰ׺�ͣ����� */
#pragma GCC optimize(2)
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
const int N=1e6+10;

int n,avr,ans,a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		avr+=a[i];
	}
	avr/=n;
	for(int i=1;i<=n;i++){
		a[i]=avr-a[i];
		a[i]+=a[i-1];
	}
	sort(a+1,a+n+1);
	int mid=(n+1)/2;
	for(int i=1;i<=n;i++)
		ans+=abs(a[mid]-a[i]);
	cout<<ans<<endl;
	return 0;
}

