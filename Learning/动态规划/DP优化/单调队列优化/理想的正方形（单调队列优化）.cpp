/*Author: AustinJiang
��Ŀ: �����������
ʱ�临�Ӷ�: O(n*n)
�㷨: �������У���̬�滮*/
#include<bits/stdc++.h>
#define for(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int INF=INT_MAX;
const int N=1e3+10;

//mx[j]��ʾ��i��ʱ��s(i-n+1,j-n+1)��s(i,j)�����е����ֵ
int a,b,n,ans=INF,mx[N],mn[N],s[N][N];
deque<int> mx1[N],mn1[N],mx2[N],mn2[N];

signed main(){
	scanf("%d %d %d",&a,&b,&n);
	for(i,a) for(j,b){
		scanf("%d",&s[i][j]);
		while(!mx2[j].empty()&&mx2[j].front()<=i-n) mx2[j].pop_front();
		while(!mn2[j].empty()&&mn2[j].front()<=i-n) mn2[j].pop_front();
		while(!mx2[j].empty()&&s[mx2[j].back()][j]<=s[i][j]) mx2[j].pop_back();
		while(!mn2[j].empty()&&s[mn2[j].back()][j]>=s[i][j]) mn2[j].pop_back();
		mx2[j].push_back(i),mn2[j].push_back(i);
		mx[j]=s[mx2[j].front()][j],mn[j]=s[mn2[j].front()][j];
		while(!mx1[i].empty()&&mx1[i].front()<=j-n) mx1[i].pop_front();
		while(!mn1[i].empty()&&mn1[i].front()<=j-n) mn1[i].pop_front();
		while(!mx1[i].empty()&&mx[mx1[i].back()]<=mx[j]) mx1[i].pop_back();
		while(!mn1[i].empty()&&mn[mn1[i].back()]>=mn[j]) mn1[i].pop_back();
		mx1[i].push_back(j),mn1[i].push_back(j);
		if(i>=n&&j>=n) ans=min(ans,mx[mx1[i].front()]-mn[mn1[i].front()]);
	} 
	printf("%d",ans);
	return 0;
}

