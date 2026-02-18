#include <iostream>
#include <string>

int recordCounter;

void CSVParsing(std::string header, std::string record){

    recordCounter++;

    int recordComasArr[3];
    size_t startPos = 0;
        for (size_t i = 0; i < record.length(); i++)
        {
            
            size_t recordComas = record.find(",", startPos);
            if (recordComas != std::string::npos) {
                recordComasArr[i] = recordComas;
                startPos = recordComas + 1; 
            } else {
                break; 
            }
        }
    
    std::string name = record.substr(0, recordComasArr[0]);
    std::string email = record.substr(recordComasArr[0] + 1, recordComasArr[1] - recordComasArr[0] - 1);
    std::string city = record.substr(recordComasArr[1] + 1, recordComasArr[2] - recordComasArr[1] - 1);
    std::string salary = record.substr(recordComasArr[2] + 1, record.length() - recordComasArr[2] - 1);

    std::cout<<"Record: "<<recordCounter<<std::endl;
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Email: "<<email<<std::endl;
    std::cout<<"City: "<<city<<std::endl;
    std::cout<<"Salary: "<<salary<<std::endl;
}




int main() {
    std::string header = "Name,Email,City,Salary";
    std::string record = "John Doe,john.doe@example.com,New York,50000";

    std::string header2 = "Name,Email,City,Salary";
    std::string record2 = "Jane Smith,jane.smith@example.com,Los Angeles,60000";

    CSVParsing(header, record);
    CSVParsing(header2, record2);
    return 0;
}