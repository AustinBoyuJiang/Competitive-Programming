/*Author��AustinJiang
��Ŀ���������㷨(Manacher) 
ʱ�临�Ӷȣ�O(n)
�㷨���ַ����������� */
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
const int N=2e5+10;

int ans,cnt,C,R,p[N];
string str;
char a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str;
	a[0]='#';
	for(auto x:str){
		a[++cnt]=x;
		a[++cnt]='#';
	}
	a[cnt]='#';
	a[cnt+1]='@';
	for(int i=1;i<cnt;i++){
		if(i>=R){
			C=R=i;
			while(a[i+p[i]+1]==a[i-p[i]-1]) p[i]++,R++;
			ans=max(ans,p[i]);
		}
		else{
			int k=C*2-i;
			p[i]=p[k];
			if(k-p[k]<=C-p[C]){
				C=R=i;
				while(a[i+p[i]+1]==a[i-p[i]-1]) p[i]++,R++;
			}
			ans=max(ans,p[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

