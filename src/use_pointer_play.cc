#include<iostream>


void initializeRefToPtr(int *& pInt) {
    std::cout << pInt << std::endl;
    pInt = (int *)malloc(3 * sizeof(int));
    std::cout << pInt << std::endl;

    pInt[0] = 0;
    pInt[1] = 1;
    pInt[2] = 2;
}

void initializePtrToPtr(int ** pInt) {
    std::cout << *pInt << std::endl;
    *pInt = (int *)malloc(3 * sizeof(int));
    std::cout << *pInt << std::endl;

    *((*pInt) + 0) = 0;
    *((*pInt) + 1) = 1;
    *((*pInt) + 2) = 2;
}

int main() {
    std::cout << "initializeRefToPtr" << std::endl;
    int * pInt = nullptr;
    std::cout << pInt << std::endl;
    initializeRefToPtr(pInt);
    std::cout << pInt << std::endl;
    std::cout << pInt[0] << std::endl;
    std::cout << pInt[1] << std::endl;
    std::cout << pInt[2] << std::endl;
    free(pInt);
    std::cout << pInt << std::endl;

    std::cout << "initializePtrToPtr" << std::endl;
    pInt = nullptr;
    std::cout << pInt << std::endl;
    initializePtrToPtr(&pInt);
    std::cout << pInt << std::endl;
    std::cout << pInt[0] << std::endl;
    std::cout << pInt[1] << std::endl;
    std::cout << pInt[2] << std::endl;
    free(pInt);
    std::cout << pInt << std::endl;

    return 0;
}
