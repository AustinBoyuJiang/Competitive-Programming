/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
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
string s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		int k;
		for(k=1;k<n;k++){
			if(k==1&&s[1]>=s[0])
				break;
			if(s[k]>s[k-1])
				break;
		}
		for(int i=0;i<k;i++)
			cout<<s[i];
		for(int i=k-1;i>=0;i--)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}

