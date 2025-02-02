
#ifndef _TRLANG_H_
#define _TRLANG_H_


#include <iostream>
#include <vector>
#include <stdlib.h>


class FloatType;
class TypeObject;


class IntType{
    private:
        long int value;
    public:
        IntType(long int val) : value(val) {};
        IntType(FloatType &ft);

        long int getValue(){return value;}

        IntType &operator+(IntType t);
        FloatType &operator+(FloatType t);

        IntType &operator-(IntType t);
        FloatType &operator-(FloatType t);

        IntType &operator*(IntType t);
        FloatType &operator*(FloatType t);

        FloatType &operator/(IntType t);
        FloatType &operator/(FloatType t);

        bool operator==(IntType t);
        bool operator==(FloatType t);

        bool operator>(IntType t);
        bool operator>(FloatType t);

        bool operator<(IntType t);
        bool operator<(FloatType t);

        bool operator>=(IntType t);
        bool operator>=(FloatType t);

        bool operator<=(IntType t);
        bool operator<=(FloatType t);
};

class FloatType{
    private:
        long double value;

    public:
        FloatType(long double val) : value(val) {};
        FloatType(IntType &it);

        long double getValue(){return value;}

        FloatType &operator+(IntType t);
        FloatType &operator+(FloatType t);

        FloatType &operator-(IntType t);
        FloatType &operator-(FloatType t);

        FloatType &operator*(IntType t);
        FloatType &operator*(FloatType t);

        FloatType &operator/(IntType t);
        FloatType &operator/(FloatType t);

        bool operator==(IntType t);
        bool operator==(FloatType t);

        bool operator>(IntType t);
        bool operator>(FloatType t);

        bool operator<(IntType t);
        bool operator<(FloatType t);

        bool operator>=(IntType t);
        bool operator>=(FloatType t);

        bool operator<=(IntType t);
        bool operator<=(FloatType t);
};

class StrType{

    private:
        char *holder;
        size_t size;

    public:

        StrType(int ns);
        StrType(const char* rstr);
        StrType(char* rstr);
        StrType(char chr);
        StrType(const StrType &st);

        ~StrType() {delete holder;}

        size_t getSize() {return size;}
        char *getValue() {return holder;}

        StrType &operator+(const StrType &st);

        bool operator==(const StrType &t);
        bool operator>(const StrType &t);
        bool operator<(const StrType &t);
        bool operator>=(const StrType &t);
        bool operator<=(const StrType &t);

        StrType &operator[](int index);
        StrType &slice(int s, int e, int step);
};

class ListType {

    private:
        std::vector<TypeObject*> *container; 
        size_t length;

    public:
        ListType() {container = new std::vector<TypeObject*>;length = 0;}
        ListType(size_t init_len) {
            container = new std::vector<TypeObject*>(init_len, 0);
            length = init_len;
        }

        ListType(const ListType &lt);
        ~ListType();

        size_t getSize() {return length;}
        std::vector<TypeObject*> *getValue() {return container;}

        ListType &operator+(const ListType &lt);
        TypeObject &operator[](int index);
        ListType &slice(int s, int e, int step);

        void add_back(TypeObject &to);
        void add_front(TypeObject &to);

        ListType &sorted(bool reversed);
        ListType &reversed();
};


class SingleLinkedNode {


    private:
        unsigned key;
        TypeObject *datum; 
        SingleLinkedNode *next;

    public:
        SingleLinkedNode();
        SingleLinkedNode(TypeObject &to);
        SingleLinkedNode(const SingleLinkedNode &sn);

        ~SingleLinkedNode();

        void insertNode(TypeObject &to);
        TypeObject *searchNode(TypeObject &to);
};




class MapType {

    private:
        SingleLinkedNode *node_arr;
        size_t size;

    public:
        MapType (size_t size_);
        SingleLinkedNode &operator[](TypeObject &to);
};


class TypeObject {


    private:   
        void *holder;
        int type;
        int hash;

    public:
        TypeObject() {};
        TypeObject(const IntType *t);
        TypeObject(const FloatType *t);
        TypeObject(const StrType *t);
        TypeObject(const ListType *t);
        TypeObject(const MapType *t);

        TypeObject(const TypeObject &to);
        ~TypeObject();

        void operator=(IntType *t);
        void operator=(FloatType *t);
        void operator=(StrType *t);
        void operator=(ListType *t);
        void operator=(MapType *t);
        void operator=(TypeObject &to);

        void deleteType();

        TypeObject &operator+(const TypeObject &t);
        TypeObject &operator-(const TypeObject &t);
        TypeObject &operator*(const TypeObject &t);
        TypeObject &operator/(const TypeObject &t);

        bool operator==(const TypeObject &t);
        bool operator<(const TypeObject &t);
        bool operator>(const TypeObject &t);
        bool operator<=(const TypeObject &t);
        bool operator>=(const TypeObject &t);

        TypeObject &operator[](int index);
        TypeObject &operator%(const TypeObject &to);

        void *getObject() {return holder;}
        int getType() {return type;}
        int getID() {return hash;}

        friend void printType(const TypeObject &tr);
};

void printType(const TypeObject &tr);

void addbackListType(TypeObject &tm, TypeObject &ts); 
void addfrontListType(TypeObject &tm, TypeObject &ts); 

IntType imod(IntType i1, IntType i2);
FloatType fmod(FloatType f1, FloatType f2);

unsigned int hash(TypeObject &to);

#endif