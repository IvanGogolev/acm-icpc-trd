vi u;
vi p;
int CUR = 1;
bool dfs(int v){
	if(u[v] == CUR)return false;
	u[v] = CUR;
	fz(e3[v]){
		if(p[z] == -1 || dfs(p[z]) ){
			p[z] = v;
			return true;
		}
	}
	return false;
}