struct SegmentTree{
	ll n;
	vll st;
	void init(ll _n) {
		n = _n;
		st = vll(4*n);
	}
	void build(int tl, int tr, int x) {
		if(tl == tr) {
			st[x] = 0;
			return;
		}
		int th = (tl+tr)>>1;
		build(tl,th,2*x);
		build(th+1,tr,2*x+1);
		st[x]=st[2*x]+st[2*x+1];
	}
	void set(int c, int val) {
		set(c,val,1,n,1);
	}
	void set(int c, int val, int tl, int tr, int x) {
		if(c < tl || c > tr) return;
		if(tl == c && tl == tr) {
			st[x] = val;
			return;
		}
		int th = (tl+tr)>>1;
		set(c,val,tl,th,2*x);
		set(c,val,th+1,tr,2*x+1);
		st[x] = st[2*x]+st[2*x+1];
	}
	ll get(int L, int R) {
		if(L > R) return 0;
		return get(L,R,1,n,1);
	}
	ll get(int L, int R, int tl, int tr, int x) {
		if(L > tr || R < tl) return 0;
		if(L <= tl && tr <= R) {
			return st[x];
		}
		int th = (tl+tr)>>1;
		return get(L,R,tl,th,2*x) + get(L,R,th+1,tr,2*x+1);
	}
};
struct HLD{
	SegmentTree st;
	ll n;
	ll nxt;
};
vector<HLD>hld;
vll num_in_comp;
vll comp;


bool predok(ll x, ll y) {
	return tin[x] <= tin[y] && tin[y] <= tout[x];
}
 
ll lca(ll x, ll y) {
	if(predok(x, y)) return x;
	if(predok(y, x)) return y;
	fdi(LOG, 0) {
		ll x2 = bp[i][x];
		if(x2 == -1) continue;
		if(predok(x2, y)) continue;
		x = x2;
	}
	return bp[0][x];
}
void change(ll pos, ll val) {
	ll x = comp[pos];
	hld[x].st.set(num_in_comp[pos], val);
}
 
ll get(ll a, ll b) {
	ll res = 0;
	while(comp[a] != comp[b]) {
		ll x = comp[a];
		res += hld[x].st.get(num_in_comp[a], hld[x].n);
		a = hld[x].nxt;
	}
	res += hld[comp[a]].st.get(num_in_comp[a], num_in_comp[b]);
	return res;
}

void init() {
	hld = vector<HLD>(n+1);
	num_in_comp = vll(n+1);
	comp = vll(n+1);
	ll K = 0;
	vll d(n+1);
	tin = vll(n+1);
	tout = vll(n+1);
	ll T = 0;
	par = vll(n+1);
	auto dfs = [&](int x, int p, auto&& dfs) -> void{
		T++;
		tin[x] = T;
		d[x] = 1;
		bool f = 1;
		ll to;
		par[x] = p;
		fy(e[x]) {
			if(y == p) continue;
			dfs(y, x, dfs);
			d[x] += d[y];
			f = 0;
			to = y;
		}
		tout[x] = T;
		
		if(f) {
			K++;
			comp[x] = K;
			num_in_comp[x] = 1;
			hld[K].nxt = p;
			hld[K].n++;
			return;
		}
		fy(e[x]) {
			if(y == p) continue;
			if(d[y] > d[to]) to = y;
		}
		comp[x] = comp[to];
		num_in_comp[x] = num_in_comp[to]+1;
		hld[comp[x]].nxt = p;
		hld[comp[x]].n++;
	};
	dfs(1, -1, dfs);
	fi(1, K) {
		hld[i].st.init(hld[i].n);
	}
	fi(1, n) {
		int x = comp[i];	
		hld[x].st.set(num_in_comp[i], a[i], i);
	}	
	dbg("inited");
}