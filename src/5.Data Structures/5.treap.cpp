struct Node {
    ll val;
    ll cnt;
    ll y;
    Node *l;
    Node *r;
};
void upd(Node *a) {
    a->cnt = 1;
    if (a->l)
        a->cnt += a->l->cnt;
    if (a->r)
        a->cnt += a->r->cnt;
}
Node *merge(Node *a, Node *b) {
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