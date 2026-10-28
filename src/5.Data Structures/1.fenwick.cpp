// Linear
vll fen;
void add(int p, ll val) {
    for(int i = p; i <= n; i = (i | (i + 1))) {
        fen[i] += val;
    }
}
ll sum(int p) {
    ll res = 0;
    for(int i = p; i >= 0; i = (i & (i + 1)) - 1) {
        res += fen[i];
    }
    return res;
}

// Matrix
vvll fen;
void add(int x, int y, ll val) {
    for(int i = x; i <= n; i = (i | (i + 1))) {
        for(int j = y; j <= n; j = (j | (j + 1))) {
            fen[i][j] += val;
        }
    }
}
ll sum(int x, int y) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            res += fen[i][j];
        }
    }
    return res;
}