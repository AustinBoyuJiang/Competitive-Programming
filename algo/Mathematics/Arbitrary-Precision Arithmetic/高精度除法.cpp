/*Author：AustinJiang
题目：高精度除法 
时间复杂度：O(n^2)
算法：高精度 */
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
const int N=1e4+10;

int n,A[N],B[N],ans[N];
string a,b;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	n=a.size();
	for(int i=0;i<n;i++)
		A[i]=a[n-i-1]-'0';
	for(int i=0;i<b.size();i++)
		B[i]=b[b.size()-i-1]-'0';
	for(int i=n-b.size();i>=0;i--){
		while(1){
			int flag=0;
			for(int j=n-1;j>=i;j--){
				if(A[j]>B[j-i]) break;
				if(A[j]<B[j-i]){
					flag=1;
					break;
				}
			}
			if(flag) break;
			for(int j=i;j<n;j++){
				A[j]-=B[j-i];
				if(A[j]<0){
					A[j]+=10;
					A[j+1]-=1;
				}
			}
			ans[i]++; 
		}
	}
	while(n>1&&!ans[n-1]) n--;
	for(int i=n-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}

