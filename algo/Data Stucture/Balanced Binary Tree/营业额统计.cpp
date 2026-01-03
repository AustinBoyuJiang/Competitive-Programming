/*Author：AustinJiang
题目：营业额统计 
时间复杂度：O(n*log(n))
算法：平衡树 
来源：HNOI 2002 */
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
const int N=4e4+10;

int n,ans,tot,root,predid,succid,val[N],ls[N],rs[N],rnd[N];

void pred(int rt,int x){
	if(!rt) return;
	if(x<val[rt]) pred(ls[rt],x);
	else predid=rt,pred(rs[rt],x);
}

void succ(int rt,int x){
	if(!rt) return;
	if(x>val[rt]) succ(rs[rt],x);
	else succid=rt,succ(ls[rt],x);
}

void lturn(int &rt){
	int tmp=rs[rt];
	rs[rt]=ls[tmp];
	ls[tmp]=rt;
	rt=tmp;
}

void rturn(int &rt){
	int tmp=ls[rt];
	ls[rt]=rs[tmp];
	rs[tmp]=rt;
	rt=tmp;
}

void insert(int &rt,int x){
	if(!rt){
		rt=++tot;
		val[rt]=x;
		rnd[rt]=rand();
		return;
	}
	if(x<val[rt]){
		insert(ls[rt],x);
		if(rnd[ls[rt]]>rnd[rt]) rturn(rt);
	}
	else if(x>val[rt]){
		insert(rs[rt],x);
		if(rnd[rs[rt]]>rnd[rt]) lturn(rt);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	val[0]=INF;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i==1) ans+=x;
		else{
			pred(root,x),succ(root,x);
			ans+=min(abs(x-val[predid]),abs(x-val[succid]));
		}
		insert(root,x);
	}
	cout<<ans<<endl;
	return 0;
}

