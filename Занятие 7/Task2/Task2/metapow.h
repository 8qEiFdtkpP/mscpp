#pragma once
#include <type_traits>

template<int N, typename T>
typename std::enable_if<(N == 0), T>::type meta_pow(T x)
{
	return 1;
}

template<int N, typename T>
typename std::enable_if<(N == 1), T>::type meta_pow(T x)
{
	return x;
}

template<int N, typename T>
typename std::enable_if<(N > 1), T>::type meta_pow(T x)
{
	return meta_pow<N - 1>(x) * x;
}

template <int N, typename T>
typename std::enable_if<(N < 0), T>::type meta_pow(T x)
{
	return 1 / meta_pow<-N>(x);
}