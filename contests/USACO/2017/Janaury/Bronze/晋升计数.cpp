/*Author：AustinJiang
题目：晋升计数 */
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

int n,a1,a2,b1,b2,c1,c2,d1,d2;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a1>>a2;
	cin>>b1>>b2;
	cin>>c1>>c2;
	cin>>d1>>d2;
	cout<<b2-b1+c2-c1+d2-d1<<endl;
	cout<<c2-c1+d2-d1<<endl;
	cout<<d2-d1<<endl;
	return 0;
}

