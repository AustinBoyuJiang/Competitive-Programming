/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=100;
const int M=110;
const int H=1e6;
const int CASE=20;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int K[CASE],f[M],h[M],s[M],c[M],a[M],b[M],d[M];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	f[find(x)]=find(y);
}

void create_data(int Case){
	int n,m,k;
	n=random(1,N);
	m=random(1,N);
	k=0;
	for(int i=1;i<=m;i++){
		f[i]=i;
		h[i]=random(1,H);
		s[i]=random(1,100);
	}
	for(int &i=k;i<K[Case];i++){
		c[i]=random(0,1);
		a[i]=random(1,m);
		int cnt=0;
		do{
			b[i]=random(1,m);
			cnt++;
		}
		while(cnt<10&&(a[i]==b[i]||find(a[i])==find(b[i])));
		if(a[i]==b[i]||find(a[i])==find(b[i])) break;
		d[i]=random(1,H);
		merge(a[i],b[i]);
	}
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",h[i],s[i]);
	for(int i=0;i<k;i++)
		printf("%d %d %d %d\n",c[i],a[i],b[i],d[i]);
}

signed main(){
	srand(time(NULL));
	for(int i=6;i<=10;i++)
		K[i]=N;
	for(int Case=1;Case<=10;Case++){
    	char in[100];
    	sprintf(in,"data/sgsopc1p5.%d.in",Case);
    	freopen(in,"w",stdout);
    	create_data(Case);
	}
	return 0;
}

