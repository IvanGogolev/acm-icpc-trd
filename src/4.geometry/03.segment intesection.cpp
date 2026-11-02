optional<Point> intersect(Seg s1, Seg s2) {
    if (fabs(cross(s1.to_vec(), s2.to_vec())) < eps) {
        return {};
    }
    double t1 = cross((s2.a - s1.a), s2.to_vec()) / cross(s1.to_vec(), s2.to_vec());
    double t2 = cross((s1.a - s2.a), s1.to_vec()) / cross(s2.to_vec(), s1.to_vec());
    if (t1 < -eps || t1 > 1 + eps) {
        return {};
    }
    if (t2 < -eps || t2 > 1 + eps) {
        return {};
    }
    return s1.a + (s1.b - s1.a) * t1;
}