#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

struct Q {
    int n;
    vector<pair<int, int>> e;
    vector<int> q;

    Q(int _n, const vector<pair<int, int>> &_e, const vector<int> &_q) : n(_n), e(_e), q(_q) {}
};

vector<Q> vq;
mt19937 rnd;
int fa[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void output() {
    int sum_n = 0, sum_m = 0;
    printf("%d\n", vq.size());
    shuffle(vq.begin(), vq.end(), rnd);
    for (auto &t: vq) {
        int n = t.n, m = t.e.size(), k = t.q.size();
//        assert(n <= 200000 && m <= 200000);
//        fprintf(stderr, "n=%d m=%d k=%d\n", n, m, k);
//        assert(2 <= k && k <= n);
        sum_n += n, sum_m += m;
        printf("%d %d %d\n", n, m, k);
        shuffle(t.e.begin(), t.e.end(), rnd);
//        sort(t.e.begin(), t.e.end());
        for (auto &pr: t.e) {
            if (rnd() & 1) swap(pr.first, pr.second);
            printf("%d %d\n", pr.first, pr.second);
        }
        for (int i = 0; i < t.q.size(); ++i) {
            printf("%d", t.q[i]);
            if (i != t.q.size() - 1) putchar(' ');
            else putchar('\n');
        }
    }
    cerr << sum_n << " " << sum_m << "\n";
}

int p[N];

void rand_chain_graph(int n, int m) { // 随机带有较长主链的图，具有一般性的图
    for (int i = 1; i <= n; ++i) p[i] = i;
    vector<pair<int, int>> e;
    auto build = [&]() {
        shuffle(p + 1, p + 1 + n, rnd);
        int lim = n * 0.75;
        for (int i = 1; i < lim; ++i) {
            e.emplace_back(p[i], p[i + 1]);
        }
        uniform_int_distribution<> U(1, lim);
        for (int i = lim + 1; i <= n; ++i) {
            int u = p[U(rnd)];
            e.emplace_back(u, p[i]);
        }
        vector<pair<int, int>> e_sel;
        set<pair<int, int>> vis;
        for (auto &pr: e) vis.insert(pr);
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n && j <= i + 30; ++j) {
                if (vis.find({p[i], p[j]}) == vis.end() && vis.find({p[j], p[i]}) == vis.end()) {
                    e_sel.emplace_back(p[i], p[j]);
                }
            }
        }
        shuffle(e_sel.begin(), e_sel.end(), rnd);
        int c = m - e.size();
        for (int i = 0; i < c; ++i) e.emplace_back(e_sel[i]);
    };
    build();
    vector<int> q;
    for (int i = 1; i <= n; ++i) q.push_back(i);
    shuffle(q.begin(), q.end(), rnd);
    vq.emplace_back(n, e, q);
}

void rand_bamboo(int n, bool needDeleteAll = false) { // 随机真正的竹子
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; ++i) p[i] = i;
    shuffle(p + 1, p + 1 + n, rnd);
    for (int i = 1; i < n; ++i) {
        e.emplace_back(p[i], p[i + 1]);
    }
    set<pair<int, int>> vis;
    vector<vector<int>> ask;
    uniform_int_distribution<> U(1, n);
    vector<int> q;
    if (needDeleteAll) {
        for (int i = 1; i <= n; ++i) {
            q.emplace_back(p[i]);
        }
    }
    else {
        int cnt = n * 0.9;
        for (int i = 1; i <= cnt; ++i) q.push_back(i);
        shuffle(q.begin(), q.end(), rnd);
    }
    vq.emplace_back(n, e, q);
}

void rand_chrysanthemum(int n) { // 随机真正的菊花图
    int c = rnd() % n + 1; // 菊花中心
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; ++i) {
        if (i != c) {
            e.emplace_back(c, i);
        }
    }
    vector<int> q;
    for (int i = 1; i <= n; ++i) {
        if (i == c) continue;
        q.push_back(i);
    }
    q.insert(q.begin() + q.size() * 0.5, c);
    vq.emplace_back(n, e, q);
}

void rand_complete_graph(int n) {
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            e.emplace_back(i, j);
        }
    }
    vector<int> q;
    for (int i = 1; i <= n; ++i) q.emplace_back(i);
    shuffle(q.begin(), q.end(), rnd);
    vq.emplace_back(n, e, q);
}

void big_test1(int n) { // 1e5随机菊花图带两个分支
    uniform_int_distribution<> U(1, n);
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; ++i) p[i] = i;
    shuffle(p + 1, p + 1 + n, rnd);
    int c = p[1];
    for (int i = 2; i <= n - 4; ++i) {
        e.emplace_back(c, p[i]);
    }
    int x = p[n / 2], y = x + 1;
    e.emplace_back(x, p[n - 3]);
    e.emplace_back(x, p[n - 2]);
    e.emplace_back(y, p[n - 1]);
    e.emplace_back(y, p[n]);
    vector<int> q;
    for (int i = 1; i <= n - 4; ++i) {
        q.push_back(p[i]);
    }
    shuffle(q.begin(), q.end(), rnd);
    for (int i = n - 3; i <= n; ++i) {
        q.insert(q.begin() + q.size() / 2, p[i]);
    }
    vq.emplace_back(n, e, q);
}

void big_test2(int n) { // 2e5大测试，根据边双建圆点为中心的"菊花"，大部分edcc点数3~7，个别edcc点数1e4
    vector<pair<int, int>> e;
    auto add = [&](int x, int y) {
        e.emplace_back(x, y);
    };
    for (int i = 1; i <= n; ++i) p[i] = i;
    shuffle(p + 1, p + 1 + n, rnd);
    vector<vector<int>> edcc; // 边双
    int pid = 1; // 当前使用到的排列下标
    uniform_int_distribution<> u_big(10000 - 100, 10000 + 100);
    for (int i = 1; i <= 5; ++i) { // 1e4环
        vector<int> v;
        int cnt = u_big(rnd);
        while (cnt--) {
            v.push_back(p[pid++]);
        }
        edcc.emplace_back(std::move(v));
    }
    uniform_int_distribution<> U(3, 7);
    while (pid + 15 <= n) { // 3~7环
        int cnt = U(rnd);
        vector<int> v;
        while (cnt--) {
            v.push_back(p[pid++]);
        }
        edcc.emplace_back(std::move(v));
    }
    while (pid <= n) { // 1环
        edcc.emplace_back(1, p[pid++]);
    }

    // 所有边双形成环
    vector<int> idx;
    for (int id = 0; id < edcc.size(); ++id) {
        auto &vd = edcc[id];
        if (vd.size() == 1) continue;
        if (vd.size() > 5) idx.push_back(id);
        for (int i = 0; i < vd.size(); ++i) {
            add(vd[i], vd[(i + 1) % vd.size()]);
        }
    }
    // 部分点环内部加边，使得图不是仙人掌
    shuffle(idx.begin(), idx.end(), rnd);
    for (int i = 0; i < idx.size() && i < 100; ++i) {
        auto &vd = edcc[idx[i]];
        add(vd[0], vd[4]);
        add(vd[3], vd[5]);
    }

    vector<int> v1, v7, v10000;
    for (int i = 0; i < edcc.size(); ++i) {
        auto &vd = edcc[i];
        if (vd.size() == 1) {
            v1.push_back(i);
        }
        else if (vd.size() <= 10) {
            v7.push_back(i);
        }
        else v10000.push_back(i);
    }
    vector<int> q;
    assert(v1.size() >= 2);
    int c0 = edcc[v1[0]][0]; // 菊花中心
    for (int i = 1; i < v1.size(); ++i) {
        add(c0, edcc[v1[i]][0]);
    }
    int c1 = edcc[v1[1]][0]; // 中心的一个子树
    int c2 = edcc[v1[2]][0]; // 中心的一个子树
    int k1 = v7.size() * 0.80;
    int k2 = v7.size() * 0.90;
    set<int> okSet;
    for (int i: v10000) {
        auto &ed = edcc[v10000[i]];
        add(c0, ed[rnd() % ed.size()]);
        okSet.insert(ed[rnd() % ed.size()]);
    }
    for (int i = 0; i < k1; ++i) {
        auto &ed = edcc[v7[i]];
        add(c0, ed[rnd() % ed.size()]);
        okSet.insert(ed[rnd() % ed.size()]);
    }
    auto getSubtreeRoot = [&](int l, int r) {
        for (int i = l; i < r; ++i) {
            fa[v7[i]] = v7[i];
        }
        vector<pair<int, int>> es;
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j <= i + 30 && j < r; ++j) {
                es.emplace_back(v7[i], v7[j]);
            }
        }
        shuffle(es.begin(), es.end(), rnd);
        for (auto &pr: es) {
            int x = pr.first, y = pr.second;
            if (find(x) != find(y)) {
                fa[find(x)] = find(y);
                add(edcc[x][rnd() % edcc[x].size()], edcc[y][rnd() % edcc[y].size()]);
            }
        }
        int id = l + r >> 1;
        okSet.insert(edcc[id][rnd() % edcc[id].size()]);
        return edcc[v7[l]][0];
    };
    add(c1, getSubtreeRoot(k1, k2));
    add(c2, getSubtreeRoot(k2, v7.size()));

    for (int i = k2; i < v7.size(); ++i) {
        auto &ed = edcc[v7[i]];
        add(c0, ed[rnd() % ed.size()]);
        if (i == k2) okSet.insert(ed[rnd() % ed.size()]);
    }
    for (int i = 1; i <= n; ++i) {
        if (okSet.find(i) == okSet.end()) {
            q.emplace_back(i);
        }
    }
    shuffle(q.begin(), q.end(), rnd);
    for (int x: okSet) q.emplace_back(x);
    vq.emplace_back(n, e, q);
}

void big_test3(int n) { // 2e5大测试，1e5环的基环树
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; ++i) p[i] = i;
    shuffle(p + 1, p + 1 + n, rnd);
    uniform_int_distribution<> u(1, 7);
    int id = 1;
    auto randTree = [&]() {
        int cnt = u(rnd);
        vector<int> v;
        for (int i = 1; i <= cnt; ++i) {
            v.push_back(p[id++]);
        }
        vector<pair<int, int>> e_sel;
        for (int i = 0; i < cnt; ++i) fa[v[i]] = v[i];
        for (int i = 0; i < cnt; ++i) {
            for (int j = i + 1; j < cnt; ++j) {
                e_sel.emplace_back(v[i], v[j]);
            }
        }
        shuffle(e_sel.begin(), e_sel.end(), rnd);
        vector<pair<int, int>> e_unused;
        for (auto &pr: e_sel) {
            int x = pr.first, y = pr.second;
            if (find(x) != find(y)) {
                fa[find(x)] = find(y);
                e.emplace_back(x, y);
            }
            else {
                e_unused.emplace_back(x, y);
            }
        }
        if (cnt >= 6 && rnd() % 100 < 3) {
            int p = rnd() % e_unused.size();
            int x = e_unused[p].first, y = e_unused[p].second;
            e.emplace_back(x, y);
        }
        return v;
    };
    set<int> okSet;
    vector<vector<int>> trees;
    while (id + 800000 < n) {
        trees.emplace_back(randTree());
    }
    while (id <= n) {
        trees.emplace_back(1, p[id++]);
    }
    int h = trees.size();
    for (int i = 0; i < h; ++i) {
        e.emplace_back(trees[i].front(), trees[(i + 1) % h].front());
    }
    for (int i = 0; i < h; ++i) {
        if (trees[i].size() > 2) {
            okSet.insert(trees[i].front());
            okSet.insert(trees[i].back());
            break;
        }
    }
    okSet.insert(trees.back().front());
    vector<int> q;
    for (int i = 1; i <= n; ++i) {
        int x = p[i];
        if (okSet.find(x) == okSet.end()) {
            q.push_back(x);
        }
    }
    for (int x: okSet) {
        q.push_back(x);
    }
    vq.emplace_back(n, e, q);
}

void small_test(int n) { // n = 50级别
    vector<pair<int, int>> e;
    auto build = [&]() {
        for (int i = 1; i <= n; ++i) p[i] = i;
        shuffle(p + 1, p + 1 + n, rnd);
        vector<vector<int>> edcc;
        int id = 1;
        uniform_int_distribution<> U(1, 5);
        while (id + 15 <= n) {
            int cnt = U(rnd);
            if (cnt == 2) cnt = 1;
            vector<int> v;
            while (cnt--) {
                v.push_back(p[id++]);
            }
            edcc.emplace_back(std::move(v));
        }
        while (id <= n) {
            edcc.emplace_back(1, p[id++]);
        }

        vector<int> idx;
        for (id = 0; id < edcc.size(); ++id) {
            auto &vd = edcc[id];
            idx.push_back(id);
            if (vd.size() > 2) {
                for (int i = 0; i < vd.size(); ++i) {
                    e.emplace_back(vd[i], vd[(i + 1) % vd.size()]);
                }
            }
        }
        shuffle(idx.begin(), idx.end(), rnd);
        vector<pair<int, int>> e_sel;
        for (int i = 0; i < idx.size(); ++i) {
            for (int j = i + 1; j <= i + 50 && j < idx.size(); ++j) {
                e_sel.emplace_back(i, j);
            }
        }
        for (int i = 0; i < edcc.size(); ++i) fa[i] = i;
        shuffle(e_sel.begin(), e_sel.end(), rnd);
        for (auto &edge: e_sel) {
            int x = edge.first, y = edge.second;
            if (find(x) != find(y)) {
                auto &vd1 = edcc[x];
                auto &vd2 = edcc[y];
                fa[find(x)] = find(y);
                int u = vd1[rnd() % vd1.size()];
                int v = vd2[rnd() % vd2.size()];
                e.emplace_back(u, v);
            }
        }
    };
    build();
    vector<int> q;
    for (int i = 1; i <= n - 5; ++i) q.emplace_back(p[i]);
    shuffle(q.begin(), q.end(), rnd);
    vq.emplace_back(n, e, q);
}

void rand_small_tree(int n) { // n = 20级别
    int k = 2 + rnd() % (n - 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        fa[i] = i;
    }
    vector<pair<int, int>> e_sel, e;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            e_sel.emplace_back(i, j);
        }
    }
    shuffle(e_sel.begin(), e_sel.end(), rnd);
    for (auto &pr: e_sel) {
        int x = pr.first, y = pr.second;
        if (find(x) != find(y)) {
            e.emplace_back(x, y);
            fa[find(x)] = find(y);
        }
    }
    vector<int> q;
    shuffle(p + 1, p + 1 + n, rnd);
    for (int i = 1; i <= k; ++i) q.emplace_back(p[i]);
    vq.emplace_back(n, e, q);
}

void rand_sweeper(int n) { // 扫把图
    for (int i = 1; i <= n; ++i) p[i] = i;
    shuffle(p + 1, p + 1 + n, rnd);
    vector<pair<int, int>> e;
    int pos = n / 2;
    for (int i = 1; i < pos; ++i) {
        e.emplace_back(p[i], p[i + 1]);
    }
    for (int i = pos + 1; i <= n - 2; ++i) {
        if (i & 1) {
            e.emplace_back(p[pos], p[i]);
        }
        else {
            e.emplace_back(p[i], p[pos]);
        }
    }
    e.emplace_back(p[n - 2], p[n - 1]);
    e.emplace_back(p[n - 2], p[n]);
    e.emplace_back(p[n - 1], p[n]);
    vector<int> q;
    for (int i = 1; i <= pos - 2; ++i) q.emplace_back(p[i]);
//    q.emplace_back(p[n]);  // 此处出现重复
    for (int i = 1; i <= 10; ++i) {
        q.emplace_back(p[pos + i]);
    }
    shuffle(q.begin(), q.end(), rnd);
    q.emplace_back(p[n]);
    q.emplace_back(p[n - 1]);
    q.emplace_back(p[pos]);
    for (int i = pos + 11; i <= n - 2; ++i) {
        q.emplace_back(p[i]);
    }
    vq.emplace_back(n, e, q);
}

int main() {
    freopen("CS.in", "w", stdout);
    rnd.seed(19260817);
    auto smallTests = [&]() {
        uniform_int_distribution<> u1(15, 25);
        for (int i = 1; i <= 2100; ++i) {
            rand_small_tree(u1(rnd));
            int x = u1(rnd), y = x + rnd() % 5;
            rand_chain_graph(x, y);
        }
        for (int i = 1; i <= 10; ++i) {
            rand_chrysanthemum(u1(rnd));
            rand_bamboo(u1(rnd), true);
            rand_bamboo(u1(rnd), false);
            rand_complete_graph(u1(rnd));
        }
        uniform_int_distribution<> u2(35, 65);
        for (int i = 1; i <= 100; ++i) {
            small_test(u2(rnd));
            int x = u2(rnd), y = x + rnd() % 7;
            rand_chain_graph(x, y);
        }
    };
    smallTests();
    auto bigTests = [&]() {
        rand_bamboo(66666);
        rand_chrysanthemum(131415);
        rand_sweeper(110077);
        big_test1(200000);
        big_test2(165066);
        big_test3(199017);
    };
    bigTests();
    output();
    return 0;
}
