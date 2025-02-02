#include "trlang.h"



TypeObject &TypeObject::operator+(const TypeObject &t) {

    TypeObject *nt = new TypeObject;


    if (type == 0 && t.type == 0) {
        *nt = &(*(IntType*)holder + *(IntType*)t.holder);
        nt -> type = 0;
    }

    else if (type == 0 && t.type == 1) {
        *nt = &(*(IntType*)holder + *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 0) {
        *nt = &(*(FloatType*)holder + *(IntType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 1) {
        *nt = &(*(FloatType*)holder + *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 2 && t.type == 2)
        *nt = &(*(StrType*)holder + *(StrType*)t.holder);

    else if (type == 3 && t.type == 3)
        *nt = &(*(ListType*)holder + *(ListType*)t.holder);

    else
        throw "excpt";

    return *nt;
}


TypeObject &TypeObject::operator-(const TypeObject &t) {

    TypeObject *nt = new TypeObject;


    if (type == 0 && t.type == 0) {
        *nt = &(*(IntType*)holder - *(IntType*)t.holder);
        nt -> type = 0;
    }

    else if (type == 0 && t.type == 1) {
        *nt = &(*(IntType*)holder - *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 0) {
        *nt = &(*(FloatType*)holder - *(IntType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 1) {
        *nt = &(*(FloatType*)holder - *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else
        throw "excpt";

    return *nt;
}


TypeObject &TypeObject::operator*(const TypeObject &t) {

    TypeObject *nt = new TypeObject;


    if (type == 0 && t.type == 0) {
        *nt = &(*(IntType*)holder * *(IntType*)t.holder);
        nt -> type = 0;
    }

    else if (type == 0 && t.type == 1) {
        *nt = &(*(IntType*)holder * *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 0) {
        *nt = &(*(FloatType*)holder * *(IntType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 1) {
        *nt = &(*(FloatType*)holder * *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else
        throw "excpt";

    return *nt;
}


TypeObject &TypeObject::operator/(const TypeObject &t) {

    TypeObject *nt = new TypeObject;


    if (type == 0 && t.type == 0) {
        *nt = &(*(IntType*)holder / *(IntType*)t.holder);
        nt -> type = 1;
    }

    else if (type == 0 && t.type == 1) {
        *nt = &(*(IntType*)holder / *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 0) {
        *nt = &(*(FloatType*)holder / *(IntType*)t.holder);
    	nt -> type = 1;
    }

    else if (type == 1 && t.type == 1) {
        *nt = &(*(FloatType*)holder / *(FloatType*)t.holder);
    	nt -> type = 1;
    }

    else
        throw "excpt";

    return *nt;
}






bool TypeObject::operator==(const TypeObject &t) {

    bool retval;

    if (type == 0 && t.type == 0) 
        retval = (*(IntType*)holder == *(IntType*)t.holder);

    else if (type == 0 && t.type == 1) 
        retval = (*(IntType*)holder == *(FloatType*)t.holder);

    else if (type == 1 && t.type == 0)
        retval = (*(FloatType*)holder == *(IntType*)t.holder);

    else if (type == 1 && t.type == 1)
        retval = (*(FloatType*)holder == *(FloatType*)t.holder);

    else if (type == 2 && t.type == 2)
        retval = (*(StrType*)holder == *(StrType*)t.holder);

    else
        throw "excpt";

    return retval;
}


bool TypeObject::operator<(const TypeObject &t) {

    bool retval;

    if (type == 0 && t.type == 0) 
        retval = (*(IntType*)holder < *(IntType*)t.holder);

    else if (type == 0 && t.type == 1) 
        retval = (*(IntType*)holder < *(FloatType*)t.holder);

    else if (type == 1 && t.type == 0)
        retval = (*(FloatType*)holder < *(IntType*)t.holder);

    else if (type == 1 && t.type == 1)
        retval = (*(FloatType*)holder < *(FloatType*)t.holder);

    else if (type == 2 && t.type == 2)
        retval = (*(StrType*)holder < *(StrType*)t.holder);

    else
        throw "excpt";

    return retval;
}


bool TypeObject::operator>(const TypeObject &t) {

    bool retval;

    if (type == 0 && t.type == 0) 
        retval = (*(IntType*)holder > *(IntType*)t.holder);

    else if (type == 0 && t.type == 1) 
        retval = (*(IntType*)holder > *(FloatType*)t.holder);

    else if (type == 1 && t.type == 0)
        retval = (*(FloatType*)holder > *(IntType*)t.holder);

    else if (type == 1 && t.type == 1)
        retval = (*(FloatType*)holder > *(FloatType*)t.holder);

    else if (type == 2 && t.type == 2)
        retval = (*(StrType*)holder > *(StrType*)t.holder);

    else
        throw "excpt";

    return retval;
}


bool TypeObject::operator>=(const TypeObject &t) {

    bool retval;

    if (type == 0 && t.type == 0) 
        retval = (*(IntType*)holder >= *(IntType*)t.holder);

    else if (type == 0 && t.type == 1) 
        retval = (*(IntType*)holder >= *(FloatType*)t.holder);

    else if (type == 1 && t.type == 0)
        retval = (*(FloatType*)holder >= *(IntType*)t.holder);

    else if (type == 1 && t.type == 1)
        retval = (*(FloatType*)holder >= *(FloatType*)t.holder);

    else if (type == 2 && t.type == 2)
        retval = (*(StrType*)holder >= *(StrType*)t.holder);

    else
        throw "excpt";

    return retval;
}


bool TypeObject::operator<=(const TypeObject &t) {

    bool retval;

    if (type == 0 && t.type == 0) 
        retval = (*(IntType*)holder <= *(IntType*)t.holder);

    else if (type == 0 && t.type == 1) 
        retval = (*(IntType*)holder <= *(FloatType*)t.holder);

    else if (type == 1 && t.type == 0)
        retval = (*(FloatType*)holder <= *(IntType*)t.holder);

    else if (type == 1 && t.type == 1)
        retval = (*(FloatType*)holder <= *(FloatType*)t.holder);

    else if (type == 2 && t.type == 2)
        retval = (*(StrType*)holder <= *(StrType*)t.holder);

    else
        throw "excpt";

    return retval;
}



TypeObject &TypeObject::operator[](int index) {

    switch (type) {

        case 2:
            return *new TypeObject(&((*((StrType*)holder))[index]));
        break;
        case 3:
            return (*(ListType*)holder)[index];
        break;
        default:
            throw "excpt";
        break;
    }
}


TypeObject &TypeObject::operator%(const TypeObject &to) {

    if (type == 0 && to.type == 0)
        return *new TypeObject(new IntType(imod(*(IntType*)holder,
         *(IntType*)to.holder)));

    if (type == 0 && to.type == 1)
        return *new TypeObject(new FloatType(fmod(*(IntType*)holder,
         *(FloatType*)to.holder)));

    if (type == 1 && to.type == 0)
        return *new TypeObject(new FloatType(fmod(*(FloatType*)holder,
         *(IntType*)to.holder)));

    if (type == 1 && to.type == 1)
        return *new TypeObject(new FloatType(fmod(*(FloatType*)holder,
         *(FloatType*)to.holder)));

    throw "excp";

}