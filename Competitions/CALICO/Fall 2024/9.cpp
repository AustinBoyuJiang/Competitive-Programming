int randint(int x) {
    return rng() % x;
};

void solve() {
    const int N = 500;
    const int BND = 750;
    int Q = 0;

    vi have = {}, done(N); done.ft = done.bk = 1;

    V<set<int>> adj(N);

    auto ask = [&](int x) {
        if (Q >= BND) return -1;
        cout << "SCAN " << x + 1 << endl;
        int r; cin >> r; --r;
        if (!done[r]) {
            have.pb(r); 
            done[r] = 1;
        }
        ++Q;
        return r;
    };

    auto scan = [&](int x) {
        while(sz(adj[x]) != 3) {
            int r = ask(x);
            if (r == -1) break;
            adj[x].ins(r);
        }
    };

    auto get = [&]() { 
        remDup(have);
        return have[randint(sz(have))]; 
    };

    auto pop = [&]() {
        int x = get();
        have.erase(find(all(have), x));
        return x;
    };

    scan(0);
    scan(N - 1);

    while(Q < BND) {
        int x = pop();
        scan(x);
    }

    vi dst(N, INF), vis(N);
    queue<int> q; q.push(0); dst[0] = 0;
    while(sz(q)) {
        int u = q.ft; q.pop();

        if (vis[u]) continue;
        vis[u] = 1;
        dbg(u);

        each(v, adj[u]) {
            if (ckmin(dst[v], dst[u] + 1)) {
                q.push(v);
            }
        }
    }

    cout << "SUBMIT " << dst.bk << endl;
}
int main() {
    setIO(); 

    int TT = 1;
    cin >> TT;

    rep(TT) solve();
    
    exit(0-0);
}
