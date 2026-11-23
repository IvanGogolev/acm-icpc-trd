vector<vector<pii> > e;
bool used[MAX + 1];
int s[MAX + 1]; // subtrees sizes
void sizes (int v, int p) {
    s[v] = 1;
    for (auto [u, _] : e[v])
        if (u != p && !used[u])
            sizes(u, v), s[v] += s[u];
}
int centroid (int v, int p, int n) {
    for (auto [u, _] : e[v])
        if (u != p && !used[u] && s[u] > n/2)
            return centroid(u, v, n);
    return v;
}


//logic
void dfs (int v, int p, int d, int c, vector<pii>& arr) {
    arr.push_back(mp(d, c));
    for (auto [u, w] : e[v])
        if (u != p && !used[u])
            dfs(u, v, min(d, w), c, arr);
} 
ll ans = 0; // logic
void solve (int v) {
    /* logic */
    sizes(v, -1);
    
    vector<pii> arr;
    int q = 0;
    for (auto [u, w] : e[v]) {
        if (!used[u]) {
            q++;
            dfs(u, v, w, q, arr);
        }
    }
    sort(All(arr));
    dbg(arr);
    vi cnt(q + 1);
    fdi(sz(arr) - 1, 0) {
    	ans += (ll)arr[i].first * (sz(arr) - i - cnt[arr[i].second]);
    	cnt[arr[i].second]++;
    }
    /* logic */

    used[v] = 1;
    for (auto[u, _] : e[v])
        if (!used[u])
            solve(centroid(u, v, s[u]));
}
// run solve(centroid(1, -1, n))