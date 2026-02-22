#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>


#if 1
int main(int argc, char* argv[]){
    std::vector<int> arg;
    arg.reserve(argc);
    int sum;
    for(int i=1; i< argc;i++){
        arg.push_back(std::stoi(std::string(argv[i])));
        sum+=arg.at(i);
    }
    std::cout<<sum<<std::endl;
}

#endif



#if 0

int main(int argc, char* argv[]){
    std::vector<int> v = {1,2,3,4,5};
    std::string key, value;
    int start, end;
    for(int i=1; i<argc; i++){
        std::string arg(argv[i]);
        std::stringstream parser(arg);
        std::getline(parser, key, '=');
        std::getline(parser, value);
        if (key == "from") {
            start = std::stoi(value);
        } else if (key == "to") {
            end = std::stoi(value);
        } else {
            std::cerr << "Error: Unsupported configuration!" << std::endl;
            return 1;
        }
    }
    int sum;
    for(; start<= end;start++){
        v.push_back(start);
        sum+=v.at(start);
    }

    std::cout<<sum<<std::endl;

    
}



#endif

#if 0
int main(){
    std::vector<int> nums {1,2,3,4,5,6};
    int sum = std::accumulate(nums.begin(), nums.end(), sum);
}

#endif

#if 0

int main(){

    #if 0
    std::vector<int> v {1,2,3,4,5,6};
    for(auto it = v.rbegin(); it !=v.rend(); it++)
    {
        std::cout<<*it<<std::endl;
    }

    #endif


    #if 1


    #endif


}
#endif

#if 0
// ./main.o > Session_6/sizevscapacity.csv
int main(){
    std::vector<int> v ;
    std::cout<<"Size,Capacity"<<std::endl;
    for(int i=0; i< 100; i++){
        v.push_back(i);
        std::cout<<v.size()<<","<<v.capacity()<<std::endl;
    }
}

#endif



