#include <iostream>
#include "metafibs.h"

int main()
{
	typedef fibs<5>::type f5;
	static_assert(fib_at<5>::value == 5, "f_at5 == 5");
	static_assert(at<f5, 5>::value == 5, "f5 == 5");

	typedef fibs<19>::type f20;
	f20 = 5;
}