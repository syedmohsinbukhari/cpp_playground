#include<iostream>


int main() {
    int i = 0;
    while(i++ < 10) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    int j = 0;
    while(++j < 10) {
        std::cout << j << ", ";
    }
    std::cout << std::endl;

    for (int k=0; k < 10; k++) {
        std::cout << k << ", ";
    }
    std::cout << std::endl;

    for (int l=0; l < 10; ++l) {
        std::cout << l << ", ";
    }
    std::cout << std::endl;

    return 0;
}
