#include <iostream>
#include "sqrt.h"
#include "solve.h"

int main(int argc, char* argv[4])
{
	const char* aStr = argv[1];
	const char* bStr = argv[2];
	const char* cStr = argv[3];

	double a = (aStr == NULL || strlen(aStr) < 1) ? 0 : std::atof(aStr);
	double b = (bStr == NULL || strlen(bStr) < 1) ? 0 : std::atof(bStr);
	double c = (cStr == NULL || strlen(cStr) < 1) ? 0 : std::atof(cStr);

	std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

	double* res = solve(a, b, c);

	if (res == NULL)
	{
		return 0;
	}

	double x1r = res[0];
	double x1i = res[1];
	double x2r = res[2];
	double x2i = res[3];

	if (x1i == 0 && x2i == 0)
	{
		if (x1r != x2r)
		{
			std::cout << "x1 = " << x1r << std::endl
				<< "x2 = " << x2r << std::endl;
		}

		else
		{
			std::cout << "x1 = x2 = " << x1r << std::endl;
		}
	}

	else
	{
		std::cout << "x1 = " << x1r << " + (" << x1i << "i)" << std::endl
			<< "x2 = " << x2r << " - (" << x2i << "i)" << std::endl;
	}
}
