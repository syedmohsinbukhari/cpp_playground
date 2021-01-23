#include<iostream>


template <typename T>
class Vector {
public:
    Vector();
    Vector(const Vector& inpVector);
    Vector(Vector&& inpVector) noexcept;
    ~Vector();
    int getSize() const;
    T getElement(int index) const;
    void append(const T& x);
    void concatenate(const Vector& inpVector);
    T * getVectorData() const;
    void emptyVectorData();
    void nullifyVectorData();
    void Print() const;
    void PrintSize() const;

private:
    T * vectorData;
    int count;
};

template <typename T>
Vector<T>::Vector() {
#if defined(DEBUG)
    std::cout << "Raw constructor" << std::endl;
#endif
    this->vectorData = nullptr;
    this->count = 0;
}

template <typename T>
Vector<T>::Vector(const Vector& inpVector) {
#if defined(DEBUG)
    std::cout << "Copy constructor" << std::endl;
#endif

    this->count = inpVector.getSize();

    this->vectorData = new T[this->count];

    for (int i=0; i < this->count; i++) {
        this->vectorData[i] = inpVector.getElement(i);
    }
}

template <typename T>
Vector<T>::Vector(Vector&& inpVector) noexcept {
#if defined(DEBUG)
    std::cout << "Move constructor" << std::endl;
#endif

    this->count = inpVector.getSize();

    this->vectorData = inpVector.vectorData;

    inpVector.nullifyVectorData();
}

template <typename T>
Vector<T>::~Vector() {
#if defined(DEBUG)
    std::cout << "Destroying" << std::endl;
#endif
    delete [] this->vectorData;
}

template <typename T>
int Vector<T>::getSize() const {
    return this->count;
}

template <typename T>
T Vector<T>::getElement(int index) const {
    return this->vectorData[index];
}

template <typename T>
void Vector<T>::append(const T& x) {
#if defined(DEBUG)
    std::cout << "Appending to vector" << std::endl;
#endif
    T * curVectorData = this->vectorData;
    this->vectorData = new T[this->count + 1];

    for (int i=0; i < this->count; i++) {
        this->vectorData[i] = curVectorData[i];
    }

    delete [] curVectorData;

    this->vectorData[this->count] = x;

    this->count += 1;
}

template <typename T>
void Vector<T>::concatenate(const Vector& inpVector) {
    for (int i=0; i < inpVector.getSize(); i++) {
        this->appendInt(inpVector.getElement(i));
    }
}

template <typename T>
T * Vector<T>::getVectorData() const {
    return this->vectorData;
}

template <typename T>
void Vector<T>::emptyVectorData() {
#if defined(DEBUG)
    std::cout << "Emptying Vector Data" << std::endl;
#endif

    delete [] this->vectorData;
    this->vectorData = nullptr;
    this->count = 0;
}

template <typename T>
void Vector<T>::nullifyVectorData() {
#if defined(DEBUG)
    std::cout << "Nullifying Vector Data" << std::endl;
#endif

    this->vectorData = nullptr;
    this->count = 0;
}

template <typename T>
void Vector<T>::Print() const {
    std::cout << "Print Vector {";
    for (int i=0; i < this->count; i++) {
        std::cout << this->vectorData[i];
        if (i != (this->count - 1)) {
            std::cout << ",";
        }
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void Vector<T>::PrintSize() const {
    std::cout << "Size of vector: " << this->count << std::endl;
}
