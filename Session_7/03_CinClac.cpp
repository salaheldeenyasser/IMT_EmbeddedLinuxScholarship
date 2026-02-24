#include<iostream>
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;

#if 0

int main(){
    string line;
    stack<char> st;
    getline(cin,line);
    int first_token_pos = line.find(' ')
    for()

        std::stringstream ss(line);
        int first_op = 0;
        int second_op = 0;
        char op;
        
        ss >> first_op >> second_op >> op;
        st.push(first_op);
        st.push(second_op);
        st.push(op);
        
    }

}

#endif

#if 0

int main(){
    string line;
    stack<char> st;
    getline(cin,line);
    int first_token_pos = line.find(' ');
    string first_token = line.substr(0,first_token_pos);
    try
    {
        int first = stoi(first_token);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

}

#endif

#if 1

int main(){
    stack<int> st;
    string line;
    getline(cin,line);
    stringstream ss(line);
    string token;
    while(ss >> token){
        int number = 0;
        if(isdigit(token[0])){
            number = stoi(token);
            st.push(number);
        }
        else{
            switch(token[0]){
                case '+':
                case '-':
                case '*':
                case '/':
                int firstop = st.top();
                st.pop();
                int secondop = st.top();
                st.pop();
                
            }
        }
    }
    
    

}

#endif