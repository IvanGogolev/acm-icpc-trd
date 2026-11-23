vll FWHT(vll P, bool inverse) {
    for (int len = 1; 2 * len <= sz(P); len <<= 1) {
        for (int i = 0; i < sz(P); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = P[i + j];
                ll v = P[i + len + j];
                P[i + j] = u + v;
                P[i + len + j] = u - v;
            }
        }
    }
    
    if (inverse) {
        for (int i = 0; i < sz(P); i++)
            P[i] = P[i] / sz(P);
    }

    return P;
}
/*
AND
if (!inverse) {
    P[i + j] = v;
    P[i + len + j] = u + v;
} else {
    P[i + j] = -u + v;
    P[i + len + j] = u;
}
*/