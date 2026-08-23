#define mod 1'000'000'007
int add(int a, int b){
	return (a + b) % mod;
}
int mult(int a, int b){
	return (ll)a * b % mod;
}
int pown(int a, ll n){
	if(n == 0)return 1;
	if(n % 2 == 0){
		int x = pown(a, n / 2);
		return mult(x, x);
	}
	return mult(a, pown(a, n - 1));
}
int obr(int a){
	return pown(a, mod - 2);
}