#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;


void printOneToTen() {
    std::thread::id th_id = std::this_thread::get_id();
    std::lock_guard<std::mutex> lck(mtx);
    std::cout << "Entering Thread: " << std::hex << th_id << std::endl;
    for (int i=1; i <= 10; i++) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}


int main() {
    auto th1 = std::thread(printOneToTen);
    auto th2 = std::thread(printOneToTen);

    th1.join();
    th2.join();

    return 0;
}
