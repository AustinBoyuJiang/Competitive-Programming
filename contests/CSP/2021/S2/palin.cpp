/*Author：AustinJiang
题目：回文
时间复杂度：O()
算法：
来源：CSP 2021 S2
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
const int N=1e6+10;

int t,n,L,R,a[N],pos[N],pre[N],ans[N],res[N];

bool find(int l,int r){
	for(int i=2;i<=n>>1;i++){
		if(a[l]==a[L-1]&&l<L-1){
			ans[i]=0;
			res[i]=a[l];
			l++,L--;
		}
		else if(a[l]==a[R+1]&&R+1<=r){
			ans[i]=0;
			res[i]=a[l];
			l++,R++;
		}
		else if(a[r]==a[L-1]&&L-1>=l){
			ans[i]=1;
			res[i]=a[r];
			r--,L--;
		}
		else if(a[r]==a[R+1]&&R+1<r){
			ans[i]=1;
			res[i]=a[r];
			r--,R++;
		}
		else return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		n<<=1;
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pos[i]=pre[a[i]];
			pos[pre[a[i]]]=i;
			pre[a[i]]=i;
		}
		L=R=pos[1];
		if(find(2,n)){
			ans[1]=0;
			res[1]=a[1];
		}
		else{
			L=R=pos[n];
			if(find(1,n-1)){
				ans[1]=1;
				res[1]=a[n];
			}
			else{
				cout<<-1<<endl;
				continue;
			}
		}
		for(int i=1;i<=n>>1;i++){
			if(a[L]==res[(n>>1)-i+1]) ans[(n>>1)+i]=0,L++;
			else ans[(n>>1)+i]=1,R--;
		}
		for(int i=1;i<=n;i++)
			cout<<"LR"[ans[i]];
		cout<<endl;
	}
	return 0;
}

