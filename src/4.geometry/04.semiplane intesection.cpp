ld area(Point a, Point b, Point c) {
    return (ld)1.0 * ((a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y));
}
bool inside(Point A, Point B, Point C, Point p) {
    if (area(A, B, p) == 0 || area(B, C, p) == 0 || area(A, C, p) == 0)
        return false;
    ld v1 = area(A, B, p);
    ld v2 = area(B, C, p);
    ld v3 = area(A, C, p);
    ld S = area(A, B, C);
    v1 = abs(v1);
    v2 = abs(v2);
    v3 = abs(v3);
    S = abs(S);
    return abs(S - v1 - v2 - v3) <= eps;
}
Point find_bis(Point A, Point B, Point C) {
    auto v = A - B;
    auto v2 = C - B;
    v.norm();
    v2.norm();
    return v + v2;
}
ld get_acos(double x) {
    return acos(max(-1., min(1., x)));
}

Line make_line(Point a, Point b) {
    ll A = round(b.y - a.y);
    ll B = round(a.x - b.x);
    ll C = round(a.y * b.x - a.x * b.y);
    if (A < 0)
    {
        A *= (-1);
        B *= (-1);
        C *= (-1);
    }
    ll g = gcd(A, gcd(abs(B), abs(C)));
    A /= g;
    B /= g;
    C /= g;
    return Line{A, B, C};
}
Point intersect(Line a, Line b) {
    ld d = a.A * b.B - b.A * a.B;
    ld d1 = -a.C * b.B + a.B * b.C;
    ld d2 = -a.A * b.C + a.C * b.A;
    ass(abs(d) > eps);
    Point res = {d1 / d, d2 / d};
    ass(on_line(res, a));
    ass(on_line(res, b));
    return {d1 / d, d2 / d};
}
Point get_ort(Point p, Point p2) {
    return {p2.y - p.y, p.x - p2.x};
}
Point get_ort(Line a) {
    return {a.A, a.B};
}
const ld pi = get_acos(-1.0);
bool good(deque<Rec> &dq) {
    vector<Point> P;
    vector<Rec> v;
    while (sz(dq)) {
        v.pb(dq.back());
        dq.pop_back();
    }
    fi(1, sz(v) - 1) {
        P.pb(intersect(v[i - 1].L, v[i].L));
    }
    P.pb(intersect(v[0].L, v[sz(v) - 1].L));
    ld res = 0;

    P.pb(P[0]);
    ld s = 0, s2 = 0;
    fi(1, sz(P) - 1) {
        s += P[i].y * P[i - 1].x;
        s2 += P[i].x * P[i - 1].y;
    }
    res = abs(s - s2);

    return res > 0 + eps;
}
bool paral(Line a, Line b) {
    return a.A * b.B - a.B * b.A == 0;
}
bool fun(ll T) {
    if (T == 0)
        return true;
    vector<Rec> vec(n + 1);
    set<tuple<ll, ll, ll>> t;
    fi(1, n) {
        Point p = a[i];
        Point p2 = a[go(i, T + 1, n)];
        vec[i] = Rec{make_line(p, p2), Seg{p, p2}, get_ort(p, p2)};
        if (area(p, p2, {p.x + 1'000'000 * vec[i].V.x, p.y + 1'000'000 * vec[i].V.y}) > 0 + eps) {
            vec[i].V = vec[i].V * -1;
        }
        // vec[i].V.norm();
        //  t.ins({vec[i].L.A,vec[i].L.B,vec[i].L.C});
    }
    // ass(sz(t)==n);
    vector<Rec> top, bot;
    fi(1, n) {
        if (vec[i].V.y > 0 + eps || (abs(vec[i].V.y) <= eps && vec[i].V.x > 0 + eps)) {
            bot.pb(vec[i]);
        } else {
            top.pb(vec[i]);
        }
    }
    sort(All(top), [](Rec &a, Rec &b)
         { return area(a.V, b.V, {0, 0}) <= eps; });
    sort(All(bot), [](Rec &a, Rec &b)
         { return area(a.V, b.V, {0, 0}) + eps >= 0; });
    vec = vector<Rec>(1);
    fz(bot) vec.pb(z);
    reverse(All(top));
    fz(top) vec.pb(z);
    deque<Rec> dq;
    dbg(vec);
    fi(1, n) {
        while (sz(dq) >= 2) {
            auto rec = dq.back();
            dq.pop_back();
            auto rec2 = dq.back();
            auto P = intersect(rec.L, rec2.L);
            dbg(P);
            if (area(vec[i].sg.a, vec[i].sg.b, P) <= eps) {
                dq.push_back(rec);
                break;
            } else {
                continue;
            }
        }

        while (sz(dq) >= 2) {
            auto rec = dq.front();
            dq.pop_front();
            auto rec2 = dq.front();
            Point P = intersect(rec.L, rec2.L);
            dbg(P);
            dbg(area(vec[i].sg.a, vec[i].sg.b, P));
            if (area(vec[i].sg.a, vec[i].sg.b, P) <= eps) {
                dq.push_front(rec);
                break;
            } else {
                continue;
            }
        }
        dq.pb(vec[i]);
    }

    while (sz(dq) >= 3) {
        auto rec = dq.front();
        dq.pop_front();
        auto rec2 = dq.front();
        auto P = intersect(rec.L, rec2.L);
        dbg(P);
        if (area(dq.back().sg.a, dq.back().sg.b, P) <= eps) {
            dq.push_front(rec);
            break;
        } else {
            continue;
        }
    }

    while (sz(dq) >= 3) {
        auto rec = dq.back();
        dq.pop_back();
        auto rec2 = dq.back();
        auto P = intersect(rec.L, rec2.L);
        dbg(P);
        if (area(dq.front().sg.a, dq.front().sg.b, P) <= eps) {
            dq.push_back(rec);
            break;
        } else {
            continue;
        }
    }

    dbg(T);
    dbg(sz(dq));

    return sz(dq) > 2;
}