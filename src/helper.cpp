
#include "trlang.h"

void printType(const TypeObject &tr) {

    switch (tr.type) {

        case 0:
            std::cout << ((IntType*)tr.holder) -> getValue();
        break;

        case 1:
            std::cout << ((FloatType*)tr.holder) -> getValue();
        break;

        case 2:
            std::cout << '"';
            std::cout << ((StrType*)tr.holder) -> getValue();
            std::cout << '"';
        break;

        case 3:

            ListType *lp = ((ListType*)tr.holder);

            std::cout << "[";

            for (size_t i = 0;i < lp -> getSize();i++) {
                printType(*(*lp -> getValue())[i]);
                
                if (i != lp -> getSize()-1)
                    std::cout << ", ";
            }

            std::cout << "]";
    }
}