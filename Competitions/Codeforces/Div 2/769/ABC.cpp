/*Author��AustinJiang
��Ŀ��
ʱ�临�Ӷȣ�O()
�㷨��
��Դ��
˼·��
*/
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

int t,n;

void solve(){
	int cnt1=0,cnt2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x=='0') cnt1++;
		else cnt2++;
	}
	if(cnt1>=2||cnt2>=2) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
