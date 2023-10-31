#include <bits/stdc++.h>

using namespace std;

struct Q {
    int n;
    vector<pair<int, int>> e;
    vector<int> q;

    Q() = default;

    Q(int _n, const vector<pair<int, int>> &_e, const vector<int> &_q) : n(_n), e(_e), q(_q) {}

    friend istream &operator>>(istream &is, Q &qq) {
        int n, m, k;
        vector<pair<int, int>> e;
        vector<int> v;
        is >> n >> m >> k;
        for (int i = 1; i <= m; ++i) {
            int x, y;
            is >> x >> y;
            e.emplace_back(x, y);
        }
        for (int i = 1; i <= k; ++i) {
            int x;
            is >> x;
            v.push_back(x);
        }
        qq = Q(n, e, v);
        return is;
    }

    void show() {
        printf("%d %d %d\n", n, e.size(), q.size());
        for (auto &pr: e) {
            printf("%d %d\n", pr.first, pr.second);
        }
        for (int x: q) printf("%d ", x);
        puts("");
    }
};

int main() {
    freopen("err.txt", "w", stdout);
    ifstream ifs1("CS.in");
    ifstream ifs2("CS.out");
    ifstream ifs3("CS1.out"); // 你的答案文件
    int T;
    ifs1 >> T;
    int err_cnt = 0;
    for (int id = 1; id <= T; ++id) {
        Q t;
        ifs1 >> t;
        bool flag = true;
        int ans1, ans2;
        ifs2 >> ans1;
        ifs3 >> ans2;
        if (ans1 != ans2) {
            fprintf(stderr, "test(%d) ans:%d your_ans:%d\n", id, ans1, ans2);
            ++err_cnt;
            flag = false;
        }
        if (!flag) {
            t.show();
        }
    }
}