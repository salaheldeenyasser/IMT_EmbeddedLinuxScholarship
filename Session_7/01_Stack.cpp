#include<iostream>
#include<stack>

int main(int argc,char*argv[]){
#if 1

    std::stack<int> st;
    st.push(15);
    st.push(20);
    st.push(25);
    st.push(30);

    /* for(int i=0;i<st.size();i++){

    } */
    while(!st.empty()){
        auto top = st.top();
        std::cout<<top<<std::endl;
        st.pop();
    }

#endif
}



