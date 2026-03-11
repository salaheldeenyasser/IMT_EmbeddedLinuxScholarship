#include <iostream>
#include <cstring>
#include <cerrno>

using namespace std;

int main()
{
    //error handling with <errno>
    #if 0
    FILE *file = fopen("non_existent_file.txt", "r");
    if (file == nullptr)
    {
        cerr << "Error opening file: " << strerror(errno) << endl;
    }
    else
    {
        cout << "File opened successfully!" << endl;
        fclose(file);
    }
    #endif

    #if 1
    

    #endif
}