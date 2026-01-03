/*Author：AustinJiang
题目：招待
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=35;

int n,tot,cnt1,cnt2,digit[N],power[N],ans1[N],ans2[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans2[++cnt2]=n;
	while(n){
		digit[tot]=n%3;
		n/=3;
		tot++;
	}
	power[0]=1;
	for(int i=1;i<N;i++)
		power[i]=power[i-1]*3;
	for(int i=0;i<=tot;i++){
		digit[i+1]+=digit[i]/3;
		digit[i]%=3;
		if(digit[i]==1)
			ans1[++cnt1]=power[i];
		if(digit[i]==2){
			digit[i+1]++;
			ans2[++cnt2]=power[i];
		}
	}
	for(int i=1;i<cnt1;i++)
		cout<<ans1[i]<<' ';
	cout<<ans1[cnt1]<<endl;
	for(int i=1;i<cnt2;i++)
		cout<<ans2[i]<<' ';
	cout<<ans2[cnt2]<<endl;
	return 0;
}

