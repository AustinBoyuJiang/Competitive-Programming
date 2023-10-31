#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 2e5 + 5;
bool vis[N];
vector<int> e[N];

int main(int argc, char *argv[]) {
    freopen("CS.in", "r", stdin);
    registerValidation(argc, argv);
    int T = inf.readInt(1, 5000, "T");
    inf.readEoln();
    int sum_n = 0, sum_m = 0, sum_k = 0;
    for (int t = 1; t <= T; ++t) {
        string testName = "test(" + to_string(t) + ") ";
        int n = inf.readInt(1, 200000, testName + "n");
        inf.readSpace();
        int m = inf.readInt(1, 200000, testName + "m");
        inf.readSpace();
        int k = inf.readInt(1, n, testName + "k");
        inf.readEoln();
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            e[i].clear();
        }
        sum_n += n;
        sum_m += m;
        sum_k += k;
        map<pair<int, int>, int> mp;
        for (int i = 1; i <= m; ++i) {
            string edgeName = "edge(" + to_string(i) + ") ";
            int u = inf.readInt(1, n, testName + edgeName + "u");
            inf.readSpace();
            int v = inf.readInt(1, n, testName + edgeName + "v");
            inf.readEoln();
            ensuref(u != v, "test(%d) edge(%d) loop", t, i);
            ensuref(mp.find({u, v}) == mp.end(),
                    "test(%d) edge(%d) multiple edge(%d)", t, i, mp.find({u, v})->second);
            mp[{u, v}] = mp[{v, u}] = i;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        queue<int> q({1});
        vis[1] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y: e[x]) {
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            ensuref(vis[i], "Test %d not connected graph", t);
        }
        set<int>s;
        for (int i = 1; i <= k; ++i) {
            int x = inf.readInt(1, n, testName + "q[" + to_string(i) + "]");
            ensuref(s.find(x) == s.end(), "test %d i=%d", t, i); // 此处赛前未加
            s.insert(x);
            if (i < k) inf.readSpace();
            else inf.readEoln();
        }
    }
    inf.readEof();
    ensure(sum_n <= 1000000);
    ensure(sum_m <= 1000000);
    printf("Input is valid! sum_n=%d sum_m=%d sum_k=%d\n", sum_n, sum_m, sum_k);
}