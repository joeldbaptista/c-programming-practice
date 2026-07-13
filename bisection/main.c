#include <stdio.h>

#define EPS			1.0e-6
#define MAX_NUM_ITERATIONS	1e4

double
foo(double x)
{
	return x * x - 2;	
}

double 
bisect(double a, double b, double (*f)(double x))
{
	double c, m;
	size_t k = 0;

	 do {
		if (a < b) {
			m = a + (b - a) / 2;
		} else {
			m = b + (a - b) / 2;
		}
		c = f(m);
		if (c * f(b) < 0) {
			a = m;
		} else {
			b = m;
		}
		if (c < 0)
			c = -c;
		++k;
	} while (c >= EPS && k < MAX_NUM_ITERATIONS);
	return m;
}

int
main(void)
{
	double a, b, c;
	double (*f)(double);

	a = 0;
	b = 2;
	f = foo;
	
	if (f(a) * f(b) < 0) {
		c = bisect(a, b, f);
		fprintf(stdout, "sqrt(2.0) ~ %.6f (%.6f^2 = %.6f)\n", c, c, c*c);
		return 0;
	} else {
		fprintf(stderr, "ERROR - Unable to find root between [%.3f, %.3f]", a, b);
		return 1;
	}
	return 0;
}
