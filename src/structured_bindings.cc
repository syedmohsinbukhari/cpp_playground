#include<iostream>
#include<tuple>


std::tuple<std::string, int> CreateCar() {
    return {"Nissan", 1991};
}


int main() {
    auto[car_make, car_yom] = CreateCar();

    std::cout << car_make << "/" << car_yom << std::endl;
}