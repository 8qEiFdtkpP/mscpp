#include <iostream>
#include "factorial.h"
#include "metapow.h"
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	const int N1 = 3;

	double left1 = factorial<N1>::value / sqrt(2 * M_PI * N1);
	double right1 = meta_pow<N1>(N1) * meta_pow<-N1, double>(M_E);

	std::cout << "difference between "
		<< left1 << " and " 
		<< right1 << " is " 
		<< abs(left1 - right1) << std::endl;


	const int N2 = 9;

	double left2 = factorial<N2>::value / sqrt(2 * M_PI * N2);
	double right2 = meta_pow<N2>(N2) * meta_pow<-N2, double>(M_E);

	std::cout << "difference between "
		<< left2 << " and "
		<< right2 << " is "
		<< abs(left2 - right2) << std::endl;

	return 0;
}