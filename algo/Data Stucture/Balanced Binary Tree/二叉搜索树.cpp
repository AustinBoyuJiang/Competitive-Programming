/*Author：AustinJiang
题目：二叉搜索树
时间复杂度：O(n^2)
算法：平衡树 */
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
const int N=1e4+10;

int n,tot,root,ls[N],rs[N],val[N],cnt[N];

void insert(int &rt,int x){
	if(!rt){
		rt=++tot;
		val[rt]=x;
		return;
	}
	if(x>val[rt]) insert(rs[rt],x);
	else if(x<val[rt]) insert(ls[rt],x);
	else cnt[rt]++;
}


signed main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		insert(root,x);
	}
	for(int i=1;i<=n;i++){
		printf("%d: ",i);
		if(ls[i]) printf("%d ",ls[i]);
		else printf("# ");
		if(rs[i]) printf("%d\n",rs[i]);
		else printf("#\n");
	}
	return 0;
}
