/*Author��AustinJiang
��Ŀ������ƥ�� 
ʱ�临�Ӷȣ�O(n^3)
�㷨����̬�滮������dp */
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
const int N=310;

//dp[i][j]��ʾ����(i,j)�����������������еĳ���
int n,dp[N][N];
string str;

bool match(int i,int j){
	if(str[i-1]=='('&&str[j-1]==')') return 1;
	if(str[i-1]=='['&&str[j-1]==']') return 1;
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str;
	n=str.size();
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if(match(i,j)) dp[i][j]=dp[i+1][j-1]+2;
			for(int k=i;k<j;k++)
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	}
	cout<<dp[1][n];
	return 0;
}

