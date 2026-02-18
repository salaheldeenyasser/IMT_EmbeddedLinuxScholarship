#include<iostream>
#include<string>
#include<chrono>
#include<thread>


class Timer{
private:
    int h;
    int min;
    int sec;
public:

    Timer(int hours, int minutes, int seconds){
        
        h = hours;
        min= minutes; 
        sec= seconds;
    }

    Timer(int minutes, int seconds){
        sec = seconds;
        min = minutes;
    }

    Timer(std::string timeStr){

        
        h   = std::stoi(timeStr.substr(0, 2));
        min = std::stoi(timeStr.substr(3, 2));
        sec = std::stoi(timeStr.substr(6, 2));
    }

    void timePrint(){
        std::cout<<h<<":"<<min<<":"<<sec<<std::endl;
    }
    void run(){
        
        countdown();
        finish();
        
    }
    void finish(){
        std::cout<<"Time's up!"<<std::endl;
    }
    void countdown(){
        int temph = h;
        int tempm = min;
        int temps = sec; 
        if(h < 0 || min < 0 || sec < 0){
            std::cout<<"Invalid time input";
            return;
        }
        while(h > 0 || min > 0 || sec > 0){
            if(sec == 0){
                if(min == 0){
                    h--;
                    min = 59; 
                    sec = 59;
                }
                else{
                    min--;
                    sec = 59;
                }
            }
            else{
                sec--;
            }
            tick();
            timePrint();
        }
        
    }
    void tick(){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    


};




int main(){
    Timer t(3, 5, 10);

    t.run();

}