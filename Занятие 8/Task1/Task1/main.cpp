#include <iostream>
#include "metaf.hpp"

int main()
{
	const unsigned N = 2;
	const double a = 2.3, b = 5.2;
	const double bi = binom<N>(a, b);
	std::cout << bi << '\n';
	return(0);
}