
#include "src\\trlang.h"
#define MAX_REPLEN 30


int main() {

    /*char line[MAX_REPLEN];

    std::cout << ">>> ";
    std::cin.getline(line, MAX_REPLEN);

    for (int i = 0;i < MAX_REPLEN && line[i];i++)
        if (line[i] == '=')
    */

    TypeObject m1 = new MapType(10);
    TypeObject str1 = new StrType("c");

    (*(MapType*)(m1.getObject()))[str1];

    return 0;
}