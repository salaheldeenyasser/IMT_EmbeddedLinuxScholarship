#include<iostream>


#if 1

template<typename T>
T add(T a, T b){
    return a+b;
}


#endif

/*template that deals with constant data*/

#if 1

template<typename T,const int scaler>
T scale(T a){
    return(a*scaler);
}


#endif

/*template with default data type and value*/

#if 1

template<typename T = int ,const int scaler = 10>
T scale(T a){
    return(a*scaler);
}


#endif

/*template class*/

#if 1

template<typename T, const int arr_sz>
class safearray{
    T data[arr_sz];
    const int size = arr_sz;

public:
    T& operator[](int index){
        if (index<arr_sz){
            return data[index];
        }
    }
};

#endif