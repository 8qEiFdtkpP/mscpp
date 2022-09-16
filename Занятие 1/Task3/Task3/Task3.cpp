#include <iostream>
#include "sqrt.h"
#include "solve.h"

int main()
{
	double a = 1;
	double b = -16;
	double c = 100;

	double* res = solve(a, b, c);

	if (res == NULL) 
	{
		return 0;
	}

	double x1r = res[0];
	double x1i = res[1];
	double x2r = res[2];
	double x2i = res[3];

	if (x1i == 0 || x2i == 0)
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
