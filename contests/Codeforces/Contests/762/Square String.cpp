/*Author：AustinJiang
题目：Square String
时间复杂度：O(n)
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

int t;

signed main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int n=str.size();
		if(n%2){
			cout<<"NO"<<endl;
			continue;
		}
		bool res=1;
		for(int i=0;i<n/2;i++){
			if(str[i]!=str[i+n/2]){
				res=0;
				break;
			}
		}
		if(!res){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

