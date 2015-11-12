#include <iostream> // Definition of cin, cout etc.
#include <cmath>     // Definitions for the math floating point package
#include <iomanip>  // Definition of setw, setprecision etc.
using namespace std;

double series( int m, long ic);               // Evaluate the series sum_k ...
double expm( double p, double ak);            // Compute 16^p mod ak
char   ihex( double x);  // Compute hex digits of fraction

// ------- Evaluate the series sum_k 16^(ic-k)/(8*k+m)
double series( int m, long ic) {
//
// This routine evaluates the series sum_k 16^(ic-k)/(8*k+m)
// using the modular exponentiation technique.
//
  const double eps = 1.0e-17;
  double ak, p, s, t;
  long k;

  s = 0.0;
  for (k = 0; k < ic; k++) { // Sum the series up to ic.
    ak = 8 * k + m;
    p = ic - k;
    t = expm(p, ak);
    s += t / ak;
    s -= floor(s);
  }
  p = 16.0;  t = 1.0;
  for (k = ic; t > eps; k++) { // Compute a few terms where k >= ic.
    ak = 8 * k + m;
    p /= 16.0;
    t = p / ak;
    s += t;
    s -= floor(s);
  }
  return s;
} // --end-- series

// ------- Compute 16^p mod ak
double expm( double p, double ak) {
//
// expm = 16^p mod ak.  This routine uses the left-to-right binary
// exponentiation scheme.  It is valid for  ak <= 2^24.
//
  const int ntp = 25;
  double p1, pt, r;
  static double tp[ntp] = { 0.0 }; // tp = power of two table.
  int i;

  if (tp[0] == 0.0) { // If this is the first call, fill the power of two table.
    tp[0] = 1.0;
    for (i = 1; i < ntp; i++)
      tp[i] = 2.0 * tp[i-1];
  }
  if (ak == 1.0)  return 0.0;

  for (i = 0; tp[i] <= p; i++)  ; // Find the greatest power of two <= p.
  pt = tp[i-1];
  p1 = p;
  r = 1.0;

  while (pt >= 1.0) { // Perform binary exponentiation algorithm modulo ak.
    if (p1 >= pt) {
      r = fmod( 16.0 * r, ak);
      p1 -= pt;
    }
    pt *= 0.5;
    if (pt >= 1.0)
      r = fmod(r * r, ak);
  }
  return fmod(r, ak);
} // --end-- expm

// ------- Compute the first few hex digits of the fraction of x
char ihex( double x) {
//
// This returns, in chx, the first nhx hex digits of the fraction of x.
//
  double y;
  const char hx[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  y = fabs(x);
  y = 16.0 * (y - floor(y));
  char chx  = hx[ (int)(y)];
  return chx;
} // --end-- ihex

// ------- main program PiQP
int main( void) {
    int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++) {
		long ic, st = 100000L;
	    double pid, s1, s2, s3, s4;
		scanf("%ld",&st);
		ic = st - 1;
		if (st==0) 
			printf("3");
		if ((st > 0) && (ic <= 16777216L)) {
			s1 = series(1, ic);
			s2 = series(4, ic);
			s3 = series(5, ic);
			s4 = series(6, ic);
			pid = fmod( 4.0 * s1 - 2.0 * s2 - s3 - s4, 1.0);
			if (pid < 0)  pid += 1.0;
			printf("%c", ihex( pid));
		}
	}
  return 0;
} // --end-- main PiQP