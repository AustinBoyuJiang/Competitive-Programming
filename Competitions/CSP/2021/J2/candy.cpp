/*Author：AustinJiang
题目：分糖果
时间复杂度：O(1)
来源：CSP 2021 J2 */
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

int n,L,R;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>L>>R;
	int k=(R+1)/n*n-1;
	if(k<L) k=R;
	cout<<k%n<<endl;
	return 0;
}

