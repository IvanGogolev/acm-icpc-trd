bool bfs() {
	fi(0, MAX - 1) d[i] = MAX;
	vector<int>qu;
	d[S] = 0;
	qu.pb(S);
	fi(0, sz(qu) - 1) {
		int x = qu[i];
		fz(e[x]) {
			if(d[z->y] > d[x] + 1 && z->c - z->f >= C) {
				d[z->y] = d[x] + 1;
				qu.pb(z->y);
			}
		}
	}
		
	return d[T] != MAX;
}
 
ll dfs(int v,int c){
	if(v == T) return c;
	for(; ptr[v] < sz(e[v]); ptr[v]++) {
		Edge* z = e[v][ptr[v]];
		if(d[v] + 1 == d[z->y] && z->c - z->f >= C) {
			ll c2 = min(c, z->c - z->f);
			if(c2 == 0) continue;
			c2 = min(c2, dfs(z->y, c2));
			if(c2){
				z->f += c2;
				z->rev->f -= c2;
				return c2;
			}
		}
	}
	return 0;
	
}
 
int solve(int x){
	int ans = 0;
	C = (1<<28);
	while(C >= 1) {
		while(bfs()) {
			fi(0, MAX - 1) ptr[i] = 0;
			while(dfs(S,INF)){
				
			}
		}
		C /= 2;
	}
	fz(e[S]) {
		if(z->f >= 0) ans += z->f;
	}
	return ans;
}