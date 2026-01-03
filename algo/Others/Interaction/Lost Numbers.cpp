/*Author：AustinJiang
题目：Lost Numbers
询问次数：4
来源：CF1167B */
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

int a[7]={0,4,8,15,16,23,42},ans[7];
PI res[1000];

int find1(int x,int y){
	int a,b,c,d;
	a=res[x].fir;
	b=res[x].sec;
	c=res[y].fir;
	d=res[y].sec;
	if(a==c) return a;
	if(a==d) return a;
	if(b==c) return b;
	if(b==d) return b;
}

int find2(int x,int y){
	if(y==res[x].fir) return res[x].sec;
	else return res[x].fir;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<6;i++)
		for(int j=i+1;j<=6;j++)
			res[a[i]*a[j]]=mp(a[i],a[j]);
	int x,y;
	cout<<"? 1 2"<<endl;
	cout.flush();
	cin>>x;
	cout<<"? 1 3"<<endl;
	cout.flush();
	cin>>y;
	ans[1]=find1(x,y);
	ans[2]=find2(x,ans[1]);
	ans[3]=find2(y,ans[1]);
	cout<<"? 4 5"<<endl;
	cout.flush();
	cin>>x;
	cout<<"? 4 6"<<endl;
	cout.flush();
	cin>>y;
	ans[4]=find1(x,y);
	ans[5]=find2(x,ans[4]);
	ans[6]=find2(y,ans[4]);
	cout<<"!";
	for(int i=1;i<=6;i++)
		cout<<' '<<ans[i];
	return 0;
}

