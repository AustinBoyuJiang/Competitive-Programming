#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
char Map[1000][1000];
set<vector<pair<int,int> > >vis;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>Map[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(Map[i][j]=='G'){
				int dx[4]={0,0,1,-1};
				int dy[4]={1,-1,0,0};
				vector<pair<int,int> >cows;
				for(int d=0;d<4;d++){
					int di=i+dx[d];
					int dj=j+dy[d];
					if(di>=0&&di<n&&dj>=0&&dj<m&&Map[di][dj]=='C'){
						cows.push_back(make_pair(di,dj));
					}
				}
				if(cows.size()>2){
					cnt++;
				}
				else if(cows.size()==2){
					sort(cows.begin(),cows.end());
					vis.insert(cows);
				}
			}
		}
	}
	cout<<cnt+vis.size()<<endl;
}
