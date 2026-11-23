void dfs(ll x, ll p = -1) {
    if (color[x]) return;
    color[x] = 1;
    tin[x] = _time++;
    tup[x] = tin[x];
    for (auto &to : e[x]) {
        if (to == p) continue;
        if (color[to]) {
            tup[x] = min(tup[x], tin[to]);
            continue;
        } else {
            dfs(to, x);
            tup[x] = min(tup[x], tup[to]);
            if (tup[to] > tin[x]) {
                ans.pb(t[{to, x}]);
                dbg(mp(to, x));
            }
        }
    }
}