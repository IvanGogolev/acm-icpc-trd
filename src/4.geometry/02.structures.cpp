const ld eps = 1e-6;
struct Point {
    ld x;
    ld y;
    Point operator+(Point B) {
        return Point{x + B.x, y + B.y};
    }
    Point operator-(Point B) {
        return Point{x - B.x, y - B.y};
    }
    Point operator*(double t) {
        return Point{x * t, y * t};
    }
    bool operator==(Point B) {
        return abs(x - B.x) <= eps && abs(y - B.y)<=eps;
    }
    Point norm() {
        ld U = sqrt(x * x + y * y);
        return Point{x / U, y / U};
    }
    ld len() {
        return sqrt(x * x + y * y);
    }
};

struct Line{
  ll A;
  ll B;
  ll C;
};

struct Rec{
  Line L;
  Seg sg;
  Point V;
};

struct Seg {
    Point a;
    Point b;
    Point to_vec() {
        return Point{b.x - a.x, b.y - a.y};
    }
};
ld dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}
ld dot(Point p1, Point p2, Point p3) {
    return dot(p2 - p1, p3 - p1);
}
ld cross(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}
ld cross(Point p1, Point p2, Point p3) {
    return cross(p2 - p1, p3 - p1);
}