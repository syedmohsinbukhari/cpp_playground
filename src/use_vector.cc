#include "libvector.cc"


int main() {
    IntVector vec1 = IntVector();
    vec1.appendInt(4);
    vec1.appendInt(5);

    vec1.Print();

    IntVector vec2(std::move(vec1));
    vec2.Print();

    vec1.Print();
}
