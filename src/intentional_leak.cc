#include<iostream>
#include<memory>


int main() {
    uint64_t * x = new uint64_t(4);
    std::cout << *x << std::endl;

    std::cout << "Allocating new memory space "
        << "to `x` without freeing previous. Hence, causing a leak."
        << std::endl;
    x = new uint64_t(9);
    std::cout << *x << std::endl;

    return 0;
}
