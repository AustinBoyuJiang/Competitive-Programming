/*Author��AustinJiang
��Ŀ��͵Ϯ��Ӫ 
ʱ�临�Ӷȣ�O(n*log(n))
�㷨��̰�� */
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
const int N=1e5+10;

int n,m,ans,a[N];
VI b;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++){
		int x;
		cin>>x;
		b.pb(x);
	}
	sort(b.begin(),b.end());
	for(int i=1;i<=n;i++){
		auto pos=lower_bound(b.begin(),b.end(),a[i]);
		if(pos==b.end()){
			cout<<"defeat"<<endl;
			return 0;
		}
		ans+=*pos;
		b.erase(pos);
	}
	cout<<ans<<endl;
	return 0;
}

