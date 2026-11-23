struct Edge{
	int y;
	int f;
	int c;
	Edge* rev;
};
int _num[MAX];
int n, m;
int S,T;
int K = 0;
int num(int x) {
	if(_num[x] == 0) {
		K++;
		_num[x] = K;
	}
	return _num[x];
}
vector<vector<Edge*>>e;
void add_edge(int x, int y, int c) {
	Edge* v = new Edge{y, 0, c, NULL};
	Edge* v2 = new Edge{x, 0, c, v};
	v->rev = v2;
	e[x].pb(v);
	e[y].pb(v2);
}
vi color;
int C = 1;
bool dfs(int x) {
	if(x == T) return true;
	if(color[x]) return false;
	color[x] = 1;
	fy(e[x]) {
		if(y->f + C <= y->c && dfs(y->y)) {
			y->f += C;
			y->rev->f -= C;
			return true;
		}
	}
	return false;
}

while(C >= 1){
	C = (1 << 30);
	while(C >= 1) {
		color = vi(n+1);
		while(dfs(S)) {
			color = vi(n+1);
		}
		C/=2;
	}
}