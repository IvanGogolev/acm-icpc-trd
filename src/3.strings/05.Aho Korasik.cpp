struct Node {
	int leaf = -1;
	char c = '\0';	
	Node* par = nullptr;
	map<char, Node*> nxt;
	Node* suf = nullptr;
	map<char, Node*> sufs;
	Node(char t, Node* p) {
		c = t;
		par = p;
	}
};
Node* root;
void add(string& s, int j) {
	Node* cur = root;
	fi(0, sz(s)- 1) {
		if(cur->nxt.count(s[i])) {
			cur = cur->nxt[s[i]];
		} else {
			Node* t = new Node(s[i],cur);
			cur->nxt[s[i]] = t;
			cur = t;
		}
	}
	cur->leaf = j;
}
Node* get_link(Node* a) {
	if(a->suf) return a->suf;
	if(a == root) {
		a->suf = root;
		return a->suf;
	}
	if(a->par == root) {
		return root;
	}
	char t = a->c;
	Node* cur = get_link(a->par);
	while(cur != root && !cur->nxt.count(t)) {
		cur = get_link(cur);
	}
	if(cur->nxt.count(t)) {
		cur = cur->nxt[t];
	}
	return a->suf = cur;
}
Node* go(Node* a,char c) {
	Node* cur = a;
	while(cur != root && !cur->nxt.count(c)) {
		cur = get_link(cur);
	}
	if(cur->nxt.count(c)) {
		cur = cur->nxt[c];
	}
	return cur;
}

string s;
ll n;
vector<string> a;
void init() {
	root = new Node('\0',nullptr);
	fi(1, n) {
		add(a[i], i);
	}
}