double a = 0, b = 1;
const int n = 100000000;
double s = 0;
double h = (b - a) / n;
fi(0, n) {
	double x = a + h * i;
	s += fun(x) * ((i==0 || i==n) ? 1 : ((i&1)==0) ? 2 :4);
}
s *= h / 3;