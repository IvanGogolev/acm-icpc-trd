void dfs(ll x, ll p = -1) {
    if (color[x]) return;
    color[x] = 1;
    _time++;
    tin[x] = _time;
    tup[x] = _time;
    ll q = 0;
    bool f = 0;
    fy(e[x]) {
        if (y == p) continue;
        if (!color[y]) {
            q++;
            dfs(y, x);
            if (tup[y] >= tin[x]) {
                f = 1;
            }
            tup[x] = min(tup[x], tup[y]);
        } else {
            tup[x] = min(tup[x], tin[y]);
        }
    }
    if (p == -1) {
        if (q > 1) ans.pb(x);
    } else {
        if (f) ans.pb(x);
    }
}