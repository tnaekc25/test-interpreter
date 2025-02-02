
#include "trlang.h"




StrType::StrType(int ns) {
            
    size = ns;
    holder = new char[ns+1];
    holder[ns] = 0;
}

StrType::StrType(const char* rstr) {
            
    size = 0;
    while(rstr[size])size++;

    holder = new char[size+1];
            
    for(size_t i = 0;i <= size;i++)
        holder[i] = rstr[i];
}

StrType::StrType(char* rstr) {
            
    size = 0;
    while(rstr[size])size++;

    holder = new char[size+1];
            
    for(size_t i = 0;i <= size;i++)
        holder[i] = rstr[i];
}

StrType::StrType(char chr) {
            
    size = 1;
    holder = new char[2];
    holder[0] = chr;
    holder[1] = 0;
}

StrType::StrType(const StrType &st) {

    size = st.size;
    holder = new char[size+1];
            
    for(size_t i = 0;i <= size;i++)
        holder[i] = st.holder[i];
}


ListType::ListType(const ListType &lt) {
    length = lt.length;
    container = new std::vector<TypeObject*>(*lt.container);
}

ListType::~ListType() {
    for (size_t i = 0;i < length;i++) delete (*container)[i];
    delete container; 
}






