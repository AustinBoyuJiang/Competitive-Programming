/*Author：AustinJiang
题目：Alphabetical Strings
时间复杂度：O(t*n)
来源：Codeforces Round #731 (Div. 3)
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

int t,n,res;
string s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		res=1,n=s.size();
		for(int i=n-1;i>=0;i--){
			if(s[0]=='a'+i) s.erase(0,1);
			else if(s[s.size()-1]=='a'+i) s.erase(s.size()-1);
			else {res=0; break;}
		}
		if(res) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

