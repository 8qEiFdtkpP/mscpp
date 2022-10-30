#pragma once

/// <summary>
/// Число, обратное к интегралу по двумерному симплексу от одночлена вида x^alpha * y ^beta.
/// </summary>
template <unsigned int alpha, unsigned int beta>
struct monomial_2d
{
	static const unsigned int value = factorial<alpha + beta + 2>::value / (factorial<alpha>::value * factorial<beta>::value);
};