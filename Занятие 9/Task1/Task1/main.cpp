#include "Expressions.h"

int main(int argc, char* argv[])
{
	Variable x;
	std::cout << "x + x + 5 = " << (x + x + 5)(5) << " (when x = 5)" << std::endl; // x + x + 5 = 15 (when x = 5)
	std::cout << typeid((x + x + 5)).name() << std::endl << std::endl; // class BinaryExpression<class BinaryExpression<class Variable,struct std::plus<double>,class Variable>,struct std::plus<double>,class Constant>

	std::cout << "x * (x + x * x / x) = " << (x * (x + x * x / x))(100) << " (when x = 100)" << std::endl; // x * (x + x * x / x) = 20000 (when x = 100)
	std::cout << typeid(x * (x + x * x / x)).name() << std::endl << std::endl; // x * (x + x * x / x) = 20000 (when x = 100)

	std::cout << "sin(x + x) = " << (sin(x + x))(3.1415) << " (when x = 3.1415)" << std::endl; // sin(x + x) = -0.000185307 (when x = 3.1415)
	std::cout << typeid(sin(x + x)).name() << std::endl << std::endl; // struct FuncExpression<class BinaryExpression<class Variable,struct std::plus<double>,class Variable> >

	std::cout << "sqrt(x*x) = " << (sqrt(x * x))(5.55) << " when (x = 5.55)" << std::endl; // sqrt(x*x) = 5.55 when (x = 5.55)
	std::cout << typeid(sqrt(x * x)).name() << std::endl << std::endl; // struct FuncExpression<class BinaryExpression<class Variable,struct std::multiplies<double>,class Variable> >

	std::cout << "x + x * sin(x / 5) / (sqrt(5 * x) + cos(x + 5 * x)) = " << (x + x * sin(x / 5) / (sqrt(5 * x) + cos(x + 5 * x)))(5) << " (when x = 5)" << std::endl; // x + x * sin(x / 5) / (sqrt(5 * x) + cos(x + 5 * x)) = 5.81629 (when x = 5)
	std::cout << typeid(x + x * sin(x / 5) / (sqrt(5 * x) + cos(x + 5 * x))).name() << std::endl << std::endl; // class BinaryExpression<class Variable,struct std::plus<double>,class BinaryExpression<class BinaryExpression<class Variable,struct std::multiplies<double>,struct FuncExpression<class BinaryExpression<class Variable,struct std::divides<double>,class Constant> > >,struct std::divides<double>,class BinaryExpression<struct FuncExpression<class BinaryExpression<class Constant,struct std::multiplies<double>,class Variable> >,struct std::plus<double>,struct FuncExpression<class BinaryExpression<class Variable,struct std::plus<double>,class BinaryExpression<class Constant,struct std::multiplies<double>,class Variable> > > > > >

	return 0;
}