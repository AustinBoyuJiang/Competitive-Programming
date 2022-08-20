/*Author：AustinJiang
题目：单词游戏
时间复杂度：O(n)
算法：图论 , 欧拉回路
来源：ICPC CERC 1999/2000,有改动
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
const int N=200;
const int W=30;

int t,n,flag[W],f[W],din[W],dout[W];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(flag,0,sizeof(flag));
		memset(din,0,sizeof(din));
		memset(dout,0,sizeof(dout));
		for(int i=1;i<26;i++)
			f[i]=i;
		cin>>n;
		for(int i=1;i<=n;i++){
			int s,e;
			string str;
			cin>>str;
			s=str[0]-'a';
			e=str[str.size()-1]-'a';
			flag[s]=flag[e]=1;
			dout[s]++,din[e]++;
			merge(s,e);
		}
		int res=1,start=0,end=0,cnt=0,id=-1;
		for(int i=0;i<26;i++){
			if(din[i]+1==dout[i]) start++;
			else if(dout[i]+1==din[i]) end++;
			else if(din[i]!=dout[i]){res=0;break;} 
			if(id==-1&&flag[i]) id=find(i);
			if(flag[i]&&id!=find(i)){res=0;break;}
		}
		if(!(start==1&&end==1)&&!(start==0&&end==0)) res=0;
		if(res) cout<<"Ordering is possible."<<endl;
		else cout<<"The door cannot be opened."<<endl;
	}
	return 0;
}
