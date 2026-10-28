struct Long {
    int base = 10000;
    int len = 4;
    vi num = {1, 0};
    int operator[](int x) const {
        if (x > num[0]) return 0;
        return num[x];
    }
    int& operator[](int x) {
        if (x > num[0]) {
            num.resize(x + 1, 0);
            num[0] = x;
        }
        return num[x];
    }
};
Long operator+(const Long& A, const Long& B) {
    Long res;

    int n = max(A[0], B[0]);
    fi(1, n) {
        res[i] = A[i] + B[i];
        if (i > 1) {
            res[i] += res[i - 1] / res.base;
            res[i - 1] %= res.base;
        }
    }
    while(res[res[0]] >= res.base) {
        int m = res[0];
        res[m + 1] = res[m] / res.base;
        res[m] %= res.base;
    }
    return res;
}
Long operator*(const Long& A, const int& B) {
    Long res;
    int n = A[0];
    fi(1, n) {
        res[i] = A[i] * B;
        if (i > 1) {
            res[i] += res[i - 1] / res.base;
            res[i - 1] %= res.base;
        }
    }
    while(res[res[0]] >= res.base) {
        int m = res[0];
        res[m + 1] = res[m] / res.base;
        res[m] %= res.base;
    }
    return res;
}
Long operator*(const Long& A, const Long& B) {
    Long res;
    fi(1, A[0]) {
        if (A[i] == 0) continue;
        fj(1, B[0]) {
            if (A[i] * B[j] == 0) continue;
            int x = i + j - 1;
            res[x] += A[i] * B[j];
            while(x > 1 && res[x - 1] >= res.base) {
                res[x] += res[x - 1] / res.base;
                res[x - 1] %= res.base;
            }
        }
        while(res[res[0]] >= res.base) {
            int m = res[0];
            res[m + 1] += res[m] / res.base;
            res[m] %= res.base;
        }
    }
    return res;
}
pair<Long, int> operator/(const Long& A, const int B) {
    Long res;
    ll x = 1;
    ll d = 0, m = 0;
    fdi(A[0], 1) {
        ll val = m * res.base + A[i];
        d = val / B;
        m = val % B;
        if (x == 1 && d == 0) continue;
        res[x] = d;
        x++;
    }
    reverse(Allf(res.num));
    return mp(res, m);
}
void print(const Long& A) {
    printf("%d", A[A[0]]);
    fdi(A[0] - 1, 1) {
        printf("%04d", A[i]);
    }
    printf(ln);
}
Long str_to_Long(const string& s) {
    int n = sz(s);
    Long res;
    int x = 1;
    for(int i = n - 1; i >= 0; i -= 4) {
        int val = 0;
        for(int j = max(0, i - 3); j <= i; j++) {
            val = val * 10 + (s[j] - '0');
        }
        res[x] = val;
        x++;
    }
    return res;
}
Long int_to_Long(int num) {
    Long res;
    int x = 1;
    while(num) {
        int val = num % res.base;
        num /= res.base;
        res[x] = val;
        x++;
    }
    return res;
}