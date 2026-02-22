#include<iostream>
#include<string>
#include<sstream>
#include<vector>


int main(int argc, char* argv[]){
    std::vector<int> v;
    std::string line;
    while(std::getline(std::cin,line)){
        std::stringstream ss(line);
        std::string command;

        ss >> command;


        if(command == "create"){
            int val;
            while(ss >> val){
                v.push_back(val);
            }
        }
        else if (command == "insert")
        {
            std::string statement;
            ss >> statement;
            size_t pos = statement.find("@");
            if(pos != std::string::npos){
                int value = std::stoi(statement.substr(0,pos));
                int index = std::stoi(statement.substr(pos+1));
                v.insert(v.begin()+index, value);
            }
        }
        else if (command == "erase"){
            int index;
            ss >> index;
            v.erase(v.begin()+index);
        }
        else if (command == "append"){
            int value;
            ss >> value;
            v.push_back(value);
        }
        else if (command == "read"){
            int index;
            ss >> index;
            std::cout << v.at(index)<< std::endl;
        }
        else if (command == "write"){
            std::string statement;
            ss >> statement;
            size_t pos = statement.find("@");
            if(pos !=std::string::npos){
                int value = std::stoi(statement.substr(0,pos));
                int index = std::stoi(statement.substr(pos+1));
                v.at(index) = value;
            }
        }
        
    }
    for(int i : v) std::cout<<i<<", ";
    return 0;
}