#include<iostream>
#include<memory>


class IntVector {
public:
    IntVector();
    IntVector(const IntVector& inpVector);
    IntVector(IntVector&& inpVector) noexcept;
    ~IntVector();
    int getSize() const;
    uint8_t getElement(int index) const;
    void appendInt(const uint8_t& x);
    void concatenate(const IntVector& inpVector);
    uint8_t * getVectorData() const;
    void emptyVectorData();
    void nullifyVectorData();
    void Print() const;
    void PrintSize() const;

private:
    uint8_t * vectorData;
    int count;
};

IntVector::IntVector() {
    std::cout << "Raw constructor" << std::endl;
    this->vectorData = nullptr;
    this->count = 0;
}

IntVector::IntVector(const IntVector& inpVector) {
    std::cout << "Copy constructor" << std::endl;

    this->count = inpVector.getSize();

    this->vectorData = new uint8_t[this->count];

    for (int i=0; i < this->count; i++) {
        this->vectorData[i] = inpVector.getElement(i);
    }
}

IntVector::IntVector(IntVector&& inpVector) noexcept {
    std::cout << "Move constructor" << std::endl;

    this->count = inpVector.getSize();

    this->vectorData = inpVector.vectorData;

    inpVector.nullifyVectorData();
}

IntVector::~IntVector() {
    std::cout << "Destroying" << std::endl;
    delete [] this->vectorData;
}

int IntVector::getSize() const {
    return this->count;
}

uint8_t IntVector::getElement(int index) const {
    return this->vectorData[index];
}

void IntVector::appendInt(const uint8_t& x) {
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

void IntVector::concatenate(const IntVector& inpVector) {
    for (int i=0; i < inpVector.getSize(); i++) {
        this->appendInt(inpVector.getElement(i));
    }
}

uint8_t * IntVector::getVectorData() const {
    return this->vectorData;
}

void IntVector::emptyVectorData() {
    std::cout << "Emptying Vector Data" << std::endl;

    delete [] this->vectorData;
    this->vectorData = nullptr;
    this->count = 0;
}

void IntVector::nullifyVectorData() {
    std::cout << "Nullifying Vector Data" << std::endl;

    this->vectorData = nullptr;
    this->count = 0;
}

void IntVector::Print() const {
    std::cout << "Print Vector {";
    for (int i=0; i < this->count; i++) {
        std::cout << unsigned(this->vectorData[i]);
        if (i != (this->count - 1)) {
            std::cout << ",";
        }
    }
    std::cout << "}" << std::endl;
}

void IntVector::PrintSize() const {
    std::cout << "Size of vector: " << this->count << std::endl;
}
