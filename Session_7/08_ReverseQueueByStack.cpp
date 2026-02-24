#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int main(){
#if 0
    int s;
    queue<int> q;
    stack<int> st;
    for(int i = 0; i<s; i++){
        cin>>s;
        cout<<endl;
        q.push(s);
    }

    for (int i = 0; i < s; i++)
    {
        int num = q.front();
        st.push(num);
        q.pop();

    }
    
    for (int i = 0; i < s; i++)
    {
        cout<<st.top()<<" ";
        st.pop();
        
    }
#endif
    
    
    
#if 1
    int size;
    queue<int> q;
    stack<int> s;

    cout<<"Enter the size of the queue: "<< endl;
    cin>>size;
    cout<<endl;
    for(int i = 0; i<size; i++){
        int num;
        cin>>num;
        cout<<endl;
        q.push(num);
    }

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        cout<<q.back()<<endl;
        s.pop();
    }

#endif

    
}