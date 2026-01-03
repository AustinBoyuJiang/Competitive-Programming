#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
using namespace std;

int n=10;

signed main(){
    for(int t=1;t<=n;t++){
    	char in[100],out[100];
    	sprintf(in,"data.exe > data/%d.in",t);
    	sprintf(out,"std.exe < data/%d.in > data/%d.out",t,t);
        system(in);
        system(out);
    }
}
