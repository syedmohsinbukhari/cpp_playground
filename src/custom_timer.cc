#include<iostream>
#include<chrono>
#include<thread>


class TimeIt{
private:
    std::chrono::time_point<std::chrono::system_clock> start_time;

public:
    TimeIt();
    ~TimeIt();
};

TimeIt::TimeIt() {
    this->start_time = std::chrono::system_clock::now();
}

TimeIt::~TimeIt() {
    auto end_time = std::chrono::system_clock::now();

    auto duration_time = std::chrono::duration_cast<std::chrono::microseconds>(
        end_time - this->start_time
    ).count();

    std::cout << duration_time << std::endl;
}


int main(){
    {
        auto tmr = TimeIt();

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return 0;
}
