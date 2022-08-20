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
        system("baoli.exe < data.in > baoli.out");
        double begin=clock();
        system("std.exe < data.in > std.out");
        double end=clock();
        double t=end-begin;
        if (system("fc std.out baoli.out")) printf("测试点#%d Wrong Answer\n",i);
        else if (t>1000) printf("测试点#%d Time Limited Exceeded 用时 %.0lfms\n",i,t);
        else printf("测试点#%d Accepted 用时%.0lfms\n",i,t),cnt++;
    }
    printf("\n");
    double res=100.0*cnt/n;
    printf("共 %d 组测试数据  AC数据 %d 组  得分%.1lf",n,cnt,res);
}
