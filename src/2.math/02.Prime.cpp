ll fun1(ll a, ll n) {
	ll t = n - 1;
	int q = 0;
	while(t % 2 == 0) {
		q++;
		t /= 2;
	}
	ll v = pown(a, t, n);
	fi(1, q) {
		ll w = mult(v, v, n);
		if(v != 1 && v != n -1 && w == 1)return true;
		v = w;
	}
	if(v > 1)return true;
	return false;
}

bool is_prime(ll n) {
	if(n < 2)return false;
	if(n == 2)return true;
	if(n % 2 == 0)return false;
	fi(1, 10) {
		ll a = next(1, n - 1);
		if(fun1(a, n))return false;
	}
	return true;
}