
#include "trlang.h"


StrType &StrType::operator+(const StrType &st) {

	size_t nsize = st.size + size;
	char *nstr = new char[nsize + 1];

	for (size_t i = 0;i <= nsize;i++)
		nstr[i] = (i < size) ? holder[i] : st.holder[i - size]; 

	return *new StrType(nstr);
}


StrType &StrType::operator[](int index) {

	if (index < 0 && index+size < size && index+size >= 0)
		return *new StrType(holder[index+size]);
	else if (index < (int)size && index >= 0)
		return *new StrType(holder[index]);
	throw "excpt";
}


StrType &StrType::slice(int s, int e, int step) {

	if (s < 0 && s+size >= 0 && s < (int)size)
		s += size;
	if (e < 0 && e+size >= 0 && e < (int)size)
		e += size;

	if (s < 0 or s >= (int)size)
		throw "excpt";
	if (e < 0 or e >= (int)size)
		throw "excpt";

	int newsz = e-s+1;
	newsz = (newsz % step) ? newsz / step + 1 : newsz / step;

	if (newsz <= 0)
		return *new StrType("");

	StrType &st = *new StrType(newsz);

	for (int i = 0;i < newsz;i++)
		st.holder[i] = holder[s + step*i];

	return st;
}
