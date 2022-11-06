#pragma once

template<int... I>
struct int_vector {};

template<class IntVector, int i>
struct push_back;

template<int... I, int i>
struct push_back<int_vector<I...>, i> {
	typedef int_vector<I..., i> type;
};

template<class IntVector, int n>
struct at;

template<int i, int... I, int n>
struct at<int_vector<i, I...>, n> : at<int_vector<I...>, n - 1> {};

template<int i, int... I>
struct at<int_vector<i, I...>, 0> : std::integral_constant<int, i> {};

template<unsigned int N>
struct fib_at
{
	static const unsigned int value = fib_at<N - 1>::value + fib_at<N - 2>::value;
};

template<>
struct fib_at<0>
{
	static const unsigned int value = 0;
};

template<>
struct fib_at<1>
{
	static const unsigned int value = 1;
};

template<unsigned int n>
struct fibs
{
	typedef typename push_back<typename fibs<n - 1>::type, fib_at<n>::value>::type type;
};

template<>
struct fibs<-1>
{
	typedef int_vector<> type;
};
