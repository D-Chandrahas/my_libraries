#include <mathfunctions.h>
using namespace std;



double factorial (double n) {
	if ((remainder(n,1) != 0) or (n<0)) {return -1;}
	if (n == 0) {return 1;}
	for (int i = n-1; i >= 1; i--){
		n *= i;
	}
	return n;
}

bool isprime (const double &n) {
	for (double i = 2; i <= n/2; i++) {
		if (remainder(n,i) == 0){
			return false;
		}
	}
	if (n == 1) {return false;}
	return true;
}

int factors (const double &n) {
	int factors = 0;
	for (double i = 1; i <= n; i++) {
		if (remainder(n,i) == 0){
			factors += 1;
		}
	}
	return factors;
}