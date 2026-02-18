#include<iostream>
#include<cstring>
#include<chrono>
#include<thread>


class Timer{
private:
    int sec;
public:
    Timer(int seconds){
        sec = seconds;
    }

    Timer(char* seconds){
        sec = std::stoi(seconds);
    }

    Timer(int minutes, int seconds){
        sec= seconds+(minutes*60);
    }


    void countdown(){
        for(int i = sec; i > 0; i--){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout<<"Remaining time: "<< i << std::endl;
        }
        std::cout<<"Time's up!"<<std::endl;
    }

};




int main(){
    Timer t = Timer(5,17);

    t.countdown();

}