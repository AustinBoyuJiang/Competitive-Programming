#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
using namespace std;

int n=50;

signed main(){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        system("data.exe > data.in");
        system("bruteForce.exe < data.in > ans.out");
        double begin=clock();
        system("std.exe < data.in > std.out");
        double end=clock();
        double t=end-begin;
        if (system("fc std.out ans.out")){
        	printf("���Ե�#%d Wrong Answer\n",i);
        	break;
		}
        else if (t>10000) printf("���Ե�#%d Time Limited Exceeded ��ʱ %.0lfms\n",i,t);
        else printf("���Ե�#%d Accepted ��ʱ%.0lfms\n",i,t),cnt++;
    }
    printf("\n");
    double res=100.0*cnt/n;
    printf("�� %d ���������  AC���� %d ��  �÷�%.1lf",n,cnt,res);
}
