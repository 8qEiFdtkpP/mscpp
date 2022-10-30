#include <iostream>
#include "Factorial.h"
#include "Fibonacci.h"
#include "Monomial2d.h"

int main()
{
	// Первые 10 чисел Фибоначчи.
	std::cout << "Fibonacci numbers" << std::endl;
	std::cout << fib_n<0>::value << " ";
	std::cout << fib_n<1>::value << " ";
	std::cout << fib_n<2>::value << " ";
	std::cout << fib_n<3>::value << " ";
	std::cout << fib_n<4>::value << " ";
	std::cout << fib_n<5>::value << " ";
	std::cout << fib_n<6>::value << " ";
	std::cout << fib_n<7>::value << " ";
	std::cout << fib_n<8>::value << " ";
	std::cout << fib_n<9>::value << " ";
	std::cout << fib_n<10>::value << std::endl;

	// Факториал чисел от 0 до 5
	std::cout << "Factorials" << std::endl;
	std::cout << factorial<0>::value << " ";
	std::cout << factorial<1>::value << " ";
	std::cout << factorial<2>::value << " ";
	std::cout << factorial<3>::value << " ";
	std::cout << factorial<4>::value << " ";
	std::cout << factorial<5>::value << std::endl;

	// Интеграл по двумерному симплексу от одночлена вида x^alpha * y^beta.
	const unsigned int alpha = 3;
	const unsigned int beta = 5;

	std::cout << "Integral x^" << alpha << " * y^" << beta << std::endl;
	std::cout << 1. / monomial_2d<alpha, beta>::value << std::endl;

	return 0;
}