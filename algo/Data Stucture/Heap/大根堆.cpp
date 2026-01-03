/*Author：AustinJiang
题目：大根堆
时间复杂度：O(n*log(n))
算法：堆，优先队列 */
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

int n,tot,heap[N];

inline void push_up(int x){
	if(x==1) return;
	if(heap[x]>heap[x/2]){
		swap(heap[x],heap[x/2]);
		push_up(x/2);
	}
}

inline void push_down(int x){
	int son=x*2;
	if(son>tot) return;
	if(son+1<=tot&&heap[son+1]>heap[son]) son++;
	if(heap[x]<heap[son]){
		swap(heap[x],heap[son]);
		push_down(son);
	}
}

inline void push(int x){
	heap[++tot]=x;
	push_up(tot);
}

inline void pop(){
	swap(heap[1],heap[tot--]);
	push_down(1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string opt;
		int x;
		cin>>opt;
		if(opt=="push") cin>>x,push(x);
		else if(!tot) cout<<"empty"<<endl;
		else cout<<heap[1]<<endl,pop();
	}
	return 0;
}

