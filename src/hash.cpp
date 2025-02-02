
#include "trlang.h"


#define A 54059
#define B 76963
#define C 86969
#define FIRSTH 37


unsigned int hash(TypeObject &to) {

	unsigned h = FIRSTH;

	switch (to.getType()) {

		case 2: 

			const char *s = ((StrType*)to.getObject()) -> getValue();

			while (*s) {
				h = (h * A) ^ (s[0] * B);
				s++;
			}

		break;
	}
	
	return h;
}