/*Author��AustinJiang
��Ŀ��D1T1:С�����ɻ� 
ʱ�临�Ӷȣ�O(1)
�㷨������ 
��Դ��NOIP2017 */
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

ll a,b;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	cout<<a*b-a-b<<endl;	
	return 0;
}

