/*Author：AustinJiang
题目：Wrong Addition
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

int t,ans[100];

signed main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int j=b.size()-1,k=0,flag=1;
		for(int i=a.size()-1;i>=0;i--){
			if(j<0){
				flag=0;
				break;
			}
			int num=b[j]-'0';
			if(num<a[i]-'0'){
				if(j-1<0){
					flag=0;
					break;
				}
				else{
					num+=(b[--j]-'0')*10;
				}
			}
			ans[k++]=num-(a[i]-'0');
			if(ans[k-1]>=10||ans[k-1]<0){
				flag=0;
				break;
			}
			j--;
		}
		if(!flag) cout<<-1<<endl;
		else{
			while(j>=0) ans[k++]=b[j--]-'0';
			while(ans[k-1]==0&&k>=2) k--;
			for(int i=k-1;i>=0;i--){
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
	return 0;
}

