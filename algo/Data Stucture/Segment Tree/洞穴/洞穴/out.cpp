#include<bits/stdc++.h>
using namespace std;
const int Case = 10;
int main()
{
	char in[100];
	for(int t=1;t<=Case;t++)
	{
		sprintf(in,"data/%d.out",t);
		freopen(in,"w",stdout);
		sprintf(in,"data/%d.in",t);
		freopen(in,"r",stdin);
		system("std.exe");
	}
	return 0;
}
