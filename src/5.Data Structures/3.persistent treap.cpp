int next(int l,int r){
	
	return l + rnd()%(r - l + 1);
}
const int MAX = 1e7;

int siz = 1;
vi Left(MAX,-1),Right(MAX,-1),Siz(MAX,0),Val(MAX,0);

void upd(int v){
	if(v == -1)return;
	Siz[v] = 1;
	if(Left[v] != -1)Siz[v] += Siz[Left[v]];
	if(Right[v] != -1)Siz[v] += Siz[Right[v]];
}

bool INIT;
int cop(int v){
	if(INIT)return v;
	int x = siz;
	siz++;
	Val[x] = Val[v];
	Left[x] = Left[v];
	Right[x] =  Right[v];
	Siz[x] = Siz[v];
	return x;
}

int merg(int L,int R){
	if(L == -1)return R;
	if(R == -1)return L;
	
	if(next( 1, (Siz[L] + Siz[R])*100 ) <= Siz[L] * 100){
		L = cop(L);
		Right[L] = merg(Right[L], R);
		upd(L);
		return L;
	}else{
		R = cop(R);
		Left[R] = merg(L,Left[R]);
		upd(R);
		return R;
	}
}
pair<int,int > split(int v,int k){
	if(Siz[v] <= k){
		return mp(v,-1);
	}
	if(k == 0){
		return mp(-1,v);
	}
	v = cop(v);
	int siz = 0;
	if(Left[v] != -1)siz = Siz[Left[v]];
	if(siz >= k){
		auto t = split(Left[v],k);
		Left[v] = t.second;
		upd(v);
		return mp(t.first,v);
	}else{
		auto t = split(Right[v], k - siz - 1);
		Right[v] = t.first;
		upd(v);
		return mp(v,t.second);
	}

}

int root = -1;
void seg_copy(int i,int j,int k){
	auto t = split(root,j - 1);
	auto g = split(root,i - 1);
	auto h = split(g.second,k);
	auto f = split(t.second,k);
	root = merg(t.first,merg(h.first,f.second));	
}

int n,m;
vi cnt,from,to;
vi res;

void solve() {
	INIT = true;
	fi(1, n){
		int v = siz++;
		upd(v);
		Val[v] = i;
		
		root = merg(root,v);
	}
	INIT = false;
}