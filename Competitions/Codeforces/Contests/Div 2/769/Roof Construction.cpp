/*Author��AustinJiang
��Ŀ��Roof Construction
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
const int N=1e5+10;

int t,n;

void solve(){
	cin>>n;
	int x=1<<(int)log2(n-1);
	for(int i=x-1;i>=0;i--) cout<<i<<' ';
	for(int i=x;i<n;i++) cout<<i<<' ';
	cout<<endl; 
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
