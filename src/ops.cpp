#include "trlang.h"


IntType &IntType::operator+(IntType t) {
	return *(new IntType(value + t.getValue()));
}

FloatType &IntType::operator+(FloatType t) {
	return *(new FloatType(value + t.getValue()));
}

FloatType &FloatType::operator+(IntType t) {
	return *(new FloatType(value + t.getValue()));
}

FloatType &FloatType::operator+(FloatType t) {
	return *(new FloatType(value + t.getValue()));
}


/*----*/
IntType &IntType::operator-(IntType t) {
	return *(new IntType(value - t.getValue()));
}

FloatType &IntType::operator-(FloatType t) {
	return *(new FloatType(value - t.getValue()));
}

FloatType &FloatType::operator-(IntType t) {
	return *(new FloatType(value - t.getValue()));
}

FloatType &FloatType::operator-(FloatType t) {
	return *(new FloatType(value - t.getValue()));
}


/*----*/
IntType &IntType::operator*(IntType t) {
	return *(new IntType(value * t.getValue()));
}

FloatType &IntType::operator*(FloatType t) {
	return *(new FloatType(value * t.getValue()));
}

FloatType &FloatType::operator*(IntType t) {
	return *(new FloatType(value * t.getValue()));
}

FloatType &FloatType::operator*(FloatType t) {
	return *(new FloatType(value * t.getValue()));
}

/*----*/
FloatType &IntType::operator/(IntType t) {

	if (t.getValue() != 0)
		return *(new FloatType(((long double)value) / t.getValue()));
	else
		throw "zerodiv";
}

FloatType &IntType::operator/(FloatType t) {
	if (t.getValue() != 0)
		return *(new FloatType(value / t.getValue()));
	else
		throw "zerodiv";
}

FloatType &FloatType::operator/(IntType t) {
	if (t.getValue() != 0)
		return *(new FloatType(value / t.getValue()));
	else
		throw "zerodiv";
}

FloatType &FloatType::operator/(FloatType t) {
	if (t.getValue() != 0)
		return *(new FloatType(value / t.getValue()));
	else
		throw "zerodiv";
}


IntType::IntType(FloatType &ft) {value = ft.getValue();}
FloatType::FloatType(IntType &it) {value = it.getValue();}



/*LOGICAL OPERATORS*/

bool IntType::operator==(IntType t) {
	return value == t.value;
}
bool IntType::operator==(FloatType t) {
	return (long double)value == t.getValue();
}

bool FloatType::operator==(FloatType t) {
	return value == t.value;
}
bool FloatType::operator==(IntType t) {
	return value == (long double)t.getValue();
}

bool StrType::operator==(const StrType &t) {

	if (size != t.size)
		return false;

	for (size_t i = 0;i < size;i++)
		if (holder[i] != t.holder[i])
			return false;

	return true;
}

/*---*/

bool IntType::operator<(IntType t) {
	return value < t.value;
}
bool IntType::operator<(FloatType t) {
	return (long double)value < t.getValue();
}

bool FloatType::operator<(FloatType t) {
	return value < t.value;
}
bool FloatType::operator<(IntType t) {
	return value < (long double)t.getValue();
}

bool StrType::operator<(const StrType &t) {

	size_t refsize = (size < t.size) ? size : t.size;

	for (size_t i = 0;i < refsize;i++)
		if (holder[i] != t.holder[i])
			return holder[i] < t.holder[i];

	return size < t.size;
}


bool IntType::operator>(IntType t) {
	return !(*this < t or *this == t);
}
bool IntType::operator>(FloatType t) {
	return !(*this < t or *this == t);
}
bool FloatType::operator>(FloatType t) {
	return !(*this < t or *this == t);
}
bool FloatType::operator>(IntType t) {
	return !(*this < t or *this == t);
}
bool StrType::operator>(const StrType &t) {
	return !(*this < t or *this == t);
}


bool IntType::operator>=(IntType t) {
	return *this > t or *this == t;
}
bool IntType::operator>=(FloatType t) {
	return *this > t or *this == t;
}
bool FloatType::operator>=(FloatType t) {
	return *this > t or *this == t;
}
bool FloatType::operator>=(IntType t) {
	return *this > t or *this == t;
}
bool StrType::operator>=(const StrType &t) {
	return *this > t or *this == t;
}


bool IntType::operator<=(IntType t) {
	return *this < t or *this == t;
}
bool IntType::operator<=(FloatType t) {
	return *this < t or *this == t;
}
bool FloatType::operator<=(FloatType t) {
	return *this < t or *this == t;
}
bool FloatType::operator<=(IntType t) {
	return *this < t or *this == t;
}
bool StrType::operator<=(const StrType &t) {
	return *this < t or *this == t;
}


IntType imod(IntType i1, IntType i2) {
	return *new IntType(i1.getValue() % i2.getValue());
}

FloatType fmod(FloatType f1, FloatType f2) {

	long double v1 = f1.getValue(), v2 = f2.getValue();

	while(v1 >= v2) v1-=v2;

	return *new FloatType(v1);
}