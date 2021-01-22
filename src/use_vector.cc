#include "libvector.cc"


int main() {
    Vector vec1 = Vector();
    vec1.appendInt(4);
    vec1.appendInt(5);

    vec1.Print();

    Vector vec2(std::move(vec1));
    vec2.Print();

    vec1.Print();
}
