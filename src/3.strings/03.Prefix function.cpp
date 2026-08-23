vi prefix_function(string s) {
	int n = sz(s);
	vi pi(n);
	fi(1, n - 1) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
        }
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}