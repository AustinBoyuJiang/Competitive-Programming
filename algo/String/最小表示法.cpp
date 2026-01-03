/*Author：AustinJiang
题目：最小表示法
时间复杂度：O(n)
算法：字符串，最小表示法 */
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

int n;
string str;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str;
	n=str.size();
	str+=str;
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n){
		if(str[i+k]==str[j+k]) k++;
		else{
			if(str[i+k]>str[j+k]) i+=k+1;
			else j+=k+1;
			if(i==j) i++;
			k=0;
		}
	}
	cout<<str.substr(min(i,j),n)<<endl;
	return 0;
}

