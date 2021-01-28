#include<iostream>
#include<string.h>

#define DATATYPE char


int main() {
    DATATYPE * ptr = (DATATYPE *)malloc(10 * sizeof(DATATYPE));

    // memset makes each byte of pointed data equal to the value given
    memset(ptr, 65, 10 * sizeof(DATATYPE));

    for (int i=0; i < 10; i++) {
        std::cout << (DATATYPE)(*((DATATYPE *)ptr + i)) << std::endl;
    }

    free(ptr);

    return 0;
}
