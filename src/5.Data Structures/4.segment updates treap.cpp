const ll E = 0;

struct Node {
    ll val;
    ll buf;
    ll min_val;
    ll cnt;
    ll y;
    Node *l;
    Node *r;
};

void push(Node* a) {
	if(!a) return;
	if(a->buf == E) return;
    a->val += a->buf;
    a->min_val += a->buf;
    
    if(a->l) {
		a->l->buf += a->buf;
	//	a->l->min_val += a->buf;
	}	
	if(a->r) {
		a->r->buf += a->buf;
	//	a->r->min_val += a->buf;
	}
	a->buf = E;
}
void upd(Node *a) {
    a->cnt = 1;
    a->min_val = a->val;
    if (a->l) {
    	a->min_val = min(a->min_val, a->l->min_val + a->l->buf);
        a->cnt += a->l->cnt;
    }
    if (a->r) {
    	a->min_val = min(a->min_val, a->r->min_val + a->r->buf);
        a->cnt += a->r->cnt;
    }
}
Node* new_node(ll val) {
	Node* x = new Node;
	x->y = rnd();
	x->val = val;
	x->buf = E;
	x->cnt = 1;
	x->l = x->r = 0;
	upd(x);	
	return x;
}
Node *merge(Node *a, Node *b) {
    push(a);
    push(b);
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    }
    b->l = merge(a, b->l);
    upd(b);
    return b;
}
pair<Node *, Node *> split(Node *a, ll q) {
    push(a);
    if (!a)
        return {0, 0};
    
    ll left = 0;
    if (a->l)
        left += a->l->cnt;
    if (left >= q) {
        auto [l, r] = split(a->l, q);
        a->l = r;
        upd(a);
        return {l, a};
    }
    auto [l, r] = split(a->r, q - left - 1);
    a->r = l;
    upd(a);
    return {a, r};
}