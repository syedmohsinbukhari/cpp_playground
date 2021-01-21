#include<iostream>
#include<vector>


struct HugeJunkData {
    uint8_t *junkArr = new uint8_t [500000000];
};


int main() {
    std::vector<HugeJunkData> *v = new std::vector<HugeJunkData>();

    std::cout << "Constructing Huge Vector" << std::endl;
    for (int i=0; i<10; i++) {
        HugeJunkData aHugeJunk = {};
        for (int j=0; j<500000000; j++) {
            aHugeJunk.junkArr[j] = 1;
        }
        v->push_back(aHugeJunk);
    }

    std::cout << std::endl
        << "Enter 0 to exit. Anything else will increase size of vector by 1"
        << std::endl;
    int inp = 1;
    while (inp) {
        std::cout << "Waiting for input: ";
        std::cin >> inp;
        HugeJunkData aHugeJunk = {};
        for (int j=0; j<500000000; j++) {
            aHugeJunk.junkArr[j] = 1;
        }
        v->push_back(aHugeJunk);
    }
    std::cout << "Exiting!" << std::endl;
}
