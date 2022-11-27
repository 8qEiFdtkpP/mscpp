#pragma once
#include <type_traits>

/// <summary>
/// Факториал числа.
/// </summary>
template<unsigned int N>
struct factorial
{
	static const unsigned int value = N * factorial<N - 1>::value;
};

template<>
struct factorial<0>
{
	static const unsigned int value = 1;
};

/// <summary>
/// Биномиальные коэффициенты.
/// </summary>
template<unsigned N, unsigned K>
struct C
{
	static const unsigned value = factorial<N>::value / factorial<K>::value / factorial<N - K>::value;
};

/// <summary>
/// Степенная функция.
/// </summary>
template<int N, typename T>
typename std::enable_if<(N < 0), T>::type meta_pow(T x)
{
	return (1 / meta_pow<-N>(x));
}

template<int N, typename T>
typename std::enable_if<(N == 0), T>::type meta_pow(T x)
{
	return (1);
}

template<int N, typename T>
typename std::enable_if<(N == 1), T>::type meta_pow(T x)
{
	return (x);
}

template<int N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 0), T>::type meta_pow(T x)
{
	T p = meta_pow<N / 2>(x);
	return (p * p);
}

template<int N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 1) && (N != 1), T>::type meta_pow(T x)
{
	return (meta_pow<N - 1>(x) * x);
}

/// <summary>
/// Число, обратное к интегралу по двумерному симплексу от одночлена вида x^alpha * y ^beta.
/// </summary>
template<unsigned int alpha, unsigned int beta>
struct monomial_2d
{
	static const unsigned int value = factorial<alpha + beta + 2>::value / (factorial<alpha>::value * factorial<beta>::value);
};

/// <summary>
/// Цикл времени компиляции.
/// </summary>
template<unsigned N, unsigned I, class Closure>
typename std::enable_if<(I == N)>::type meta_loop0(Closure& closure)
{

}

template<unsigned N, unsigned I, class Closure>
typename std::enable_if<(I < N)>::type meta_loop0(Closure& closure)
{
	closure.template apply<I>();
	meta_loop0<N, I + 1>(closure);
}

template <unsigned N, class Closure>
void meta_loop(Closure& closure)
{
	meta_loop0<N, 0>(closure);
}

/// <summary>
/// Вычисление ряда указанной длины.
/// </summary>
template<class Closure>
struct abstract_sum_closure
{
	typedef typename Closure::value_type value_type;

	abstract_sum_closure(Closure& closure) : closure(closure), result(value_type())
	{

	}

	template<unsigned I>
	void apply()
	{
		result += closure.template value<I>();
	}

	Closure& closure;
	value_type result;
};

template <unsigned N, class Closure>
typename Closure::value_type abstract_sum(Closure& closure)
{
	abstract_sum_closure<Closure> my_closure(closure);
	meta_loop<N>(my_closure);
	return my_closure.result;
}

/// <summary>
/// Замыкание бинома и вычисление интеграла.
/// </summary>
template<unsigned N, typename T>
struct binom_closure
{
	typedef T value_type;

	binom_closure(value_type a, value_type b) : a(a), b(b)
	{

	}

	template<unsigned K>
	value_type value() const
	{
		return (C<N, K>::value * meta_pow<K>(a) * meta_pow<N - K>(b) / monomial_2d<K, N - K>::value);
	}

private:
	const value_type a, b;
};

template<unsigned N, typename T>
T binom(T a, T b)
{
	binom_closure<N, T> closure(a, b);
	return abstract_sum<N + 1>(closure);
}