/*Author��AustinJiang
��Ŀ��
ʱ�临�Ӷȣ�O()
�㷨��
��Դ��
˼·��
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
const int T=10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

signed main(){
    for(int t=1;t<=T;t++){
    	char in[100],out[100];
    	sprintf(in,"input.exe > data/%d.in",t);
    	sprintf(out,"output.exe < data/%d.in > data/%d.out",t,t);
        system(in);
        system(out);
    }
    return 0;
}

