#include<bits/stdc++.h>
using namespace std;

const int E = 2510;

int n;
long long c;
int Map[E][E],sumP[E][E],cowX[E],cowY[E],*dcfX,*dcfY;

struct point{
	int x,y;
}dcfPos[E];

int cmp(point a,point b){
	return a.x<b.x;
}

int binary(int x,int a[2510]){
	int l=0,r=n-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(x>a[mid]){
			l=mid+1;
		}
		else if(x<a[mid]){
			r=mid-1;
		}
		else{
			return mid;
		}
	}
}

int *dcf1(int a[2510]){
	int b[2510],c[2510];
	static int result[2510];
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	sort(b,b+n);
	c[0]=b[0];
	for(int i=1;i<n;i++){
		if(b[i]!=b[i-1]){
			c[i] = b[i];
		}
	}
	for(int i=0;i<n;i++){
		result[i] = binary(a[i],c);
	}
	return result;
}

int *dcf2(int a[2510]){
	int b[2510],c[2510];
	static int result[2510];
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	sort(b,b+n);
	c[0]=b[0];
	for(int i=1;i<n;i++){
		if(b[i]!=b[i-1]){
			c[i] = b[i];
		}
	}
	for(int i=0;i<n;i++){
		result[i] = binary(a[i],c);
	}
	return result;
}

int main(){
	cin>>n;
	c=0;
	for(int i=0;i<n;i++){
		cin>>cowX[i]>>cowY[i];
	}
	dcfX=dcf1(cowX);
	dcfY=dcf2(cowY);
	for(int i=0;i<n;i++){
		dcfPos[i].x=dcfX[i];
		dcfPos[i].y=dcfY[i];
		Map[dcfX[i]][dcfY[i]] = 1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sumP[i + 1][j + 1] = Map[i][j] + sumP[i + 1][j] + sumP[i][j + 1] - sumP[i][j];
		}
	}
	sort(dcfPos,dcfPos+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int column1 = dcfPos[i].x;
        	int column2 = dcfPos[j].x;
        	int row1 = min(dcfPos[i].y, dcfPos[j].y);
        	int row2 = max(dcfPos[i].y, dcfPos[j].y);
        	long long count1 = sumP[column2 + 1][row1 + 1] - sumP[column1][row1 + 1] - sumP[column2 + 1][0] + sumP[column1][0];
        	long long count2 = sumP[column2 + 1][n] - sumP[column1][n] - sumP[column2 + 1][row2] + sumP[column1][row2];
        	c += count1 * count2;
		}
	}
	cout<<c+1<<endl;
}
