#include <iostream>
#include <cstdio>
#include <string>
#include <utility> 
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
const int N = 505;
struct Point{
	int x, y;
}a[N],b[N];
const int inf = 10005;
int e[N][N];
int read()
{
	int x = 0, f = 1; char ch = getchar();
	for(;ch < '0' && ch > '9'; ch = getchar()){if(ch == '-')f = -1;}
	for(;ch >= '0'&& ch <='9'; ch = getchar())x = x * 10 + ch - '0';
	return x * f;
}
int check(Point a, Point b, Point c)//判断C在A到B的左边还是右边
{
	return (a.x - c.x) *(b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
int n ,m;
vector<Point>ans;
int vis[N];
void dfs(int be, int k, int anst)
{
	cout << be << ' '<< k << endl;
	vis[k] = 1;
	ans.push_back(a[k]);
	if(e[k][be] == 1 && ans.size() != 0){
		for(auto x : ans){
			cout << x.x << ',' << x.y << endl;
		}
		exit(0);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i] && e[be][i] + e[i][be] == anst && e[k][i] == 1){
			dfs(be, i, anst);
		}
	}
}
void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i].x >> b[i].y;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			e[i][j] = inf;
			if(i != j){
				e[i][j] = 1;
				for(int k = 1; k <= m; k++){
					if(check(a[i], a[j], b[k]) <= 0)e[i][j] = inf;
				}
				//if(e[i][j] == 1)cout<< i <<',' << j << endl;
			}
		}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				e[i][j] = min(e[i][k] + e[k][j], e[i][j]);
			}
		}
	}
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<e[i][j]<<' ';
		}
		cout<<endl;
	}*/
	int ans = inf;
	int be = 0;
	for(int i = 1; i <= n; i++){
		if(e[i][i] < ans) ans = e[i][i], be = i;
	}
	if(ans == inf)ans = -1;
	cout << ans << endl;
	//dfs(be, be, ans);
}
signed main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int T = read();
	while(T--){
		solve();
	}
}