/*Author��AustinJiang
��Ŀ��Ⱦɫ����2
ʱ�临�Ӷȣ�O(log(m))
�㷨�������ݣ���ѧ
��Դ��jmcoding
˼·��(m-1)^n+(-1)^n*(m-1)��Ⱦɫ��
nƬ����m����ɫ��a(n)��Ⱦɫ����A(n)Ϊn����n
��������������ɫ������ͬ��A(1)��m��Ⱦ����A(2)��A(n)����m-1��Ⱦ�� 
���з�Ϊ���࣬A(1)��A(n)��ɫ�벻ͬɫ 
ͬɫʱ���԰�A(1)��A(n)����һ�����򣬴�ʱ��a(n-1)��Ⱦ��
��˿��Եó�a(n)=m*(m-1)^(n-1)-a(n-1)��a(2)=m*(m-1)
a(n)=m*(m-1)^(n-1)-a(n-1)����ͬʱ��ȥ (m-1)�ó� a(n)-(m-1)^n=m*(m-1)^(n-1)-(m-1)^n-a(n-1)
�� m*(m-1)^(n-1)-(m-1)^nת��
m*((m-1)^n/(m-1))-(m-1)^n
(m-1)^n*(m/(m-1)-1)
(m-1)^n*(m/(m-1)-(m-1)/(m-1))
(m-1)^n*((m-(m-1))/(m-1))
(m-1)^n*(1/(m-1))
(m-1)^n/(m-1)
(m-1)^(n-1)
�ó��¹�ʽ a(n)-(m-1)^n=(m-1)^(n-1)-a(n-1)������ת�� 
a(n)+a(n-1)=(m-1)^n+(m-1)^(n-1)�����
a(n-1)+a(n-2)=(m-1)^(n-1)+(m-1)^(n-2)��������ʽ��� 
a(n)+a(n-1)-a(n-1)-a(n-2)=(m-1)^n+(m-1)^(n-1)-(m-1)^(n-1)-(m-1)^(n-2)
�ó� a(n)-a(n-2)=(m-1)^n-(m-1)^(n-2)
a(n)-(m-1)^n=-(m-1)^(n-2)+a(n-2)
���� 
a(n)-(m-1)^n=(m-1)^(n-1)-a(n-1)
			=-(m-1)^(n-2)+a(n-2)
			=(-1)^2*(a(n-2)-(m-1)^(n-2))
			=(-1)^3*(a(n-3)-(m-1)^(n-3))
			=(-1)^(n-3)*(a(3)-(m-1)^3)
			=(-1)^(n-2)*(a(2)-(m-1)^2)
��a(2)����� m*(m-1)
(-1)^(n-2)*(m*(m-1)-(m-1)^2)
(-1)^(n-2)*(m*(m-1)-(m-1)*(m-1)) 
(-1)^(n-2)*((m-1)*(m-(m-1)))
(-1)^(n-2)*((m-1)*(m-m+1))
(-1)^(n-2)*((m-1)*1)
(-1)^(n-2)*(m-1)
(-1)^n/(-1)^2*(m-1)
(-1)^n/1*(m-1)
(-1)^n*(m-1)
����a(n)-(m-1)^n=(-1)^n*(m-1)
a(n)=(-1)^n*(m-1)+(m-1)^n
���յó� a(i)=(m-1)^n+(-1)^n*(m-1) */
#include<bits/stdc++.h>
#define int long long
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
const int MOD=1e9+7;

int n,m;

int pow(int a,int b){
	int ans=1;
	while(b){
		if(b%2) ans*=a,ans%=MOD;
		a*=a,a%=MOD;
		b/=2;
	}
	return ans;
}

//int a(int n){
//	if(n==2) return m*(m-1)%MOD;
//	return (m*pow(m-1,n-1)-a(n-1))%MOD;
//}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cout<<pow(m-1,n)+(n&1?-1:1)*(m-1)<<endl;
	return 0;
}

