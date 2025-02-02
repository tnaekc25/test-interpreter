
#include "trlang.h"


/*CONSTRUCTOR*/
TypeObject::TypeObject(const IntType *t) {
    holder = (void*)t;
    type = 0;
}

TypeObject::TypeObject(const FloatType *t) {
    holder = (void*)t;
    type = 1;
}

TypeObject::TypeObject(const StrType *t) {
    holder = (void*)t;
    type = 2;
}

TypeObject::TypeObject(const ListType *t) {
    holder = (void*)t;
    type = 3;
}

TypeObject::TypeObject(const MapType *t) {
    holder = (void*)t;
    type = 4;
}

/*COPY CONSTRUCTOR*/
TypeObject::TypeObject(const TypeObject &to) {
    
    type = to.type;
    hash = to.hash;

    switch (type) {

        case 0:
            holder = (void*)new IntType(*(IntType*)to.holder);
        break;

        case 1:
            holder = (void*)new FloatType(*(FloatType*)to.holder);
        break;

        case 2:
            holder = (void*)new StrType(*(StrType*)to.holder);
        break;

        case 3:
            holder = (void*)new ListType(*(ListType*)to.holder);
        break;

        case 4:
            holder = (void*)new MapType(*(MapType*)to.holder);
        break;

    }
}


/*---*/
void TypeObject::deleteType() {
    switch (type) {

        case 0:
            delete (IntType*)holder;
        break;

        case 1:
            delete (FloatType*)holder;
        break;

        case 2:
            delete (StrType*)holder;
        break;

        case 3:
            delete (ListType*)holder;
        break;

        case 4:
            delete (MapType*)holder;
        break;
    }
}


/*DESTRUCTOR*/
TypeObject::~TypeObject() {
    deleteType(); 
}


/*ASSIGNMENT*/
void TypeObject::operator=(IntType *t){
    deleteType();

    type = 0;
    holder = (void*)t;
}

void TypeObject::operator=(FloatType *t){
    deleteType();

    type = 1;
    holder = (void*)t;
}

void TypeObject::operator=(StrType *t){
    deleteType();

    type = 2;
    holder = (void*)t;
}

void TypeObject::operator=(ListType *t){
    deleteType();

    type = 3;
    holder = (void*)t;
}

void TypeObject::operator=(MapType *t){
    deleteType();

    type = 4;
    holder = (void*)t;
}


void TypeObject::operator=(TypeObject &to){

    deleteType();

    type = to.getType();
    hash = to.getID();

    switch (type) {

        case 0:
            holder = (void*)new IntType(*(IntType*)to.holder);
        break;

        case 1:
            holder = (void*)new FloatType(*(FloatType*)to.holder);
        break;

        case 2:
            holder = (void*)new StrType(*(StrType*)to.holder);
        break;

        case 3:
            holder = (void*)new ListType(*(ListType*)to.holder);
        break;

        case 4:
            holder = (void*)new MapType(*(MapType*)to.holder);
        break;
    }
}