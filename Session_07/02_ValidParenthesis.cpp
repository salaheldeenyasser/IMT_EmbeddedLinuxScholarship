#include<iostream>
#include<string>
#include<stack>
using namespace std;

#if 0
class Solution {
public:
    bool isValid(string s) {
        stack<string> st ;
        for(char ch:s){

            st.push(ch);
        }

        if(st.size()%2!=0){
            return 0;
        }

        if(){}

    }
};
#endif

#if 1


class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        bool ret= true;
        for(char ch:s){
            if (ch == '(' || ch == '{' || ch == '[' || ch == '<'){
                st.push(ch);
            }
            else {
                if(st.empty()){
                    ret = false;
                }
                else if( (ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '>' && st.top() == '<')){
                        st.pop();
                }
                else{
                    ret = false;
                }
            }   
        }
        
        if(!st.empty()){
            ret = false;
        }
        
        return ret;
    }
};

int main(){
    string s = "({[]})";
    Solution sol;
    cout<<sol.isValid(s)<<endl;
}
#endif