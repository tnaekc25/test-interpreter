
#include "trlang.h"



ListType &ListType::operator+(const ListType &lt) {

	size_t new_length = lt.length + length;
	ListType *np = new ListType(new_length);

	for (size_t i = 0;i < new_length;i++)
		(*np -> container)[i] =
		 (i < length) ? (*container)[i] : (*lt.container)[i - length];

	return *np;
}


TypeObject &ListType::operator[](int index) {

	if (index < 0 && index+length < length && index+length >= 0)
		return *((*container)[index+length]);
	else if (index < (int)length && index >= 0)
		return *((*container)[index]);
	throw "excpt";
}


void ListType::add_back(TypeObject &to) {

    if (to.getType() == 3)
        container -> push_back(&to);
    else 
        container -> push_back(new TypeObject(to));
    
    length++;
}

void ListType::add_front(TypeObject &to) {

	container -> push_back((*container)[length-1]);

	TypeObject *temp1, *temp2 = (*container)[0];

	for (size_t i = 0;i < length;i++) {
		temp1 = (*container)[i+1];
		(*container)[i+1] = temp2;
		temp2 = temp1;
	}

    (*container)[0] = new TypeObject(to);
    length++;
}


void addbackListType(TypeObject &tm, TypeObject &ts) {

    if (tm.getType() == 3)
        ((ListType*)tm.getObject()) -> add_back(ts);
}

void addfrontListType(TypeObject &tm, TypeObject &ts) {

    if (tm.getType() == 3)
        ((ListType*)tm.getObject()) -> add_front(ts);
}



ListType &ListType::sorted(bool reversed) {

	int *stack = new int[length*2];
	int ss = 0;

	stack[ss++] = 0;
	stack[ss++] = length - 1;

	ListType &new_lt = *new ListType(*this);


	while (ss) {
		int e = stack[--ss], s = stack[--ss];
		TypeObject *pivot = (*new_lt.container)[s];
		int i = s+1;
		TypeObject *temp;
		int ec = e;

		while(i <= ec) {

			if ((*(*new_lt.container)[i] < *pivot && reversed)
			 || ((*(*new_lt.container)[i] > *pivot) && !reversed)) {
				(*new_lt.container)[i-1] = (*new_lt.container)[i];
				(*new_lt.container)[i++] = pivot;
			}

			else {
				temp = (*new_lt.container)[ec];
				(*new_lt.container)[ec--] = (*new_lt.container)[i];
				(*new_lt.container)[i] = temp;
			}
		}

		if (s < i-1) {
			stack[ss++] = s;
			stack[ss++] = i-1;
		}

		if (i < e) {
			stack[ss++] = i;
			stack[ss++] = e;
		}
	}

	return new_lt;
}


ListType &ListType::reversed() {

	ListType &new_lt = *new ListType(*this);

	TypeObject *temp;

	for (int i = 0;i < (int)length / 2;i++) {
		temp = (*new_lt.container)[i];
		(*new_lt.container)[i] = (*new_lt.container)[length-i-1];
		(*new_lt.container)[length-i-1] = temp;
	}

	return new_lt;
}


ListType &ListType::slice(int s, int e, int step) {

	if (s < 0 && s+length >= 0 && s < (int)length)
		s += length;
	if (e < 0 && e+length >= 0 && e < (int)length)
		e += length;

	if (s < 0 or s >= (int)length)
		throw "excpt";
	if (e < 0 or e >= (int)length)
		throw "excpt";


	int newsz = (e > s) ? e-s+1 : e-s-1;
	newsz = (newsz % step) ? newsz / step + 1 : newsz / step;

	if (newsz <= 0)
		return *new ListType(0);

	ListType &lt = *new ListType(newsz);

	for (int i = 0;i < newsz;i++)
		(*lt.container)[i] = (*container)[s + step*i];

	return lt;
}