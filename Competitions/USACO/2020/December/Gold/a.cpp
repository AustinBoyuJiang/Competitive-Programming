#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int main(){
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	int n;
	ll d;
	cin >> n >> d;
	bool empty[n][n];
	vector<pair<int, int> > starts;
	vector<pair<int, int> > rocks;
	int dist_rock[n][n];
	int dist_source[n][n];
	bool ans[n][n];
	for(int i = 0; i<n; i++){
		string s;
		cin >> s;
		for(int j = 0; j<n; j++){
			if(s[j]=='#'){
				empty[i][j] = false;
				rocks.push_back(make_pair(i,j));
			}
			else{
				empty[i][j] = true;
			}
			if(s[j]=='S'){
				starts.push_back(make_pair(i,j));
			}
			dist_rock[i][j] = -1;
			dist_source[i][j] = -1;
			ans[i][j] = false;
		}
	}
	// First, we calculate distance of everything to a rock
	vector<pair<int, int> > bfs_list;
	for(int i = 0; i<rocks.size(); i++){
		bfs_list.push_back(rocks[i]);
		dist_rock[rocks[i].first][rocks[i].second] = 0;
	}
	for(int i = 0; i<bfs_list.size(); i++){
		pair<int, int> now = bfs_list[i];
		for(int j = 0; j<4; j++){
			pair<int, int> to = make_pair(now.first+dr[j],now.second+dc[j]);
			if(!(to.first>=0 && to.first<n && to.second>=0 && to.second<n)){
				continue;
			} 
			if(dist_rock[to.first][to.second]!=-1){
				continue;
			}
			int to_dist = dist_rock[now.first][now.second] + 1;
			dist_rock[to.first][to.second] = to_dist;
			bfs_list.push_back(to);
		}
	}
	// Then, we do a BFS from the sources
	bfs_list.clear();
	for(int i = 0; i<starts.size(); i++){
		bfs_list.push_back(starts[i]);
		dist_source[starts[i].first][starts[i].second] = 0;
	}
	// centers[i] will store all empty cells i that our center 
	// can reach, and who are distance i+1 from a rock
	// (meaning they can replicate i times)
	vector<pair<int, int> > centers[n*n];
	for(int i = 0; i<bfs_list.size(); i++){
		pair<int, int> now = bfs_list[i];
		ans[now.first][now.second] = true;
		int now_dist = dist_source[now.first][now.second];
		centers[dist_rock[now.first][now.second]-1].push_back(now);
		// Do not continue if replicating would force robots to rocks
		if(now_dist>=d*dist_rock[now.first][now.second]){
			continue;
		}
		for(int j = 0; j<4; j++){
			pair<int, int> to = make_pair(now.first+dr[j],now.second+dc[j]);

			if(!(to.first>=0 && to.first<n && to.second>=0 && to.second<n)){
				continue;
			} 
			if(dist_source[to.first][to.second]!=-1){
				continue;
			}
			if(!empty[to.first][to.second]){
				continue;
			}
			int to_dist = now_dist + 1;
			// Do not move if it would force robots to rocks
			if(to_dist > d*dist_rock[to.first][to.second]){
				continue;
			}
			dist_source[to.first][to.second] = to_dist;
			bfs_list.push_back(to);
		}
	}
	// Do a modified BFS such that we reach every cell where
	// there is some other cell in centers[z] and the distance
	// between the two is <=z
	vector<pair<int, int> > next_stage;
	for(int i = n*n-1; i>=0; i--){
		swap(bfs_list,next_stage);
		next_stage.clear();
		for(int j = 0; j<bfs_list.size(); j++){
			pair<int, int> now = bfs_list[j];
			for(int k = 0; k<4; k++){
				pair<int, int> to = make_pair(now.first+dr[k],now.second+dc[k]);

				if(!(to.first>=0 && to.first<n && to.second>=0 && to.second<n)){
					continue;
				} 
				if(ans[to.first][to.second]){
					continue;
				}
				if(!empty[to.first][to.second]){
					continue;
				}
				ans[to.first][to.second] = true;
				next_stage.push_back(to);
			}
		}
		for(int j = 0; j<centers[i].size(); j++){
			next_stage.push_back(centers[i][j]);
		}
	}
	int tot = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(ans[i][j]){
				tot++;
			}
		}
	}
	cout << tot << endl;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(ans[i][j]<10) cout<<ans[i][j]<<" ";
			else cout<<ans[i][j]<<"";
		}
		cout<<endl;
	}
}
