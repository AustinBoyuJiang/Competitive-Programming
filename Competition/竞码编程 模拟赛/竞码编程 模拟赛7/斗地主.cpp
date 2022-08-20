/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
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

int n,ans,v[4];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>v[1]>>v[2]>>v[3];
	if(v[1]==0&&v[2]==0&&v[3]==0){
		cout<<2<<endl;
		return 0;
	}
	sort(v+1,v+4);
	while(v[3]>=6||v[1]<=-6){
		if(abs(v[3])>=abs(v[1])){
			v[1]+=3;
			v[2]+=3;
			v[3]-=6;
		}
		else{
			v[1]+=6;
			v[2]-=3;
			v[3]-=3;
		}
		ans++;
		sort(v+1,v+4);
		if(ans>=n){
			cout<<-1<<endl;
			return 0;
		}
	}
	while(v[3]>=4||v[1]<=-4){
		if(abs(v[3])>=abs(v[1])){
			v[1]+=2;
			v[2]+=2;
			v[3]-=4;
		}
		else{
			v[1]+=4;
			v[2]-=2;
			v[3]-=2;
		}
		ans++;
		sort(v+1,v+4);
		if(ans>=n){
			cout<<-1<<endl;
			return 0;
		}
	}
	while(v[3]>=2||v[1]<=-2){
		if(abs(v[3])>=abs(v[1])){
			v[1]+=1;
			v[2]+=1;
			v[3]-=2;
		}
		else{
			v[1]+=2;
			v[2]-=1;
			v[3]-=1;
		}
		ans++;
		sort(v+1,v+4);
		if(ans>=n){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(v[1]!=0||v[2]!=0||v[3]!=0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}

