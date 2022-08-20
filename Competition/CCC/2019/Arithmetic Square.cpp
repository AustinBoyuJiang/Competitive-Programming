/*Author：AustinJiang
题目：Arithmetic Square
时间复杂度：O()
算法：
来源：CCC 2019 Senior */
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
const int N=5;

int n,cnt,flag[N][N];
double a[N][N];
string str;

inline void check(int x,int y){
	if(flag[x][y]) return;
	if(x==1){
		a[x][y]=a[x+1][y]-(a[x+2][y]-a[x+1][y]);
		if(flag[x+1][y]&&flag[x+2][y]){
			flag[x][y]=1;
			cnt++;
			return;
		}
	}
	if(x==2){
		a[x][y]=a[x-1][y]+(a[x+1][y]-a[x-1][y])/2;
		if(flag[x-1][y]&&flag[x+1][y]){
			flag[x][y]=1;
			cnt++;
			return;
		}
	}
	if(x==3){
		a[x][y]=a[x-1][y]+(a[x-1][y]-a[x-2][y]);
		if(flag[x-1][y]&&flag[x-2][y]){
			flag[x][y]=1;
			cnt++;
			return;
		}
	}
	if(y==1){
		a[x][y]=a[x][y+1]-(a[x][y+2]-a[x][y+1]);
		if(flag[x][y+1]&&flag[x][y+3]){
			flag[x][y]=1;
			cnt++;
			return;
		}
	}
	if(y==2){
		a[x][y]=a[x][y-1]+(a[x][y+1]-a[x][y-1])/2;
		if(flag[x][y-1]&&flag[x][y+1]){
			flag[x][y]=1;
			cnt++;
			return;
		}
	}
	if(y==3){
		a[x][y]=a[x][y-1]+(a[x][y-1]-a[x][y-2]);
		if(flag[x][y-1]&&flag[x][y-2]){
			flag[x][y]=1;
			cnt++;
			return;
		}
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>str;
			if(str!="X"){
				flag[i][j]=1;
				cnt++;
				for(auto x:str){
					a[i][j]*=10;
					a[i][j]+=x-'0';
				}
			}
		}
	}
	int tot=0;
	while(1){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				check(i,j);
				if(cnt>=9){			
					for(int i=1;i<=3;i++){
						for(int j=1;j<=3;j++){
							cout<<a[i][j]<<' ';
						}
						cout<<endl;
					}
					return 0;
				}
			}
		}
		tot++;
	}
}

