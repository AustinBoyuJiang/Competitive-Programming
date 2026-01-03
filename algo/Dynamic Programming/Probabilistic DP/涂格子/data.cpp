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

int n,m;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	n=random(100000,1000000);
	m=random(2,n);
	cout<<n<<" "<<m<<endl;
	return 0;
}

