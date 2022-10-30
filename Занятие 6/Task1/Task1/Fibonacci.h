#pragma once

/// <summary>
/// N-ое число Фибоначчи.
/// </summary>
template<unsigned int N>
struct fib_n
{
	static const unsigned int value = fib_n<N - 1>::value + fib_n<N - 2>::value;
};

template<>
struct fib_n<0>
{
	static const unsigned int value = 0;
};

template<>
struct fib_n<1>
{
	static const unsigned int value = 1;
};