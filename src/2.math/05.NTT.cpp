pii fun(int lg) {
	int n = (next(0, MAX / (1 << lg) / 2) * 2 + 1) * (1 << lg) + 1;
	while(!is_prime(n)) {
		n = (next(0, MAX / (1 << lg) / 2) * 2 + 1) * (1 << lg) + 1;
	}
	vi d;
	fj(1, n - 1) {
		if(j * j > n - 1)break;
		if( (n - 1) % j == 0) {
			d.pb(j);
			if(j * j != n - 1)d.pb((n - 1) / j);
		}
	}
	sort(All(d));
	d.pop_back();
	
	fj(2, n - 1) {
		bool f = 1;
		fx(d) {
			if(pown(j, x, n) == 1) {
				f = 0;
				break;
			}
		}
		if(f)return mp(n, j);
	}
	return mp(n, -1);
}
int LG = 19;
int MOD, G;
void fft(vi & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }
	for (int len = 2; len <= n; len <<= 1) {
    	
    	int wlen = G;	
    	if(invert)wlen = dv(1, wlen, MOD);
    	for(int i = len;i < (1 << LG);i <<= 1) {
    		wlen = mult(wlen, wlen, MOD);
    	}
    	
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j];
                int v = mult(a[i+j+len/2], w, MOD);
                a[i+j] = add(u, v, MOD);
                a[i+j+len/2] = sub(u, v, MOD);
                w = mult(w, wlen, MOD);
            }
        }
    }    
    if (invert) {
        int rn = dv(1, n, MOD);
        for (int & x : a)
            x = mult(x, rn, MOD);
    }
}
vi multiply(vi const& a, vi const& b) {
    vi fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < sz(a) + sz(b) ) {
        n <<= 1;
    }
  	
    fa.resize(n);
    fb.resize(n);
 	fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = mult(fa[i], fb[i], MOD);
    fft(fa, true);
    while(fa.back() == 0)fa.pop_back();
    return fa;
}
auto T = fun(LG);
MOD = T.first;
G = T.second;
G = pown(G, (MOD - 1) / (1 << LG), MOD);
