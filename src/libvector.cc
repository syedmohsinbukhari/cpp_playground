#include<iostream>
#include<memory>


class Vector {
public:
    Vector();
    Vector(const Vector& inpVector);
    Vector(Vector&& inpVector) noexcept;
    ~Vector();
    int getSize() const;
    uint8_t getElement(int index) const;
    void appendInt(const uint8_t& x);
    void concatenate(const Vector& inpVector);
    uint8_t * getVectorData() const;
    void emptyVectorData();
    void nullifyVectorData();
    void Print() const;
    void PrintSize() const;

private:
    uint8_t * vectorData;
    int count;
};

Vector::Vector() {
    std::cout << "Raw constructor" << std::endl;
    this->vectorData = nullptr;
    this->count = 0;
}

Vector::Vector(const Vector& inpVector) {
    std::cout << "Copy constructor" << std::endl;

    this->count = inpVector.getSize();

    this->vectorData = new uint8_t[this->count];

    for (int i=0; i < this->count; i++) {
        this->vectorData[i] = inpVector.getElement(i);
    }
}

Vector::Vector(Vector&& inpVector) noexcept {
    std::cout << "Move constructor" << std::endl;

    this->count = inpVector.getSize();

    this->vectorData = inpVector.vectorData;

    inpVector.nullifyVectorData();
}

Vector::~Vector() {
    std::cout << "Destroying" << std::endl;
    delete [] this->vectorData;
}

int Vector::getSize() const {
    return this->count;
}

uint8_t Vector::getElement(int index) const {
    return this->vectorData[index];
}

void Vector::appendInt(const uint8_t& x) {
    std::cout << "Copying to vector: " << (int)x << std::endl;
    uint8_t * curVectorData = this->vectorData;
    this->vectorData = new uint8_t[this->count + 1];

    for (int i=0; i < this->count; i++) {
        this->vectorData[i] = curVectorData[i];
    }

    delete [] curVectorData;

    this->vectorData[this->count] = x;

    this->count += 1;
}

void Vector::concatenate(const Vector& inpVector) {
    for (int i=0; i < inpVector.getSize(); i++) {
        this->appendInt(inpVector.getElement(i));
    }
}

uint8_t * Vector::getVectorData() const {
    return this->vectorData;
}

void Vector::emptyVectorData() {
    std::cout << "Emptying Vector Data" << std::endl;

    delete [] this->vectorData;
    this->vectorData = nullptr;
    this->count = 0;
}

void Vector::nullifyVectorData() {
    std::cout << "Nullifying Vector Data" << std::endl;

    this->vectorData = nullptr;
    this->count = 0;
}

void Vector::Print() const {
    std::cout << "Print Vector {";
    for (int i=0; i < this->count; i++) {
        std::cout << unsigned(this->vectorData[i]);
        if (i != (this->count - 1)) {
            std::cout << ",";
        }
    }
    std::cout << "}" << std::endl;
}

void Vector::PrintSize() const {
    std::cout << "Size of vector: " << this->count << std::endl;
}
