/*Author：AustinJiang
题目：插入排序
时间复杂度：O(q*n)
算法：插入排序 
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
const int N=8e3+10;

int n,q,a[N],f[N],id[N],pos[N];

void exchange(int i,int j){
	swap(f[i],f[j]);
	swap(id[i],id[j]);
	swap(pos[id[i]],pos[id[j]]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
		pos[i]=i;
		id[i]=i;
		for(int j=i;j>=2;j--)
			if(f[j]<f[j-1]) exchange(j,j-1);
	}
	for(int i=1;i<=q;i++){
		int opt,x,y;
		cin>>opt;
		if(opt==1){
			cin>>x>>y;
			if(y>a[x]){
				f[pos[x]]=y;
				for(int j=pos[x];j<n;j++)
					if(f[j]==f[j+1]&&id[j]>id[j+1]||f[j]>f[j+1]) exchange(j,j+1);
			}
			else if(y<a[x]){
				f[pos[x]]=y;
				for(int j=pos[x];j>=2;j--)
					if(f[j]==f[j-1]&&id[j]<id[j-1]||f[j]<f[j-1]) exchange(j,j-1);
			}
			a[x]=y;
		}
		else{
			cin>>x;
			cout<<pos[x]<<endl;
		}
	}
	return 0;
}

