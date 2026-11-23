bool deikstr() {
    vll d(_k + 1, INF);
    set<pll> t;
    d[S] = 0;
    t.ins({d[S], S});
    vector<Edge *> p(_k + 1, NULL);
    while (sz(t)) {
        auto [_, x] = *t.begin();
        t.erase(t.begin());
        fy(e[x]) {
            if (y->f + 1 <= y->c && d[y->y] > d[x] + y->w) {
                t.erase({d[y->y], y->y});
                d[y->y] = d[x] + y->w;
                t.ins({d[y->y], y->y});
                p[y->y] = y;
            }
        }
    }
    if (d[T] == INF) return false;
    int x = T;
    while (x != S) {
        p[x]->f++;
        p[x]->rev->f--;
        x = p[x]->rev->y;
    }
    fi(1, _k) {
        fy(e[i]) {
            y->w = y->w + d[i] - d[y->y];
        }
    }
    return true;
}