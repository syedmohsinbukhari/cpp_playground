#include "libvector.cc"
#include<memory>


int main() {
    Vector<double> vec1 = Vector<double>();
    vec1.append(4.5);
    vec1.append(5.4);

    vec1.Print();

    Vector<double> vec2(std::move(vec1));
    vec2.Print();

    vec1.Print();
}
