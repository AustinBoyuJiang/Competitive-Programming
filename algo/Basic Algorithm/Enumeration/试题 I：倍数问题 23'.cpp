/*Author：AustinJiang
题目：试题 I:倍数问题 23'
时间复杂度：O(K^2)
算法：枚举 
来源：第九届蓝桥杯大赛个人赛省赛（软件类）C/C++ 大学 A 组 */
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
const int N=1e3+10;

int n,K,ans,mx[N][3];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>mx[x%K][0]){
			mx[x%K][2]=mx[x%K][1];
			mx[x%K][1]=mx[x%K][0];
			mx[x%K][0]=x;
		}
		else if(x>mx[x%K][1]){
			mx[x%K][2]=mx[x%K][1];
			mx[x%K][1]=x;
		}
		else if(x>mx[x%K][2]){
			mx[x%K][2]=x;
		}
	}
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			int k=(K-(i+j)%K)%K;
			int a,b,c;
			if(i==j&&i!=k){
				a=mx[i][0];
				b=mx[j][1];
				c=mx[k][0];
			}
			else if(i==k&&i!=j){
				a=mx[i][0];
				b=mx[j][0];
				c=mx[k][1];
			}
			else if(j==k&&i!=j){
				a=mx[i][0];
				b=mx[j][0];
				c=mx[k][1];
			}
			else if(i==k&&i==j){
				a=mx[i][0];
				b=mx[j][1];
				c=mx[k][2];
			}
			else{
				a=mx[i][0];
				b=mx[j][0];
				c=mx[k][0];
			}
			ans=max(ans,a+b+c);
		}
	}
	cout<<ans<<endl;
	return 0;
}

