#pragma once
#include<functional>
#include<iostream>
#include<math.h>

// Базовый класс.
template<class O>
struct MathObjectBase
{
	O& self()
	{
		return static_cast<O&>(*this);
	}

	const O& self() const
	{
		return static_cast<const O&>(*this);
	}
};

// Выражение.
template<class E>
struct Expression : public MathObjectBase<E>
{

};

// Переменная.
class Variable : public Expression<Variable>
{
public:
	double operator()(double x) const
	{
		return x;
	}
};

// Константа.
class Constant : public Expression<Constant>
{
private:
	double value;

public:
	Constant(double value) : value(value)
	{

	}

	double operator()(double x) const
	{
		return value;
	}
};

// Унарный минус.
template<class E>
class Negate : public Expression<Negate<E>>
{
private:
	const E expr;

	Negate<E> operator-(const Expression<E>& expr)
	{
		return Negate<E>(expr);
	}

public:
	Negate(const Expression<E>& expr) : expr(expr.self())
	{

	}

	double operator()(double x) const
	{
		return -expr(x);
	}
};

// Бинарная операция.
template<class E1, class OP, class E2>
class BinaryExpression : public Expression<BinaryExpression<E1, OP, E2>>
{
private:
	const E1 expr1;
	const OP op;
	const E2 expr2;

public:
	BinaryExpression(const Expression<E1>& expr1, const OP& op, const Expression<E2>& expr2) : expr1(expr1.self()), op(op), expr2(expr2.self())
	{

	}

	double operator()(double x) const
	{
		return op(expr1(x), expr2(x));
	}
};

#define DEFINE_BIN_OP(oper, OP) \
	template<class E1, class E2> \
	BinaryExpression<E1, std::OP<double>, E2> operator oper(const Expression<E1> &expr1, const Expression<E2> &expr2) \
	{ \
		return BinaryExpression<E1, std::OP<double>, E2>(expr1, std::OP<double>(), expr2); \
	} \
	template<class E> \
	BinaryExpression<E, std::OP<double>, Constant> operator oper(const Expression<E> &expr, double value) \
	{ \
		return BinaryExpression<E, std::OP<double>, Constant>(expr, std::OP<double>(), Constant(value)); \
	} \
	template<class E> \
	BinaryExpression<Constant, std::OP<double>, E> operator oper(double value, const Expression<E> &expr) \
	{ \
		return BinaryExpression<Constant, std::OP<double>, E>(Constant(value), std::OP<double>(), expr); \
	}

DEFINE_BIN_OP(+, plus);
DEFINE_BIN_OP(-, minus);
DEFINE_BIN_OP(*, multiplies);
DEFINE_BIN_OP(/ , divides);

// Функция.
template<class E>
struct FuncExpression : public Expression<FuncExpression<E>>
{
	typedef double (*func_t)(double);

	FuncExpression(const Expression<E>& expr, func_t func) : expr(expr.self()), func(func)
	{

	}

	double operator()(double x) const
	{
		return func(expr(x));
	}

private:
	const E expr;
	func_t func;
};

#define DEFINE_FUNC(func) \
	template<class E> \
	FuncExpression<E> func(const Expression<E> &expr) \
	{ \
		return FuncExpression<E>(expr, std::func); \
	} 

DEFINE_FUNC(sin);
DEFINE_FUNC(cos);

template<class E>
double sqrt(double x)
{
	union
	{
		int i;
		float x;
	} u;

	u.x = x;
	u.i = (1 << 29) + (u.i >> 1) - (1 << 22);

	u.x = u.x + x / u.x;
	u.x = 0.25f * u.x + x / u.x;

	return u.x;
}

DEFINE_FUNC(sqrt);